#include <stdio.h>
#include <ctype.h>

#define SIZE 10
#define MAXLINE 1000

int getch(void);
void ungetch(int);
int getint(int *);
int strend(char *s,char *t);
int mystrlen(char *t);
int mgetline(char s[],int lim);

int main(){

    char s[MAXLINE],t[MAXLINE];
    int ret;
    mgetline(s,MAXLINE);
    mgetline(t,MAXLINE);
    ret = strend(s,t);
    printf("%d",ret);

    return 0;
}

int mgetline(char s[],int lim)
{
    int c,i;
    
    for(i=0;i<lim-1 && ((c=getchar())!=EOF) && c!='\n';++i)
        s[i]=c;

    if(c=='\n')
    {
        s[i]=c;
        ++i;
    }
    s[i]='\0';

    return i;
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

int strend(char *s,char *t)
{
    int len;
    len=mystrlen(t);
    while(*s!='\0'){
        printf("s value: %c\n", *s);
        ++s;
    }
    printf("s out value: %c\n", *s);
    --s;
    printf("s out operand value: %c\n", *s);

    while(*t!='\0'){
        printf("t value: %c\n", *t);
        ++t;
        
    }        
    --t;
    while(len > 0)
    {
        if(*t==*s)
        {
            --t;
            --s;
            --len;
        }
        else
            return 0;
    }
    if( len == 0)
        return 1;
}

int mystrlen(char *t)
{
    char *p;
    p=t;

    while(*p!='\0')
        ++p;

    return p-t;
}