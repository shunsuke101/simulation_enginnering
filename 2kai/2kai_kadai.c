#include<stdio.h>
#include<math.h>

double f_r(double r_pre,double v_pre, double h);
double f_v(double r_pre,double v_pre,double R, double g,double h);


void main(){
	//パラメータ
	double R=6378137; //地球の半径
	double g=9.80665; //重力加速度

	//初期値
	double r=R;
	double v=11000; //初速度

	//刻み幅
	double h=0x1.0p-4;

	//カウンター
	double i=1.0;
	printf("# t r v \n");
	while(R<=r){
		double r_new=f_r(r,v,h);
		double v_new=f_v(r,v,R,g,h);

		r=r_new;
		v=v_new;
		printf("%5.5lf %5.5lf %5.5lf\n",0.0+h*i,r,v);
		i++;

		if(10*R<r){
			printf("目標高度に到達");
			break;
		}
	}
}

double f_r(double r_pre,double v_pre, double h){
	return r_pre+v_pre*h;
}
double f_v(double r_pre,double v_pre,double R, double g,double h){
	return v_pre-((R*R*g)/(r_pre*r_pre))*h;
}

