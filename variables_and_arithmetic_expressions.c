#include "stdio.h"

main(){
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    printf("Table of fahrenheit temperature in Celsius\n");
    while (fahr <= upper)
    {
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("%3.0f\t %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }

    lower = 0;
    upper = 300;
    step = 20;

    celsius = lower;
    printf("Temperature table celsius to fahrenheit\n");
    while (celsius <= upper)
    {
        fahr = (9.0 / 5.0) * celsius + 32.0;
        printf("%3.0f\t %6.1f\n", celsius, fahr);
        celsius = celsius + step;
    }
}