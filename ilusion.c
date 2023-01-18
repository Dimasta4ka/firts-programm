#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h> 
#include <strings.h> 
#include <unistd.h> 
#include <conio.h> 
#include <time.h>
#define size 21
#define fill 127 
void Print(char map[size][size]){ 
    for(int i=0;i<size;i++){ 
        for(int j=0;j<size;j++) 
            printf("%2.c",map[i][j]); 
        printf("\n"); 
    } 
} 
void FillMap(int x, char map[size][size]){ 
    int m = x; 
    int M = size-x; 
    while(m<M){ 
    for(int i=m;i<M;i++){ 
            map[i][m] = fill; 
            map[i][M-1] = fill; 
        } 
        for(int i=m;i<M;i++){ 
            map[m][i] = fill; 
            map[M-1][i] = fill; 
        } 
        m+=2; 
        M-=2; 
    } 
} 
int main() 
{ 
    char map[size][size]; 
    bool a = false; 
    while(true){ 
        system("cls"); 
        memset(map,46,sizeof(map)); 
        FillMap(a,map); 
        Print(map); 
        if(a) a = false; 
        else a = true; 
        sleep(1); 
    } 
    return 0; 
}