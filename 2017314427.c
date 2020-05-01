
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

//
void choose(int a);
double angle(int a, double b);
double discr1_6(int a, double b);
double fac(int a);
double pow(double b, int n);
void giveans1_6(int a, double b, double c);

//calculating functions.
double cosx(double x);
double sinx(double x);
double tanx(double x);
double acosx(double x);
double asinx(double x);
double atanx(double x);
double xpowy(double x, int y);
double xpow1_y(double x, int y);
double epowx(double x);
double lnx(double x);



#include <stdio.h>

main()
{
	int ans, angle_tp;
	double realangle, rad, x, value,y;
	printf("**********Input Your Desired Function**********\n");
	printf("1)Cos(x)\n2)Sin(x)\n3)Tan(x)\n4)Acos(x)\n5)Asin(x)\n6)Atan(x)\n7)x^y\n8)x^(1/y)\n9)e^x\n10)loge(x)\n");
	scanf("%d", &ans);
	printf("------------------------------------------------\n");
	while (!((ans > 0) && (ans < 11))) {//If input is wrong, repeat the question.
		printf("Your Input is Worng! Try Again\n");
		printf("**********Input Your Desired Function**********\n");
		printf("1)Cos(x)\n2)Sin(x)\n3)Tan(x)\n4)Acos(x)\n5)Asin(x)\n6)Atan(x)\n7)x^y\n8)x^(1/y)\n9)e^x\n10)loge(x)\n");
		scanf("%d", &ans);
		printf("------------------------------------------------\n");
	}
	choose(ans);
	printf(" has been chosen\n");
	if (ans < 4)//if answer<4, calculate in sinx or cosx or tanx
	{
		printf("Input Your Desired Angle Type\n");
		printf("1)Degrees\n2)Radians\n3)Gradians\n");
		scanf("%d", &angle_tp);
		printf("------------------------------------------------\n");
		while ((angle_tp <= 0) || (angle_tp >= 4))//check if input is right.
		{
			printf("Your Input is Worng! Try Again\n");
			printf("Input Your Desired Angle Type\n");
			printf("1)Degrees\n2)Radians\n3)Gradians\n");
			scanf("%d", &angle_tp);
			printf("------------------------------------------------\n");
		}
		printf("Input Your Desired Angle Value\n");
		scanf("%lf", &realangle);
		rad = angle(angle_tp, realangle);
		giveans1_6(ans, realangle, discr1_6(ans, rad));
	}

	else if ((ans > 3) && (ans < 7))//the user choose 4~6
	{
		printf("Input your value\nValue should be in range(-1<=x<=1)\n");
		scanf("%lf", &value);
		while ((value > 1) || (value < -1))//check if x is in range.
		{
			printf("******error******\nThe value exceed the range of xd\n");
			printf("Input your value\nValue should be in range(-1<=x<=1)\n");
			scanf("%lf", &value);
		}
		giveans1_6(ans, value, discr1_6(ans, value));
	}

	else if (ans == 7 || ans == 8)//the user choose 7 or 8
	{
		printf("Input x's value and y's value.(y should be integer.)\nx: ");
		scanf("%lf", &x);
		printf("y: ");
		scanf("%lf", &y);
		while (y - (int)y)//check if y is integer or not.
		{
			printf("******error******\ny should be integer.\n");
			printf("y: ");
			scanf("%lf", &y);
		}
		if (ans == 7)
			printf("(%lf)^%.1lf= %lf", x, y, xpowy(x, y));
		else
			if(x>=0)
				printf("(%lf)^(1/%.1lf)=%lf", x, y, xpow1_y(x, y));
			else
				printf("(%lf)^(1/%.1lf)=%lfi", x, y, xpow1_y(-x, y));	
	}

	else//the suer choose 9 or 10 function.
	{
		printf("Input x's value\nx: ");
		scanf("%lf", &x);
		if (ans == 9)
			printf("e^%lf= %lf\n", x, epowx(x));
		else
			while (x <= 0)
			{
				printf("******error******\nx should be greater than 0\n");
				printf("Input x's value\nx: ");
				scanf("%lf", &x);
			}
			printf("loge%lf= %lf\n", x, lnx(x));
	}

}

void choose(int a)
//Repeat what  the user choose.(a= desired fuction type)
{
	if (a == 1)
		printf("Cos(x)");
	else if (a == 2)
		printf("Sin(x)");
	else if (a == 3)
		printf("Tan(x)");
	else if (a == 4)
		printf("Acos(x)");
	else if (a == 5)
		printf("Asin(x)");
	else if (a == 6)
		printf("Atan(x)");
	else if (a == 7)
		printf("x^y");
	else if (a == 8)
		printf("x^(1/y)");
	else if (a == 9)
		printf("e^x");
	else
		printf("loge(x)");
}


