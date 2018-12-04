#include "my_complex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//using two kind of form to represent the complex
enum coordinate_type{RECTANGULAR=1,POLAR};

struct complex_struct
{
    enum coordinate_type t;
    double x, y;
};
double real_part(struct complex_struct z)
{
    if(z.t==RECTANGULAR)
        return z.x;
    else
        return z.x * cos(z.y);
}
double img_part(struct complex_struct z)
{
    if(z.t==RECTANGULAR)
        return z.y;
    else
        return z.x*sin(z.y);
}
double magnitude(struct complex_struct z)
{
    if(z.t==RECTANGULAR)
        return sqrt(z.x * z.x + z.y * z.y);
    else
        return z.x;
}
double angle(struct complex_struct z)
{
    if(z.t==RECTANGULAR)
    {
        double PI = acos(-1.0);
        if (z.x > 0)
            return atan(z.y / z.x);
        else
            return atan(z.y / z.x) + PI;
    }
    else
    {
        return z.y;
    }
}
struct complex_struct make_from_real_img(double x, double y)
{
    struct complex_struct z;
    z.t=RECTANGULAR;
    z.x = x;
    z.y = y;
    return z;
}
struct complex_struct make_from_mag_ang(double r, double A)
{
    struct complex_struct z;
    z.t=POLAR;
    z.x=r;
    z.y=A;
    return z;
}
//
//struct complex_struct {
//    double r, A;
//};
//double real_part(struct complex_struct z)
//{
//    return z.r * cos(z.A);
//}
//double img_part(struct complex_struct z)
//{
//    return z.r * sin(z.A);
//}
//double magnitude(struct complex_struct z)
//{
//    return z.r;
//}
//double angle(struct complex_struct z)
//{
//    return z.A;
//}
//struct complex_struct make_from_real_img(double x, double y)
//{
//    struct complex_struct z;
//    double PI = acos(-1.0);
//    z.r = sqrt(x * x + y * y);
//    if (x > 0)
//    z.A = atan(y / x);
//    else
//    z.A = atan(y / x) + PI;
//    return z;
//}
//struct complex_struct make_from_mag_ang(double r, double A)
//{
//    struct complex_struct z;
//    z.r = r;
//    z.A = A;
//    return z;
//}
//






//+-*/
//3kinds:two polar,two rectangular,one polar and one rectangular
struct complex_struct add_complex(struct complex_struct z1, struct
complex_struct z2)
{
    return make_from_real_img(real_part(z1) + real_part(z2),
    img_part(z1) + img_part(z2));
}
struct complex_struct sub_complex(struct complex_struct z1, struct
complex_struct z2)
{
    return make_from_real_img(real_part(z1) - real_part(z2),
    img_part(z1) - img_part(z2));
}
struct complex_struct mul_complex(struct complex_struct z1, struct
complex_struct z2)
{
    return make_from_mag_ang(magnitude(z1) * magnitude(z2),
    angle(z1) + angle(z2));
}
struct complex_struct div_complex(struct complex_struct z1, struct
complex_struct z2)
{
    return make_from_mag_ang(magnitude(z1) / magnitude(z2),
    angle(z1) - angle(z2));
}
void print_complex(struct complex_struct z)
{
    double real=real_part(z);
    double imag=img_part(z);
    if(real-0.0==0 || imag-0.0==0)
    {
        if(real-0.0==0.0 && imag-0.0==0.0)
        {
            printf("0\n");
        }else if(real-0.0==0)
        {
                printf("%fi\n",imag);
        }else if(imag==0)
        {
            printf("%f\n",real);
        }

    }else
    {
        printf("%f",real);
        if(imag>0.0)
            printf("+");
        printf("%fi\n",imag);
    }
}
//---------------------------------------------------------
void test_complex()
{
    struct complex_struct z1=make_from_real_img(1,1);
    printf("angle:%f\n",angle(z1));
    printf("magnitude:%f\n",magnitude(z1));


    struct complex_struct z2=make_from_real_img(-1,9);
    struct complex_struct z3=make_from_real_img(1,-9);
    struct complex_struct z4=make_from_real_img(-1,-9);
    struct complex_struct z5=make_from_real_img(-1,0);
    struct complex_struct z6=make_from_real_img(1,-9);
    struct complex_struct z7=make_from_real_img(1,0);
    print_complex(z1);
    print_complex(z2);
    print_complex(z3);
    print_complex(z4);
    print_complex(z5);
    print_complex(z6);
    print_complex(z7);
}

