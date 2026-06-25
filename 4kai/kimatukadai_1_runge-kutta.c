#include<stdio.h>

double f_x(double y_pre);
double f_y(double x_pre);


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
                double k1x=h*f_x(y);
		double k1y=h*f_y(x);
		double k2x=h*f_x(y+k1y/2);
		double k2y=h*f_y(x+k1x/2);
		double k3x=h*f_x(y+k2y/2);
		double k3y=h*f_y(x+k2x/2);
		double k4x=h*f_x(y+k3y);
		double k4y=h*f_y(x+k3x);
		double x_new=x+(k1x+2.0*k2x+2.0*k3x+k4x)/6.0;
                double y_new=y+(k1y+2.0*k2y+2.0*k3y+k4y)/6.0;
                

                x=x_new;
                y=y_new;
                printf("%5.5lf %5.5lf %5.5lf\n",t,x,y);
                i++;
                t=h*i;
        }
}

double f_x(double y_pre){
        return y_pre;
}
double f_y(double x_pre){
        return -x_pre;
}
