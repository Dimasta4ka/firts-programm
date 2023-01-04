#include <stdio.h>

#define LIM 20

int main()
{
    char s[LIM];
    int i, c;
    
    for(i=0; (c=getchar()) != EOF; ++i)
    {
        if(i==LIM-1)
            break;
        if(c=='\n')
            break;
        s[i]=c;
    }
    s[i]='\0';
    printf("%s\n", s);
    return 0;
}
