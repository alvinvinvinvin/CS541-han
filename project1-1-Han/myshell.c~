/*
 * Han Chen
 * Feb. 16, 2014
 *
 * CS441/541: Project 1 Part 1
 *
 */
#include "myshell.h"
#define LINELEN 1024


int main(int argc, char * argv[]) 
{
	if(argc > 1)
		batch_mode(argc, argv);
	else
		interactive_mode();
	return 0;
}	

int interactive_mode()
{
	char command[LINELEN];
	int num_jobs = 0;
	job_t *loc_jobs = NULL;
	int i, j;
	int jobs = 0;
	int history = 0;
	int background = 0;
	char *fgets_rtn = NULL;
	printf("$myshell ");
	fgets_rtn = fgets(command,LINELEN,stdin);
	
	while (1)
	{
		if ( NULL == fgets_rtn )
		{
			break;
		}

		if ( '\n' == command[strlen(command) -1])
		{
			command[strlen(command) -1] = '\0';
		}
		/*
     		* Allocate some space for the job_t array
     		* Necessary so split_input_into_jobs() function has a memory
     		* handle to work with.
     		*/
		loc_jobs = (job_t*)malloc(sizeof(job_t) * 1);
    		if( NULL == loc_jobs ) 
		{
        		fprintf(stderr, "Error: Failed to allocate memory! Critical failure on %d!", __LINE__);
        		exit(-1);
    		}
		int is_background = background_check(command);
		if(command[0] != '\0')
		history++;
			
		split_input_into_jobs(command, &num_jobs, &loc_jobs);

    		/*
     		* For each of those jobs split out the argument set
     		*/
    		for( i = 0; i < num_jobs; ++i ) 
		{
			split_job_into_args( &(loc_jobs[i]) );
			if (is_background)
			{
				if (build_in_commmands(loc_jobs[i].argv[0]) != '1')
				{
					char bic = build_in_commmands(loc_jobs[i].argv[0]);
					switch(bic)
					{
						case 'h':
						printf("Job %d^: \"history\"", history);
						jobs++;
						break;
						case 'j':
						printf("Job %d^: \"jobs\"", history);
						jobs++;
						break;		
						case 'e':
						printf("Job %d^: \"exit\"", history);
						jobs++;
						printf("\n");
                				printf("Total number of jobs: %d \n", jobs);
                				printf("Total number of jobs in history: %d \n", history);
               					printf("Total number of jobs in background: %d \n", background);
                				exit(0);
					}

				}
				else
                    		{
                        		jobs++;
                        		printf("Job %d : \"%s\"", history,loc_jobs[i].argv[0]);
                    		}
                	}
			else
                	{
                    		jobs++;
                   		background++;
                    		printf("Job %d*: \"%s\"", history,loc_jobs[i].argv[0]);
                	}
			/*
         		* Display the arguments
         		*/
        		fflush(NULL);
        		for( j = 1; j < loc_jobs[i].argc; ++j ) 
			{
            			printf(" [%s]", loc_jobs[i].argv[j]);
            			fflush(NULL);
        		}
        		printf("\n");
        		fflush(NULL);
    		}
			
		/*
     		* Cleanup
     		*/
    		if( NULL != loc_jobs ) 
		{
        		/* Cleanup struct fields */
        		for( i = 0; i < num_jobs; ++i ) 
			{
            			/* .full_command */
            			if( NULL != loc_jobs[i].full_command ) 
				{
                			free( loc_jobs[i].full_command );
                			loc_jobs[i].full_command = NULL;
            			}

            			/* .argv */
            			if( NULL != loc_jobs[i].argv ) 
				{
                			for( j = 0; j < loc_jobs[i].argc; ++j ) 
					{
                    				if( NULL != loc_jobs[i].argv[j] ) 
						{
                        				free( loc_jobs[i].argv[j] );
                        				loc_jobs[i].argv[j] = NULL;
                    				}
                			}
                			free( loc_jobs[i].argv );
                			loc_jobs[i].argv = NULL;
            			}

            			/* .argc */
            			loc_jobs[i].argc = 0;
        		}

        		/* Free the array */
        		free(loc_jobs);
        		loc_jobs = NULL;
    		}
		printf("$myshell ");
            	fgets_rtn = fgets(command,LINELEN,stdin);
    	}
	return 0;
}

