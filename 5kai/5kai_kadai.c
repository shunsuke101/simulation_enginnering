#include<stdio.h>


void main()
{
	double h=1.0/64.0; /*刻み幅*/
	double y=-2+h*h*36;
	double a[100]; /*下対角成分*/
	double b[100]; /*主対角成分*/
	double c[100]; /*上対角成分*/
	double d[100]; /*解の出力*/
	double p[100]; /*c^*/
	double q[100]; /*d^*/
	int n=64; /*分割数*/

	/*配列の作成*/
	a[0]=0;
	for(int i=0;i<n;i++){
		a[i+1]=1;
		b[i]=y;
		c[i]=1;
		d[i]=0.0;
		p[i]=0.0;
		q[i]=0.0;
	}
	c[n-1]=0;
	d[n-1]=-1;
	
	/*行列計算トマス法*/
	p[0]=c[0]/b[0];
	q[0]=d[0]/b[0];

	for(int j=1;j<n;j++)
	{
		double w=b[j]-p[j-1]*a[j];
		p[j]=c[j]/w;
		q[j]=(d[j]-q[j-1]*a[j])/w;
	}

	d[n-1]=q[n-1];

	for(int k=n-2;k>=0;k--)
	{
		d[k]=q[k]-d[k+1]*p[k];
	}

	/*数値の出力*/
	printf("# t x \n");
	for(int l=0;l<n-1;l++){
		printf("%lf %lf\n",h*(l+1),d[l]);
	}
}	



		

