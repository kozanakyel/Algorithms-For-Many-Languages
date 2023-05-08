#include <stdio.h>
#include <ctype.h>

#define SIZE 10

int getch(void);
void ungetch(int);
int getint(int *);

int main(){
    int n, r, array[SIZE];
    for(int i=0; i<SIZE; i++){
        array[i]=999;
    }
    for(n = 0; n < SIZE; n++)
    {
        if ((r =getint(&array[n])) == 0) {
            getch();
        }
        if (r == EOF) {
            continue;
        }
    }
    for(int i = 0; i < SIZE; i++)
    {printf("array[%d] = %d\n", i, array[i]);}

    return 0;
}

int getint(int *pn)
{
    int c, d, sign;
    while (isspace(c = getch())) {  /*  skip white spaces, ' ', '\t', '\n'*/
        ;
    }
    if (!isdigit(c) && c != EOF && c != '-' && c != '+') {
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '-' || c == '+') {
        d = c;
        while (!isdigit(c = getchar())) {
            if (c !=EOF) {
                ungetch(c);
            }
            ungetch(d);
                        
            return d;
        }
    }
    for (*pn = 0; isdigit(c); c = getch()) {
        *pn = 10 * *pn + (c - '0');
    }
    *pn = sign * *pn;
    if(c !=EOF)
        ungetch(c);
    return c;
}



void swap(int *px, int *py){
    int temp;

    temp = *px;
    *px = *py;
    *py = temp;
}

#define BUFSIZE 100
char buf[BUFSIZE];
int bufp=0;

int getch(){
    if(bufp>0){
        return buf[--bufp];
    }else{
        return getchar();
    }
}

void ungetch(int c)
{
    if(bufp >= BUFSIZ)
        printf("ungetch(): too many characters\n");
    else
        buf[bufp++] = c;
    
}