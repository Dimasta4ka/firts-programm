// Добавьте команды, с помощью которых можно было бы печатать верхний элемент стека (с
// сохранением его в стеке), дублировать его в стеке, менять местами два верхних элемента стека. Введите
// команду очистки стека.
#include <stdio.h>
#include <stdlib.h> //for atof()
#include <math.h>

#define MAXOP 100 //max size of operand or operator
#define NUMBER '0' //signal that a number was found

int getop(char[]);
void push(double);
double pop(void);
void clear(void);

/* reverse polish calculator */
int main()
{
    int type;
    double op1, op2;
    char s[MAXOP];
    
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
            case '?':
                op2 = pop();
                printf("\t%.8g\n", op2);
                push(op2);
                break;
            case 'd': //double
                op2 = pop();
                push(op2);
                push(op2);
                break;
            case 'r': //reverse
                op1 = pop();
                op2 = pop();
                push(op1);
                push(op2);
                break;
            case 'c': //clean
                clear();
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
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

/* clear */
void clear(void)
{
    sp = 0;
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