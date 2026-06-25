#include<stdio.h>
#include<math.h>
#define J 64  /*x座標の分割数*/
#define K 64  /*y座標の分割数*/
#define MAX_ITER 10000
#define TOL 1e-6


int main(){
  double u[J+1][K+1];
  double dx=1.0/(double)J, dy=1/(double)K;
  int j,k,iter;
  double old,max_error;
  
  /*配列の初期化*/
  for(j=0;j<=J;j++){
	  for(k=0;k<=K;k++)
		  u[j][k]=0.0;
  }
  printf("\n");


  /*境界条件*/
  for(j=0;j<=J;j++)
  {
	  u[0][j]=0.0;
	  u[j][0]=0.0;
	  u[J][j]=8.0;
	  u[j][K]=16.0;
  }
  for(iter=0;iter<MAX_ITER;iter++){
	max_error=0.0;
  	for(j=1;j<J;j++){
    		for(k=1;k<K;k++){
			old=u[j][k];
			u[j][k]=(u[j-1][k]+u[j+1][k]+u[j][k-1]+u[j][k+1])/4; 
			double err=fabs(u[j][k]-old);
			if(err>max_error){
				max_error=err;
			}
		}
  	}
	if(max_error<TOL){
		break;
	}
  }

  for(j=0;j<=J;j++){
    for(k=0;k<=K;k++){
        printf("%lf %lf %lf\n",j*dx,k*dy,u[j][k]);
    }
  }

  return 0;
}
