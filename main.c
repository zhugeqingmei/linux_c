#include "stdio.h"
#include "systemPro.h"
int fib(int n)
{
    if(n==1 || n==0)
    {
        return 1;
    }else{
        return fib(n-1)+fib(n-2);
    }

}
int my_gcd(int a,int b)
{
    if(a%b==0)
    {
        return b;
    }
    else{
        return my_gcd(b,a%b);
    }
}
int factorial(int n)
{
    if(n==0)
        return 1;
    return n*factorial(n-1);
}
void teseIf(int x,int y)
{
    //if print failed ,x must<=0
    if(x>0)
        printf("Test OK!\n");
    else if(x<=0 && y>0)
        printf("Test OK!\n");
    else
        printf("Test failed!\n");
}
//得到整数的十位和个位
void getNumber(int n)
{
    int shi=n%100/10;
    int ge=n%10;
    printf("shi=%d\nge=%d\n",shi,ge);
}

void testOperator()
{
    int a=1,b=2,c=3;
    if(a>b<c)
    {
        printf("out");
    }
}

//test variable i value
void foo()
{
    int i;
    printf("i=%d\n",i);
    i=77;
}

int main()
{
    //发出声音
//    printf("s\a\b");
//    foo();
//    foo();
//    testOperator();
//    getNumber(234);
//    printf("factorial(10)=%d\n",factorial(10));
//
//    printf("my_gcd(10,5)=%d\n",my_gcd(10,5));
//    printf("my_gcd(10,5)=%d\n",my_gcd(5,10));

    systemProMain();

    return 0;
}















