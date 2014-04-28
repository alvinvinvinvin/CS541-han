/*
 * Han Chen CS541
 * 2/3/2014
 *
 * Project 0.2 - Program 1 - Echo Program
*/


#include "verify.h"

int main(int argc, char **argv)
{
	char buffer[LINELEN];
	char *fgets_rtn = NULL;

	int i;
	for ( i=1; ; ++i )
	{
		fgets_rtn = fgets(buffer, LINELEN, stdin);
		if ( NULL == fgets_rtn )
		{
			return 0;
		}

		if ( '\n' == buffer[strlen(buffer) -1])
		{
			buffer[strlen(buffer) -1] = '\0';
			
		}
		printf(" %d) Echo: \"%s\"\n", i, buffer);
	}

	return 0;
}
