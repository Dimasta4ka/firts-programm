#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h> 
#include <strings.h> 
#include <time.h>
int main() 
{ 
    srand(time(NULL)); 
    char z[25][25]; 
    memset(z,46,sizeof(z)); 
    double s = 0; 
    int color = 42; 
    while(true){ 
        system("cls"); 
        for(int i=0;i<25;i++){ 
            for(int j=0;j<25;j++) 
                if(((double)i-12)*((double)i-12)+
            ((double)j-12)*((double)j-12)<s) 
                    z[i][j]=color; 
        } 
        for(int i=0;i<25;i++){ 
            for(int j=0;j<25;j++) 
                printf("%2.c",z[i][j]); 
            printf("\n"); 
        } 
        s+=5; 
        if(s==300){ 
            s=0; 
            color = 33+rand()%31; 
        } 
    } 
    return 0; 
}