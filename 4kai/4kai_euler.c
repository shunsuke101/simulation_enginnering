#include<stdio.h>
#include<math.h>
double f_x(double x_pre,double y_pre, double h);
double f_y(double x_pre,double y_pre,double h);


void main(){
        //初期値
        double x=0;
        double y=1; //初速度
	double t=0; //時刻
	int T=20; //時間の範囲

        //刻み幅
        double h=0.25;

        //カウンター
        double i=0.0;
        printf("# t x y \n");
        while(t<=T){
                double x_new=f_x(x,y,h);
                double y_new=f_y(x,y,h);

                x=x_new;
                y=y_new;
                printf("%5.5lf %5.5lf %5.5lf\n",t,x,y);
                i++;
		t=h*i;
        }
}

double f_x(double x_pre,double y_pre, double h){
        return x_pre+y_pre*h;
}
double f_y(double x_pre,double y_pre,double h){
        return y_pre-x_pre*h;
}
