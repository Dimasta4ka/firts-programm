#include <stdio.h>

#define IN 1
#define OUT 0;

int htoi(char s[]);

int main()
{
    char hox[4] = {'0', 'x', 'F', 'f'};
    printf("%d\n", htoi(hox));
    return 0;
}


/*htoi(s)*/

int htoi(char s[])
{
    int i, number, indigit, hexdig;
    i = 0;
    if(s[i] == '0')
    {
        i++;
        if(s[i] == 'x' || 'X')
            i++;
    }
    indigit = IN;//внутри числа
    number=0;//результат функции htoi
    for(;indigit == IN; i++)
    {
        if(s[i] >= '0' && s[i] <= '9')
            hexdig = s[i] - '0';//принимает значение между 0 и 15
        else if(s[i] >= 'a' && s[i] <= 'f')
            hexdig = s[i] - 'a'+ 10;
        else if(s[i] >= 'A' && s[i] <= 'F')
            hexdig = s[i] - 'A'+ 10;
        else
            indigit = OUT;//вне числа
        if(indigit == IN)
            number = number*16 + hexdig;
    }
    return number;
}
