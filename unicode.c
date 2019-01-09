#include "unicode.h"
#include <stdio.h>
#include <locale.h>
#include <wchar.h>

int zh_bmp()
{
    if(!setlocale(LC_CTYPE, ""))
    {
        fprintf(stderr, "Can't set the specified locale! Check LANG, LC_CYTPE, LCALL.\n");
        return 1;
    }
    wchar_t wc = L'你';
    printf("wchar_t string:%ls", L"你好\n");
    printf("wchar_t char:%lc\n", wc);
    printf("你你好孟\n");
    return 0;
}

void test_bits(void)
{
    unsigned int a,b, mask = 0x0000ff00;
    a = 0x12345678;
    b = (a & mask) >> 8;
    printf("get the 8-15:%x\n", b);//得到8-15位的数据
    printf("the same as up:%x\n", (a >> 8) & ~(~0 << 8));
    printf("the same as up:%x\n", a & ~mask);//clear to 0 8-15
    printf("the same as up:%x\n", a | mask);//clear to 0 8-15
    printf("old the values:a = %d, b = %d\n", a, b);
    a = a ^ b;
    b = b ^ a;
    a = a ^ b;
    printf("exchange the values:a = %d, b = %d\n", a, b);
    printf("sizeof:%lu %lu\n", sizeof a, sizeof(unsigned int));
}

/**
 * the result is undefined.
*/
void test_side_effect()
{
    // int a = 0;
    // a = (++a) + (++a) + (++a);
    // printf("a = :%d\n", a);

    //search 256*N,in 0-1024.N=1,2,3..
    int i = 0;
    for(; i <= 1024; ++i)
    {
        if((i & 0xff) == 0)
            printf("%d\n", i);
    }
}

int test_unicode()
{
    zh_bmp();
    // test_bits();
    // test_side_effect();
    return 0;
}
