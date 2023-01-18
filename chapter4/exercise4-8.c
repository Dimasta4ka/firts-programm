// Предположим, что число символов, возвращаемых назад, не превышает 1. Модифицируйте
// с учетом этого факта функции getch и ungetch.
/* getch */
#include <string.h>
#include <stdio.h>

/* ungets */
void ungets( char s[])
{
    int len;
    
    len = strlen(s);
    while(len > 0)
        ungetch(s[--len]);
}

char buf = 0;

int getch(void) // get a (possibly pushed-back) character  
{
    int c;
    if(buf == 0)
        c = getchar();
    else
        c = buf;
    buf = 0;
    return c;    
}

/* ungetch */
void ungetch(int c) // push character back on input
{
    if(buf != 0)
        printf("ungetch: too many characnters\n");
    else
        buf = c;
}