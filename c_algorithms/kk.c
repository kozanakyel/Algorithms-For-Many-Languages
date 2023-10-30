#include <stdio.h>
#include <string.h>

#define K 5

#define IN 1
#define OUT 0

#define MAXLINE 1000
int max; /* maximum length seen so far */

int xgetline(char line[], int maxline);
void copy(char to[], char from[]);

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
	

	int len; /* current line length */
	extern int max;
	char line[MAXLINE]; /* current input line */
	char longest[MAXLINE]; /* longest line saved here */
	max = 0;
	while ((len = xgetline(line, MAXLINE)) > 0)
		if (len > max) {
			max = len;
			copy(longest, line);
		}
	if (max > 0) /* there was a line */
		printf("%s", longest);
	return 0;
	// hello\n\0

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



