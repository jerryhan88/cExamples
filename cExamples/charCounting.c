#include <stdio.h>

// int main(int argc, char const *argv[])
// {
	
// 	long nc;
// 	nc = 0;

// 	while (getchar() != EOF)
// 		++nc;
// 	printf("%ld\n", nc);


// 	return 0;
// }

#define IN 1
#define OUT 0

int main()
{
	int c, nl, nw, nc, state;

	state = OUT;
	nl = nw = nc = 0;
	while ((c = getchar()) != EOF) {
		++nc;
		if (c == '\n')
			++nl;
		if ( c == ' ' || c == '\n' || c == '\t')
			state = OUT;
		else if (state == OUT) {
			state = IN;
			++nw;
		}
	}
	printf("%d %d %d\n", nl, nw, nc);
}