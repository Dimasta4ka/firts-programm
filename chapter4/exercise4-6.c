// Введите команды для работы с переменными (легко обеспечить до 26 переменных, каждая
// из которых имеет имя, представленное одной буквой латинского алфавита). Добавьте переменную,
// предназначенную для хранения самого последнего из напечатанных значений.
#include <stdio.h>
#include <stdlib.h> //for atof()
#include <math.h>

#define MAXOP 100 //max size of operand or operator
#define NUMBER '0' //signal that a number was found

int getop(char[]);
void push(double);
double pop(void);

/* reverse polish calculator */
int main()
{
    int type, i, val;
    double op2, v;
    char s[MAXOP];
    double variable[26];
    
    val = 0;
    for(i = 0; i < 26; i++)
        variable[i] = 0.0;
    while((type = getop(s)) != EOF)
    {
        switch(type)
        {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() + pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if(op2 != 0)
                    push(pop() / op2);
                else
                    printf("error: zero devisior\n");
                break;
            case '%':
                op2 = pop();
                if(op2 != 0.0)
                    push(fmod(pop(), op2));
                else
                    printf("error: zero devisor\n");
                break;
            case '=':
                pop();
                if(val >= 'A' && val <= 'Z')
                    variable[val - 'A'] = pop();
                else
                    printf("error: not name of variable\n");
                break;
            case '\n':
                v = pop();
                printf("\t%.8g\n", v);
                break;
            default:
                if(type >= 'A' && type <= 'Z')
                    push(variable[type - 'A']);
                else if (type == 'v')
                    push(v);
                else
                    printf("error: unknown command %s\n", s);
                break;
        }
        val = type;
    }
    return 0;
}

#define MAXVAL 100 //maximum depth of val stack


double val[MAXVAL]; //value stack
int sp = 0; //next free stack position

/* push: push f into value stack */
void push(double f)
{
    if(sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can`t push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
    if(sp > 0)
        return val[--sp];
    else
    {
        printf("error: stack empty\n");
        return 0.0;
    }
}

#include <ctype.h>

int getch(void);
void ungetch(int);

/* getop: get next character ot numeric operand */
int getop(char s[])
{
    int i, c;
    while((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if(!isdigit(c) && c != '.' && c != '-') // not a number
        return c; 
    i = 0;
    if (c == '-')
    {
        if(isdigit(c = getch()) || c == '.')
            s[++i] = c; //negative numbers
        else
            {
                if(c != EOF)
                    ungetch(c);
                return '-';
            }
    }
    if(isdigit(c)) //collect integer part
        while(isdigit(s[++i] = c = getch()))
            ;
    if(c == '.') //collect fraction part
        while(isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if(c != EOF)
        ungetch(c);
    return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE];  //buffer for ungetch;
int bufp = 0; //next free position in buf

int getch(void) // get a (possibly pushed-back) character  
{
   return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) // push character back on input
{
    if(bufp >= BUFSIZE)
        printf("ungetch: too many characnters\n");
    else
        buf[bufp++] = c;
}