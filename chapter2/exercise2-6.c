#include <stdio.h>

unsigned setbits(unsigned int x, int p, int n, unsigned int y);
void bin(unsigned int n);//просмотр десятичных чисел в двоичном виде

int main()
{
    unsigned int x, y;
    int p, n;
    
    printf("Enter the numbers\nx: ");
    scanf("%d", &x);
    bin(x);
    printf("\n");
    printf("p: ");
    scanf("%d", &p);
    printf("n: ");
    scanf("%d", &n);
    printf("y: ");
    scanf("%d", &y);
    bin(y);
    printf("\n");
    x = setbits(x, p, n, y);
    printf("%d\n", x);
    bin(x);
    return 0;
}

/*setbits(x, p, n, y)*/

unsigned setbits(unsigned int x, int p, int n, unsigned int y)
{
    return (x & ~(~(~0<<n)<<(p+1-n))) | ((y&~(~0<<n))<<(p+1-n));
}

void bin(unsigned int n) //
{
    int m, c, i, count, j;
    c = i = n;
    for(count = 0; n>=2; count++)
        n = n/2;
    m = count + 1;
    unsigned int x[m];
    while (i>=2)
    {
        i = i/2;
        c = c%2;
        x[count] = c;
        c=i;
        count--;
    }
    x[0] = i;
    for(j=0; j<=((sizeof(x)/4) - 1); j++)
        printf("%d", x[j]);
}