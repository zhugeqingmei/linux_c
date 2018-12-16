#include "unicode.h"
#include <stdio.h>
#include <locale.h>

int zh_bmp()
{
    if(!setlocale(LC_CTYPE, ""))
    {
        fprintf(stderr, "Can't set the specified locale! Check LANG, LC_CYTPE, LCALL.\n");
        return 1;
    }
    printf("%ls", L"你好\n");
    printf("你你好孟\n");
    return 0;
}

int test_unicode()
{
    zh_bmp();
    return 0;
}
