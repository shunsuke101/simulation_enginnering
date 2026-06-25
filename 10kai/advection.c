#include<stdio.h>
#include<math.h>
#define J 16
#define N 32
#define T 1.0

#define C 1.5
double f(double x, double t){
  double a=x-C*t;
  return exp(-10.0*a*a);
}

int main(){
  double u0[J+1], u1[J+1];
  double x, t, dx=1.0/(double)J, dt=T/(double)N;
  double mu=C*dt/dx;
  int j, n;

  printf("%d",J+1); /*xの分割数を出力*/
  /*分割されたx座標を出力*/
  for(j=0;j<=J;j++){
    x=(double)j*dx;
    printf(" %e",x);
  }
  printf("\n");

  printf("0.0");/*t=0.0の時のuの座標を出力*/
  for(j=0;j<=J;j++){
    x=(double)j*dx;
    u0[j]=f(x,0.0);
    printf(" %e", u0[j]);
  }
  printf("\n");

  for(n=1;n<=N;n++){
    for(j=1;j<J;j++){
	/*u1[j]=((1+mu)*u0[j])-(mu*u0[j+1]); 前進差分近似*/
	u1[j]=((1-mu)*u0[j])+(mu*u0[j-1]); /*後進差分近似*/
	/*u1[j]=u0[j]-(mu/2)*(u0[j+1]-u[j-1]);*/
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

