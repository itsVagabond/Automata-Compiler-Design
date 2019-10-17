// construct a deterministic pushdown automata to accept strings in which there are more numbers of a's than b's.

#include <stdio.h>
#include <string.h>

int main()
{
	/* code */
	int i=0, j=0, counta=0, countb=0, n;
	char v[100];
	printf("Enter the Palindrome string\n");
	gets(v);
	n = strlen(v);
	printf("Length of string is %d\n", n);

	do{
		switch(j){
			case 0: if (v[i] == 'b')
			{
				/* code */
				j=1;
				countb++;
				printf("Input: %c\tThe state is changed to state %d\n", v[i], j);
				i++;
			}
			else if (v[i] == 'a')
			{
				/* code */
				j=0;
				counta++;
				printf("Input: %c\tThe state remains to state %d\n", v[i], j);
				i++;

			}
			break;

			case 1: if (v[i] == 'a')
			{
				/* code */
				j=0;
				counta++;
				printf("Input: %c\tThe state is changed to state %d\n", v[i], j);
				i++;
			}
			else if (v[i] == 'b')
			{
				/* code */
				j=1;
				countb++;
				printf("Input: %c\tThe state remains to state %d\n", v[i], j);
				i++;

			}
			break;
		}
	} while(i<n);

	if (counta > countb)
	{
		/* code */
		printf("\nAccepted!\n");
		printf("a = %d\tb=%d\n", counta, countb);
	}
	else
	{
		printf("\nRejected!\n");
		printf("a = %d\tb=%d\n", counta, countb);
	}
	return 0;
}