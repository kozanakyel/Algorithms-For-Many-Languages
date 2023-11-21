#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>

#define ALLOCSIZE 10000
static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;   // &allocbuf[0]

char *xalloc(int n);
void xafree(char *p);
void xswap(int *x, int *y);

int xstrend(char *, char *);

int main(int argc, char *argv[]){   // argc: count of args, argv is a pointer
    // int a[10];
    // int *pa;
    // pa = &a[0];
    // int x = *pa;

    // pa=a;  // legal for pa point to arrays first address
    // char s[] and char *s is same we prefer latter version
    // same f(&a[2]) and f(a+2)

    // char *pmsg;
    // pmsg = "now is the time";
    // char amsg[] = "now is the time";

    int i;
    for (i = 1; i < argc; i++)
        printf("%s%s", argv[i], (i < argc-1) ? " " : "");
    printf("\n");

    int x=1, y=2, z[10];
    int *ip;
    ip = &x;
    y = *ip;
    *ip = 0;
    // ip = &z[0];
    *ip += 10;

    xswap(&x, &y);

    char *k = "python validations...";
    

    printf("%d %c\n", x, k[2]);

    int res;
    char a[] = "kalemmm";
    char b[] = "klj";
    res = xstrend(a, b);
    printf("res: %d\n", res);
}

char *xalloc(int n){
    if(allocbuf + ALLOCSIZE - allocp >= n){
        allocp += n;
        return allocp - n;
    }else{
        return 0;
    }
}

void xafree(char *p) /* free storage pointed to by p */
{
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p;
}

int xstrlen(char *s){   // hello world!'\0'
    char *p = s;
    while(*p != '\0')
        p++;
    return p-s;
}

/* strcpy: copy t to s; pointer version */
void xstrcpy(char *s, char *t)
{
    int i;
    i = 0;
    while (*s++ = *t++) {
        ;
    }
    // while ((*s = *t) != '\0') {
    //     s++;
    //     t++;
    // }
}

void xstrcat(char *s, char *t){
    while(*s++);
    while(*(s++ - 1)=*t++);
}

void xswap(int *pa, int *pb){
    int temp;

    temp = *pa;
    *pa = *pb;
    *pb = temp;
}

void xxswap(void *v[], int i, int j)
{
    void *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}


int xstrcmp(char *s, char *t){
    for(; *s==*t; s++, t++)
        if(*s=='\0')
            return 0;
    return *s-*t;
}

int xstrend(char *s, char *t){
    int len;
    len = strlen(t);
    while(*s != '\0')
        ++s;
    --s;
    while(*t != '\0')
        ++t;
    --t;

    while(len>0){
        if(*t==*s){
            --t;
            --s;
            --len;
        }else
            return 0;
    }
    if(len==0)
        return 1;
}



void qsort(void *v[], int left, int right, 
            int (*comp)(void *, void *)){
    int i, last;
    void xxswap(void *v[], int, int);

    if(left>=right)
        return;
    xxswap(v, left, (left+right)/2);
    last = left;
    for(i=left+1;i<=right;i++)
    if((*comp)(v[i], v[left]) < 0)
        xxswap(v, ++last, i);
    xxswap(v, left, last);
    qsort(v, left, last-1, comp);
    qsort(v, last+1, right, comp);
}



