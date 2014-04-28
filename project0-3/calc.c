/*
 * [Han Chen]
 * [2/7/2014]
 *
 * [Project 0.3 - Program 2 - Calculator Program]
 */
#include "support.h"

int main(int argc, char **argv) 
{
	int i;
	for( i = 1; i < argc; ++i ) 
	{
		printf("Processing File: %s\n", argv[i]);
		process_file(argv[i]);
	}

	return 0;
}

int process_file(char *filename) 
{
    	double result = 0;
	char buffer[LINELEN];
	char *fgets_rtn = NULL;
	FILE *fd = NULL;
	/* Open a file */
	fd = fopen(filename, "r");
	/* If opening failed */
	if (NULL == fd)
	{
		fprintf(stderr, "Error: Cannot open the file %s for reading!\n", filename);
		return -1;
	}
	/* Initial value of operation is '+' */
	char op = '+';
	/* Set a method to receive the returned value from the method of that to determine whether the string is a valid operation or not; */
	char optemp;
	double resulttemp;
	/* traverse every line of the TXT file until it has read the end-of-file */
	while( 0 == feof(fd) ) 
	{
		/* Read file */
		fgets_rtn = fgets(buffer, LINELEN, fd);
		/* Ctrl + D */
		if( NULL == fgets_rtn) 
		{
			break;
		}
		/* Strip off the new line */
        	if( '\n' == buffer[ strlen(buffer) - 1] ) 
		{
			buffer[ strlen(buffer) - 1] = '\0';
        	}
		/* determine whether the string is valid float or not */
        	if(is_valid_float(buffer)) 
		{
			/* use calc method to compute */
			resulttemp = calc(result, strtod(buffer, NULL), op);
			printf("%.3f %c %.3f = %.3f\n", result, op, strtod(buffer, NULL), resulttemp);
			result = resulttemp;		
		} 
		/* determine whether the string is valid operation or not if it is not a valid number */
		else
		{
			optemp = is_op(buffer);
			/* do defferent operations by the optemp receives defferents returned value from is_op */
			if(optemp == '0') 
			{
				printf("Error: \"%s\" is not a valid operation...\n", buffer);
			}
			else if(optemp == '1')
			{
				printf("Error: %s is not a valid number...\n", buffer);
			}
			else 
			{
				/* assign the returned value from optemp to op to calculate by defferent methods */
				op = optemp;
			}
		}
	}
	printf("Final Total: %.2f\n", result);
	/* close the file */
	fclose(fd);
	
	return 0;
}
/* Determine whether it is valid float number or not */
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

/* Method of calculating in defferent operations */
double calc(double num1, double num2, char op)
{
	double result = 0;
	switch(op)
	{
		case '+': 
		result = num1 + num2;
		break;
		case '*':
		result = num1 * num2;
		break;
		case '-':
		result = num1 - num2;
		break;
		case '/':
		result = num1 / num2;
		break;
		case '%':
        if(num1>=num2)
        {
            result = num1 - num2;
            while(result >= num2)
            {
                result = result - num2;
            }
        }
        else result = num1;
		break;
	}
	return result;
}
/* function of that to determine whether the string is a valid operation or not */
char is_op(char *str)
{
	/* Returning '0' means the string begins with 'op', but it's not a valid operation. Returning '1' means it does not begin with 'op' */
	if(strncmp("op *", str, 5) == 0)
		
		return '*';
	
	else if(strncmp("op +", str, 5) == 0)
		
		return '+';
	
	else if(strncmp("op -", str, 5) == 0)
	
		return '-';

	else if(strncmp("op /", str, 5) == 0)

		return '/';

	else if(strncmp("op %", str, 5) == 0)

		return '%';

	if(str[0] != 'o' || str[1] != 'p')

		return '1';

	return '0';

}
	
