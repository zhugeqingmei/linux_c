#include "my_complex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

struct complex_struct
{
    double x, y;
};
double real_part(struct complex_struct z)
{
    return z.x;
}
double img_part(struct complex_struct z)
{
    return z.y;
}
double magnitude(struct complex_struct z)
{
    return sqrt(z.x * z.x + z.y * z.y);
}
double angle(struct complex_struct z)
{
    double PI = acos(-1.0);
    if (z.x > 0)
        return atan(z.y / z.x);
    else
        return atan(z.y / z.x) + PI;
}
struct complex_struct make_from_real_img(double x, double y)
{
    struct complex_struct z;
    z.x = x;
    z.y = y;
    return z;
}
struct complex_struct make_from_mag_ang(double r, double A)
{
    struct complex_struct z;
    z.x = r * cos(A);
    z.y = r * sin(A);
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
void test_complex()
{
    struct complex_struct z1={1,9};
    struct complex_struct z2={-1,9};
    struct complex_struct z3={1,-9};
    struct complex_struct z4={-1,-9};
    struct complex_struct z5={-1,0};
    struct complex_struct z6={0,-9};
    struct complex_struct z7={0,0};
    print_complex(z1);
    print_complex(z2);
    print_complex(z3);
    print_complex(z4);
    print_complex(z5);
    print_complex(z6);
    print_complex(z7);
}

extern int my_gcd(int a,int b);

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
        a*=-1;
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
    printf("%d\%d\n",rational_get_num(a),rational_get_den(a));
}

void test_ratinal()
{
    struct rational_struct z=make_rational(1,3);
    print_rational(z);
}

