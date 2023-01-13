// Дополните функцию atof таким образом, чтобы она справлялась с числами вида
// 123.456e-6 в которых после мантиссы может стоять е (или Е) с последующим порядком (быть может, со знаком)

#include <stdio.h>
#include <ctype.h>

#define MAXLINE 100

/*rudimentary calculator*/
int main()
{
    double atof(char[]);
    char line[MAXLINE];
    int getlin(char line[], int max);
    while(getlin(line, MAXLINE) > 0)
        printf("\t%g\n", atof(line));
    return 0;
}

/*atof: convert string s to double*/
double atof(char s[])
{
    double val, power;
    int i, sign, exp;
    
    for(i = 0; isspace(s[i]); i++) //skip white space
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if(s[i] == '+' || s[i] == '-')
        i++;
    for(val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val +(s[i] -'0');
    if(s[i] == '.')
        i++;
    for(power = 1.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] -'0');
        power *= 10.0;
    }
    val = sign * val / power;
    if(s[i] == 'e' || s[i] == 'E')
    {
        i++;
        sign = (s[i] == '-') ? -1 : 1;
        if(s[i] == '+' || s[i] == '-')
            i++;
        for(exp = 0; isdigit(s[i]); i++)
            exp = 10*exp + (s[i] - '0');
        if(sign == 1)
            for(; exp > 0; exp--)
                val *=10;
        else
            for(; exp > 0; exp--)
                val /= 10;
    }
    return val;
}

/* getlin */
int getlin(char line[], int max)
{
    int c, i;
    
    i = 0;
    while(--max > 0 && (c=getchar()) != EOF && c != '\n')
        line[i++] = c;
    if(c == '\n')
        line[i++] = c;
    line[i] = '\0';
    return i;
}