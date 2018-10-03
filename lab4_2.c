#include <stdio.h>
#include <string.h>

int main()
{
	/* code */
	int i=0, j=0, n, counta=0, countb=0;
	char v[1000];
	printf("Enter the string over the alphabet{a,b}\n");
	gets(v);
	n = strlen(v);
	printf("The string length is %d\n", n);
	if (v[0] == 'b')
	{
		/* code */
		j = 3;
		printf("Input: %c\tThe state is Changed to state 3\n", v[i]);
	}
	do{
		switch(j)
		{
			case 0: if (v[i] == 'b')
			{
				/* code */
				j=1;
				countb++;
				printf("Input: %c\tThe state is changed to state 1\n", v[i]);
				i++;
			}
			else if (v[i] == 'a')
			{
				/* code */
				j=0;
				counta++;
				printf("Input: %c\tThe state remains to state 0\n", v[i]);
				i++;

			}
			break;

			case 1: if (v[i] == 'a')
			{
				/* code */
				j=3;
				printf("Input: %c\tThe state is Changed to state 3\n", v[i]);
				i++;
			}
			if (v[i] == 'b')
			{
				/* code */
				j=1;
				countb++;
				printf("Input: %c\tThe state remains to state 1\n", v[i]);
				i++;
			}
			break;

			case 3: printf("Input: %c\tIt is in state 3 - Dead State\n", v[i]);
					i++;
					break;
		}
	}while(i<n);

	if (counta==(2 * countb))
	{
		/* code */
		j = 2;
		printf("The state is Changed to state 2 - Final State\n");
		printf("a = %d\tb=%d\n", counta, countb);
	}else{
		j=3;
		printf("The state is Changed to state 3\n");
		printf("It is in state 3 - Dead State\n");
		printf("a = %d\tb=%d\n", counta, countb);
	}

	printf("\nIt is in the %d state in the end.\n",j);

	return 0;
}