extern int my_gcd(int a,int b);

//最大公约数
int my_gysh(int a,int b)
{
    int g=my_gcd(a,b);
    return a*b/g;
}

struct rational_struct
{
    int a;
    int b;
};
struct rational_struct make_rational(int a,int b)
{
    if(b==0)
        printf("b!=0\n");
    if(b<0)
    {
        a*=-1;
        b*=-1;
    }
    int a_cpy=abs(a);
    int g=my_gcd(a_cpy,b);
    if(g!=1)
    {
        a=a/g;
        b=b/g;
    }
    struct rational_struct z={a,b};
    return z;
}
int rational_get_num(struct rational_struct z)
{
    return z.a;
}
int rational_get_den(struct rational_struct z)
{
    return z.b;
}
void print_rational(struct rational_struct a)
{
    int num=rational_get_num(a);
    int den=rational_get_den(a);
    if(den==1)
    {
        printf("%d\n",num);
    }else
    {
        printf("%d/%d\n",num,den);
    }
}
struct rational_struct add_rational(struct rational_struct z1,struct rational_struct z2)
{
    int den1,den2,num1,num2;
    den1=rational_get_den(z1);
    den2=rational_get_den(z2);
    int number_gysh=my_gysh(den1,den2);//这是新的分母
    num1=rational_get_num(z1)*number_gysh/den1;//这是新的分子
    num2=rational_get_num(z2)*number_gysh/den2;//这是新的分子
    return make_rational(num1+num2,number_gysh);
}
struct rational_struct sub_rational(struct rational_struct z1,struct rational_struct z2)
{
    int den1,den2,num1,num2;
    den1=rational_get_den(z1);
    den2=rational_get_den(z2);
    int number_gysh=my_gysh(den1,den2);//这是新的分母
    num1=rational_get_num(z1)*number_gysh/den1;//这是新的分子
    num2=rational_get_num(z2)*number_gysh/den2;//这是新的分子
    return make_rational(num1-num2,number_gysh);
}
struct rational_struct mul_rational(struct rational_struct z1,struct rational_struct z2)
{
    int den1,den2,num1,num2;
    den1=rational_get_den(z1);
    den2=rational_get_den(z2);

    num1=rational_get_num(z1);//这是新的分子
    num2=rational_get_num(z2);//这是新的分子
    return make_rational(num1*num2,den1*den2);
}
struct rational_struct div_rational(struct rational_struct z1,struct rational_struct z2)
{
    int den1,den2,num1,num2;
    den1=rational_get_den(z1);
    den2=rational_get_den(z2);

    num1=rational_get_num(z1);//这是新的分子
    num2=rational_get_num(z2);//这是新的分子
    return make_rational(num1*den2,den1*num2);
}
//-------------------------------------------------------------
void test_rational()
{
    struct rational_struct z=make_rational(1,3);
    struct rational_struct z1=make_rational(3,6);
    struct rational_struct z2=make_rational(3,-6);
    struct rational_struct z3=make_rational(3,-3);
    print_rational(z);
    print_rational(z1);
    print_rational(z2);
    print_rational(z3);

    print_rational(add_rational(z,z1));
    print_rational(add_rational(z,z2));
    print_rational(add_rational(z,z3));

    print_rational(sub_rational(z,z1));
    print_rational(sub_rational(z,z2));
    print_rational(sub_rational(z,z3));

    print_rational(mul_rational(z,z1));
    print_rational(mul_rational(z,z2));
    print_rational(mul_rational(z,z3));

    print_rational(div_rational(z,z1));
    print_rational(div_rational(z,z2));
    print_rational(div_rational(z,z3));

}
//----------------------------------------------------
//OVRWRITE THE ENUM VARIABLE.
//void excise()
//{
//    int RECTANGULAR;
//    printf("%d,%d\n",RECTANGULAR,POLAR);
//}
//#define SHITMAN 11
//#define SHITMANS 22
//void exciseV2()
//{
//    int SHITMAN;
//    printf("%d %d\n",SHITMAN,SHITMANS);
//}
//------------------------------------------------------
//ex8.3
#define N   100000
#define M   10
int a[N];
int count_a[M];

void test_rand()
{
    int i;
    srand(time(NULL));
    for(i=0;i<N;i++)
    {
        a[i]=rand()%10;
        count_a[a[i]]++;
    }
    for(i=0;i<M;i++)
    {
        printf("%d:%d\n",i,count_a[i]);

    }
}









