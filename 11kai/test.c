#include<stdio.h>
#include<math.h>
#define J 32 //空間xの分割数
#define N 300 //時間tの分割数発散するかしないかはここにかかわるN=512で収束、N=256で発散
#define T 0.1 //時間の上限

#define C 8.92e+3 //波動方程式の係数

void main(){
	double x, t, dx=1.0/(double)J, dt=T/(double)N;
  	double mu=(C*dt*dt)/(dx*dx);

	if(mu<=1)
    	{
        	printf("dtの値%e\n",dt);
            	printf("muの値%e\n",mu);
            	printf("収束条件");
    	}else{
            	printf("dtの値%e\n",dt);
            	printf("muの値%e\n",mu);
            	printf("発散条件");
    	}
}
