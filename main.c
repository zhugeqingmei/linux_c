#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include "systemPro.h"
#include "my_complex.h"
#include "ex_10_1.h"
#include "unicode.h"
#include <sys/types.h>
#include <unistd.h>

void test_struct()
{
//    struct complex
//    {
//        double x,y;
//    }z={1.0,1.0};//right
    //z={1.0,1.0};//wrong
}
void print_diamond(int n,char c)
{
    if(n%2==0)
        printf("even number!\n");
    int x[50],space[50];
    int i,j,x_index,space_index;

    j=0;
    for(i=1;i<n+1;i+=2)
    {
        x[j++]=i;
    }
    for(i=n-2;i>0;i-=2)
    {
        x[j++]=i;
    }

    i=(n-1)/2;
    j=0;
    for(;i>=0;i--)
    {
        space[j++]=i;
    }
    for(i=1;i<=(n-1)/2;i++)
    {
        space[j++]=i;
    }
    x_index=0;
    space_index=0;
    for(i=0;i<n;i++)
    {
        j=space[space_index++];
        for(;j>0;j--)
        {
            printf(" \t");
        }
        j=x[x_index++];
        for(;j>0;j--)
        {
            printf("*\t");
        }
        printf("\n");
    }
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
void test_array()
{
    printf("%d\n",RAND_MAX);//2147483647
    printf("%d\n",INT_MAX);//2147483647

}

void test_default_char()
{
    char t = 0xFF;
    printf("test_default_char:%d\n",t);
}

void test_shift(void)
{
    int i = 1;
    int j = 0xcFFFFFF3;
    i <<= 33;
    printf("i shift 33:%d\n", i);
    printf("%x\n", 0xCFFFFFF3>>2);
    printf("%x\n", j>>2);

    printf("%x\n", (~0 << 8));
    printf("%x\n", ~(~0 << 8));
}

int test_fork(void)
{
    pid_t pid;
    char *message;
    int n;
    pid = fork();
    if(pid < 0)
    {
        perror("fork failed");
        exit(1);
    }
    if(pid == 0)
    {
        message = "This is the child\n";
        n = 6;
    }else
    {
        message = "This is the parent\n";
        n = 3;
    }
    for(; n > 0; n--)
    {
        printf(message);
        // sleep(1);
    }
    return 0;
}

int main()
{
    //发出声音
    // printf("s\a\b");
    // foo();
    // foo();
    // testOperator();
    // getNumber(234);
    // printf("factorial(10)=%d\n",factorial(10));

    // printf("my_gcd(10,5)=%d\n",my_gcd(10,5));
    // printf("my_gcd(10,5)=%d\n",my_gcd(5,10));

    // systemProMain();

    // factorial_loop(10);
    // count_9();
    // printf("is_prime(9):%d\n",is_prime(9));
    // printf("is_prime(19):%d\n",is_prime(19));
    // printf("5%%1=%d\n",5%1);
    // print_prime();
    // print_9X9();
    // print_diamond(5,'*');
    // print_diamond(13,'*');
    // test_complex();
    // test_rational();
    // test_array();
    // excise();
    // test_rand();
    // ex8_5_scissor();

    // test_ex_10_1();

    // test_default_char();

    // test_unicode();
    // test_shift();
    test_fork();
    return 0;
}















