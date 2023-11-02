#include <stdio.h>
#include <stddef.h>

#define ALLOCSIZE 10000
static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;   // &allocbuf[0]

void xswap(int *x, int *y);

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

    int x=1, y=2, z[10];
    int *ip;
    ip = &x;
    y = *ip;
    *ip = 0;
    // ip = &z[0];
    *ip += 10;

    xswap(&x, &y);

    printf("%d\n", x);

}

char *alloc(int n){
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
}

void xstrcatf(char *s, char *t){
    while(*s++);
    while(*(s++ - 1)=*t++);
}

void xswap(int *pa, int *pb){
    int temp;

    temp = *pa;
    *pa = *pb;
    *pb = temp;
}

