/*
 * [Han Chen]
 * [2/7/2014]
 *
 * [Project 0.3 - Program 1 - File Echo Program]
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
    
	char buffer[LINELEN];
	char *fgets_rtn = NULL;
	FILE *fd = NULL;
	/* Open a file */
	fd = fopen(filename, "r");
	if (NULL == fd)
	{
		fprintf(stderr, "Error: Cannot open the file %s for reading!\n", filename);
		return -1;
	}

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

        	/* Echo the input back the user */
        	printf("Line: %s\n", buffer);
	}
	/* close the file */
	fclose(fd);
	return 0;
}
