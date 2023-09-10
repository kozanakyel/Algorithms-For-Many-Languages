#include <stdio.h>

#define MAXLINE 1000

int power(int, int);
void copy(char to[], char from[]);
int my_getline(char line[], int maxline);

extern int xextern;

int main(){
    printf("Extern global The value of x is: %d\n", xextern);

    int i;
    for(i=0;i<10;++i)
        printf("%d %d %d\n", i, power(2,i), power(-3,i));

    int len; /* current line length */
    int max; /* maximum length seen so far */
    char line[MAXLINE]; /* current input line */
    char longest[MAXLINE]; /* longest line saved here */
    max = 0;
    while ((len = my_getline(line, MAXLINE)) > 0)
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    if (max > 0) /* there was a line */
    printf("%s", longest);

    return 0;
}

int power(int base, int n){
    int i, p;
    p=1;
    for(i=1;i<=n;++i){
        p*=base;
    }
    return p;
}

void copy(char to[], char from[]){
    int i;
    i=0;
    while((to[i]=from[i])!='\0')
        ++i;
}

int my_getline(char s[], int lim){
    int c, i;
    for(i=0;i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i]=c;
    if(c=='\n'){
        s[i]=c;
        ++i;
    }
    s[i]='\0';
    return i;
}
