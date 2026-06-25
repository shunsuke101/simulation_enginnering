#include <stdio.h>

#define J 16
#define A 1.12e-4
#define T 1000.0   // 最終時間
#define N 60   // 時間分割数：ここを変えるとdtが変わる（発散/非発散の切替）

void main() {
    double u0[J+1], u1[J+1];
    double x, t, dx = 1.0 / (double)J, dt = T / (double)N;
    double r = (A * dt )/ (dx * dx);
    int j, n;

    if(r<=0.5)
    {
	    printf("tの値%e\n",dt);
	    printf("rの値%e\n",r);
	    printf("収束条件");
    }else{
	    printf("tの値%e\n",dt);
	    printf("%e\n",r);
	    printf("発散条件");
    }

}