double angle(int a, double b)// change any type of angles as radian. 
//(a= desired angle type, b= desired angle value)
{
	double k;
	if (a == 1)
		k = 3.14159265358979 * b / 180;
	else if (a == 2)
		k = b;
	else
		k = b / 400 * 2 * 3.14159265358979;
	return k;
}

double discr1_6(int a, double b)//calculate with desired function.(a=desired function, b=radian)
{
	if (a == 1)
		return cosx(b);
	else if (a == 2)
		return sinx(b);
	else if (a == 3)
		return tanx(b);
	else if (a == 4)
		return acosx(b);
	else if (a == 5)
		return asinx(b);
	else if (a == 6)
		return atanx(b);
}

void giveans1_6(int a, double b, double c)//Give users an answer or determine if it is error 
//(a= function type, b= input degree value or just value, c= calculated answer)
{
	if (a == 1)
		printf("Cos(%lf)= %lf\n", b, c);
	else if (a == 2)
		printf("Sin(%lf)= %lf", b, c);
	else if (a == 3)
		printf("Tan(%lf)= %lf", b, c);
	else if (a == 4)
		printf("Acos(%lf)= %lfrad or %lfdegree or %lfgradian", b, c, c * 180.0 / 3.14159265358979, c * 200.0 / 3.14159265358979);
	else if (a == 5)
		printf("Asin(%lf)= %lfrad or %lfdegree or %lfgradian", b, c, c * 180.0 / 3.14159265358979, c * 200.0 / 3.14159265358979);
	else if (a == 6)
		printf("Atan(%lf)= %lfrad or %lfdegree or %lfgradian", b, c, c * 180.0 / 3.14159265358979, c * 200.0 / 3.14159265358979);
}


//factorial function
double fac(int a)
{
	if (a == 0)
		return 1.0;
	else
		return a * fac(a - 1);
}

//power function
double pow(double b, int n)
{
	if (n == 0)
		return 1.0;
	else
		return b * pow(b, n - 1);
}

//cos(x) fuction using taylor series
double cosx(double x)
{
	double cos = 0;
	for (int i = 0; i <= 15; ++i)
		cos += pow(-1, i) * pow(x, 2.0 * i) / fac(2.0 * i);
	return cos;
}

//sin(x) function using taylor seires
double sinx(double x)
{
	double sin = 0;
	;
	for (int i = 1; i <= 15; ++i)
	{
		sin += pow(-1, i - 1) * pow(x, 2 * i - 1) / fac(2 * i - 1);
	}
	return sin;
}

//tan(x) function using sin(x) and cos(x)
double tanx(double x)
{
	return sinx(x) / cosx(x);
}

//acos(x) function using taylor series.(-1<=x<=1)
double acosx(double x)
{
	double arccos, arcsin = 0;
	for (int i = 0; i <= 15; ++i)
		arcsin += fac(2.0 * i) * pow(x, 2 * i + 1) / (pow(4.0, i) * pow(fac(i), 2) * (2.0 * i + 1));
	arccos = 3.141592653589793238 / 2 - arcsin;
	return arccos;

}

//asin(x) function using taylor series.(-1<=x<=1)
double asinx(double x)
{
	double arcsin = 0;
	for (int i = 0; i <= 15; ++i)
		arcsin += fac(2 * i) * pow(x, 2 * i + 1) / (pow(4.0, i) * pow(fac(i), 2) * (2 * i + 1));
	return arcsin;
}

//atan function using taylor series.(-1<=x<=1)
double atanx(double x)
{
	double arctan = 0;
	for (int i = 0; i <= 30; ++i)
		arctan += pow(-1, i) * pow(x, 2 * i + 1) / (2 * i + 1);
	return arctan;
}

//x^y function using pow function.
double xpowy(double x, int y)
{
	return pow(x, y);
}
//x^(1/y) function using (x^(1/y)=e^((lnx)/y))
double xpow1_y(double x, int y)
{
	return epowx(lnx(x) / y);
}
//e^x function using taylor series.
double epowx(double x)
{
	double e = 0;
	for (int i = 0; i <= 20; ++i)
		e += pow(x, i) / fac(i);
	return e;
}

//lnx expansions.
double lnx(double x)
{

	double sum = 0;
	if ((x > 0) && (x <= 2))
	{
		for (int i = 1; i <= 300; ++i)
			sum += pow(-1, i + 1) * pow(x - 1, i) / i;
	}
	else
	{
		for (int i = 1; i <= 500; ++i)
			sum += pow(((x - 1) / x), i) / i;
	}
	return sum;
}