int batch_mode(int argc, char ** argv)
{
	int num_jobs = 0;
	job_t *loc_jobs = NULL;
	int i, j;
	int jobs = 0;
	int history = 0;
	int background = 0;
	
	for(i=1; i < argc; ++i)
	{
		char command[LINELEN];
		char *fgets_rtn = NULL;
		FILE *fd = NULL;
		/* Open a file */
		fd = fopen(argv[i], "r");
		/* If opening failed */
		if (NULL == fd)
		{
			fprintf(stderr, "Error: Cannot open the file %s for reading!\n", argv[i]);
			return -1;
		}


		while( 0 == feof(fd) ) 
		{
			/* Read file */
			fgets_rtn = fgets(command, LINELEN, fd);
			/* Ctrl + D */
			if( NULL == fgets_rtn) 
			{
				break;
			}
			/* Strip off the new line */
        		if( '\n' == command[ strlen(command) - 1] ) 
			{
				command[ strlen(command) - 1] = '\0';
        		}
			/*
     			* Allocate some space for the job_t array
     			* Necessary so split_input_into_jobs() function has a memory
     			* handle to work with.
     			*/
			loc_jobs = (job_t*)malloc(sizeof(job_t) * 1);
    			if( NULL == loc_jobs ) 
			{
        			fprintf(stderr, "Error: Failed to allocate memory! Critical failure on %d!", __LINE__);
        			exit(-1);
    			}
			int is_background = background_check(command);
			
			split_input_into_jobs(command, &num_jobs, &loc_jobs);
			
    			/*
     			* For each of those jobs split out the argument set
     			*/
    			for( i = 0; i < num_jobs; ++i ) 
			{
				history++;
				split_job_into_args( &(loc_jobs[i]) );
				if (is_background)
				{
					if (build_in_commmands(loc_jobs[i].argv[0]) != '1')
					{
						char bic = build_in_commmands(loc_jobs[i].argv[0]);
						switch(bic)
						{
							case 'h':
							printf("Job %d^: \"history\"", history);
							jobs++;
							break;
							case 'j':
							printf("Job %d^: \"jobs\"", history);
							jobs++;
							break;		
							case 'e':
							printf("Job %d^: \"exit\"", history);
							jobs++;
							printf("\n");
                					printf("Total number of jobs: %d \n", jobs);
                					printf("Total number of jobs in history: %d \n", history);
               						printf("Total number of jobs in background: %d \n", background);
                					exit(0);
						}

					}
					else
                    			{
                        			jobs++;
                        			printf("Job %d : \"%s\"", history,loc_jobs[i].argv[0]);
                    			}
                		}
				else
                		{
                    			jobs++;
                   			background++;
                    			printf("Job %d*: \"%s\"", history,loc_jobs[i].argv[0]);
                		}
				/*
         			* Display the arguments
         			*/
        			fflush(NULL);
        			for( j = 1; j < loc_jobs[i].argc; ++j ) 
				{
            				printf(" [%s]", loc_jobs[i].argv[j]);
            				fflush(NULL);
        			}
        			printf("\n");
        			fflush(NULL);
    			}
			
			/*
     			* Cleanup
     			*/
    			if( NULL != loc_jobs ) 
			{
        			/* Cleanup struct fields */
        			for( i = 0; i < num_jobs; ++i ) 
				{
            				/* .full_command */
            				if( NULL != loc_jobs[i].full_command ) 
					{
                				free( loc_jobs[i].full_command );
                				loc_jobs[i].full_command = NULL;
            				}

            				/* .argv */
            				if( NULL != loc_jobs[i].argv ) 
					{
                				for( j = 0; j < loc_jobs[i].argc; ++j ) 
						{
                    					if( NULL != loc_jobs[i].argv[j] ) 
							{
                        					free( loc_jobs[i].argv[j] );
                        					loc_jobs[i].argv[j] = NULL;
                    					}
                				}
                				free( loc_jobs[i].argv );
                				loc_jobs[i].argv = NULL;
            				}

            				/* .argc */
            				loc_jobs[i].argc = 0;
        			}

        			/* Free the array */
        			free(loc_jobs);
        			loc_jobs = NULL;
    			}
			
    		}
	}
	printf("\n");
        printf("Total number of jobs: %d \n", jobs);
	printf("Total number of jobs in history: %d \n", history);
	printf("Total number of jobs in background: %d \n", background);
	return 0;
}


