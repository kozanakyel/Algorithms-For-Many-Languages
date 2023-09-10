#include <stdio.h>
#include <stddef.h>

#define ALLOCSIZE 10000
static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;   // &allocbuf[0]

int main(int argc, char *argv[]){   // argc: count of args, argv is a pointer
    int a[10];
    int *pa;
    pa = &a[0];
    int x = *pa;

    pa=a;  // legal for pa point to arrays first address
    // char s[] and char *s is same we prefer latter version
    // same f(&a[2]) and f(a+2)

    char *pmsg;
    pmsg = "now is the time";
    char amsg[] = "now is the time";

    return 0;
}

char *alloc(int n){
    if(allocbuf + ALLOCSIZE - allocp >= n){
        allocp += n;
        return allocp - n;
    }else{
        return 0;
    }
}

void afree(char *p) /* free storage pointed to by p */
{
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p;
}

int strlen(char *s){   // hello world!'\0'
    char *p = s;
    while(*p != '\0')
        p++;
    return p-s;
}

/* strcpy: copy t to s; pointer version */
void strcpy(char *s, char *t)
{
    int i;
    i = 0;
    while (*s++ = *t++) {
            ;
    }
}

void strcatf(char *s, char *t){
    while(*s++);
    while(*(s++ - 1)=*t++);
}

