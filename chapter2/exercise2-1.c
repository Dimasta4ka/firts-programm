#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <float.h>

int main()
{
    double c;
    c=UINT_MAX;

    printf("values from standard headers\n\n");
    printf("signed char: %d   %d\n", SCHAR_MIN, SCHAR_MAX);
    printf("unsigned char: %d   %d\n", 0, UCHAR_MAX);
    printf("signed int: %d   %d\n", INT_MIN, INT_MAX);
    printf("unsigned int: %d   %.lf\n", 0, c);
    printf("signed short: %d   %d\n", SHRT_MIN, SHRT_MAX);
    printf("unsigned short: %d   %d\n", 0, USHRT_MAX);
    printf("signed long: %ld   %ld\n", LONG_MIN, LONG_MAX);
    printf("unsigned long: %d   %lu\n\n", 0, ULONG_MAX);
    
    printf("values by direct computation\n\n");
    printf("signed char: -%g   %g\n", pow(2, sizeof(char)*8)/2, 
                                      pow(2, sizeof(char)*8)/2-1);
    printf("unsigned char: %d   %g\n", 0, pow(2, sizeof(char)*8)-1);
    printf("signed int: -%.lf   %.lf\n", pow(2, sizeof(int)*8)/2, 
                                         pow(2, sizeof(int)*8)/2-1);
    printf("usigned int: %d   %.lf\n", 0, pow(2, sizeof(int)*8)-1);
    printf("signed short: -%.lf   %.lf\n", pow(2, sizeof(short)*8)/2, 
                                           pow(2, sizeof(short)*8)/2-1);
    printf("unsigned short: %d   %.lf\n", 0, pow(2, sizeof(short)*8)-1);
    printf("signed long: -%.lf   %.lf\n", pow(2, sizeof(long)*8)/2, 
                                          pow(2, sizeof(long)*8)/2-1);
    printf("unsigned long: %d   %.lf\n\n", 0, pow(2, sizeof(long)*8)-1);
    return 0;
} 