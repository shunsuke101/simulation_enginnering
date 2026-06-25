#include<stdio.h>
#include<math.h>
#define J 64
#define N 128
#define T 1.0

#define C -1
double f(double x, double t){
  double a=1-x-t;
  return exp(-20.0*a*a);
}

int main(){
  double u0[J+1], u1[J+1];
  double x, t, dx=1.0/(double)J, dt=T/(double)N;
  double mu=C*dt/dx;
  int j, n;
  
  printf("%d",J+1);
  for(j=0;j<=J;j++){
    x=(double)j*dx;
    printf(" %e",x);
  }
  printf("\n");

  printf("0.0");
  for(j=0;j<=J;j++){
    x=(double)j*dx;
    u0[j]=f(x,0.0);
    printf(" %e", u0[j]);
  }
  printf("\n");

  for(n=1;n<=N;n++){
    for(j=1;j<J;j++){
	u1[j]=((1+mu)*u0[j])-(mu*u0[j+1]); /*c<0ので前進差分近似*/
    }
    for(j=1;j<J;j++){
      u0[j]=u1[j];
    }

    t=(double)n*dt;
    printf("%e", t);
    u0[0]=f(0.0, t);
    u0[J]=f(1.0, t);
    for(j=0;j<=J;j++) printf(" %e", u0[j]);
    printf("\n");
  }
  
  return 0;
}
