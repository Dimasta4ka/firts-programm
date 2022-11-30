#include <stdio.h>

main()
{
    // int c;
    
    // while ((c = getchar()) != EOF)
    // {
    // putchar(c);
    // }
    long nc;

    nc = 0;
    while (getchar() != EOF)
        ++nc;
    printf("%ld/n", nc);
}