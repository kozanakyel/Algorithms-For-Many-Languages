#include <stdio.h>

int power(int, int);

int main(){

    int i;
    for(i=0;i<10;++i)
        printf("%d %d %d\n", i, power(2,i), power(-3,i));

    // int c;
    // c= getchar();
    // while (c!=EOF)
    // {
    //     if(c==EOF){
    //         printf("same: %d", c);
    //         break;
    //     }
    //     putchar(c); // write console
    //     c = getchar();  // get written char
        
    // }

    // double nc;
    // for(nc=0; getchar()!=EOF; ++nc)
    //     ;
    // printf("%.0f\n", nc);

    // int c, nl;

    // nl = 0;
    // while((c=getchar()) != EOF)
    //     if(c=='\n')
    //         ++nl;
    // printf("%d\n", nl);

    // int c, i, nwhite, nother;
    // int ndigit[10];

    // nwhite = nother = 0;
    // for(i = 0; i <10;++i)
    //     ndigit[i] = 0;

    // while((c=getchar()) != EOF)
    //     if(c>='0' && c<='9')
    //         ++ndigit[c-'0'];   // '0' has a ASCI value
    //     else if(c==' ' || c=='\n' || c=='\t')
    //         ++nwhite;
    //     else
    //         ++nother;

    // printf("digits =");
    // for(i=0; i<10; ++i)
    //     printf(" %d", ndigit[i]);
    // printf(", white space = %d, other = %d\n",
    //     nwhite, nother);



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
