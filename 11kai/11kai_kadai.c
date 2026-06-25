#include<stdio.h>

#define J 32 //空間xの分割数
#define N 320 //時間tの分割数発散するかしないかはここにかかわるN=320で収束、N=300で発散
#define T 0.1 //時間の上限

#define C 8.92e+3 //波動方程式の係数


void main(){
  double u0[J+1], u1[J+1], u2[J+1]; /*uの番号はtの前後関係、配列はx座標を表す*/
  double x, t, dx=1.0/(double)J, dt=T/(double)N;
  double mu=(C*dt*dt)/(dx*dx);
  int j, n;

  // ---- 初期条件 ----
  for (j = 0; j <= J; j++) {
	x = (double)j * dx;
        if (x <= 0.5)
            u0[j] = x;
        else
            u0[j] = 1.0 - x;
   }
    // 境界条件
    u0[0] = 0.0;
    u0[J] = 0.0;

    for(j=1;j<J;j++){
	    u1[j]=u0[j];
    }


  printf("%d",J+1); /*xの分割数を出力*/
  /*分割されたx座標を出力*/
  for(j=0;j<=J;j++){
    x=(double)j*dx;
    printf("%e",x);
  }
  printf("\n");

  printf("0.0");/*t=0.0の時のuの座標を出力*/
  for(j=0;j<=J;j++){
    x=(double)j*dx;
    printf(" %e", u0[j]);
  }
  printf("\n");

  //t=0.0以降をt=0.1まで求める
  for(n=1;n<=N;n++){
    for(j=1;j<J;j++){
	u2[j]=(2-2*mu)*u1[j]+mu*(u1[j-1]+u1[j+1])-u0[j];
    }

    for(j=1;j<J;j++){
	u0[j]=u1[j];
      	u1[j]=u2[j];
    }

    t=(double)n*dt;
    printf("%e", t);
    u0[0]=0;
    u0[J]=0;
    for(j=0;j<=J;j++) printf(" %e", u0[j]);
    printf("\n");
  }
}

