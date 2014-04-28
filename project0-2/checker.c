/*
 * Han Chen CS541
 * 2/3/2014
 *
 * Project 0.2 - Program 3 - In Put Verification Checker
*/
#include "verify.h"
double result = 0;
int main(int argc, char **argv)
{
	char buffer[LINELEN];
	char *fgets_rtn;
	if( argv[1] != NULL)
	{
		interactive(argc, argv);
		printf("\n");
		printf("Final Total: %.2f\n", result);
	}
	else 
	{
		double total;
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
				total += strtol(buffer, NULL, 10);
				printf("Running Total: %.2f\n", total);
			}
			else if (is_valid_float(buffer))
			{
				total += strtod(buffer, NULL);
				printf("Running Total: %.2f\n", total);
			}

			else
			{
				printf("Error: %s is not a valid number...\n", buffer);
				printf("Running Total: %.2f\n", total);
			}
		
		}
		printf("\n");
		printf("Final Total: %.2f\n", total);
	}
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

int interactive(int argc, char **argv)
{	
	int j;
	
	for (j=1; j < argc; j++)
	{
		if(is_valid_int(argv[j]))
		{
			double temp1;
			temp1 = result + strtol(argv[j], NULL, 10);
			printf("%.2f + %.2f = %.2f\n", result, (double)strtol(argv[j], NULL, 10),temp1);
			result = temp1;
		}
		
		else if (is_valid_float(argv[j]))
		{
			double temp2;
			temp2 = result + strtod(argv[j], NULL);
			printf("%.2f + %.2f = %.2f\n", result, strtod(argv[j], NULL),temp2);
			result = temp2;
		}
		else 
		{
			printf("%s is not a valid number...\n", argv[j]);
		}
	}
	return 1;
}


