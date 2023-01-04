#include <stdio.h>

void squeeze(char s1[], char s2[]);

int main()
{
    char first[] = "afbrofbera";
    char second[] = "fredl";
    
    squeeze(first, second);
    printf("%s\n", first);
    return 0;
}

/*squeeze*/

void squeeze(char s1[], char s2[])
{
    int i, j, n, c;
    i=j=0; 
    
    while(s2[i] != '\0')
        if(s1[j] == s2[i]) //удаляем встречающиеся символы
        {
            for(n=c=j; s1[c] != '\0'; n++)
                s1[n] = s1[++c];
        }
        else if(s1[j] == '\0')
        {
            i++;
            j=0;
        }
        else
            j++;
}