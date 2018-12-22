#include <stdio.h>

// int bar(int c, int d)
// {
//     int e = c + d;
//     return e;
// }
// int foo(int a, int b)
// {
//     return bar(a, b);
// }

// int main(void)
// {
//     foo(2, 3);
//     return 0;
// }

int foo();
int bar();
int main(void)
{
    foo(2, 3, 4);
    return 0;
}
int foo(int a, int b)
{
    printf("a = %d,b = %d\n", a, b);
    return bar(a);
}
int bar(int c, int d)
{
    int e = c + d;
    printf("c = %d,d = %d\n", c, d);
    return e;
}