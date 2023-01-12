// Напишите функцию itob(n, s, b), которая переводит целое n в строку s,
// представляющую число по основанию b. В частности, itob(n, s, 16) помещает в s текст числа n в
// шестнадцатеричном виде

#include <stdio.h>
#include <string.h>
#define LEN 100

void itob(int n, char s[], int b);
void reverse(char s[]);
int abs(int x);

int main()
{
    int n, b;
    char s[LEN];
    
    printf("Enter the number n: ");
    scanf("%d", &n);
    printf("base b: ");
    scanf("%d", &b);
    itob(n, s, b);
    printf("%s", s);
    printf("\n");
    return 0;
}

/*itob*/
void itob(int n, char s[], int b)
{
    int i, sign, c;
    
    sign = n; //сохраняем знак
    if(sign < 0)
        n = -n;
    i = 0;
    do //генерируем цифры в обратном порядке
    {
        c = (n % b);
        s[i++] = (c>9) ? c+'A'-10: c + '0';//если 16-ричное отображение
        n /= b;                            //подбираем буквы
    } while (n >= 1);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

/*reverse*/
void reverse(char s[])
{
    int i, j;
    char c;
    
    for(i = 0, j = strlen(s) - 1; i < j; i++, j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}