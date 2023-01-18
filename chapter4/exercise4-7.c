// Напишите программу ungets(s), возвращающую строку s во входной поток. Должна ли
// ungets "знать" что-либо о переменных buf и bufр, или ей достаточно пользоваться только функцией
// ungetch?
#include <string.h>

/* ungets */
void ungets( char s[])
{
    int len;
    
    len = strlen(s);
    while(len > 0)
        ungetch(s[--len]);
} 