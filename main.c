#include "stdio.h"
#include "math.h"
#include "systemPro.h"

void print_diamond(int n,char c)
{

}

void print_9X9()
{
    int i,j;
    for(i=1;i<10;i++)
    {
        for(j=1;j<i+1;j++)
        {
            printf("%d\t",i*j);

        }
        printf("\n");
    }
}

//delete continue break
int is_prime(int n)
{
    int middle=sqrt(n)+1;
    int i;
    for(i=2;i<middle;i++)
    {
        if(n%i==0)
            return 0;
    }
    return 1;
}
//print prime 1-99
void print_prime()
{
    int i;
    for(i=1;i<100;i++)
    {
        if(is_prime(i))
            printf("prime:%d\n",i);
    }
}
//count the 9 numbers between 1to 100.
void count_9()
{
    int i,count,temp1,temp2;
    count=0;
    for(i=2;i<100;i++)
    {
        temp1=i%10;
        if(temp1==9)
            count++;
        temp2=(i-temp1)/10;
        if(temp2==9)
            count++;
    }
    printf("the number 1-100 of 9 is:%d\n",count);
    return;
}

//
void factorial_loop(int n)
{
    int result=1;
    while(n>0)
    {
        result*=n;
        n--;
    }
    printf("factorial(%d)=%d\n",n,result);
}

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
    if(a>b && a<c)
    {
        printf("out");
    }
}

//test variable i value
void foo()
{
    int i=0;
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

    //systemProMain();

    //factorial_loop(10);
    //count_9();
//    printf("is_prime(9):%d\n",is_prime(9));
//    printf("is_prime(19):%d\n",is_prime(19));
//    printf("5%%1=%d\n",5%1);
    //print_prime();
    print_9X9();
    return 0;
}















