// Напишите функцию strindex(s, t), которая выдает позицию самого правого вхождения
// t в s или -1, если вхождения не обнаружено.
#include <stdio.h>

#define MAXLINE 1000 /*maximum input line lenght*/
#define MAXPATTERN 20

int getlin(char line[], int max);
int strindex(char source[], char searchfor[]);

char pattern[MAXPATTERN]; /*pattern to search for*/

/*find all line matching pattern*/
int main()
{
    char line[MAXLINE];
    int found, i;
    found = 0;
    
    printf("Enter the pattern: ");
    gets(pattern);
    while(getlin(line, MAXLINE) > 0)
        if((i = strindex(line, pattern)) >=0)
        {
            printf("%s", line);
            printf("the position of the rightmost occurence: %d\n", i);
            found++;
        }
        else 
            printf("occurence: %d\n", i);
    printf("%d\n", found);
    return 0;
}


/*getlin: get line into line[], return lenght*/
int getlin(char line[], int max)
{
    int c, i;
    
    i = 0;
    printf("Enter the line: ");
    while(--max > 0 && (c=getchar()) != EOF && c != '\n')
        line[i++] = c;
    if(c == '\n')
        line[i++] = c;
    line[i] = '\0';
    return i;
}

/*strindex: return index of pattern in line, -1 if none*/
int strindex(char source[], char searchfor[])
{
    int i, j, k, pos;
    
    for(pos = -1, i = 0; source[i] != '\0'; i++)
    {
        for(j = i, k = 0; searchfor[k] != '\0' && source[j] == searchfor[k]; j++, k++)
            ;
        if(k > 0 && searchfor[k] == '\0')
            pos = i;
    }
    return pos;
}
