#include <stdio.h>
#include "viewbin.h"

unsigned rightrot(unsigned x, int n);
int countbits(unsigned x);

int main()
{
    unsigned int x;
    int n;
    
    printf("Enter the number:\nx: ");
    scanf("%d", &x);
    bin(x);//преобразуем в двоичный вид
    printf("n: ");
    scanf("%d", &n);
    printf("\n%d\n", rightrot(x, n));
    bin(rightrot(x, n));
    return 0;
}

/*считаем количество занятых битов*/
int countbits(unsigned x)
{
    int count;
    for(count=1; x>=2; count++)
        x/=2;
    return count;
}


/*rightrot*/
unsigned  rightrot(unsigned x, int n)
{
    int rotbits, bitscount;
    bitscount = (countbits(x)-1);
    while(n--)
    {
        rotbits= x & 1;//запоминаем самый младшый бит
        x = x>>1;//сдвигаем ч на позицию вправо
        x = x | (rotbits<<bitscount);//ставим младший бит 
                                        //на место старшего
    }
    return x;
}