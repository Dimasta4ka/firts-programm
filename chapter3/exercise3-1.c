#include <stdio.h>


int binsearch(int x, int v[], int n);

int main()
{
    int x;
    
    x = 8;
    int v[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printf("%d\n", binsearch(x, v, 10));
    return 0;
}
    

/*binsearch()*/
int binsearch(int x, int v[], int n)
{
    int low, high, mid;
    
    low = 0;
    high = n - 1;
    mid = (low+high)/2;
    while(low<=high && x != v[mid])
    {
        if(x < v[mid])
            high = mid - 1;
        else if(x > v[mid])
            low = mid + 1;
        mid = (low + high)/2;
    }
    if(x==v[mid])//совпадение найдено
        return mid;
    else
        return -1;//нет совпадений
}