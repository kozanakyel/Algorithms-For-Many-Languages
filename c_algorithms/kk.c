#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define abs(x) ((x) > 0 ? (x) : -(x))

#define K 5

#define IN 1
#define OUT 0

#define MAXLINE 1000
int max; /* maximum length seen so far */

//octal
#define VTAB '\013'      // Asci VERTICAL TAB
#define BELL '\007'		// asci BELL CHARACTER
//hexadecimal
#define VT '\xb'
#define BE '\x7'

// short int ... /short is 16 bits / long at least 32 bits

int xgetline(char line[], int maxline);
void copy(char to[], char from[]);
int bitcount(unsigned k);

void reverse(char s[]);
void itoa(int n, char k[]);

int main(){

	// int c;

	// long nc;

	// nc = 0;
	// while (getchar() != EOF)
	// 	++nc;
	// printf("%ld\n", nc);

	// while(getchar() != EOF)
	// 	// int bl = (getchar() == EOF);
	// 	// printf("res: %d\n", EOF);
	// 	++nc;
	// 	//putchar(c);
	
	// double nc;

	// for(nc=0; getchar()!=EOF; ++nc)
	// 	;
	// printf("%.0f\n", nc);

	// int c, nl;

	// nl = 0;
	// while((c=getchar()) != EOF){
	// 	if(c=='\n'){
	// 		++nl;
	// 	}
	// }
	// printf("%d\n", nl);


	//count chars, newlines and words...
	// int c, nc, nl, nw, state;

	// state = OUT;
	// nl = nc = nw = 0;
	// while((c=getchar()) != EOF){
	// 	++nc;
	// 	if(c == '\n')
	// 		++nl;
	// 	if(c == ' ' || c == '\n' || c == '\t')
	// 		state = OUT;
	// 	else if(state == OUT){
	// 		state = IN;
	// 		++nw;
	// 	}

	// } 
	// printf("\n%d %d %d\n", nc, nw, nl);


	// count digits whitespaces and other chars
	// int c, i, nwhite, nother;
	// int ndigit[10];

	// nwhite = nother = 0;
	// for(i=0;i<10;++i)
	// 	ndigit[i]=0;
	// while((c=getchar()) != EOF){
	// 	if(c>='0' && c<='9')
	// 		++ndigit[c-'0'];
	// 	else if(c==' ' || c=='\n' || c=='\t')
	// 		++nwhite;
	// 	else 
	// 		++nother;
	// }
	// printf("digits=");
	// for(i=0;i<10;++i)
	// 	printf(" %d", ndigit[i]);
	// printf(", whspace = %d, other = %d", nwhite, nother);
	

	// int len; /* current line length */
	// extern int max;
	// char line[MAXLINE]; /* current input line */
	// char longest[MAXLINE]; /* longest line saved here */
	// max = 0;
	// while ((len = xgetline(line, MAXLINE)) > 0)
	// 	if (len > max) {
	// 		max = len;
	// 		copy(longest, line);
	// 	}
	// if (max > 0) /* there was a line */
	// 	printf("%s", longest);
	// return 0;
	// hello\n\0
	char k[] = "he\vllo,  \"  \?  \v   " "\"w\vo\vr\tld\n";
	int s = strlen(k);
	char l[] = "123456";
	char m[] = "LHFSDLSDH"   "   klhjsfk";

	

	printf("%d %d %d\n", s, atoi(l), bitcount(9724e5));
	reverse(k);
	printf("%s\n", k);

	/**
	 * char constant and string one letter not the same thing.
	 * char const is 'x' and string is "x", the string has last value
	 * as a '\0' for null character but char constat dont have it.
	*/

	int number;
    char str[MAXLINE];

    /*  number=-2345645; */

    number = -2147483648;

    printf("Integer %d printed as\n String:", number);

    itoa(number, str);

    printf("%s", str);
}


int xgetline(char s[],int lim)
{
	int c, i;
	for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

void copy(char to[], char from[])
{
	int i;
	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}

int xstrlen(char s[])
{
	int i;
	while (s[i] != '\0')
		++i;
	return i;
}

int bitcount(unsigned x)
{
	int b;
	for (b = 0; x != 0; x >>= 1)
		if (x & 01)
			b++;
	return b;
}


void reverse(char s[])
{
	int c, i, j;   // s as a temp variable for changing
	for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
		c = s[i], s[i] = s[j], s[j] = c;
	}
}


void itoa(int n, char s[]){
	int i, sign;
	sign = n;
	i=0;

	do{
		s[i++]=abs(n%10)+'0';
		printf("%c\n", (char)s[i]);
	}while((n/=10)!=0);

	if(sign<0)
		s[i++]='-';
	s[i]='\0';
	reverse(s);
}






