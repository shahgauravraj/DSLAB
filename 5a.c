#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double eval_sinx(double xrad, long int NT, long int (*funcptr)());
long int fact(long int n);

#define pi 22/7

int main()
{
	long int NT;
	double sinx, xrad, xdeg;

	printf("Enter the angle in degrees:");
	scanf("%lf",&xdeg);

	printf("Enter the number of terms:");
	scanf("%ld",&NT);

	xrad=xdeg*pi/180;
	sinx=eval_sinx(xrad,NT,fact);
	printf("\n Sin(%lf)=%lf\n",xdeg, sinx); 
}

double eval_sinx(double xrad,long int NT, long int (*funcptr)())
{
            int i;
	double sinx=0;
	int sign=1;
	for(i=1;  i<=NT;  i+=2)
	{
		sinx=sinx + sign * pow(xrad,i)/(*funcptr)(i);
		sign=-(sign);
	}
	return(sinx);
}

long int fact(long int n)
{
	if(n==0 || n==1)
		return(1);
	return(n*fact(n-1));
}
