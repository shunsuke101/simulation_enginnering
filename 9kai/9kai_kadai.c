#include <stdio.h>

#define J 16
#define A 1.12e-4
#define T 1000.0   // 最終時間
#define N 60   // 時間分割数：ここを変えるとdtが変わる（発散/非発散の切替）N=50で発散、N=60で収束

int main() {
    double u0[J+1], u1[J+1];
    double x, t, dx = 1.0 / (double)J, dt = T / (double)N;
    double r = A * dt / (dx * dx);
    int j, n;


    // ---- 初期条件 ----
    for (j = 0; j <= J; j++) {
        x = j * dx;
        if (x <= 0.5)
            u0[j] = x;
        else
            u0[j] = 1.0 - x;
    }
    // 境界条件
    u0[0] = 0.0;
    u0[J] = 0.0;

    // ---- x座標の出力 ----
    printf("%d", J + 1);
    for (j = 0; j <= J; j++) {
        x = j * dx;
        printf(" %e", x);
    }
    printf("\n");

    // ---- 初期時刻 t=0 ----
    printf("0.0");
    for (j = 0; j <= J; j++)
        printf(" %e", u0[j]);
    printf("\n");

    // ---- 時間ステップ ----
    for (n = 1; n <= N; n++) {
        // 内部点の更新
        for (j = 1; j < J; j++) {
            u1[j] = (1.0 - 2.0 * r) * u0[j] + r * (u0[j - 1] + u0[j + 1]);
        }
        // 境界条件
        u1[0] = 0.0;
        u1[J] = 0.0;

        // u0 ← u1
        for (j = 0; j <= J; j++)
            u0[j] = u1[j];

        // 出力
        t = n * dt;
        printf("%e", t);
        for (j = 0; j <= J; j++)
   	    printf(" %e", u0[j]);
        printf("\n");
    }
    return 0;
}

