/*
 * Han Chen CS541
 * 2/3/2014
 *
 * Project 0.2 - Program 2 - Echo Program
*/
#include "verify.h"


int main(int argc, char **argv)
{
	char buffer[LINELEN];
	char *fgets_rtn;
	double result;

	
	while (1)
	{
		fgets_rtn = fgets(buffer, LINELEN, stdin);
		if ( NULL == fgets_rtn )
		{
			break;
		}

		if ( '\n' == buffer[strlen(buffer) -1])
		{
			buffer[strlen(buffer) -1] = '\0';
		}
		
		if (is_valid_int(buffer))
		{
			result += strtol(buffer, NULL, 10);
			printf("Running Total: %.2f\n", result);
		}
		else if (is_valid_float(buffer))
		{
			result += strtod(buffer, NULL);
			printf("Running Total: %.2f\n", result);
		}

		else
		{
			printf("Error: %s is not a valid number...\n", buffer);
			printf("Running Total: %.2f\n", result);
		}

	}
	printf("\n");
	printf("Final Total: %.2f\n", result);
		
return 0;
}

int is_valid_int(char *str)
{
	int i;
	int space_flag, pn_flag = 1;
	for ( i=0; i<strlen(str); i++)
	{
		
		if (pn_flag&&(str[i]=='+'||str[i]=='-'))
		{
			pn_flag = 0;
			continue;
		}
		else pn_flag = 0;

		if (space_flag&&isspace(str[i]))
		{
			continue;
		}
		else space_flag = 0;

		if (!isdigit(str[i]))
		{
			return 0;
		}
	}
    return 1;
}

int is_valid_float(char *str)
{
	int i;
	int point_flag = 1;
	int space_flag, pn_flag = 1;
	for ( i=0; i<strlen(str); i++)
	{
		
		if (pn_flag&&(str[i]=='+'||str[i]=='-'))
		{
			pn_flag = 0;
			continue;
		}
		else pn_flag = 0;

		if (space_flag && isspace(str[i]))
		{
			continue;
		}
		else space_flag = 0;

		if (point_flag && str[i]=='.')
		{
			point_flag = 0;
			continue;
		}

		if (!isdigit(str[i]))
		{
			return 0;
		}
	}
	return 1;
}
	
