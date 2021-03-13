#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "binary.c"

int* my_atoi(const char* str);
int length(const int* arr);

int main()
{
	char a[55];
	printf("Enter a string: ");
	scanf("%s", a);

	printf("The length of %s is %i\n\n", a, (int) strlen(a));
	//printf("%i is the ASCII representation\n", my_atoi(a)[0]);
	
	//test
	int* num_of_str = my_atoi(a);

	printf("%s in binary would be\n", a);
	for (int i = 0; i < length(num_of_str); i++)
	{
		long long int bin_rep = binary(num_of_str[i]);
		int digit_count = (bin_rep==0)?1:log10(bin_rep)+1;
		
		if (digit_count % 4 == 0)
		{
			printf("%lli ", bin_rep);
		}

		else 
		{
			for (int i = 0; i < 4 - (digit_count % 4); i++)
			{
				printf("0");
			}
			printf("%lli ", bin_rep);
		}
	}
	printf("\n");
}

int* my_atoi(const char* str) 
{
	int* arr_of_decimals = malloc(30 * sizeof(int));
	for (int i = 0; str[i] != '\0'; i++)
	{
		arr_of_decimals[i] = str[i];
	}

	return arr_of_decimals;
}

int length(const int* arr)
{
	int counter = 0;
	while (arr[counter] != 0)
	{
		counter++;
	}
	return counter;
}
