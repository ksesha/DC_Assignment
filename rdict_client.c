/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */
#include <rpc/rpc.h>

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>


#include "rdict.h"

#define	MAXWORD	50		/* maximum length of a command or word	*/

#define	RMACHINE	"localhost"	/* name of remote machine	*/
CLIENT	*clnt;			/* handle for remote procedure	*/


int	nextin(char *cmd, char *word, char *meaning);
char ** insertw_1(dictionary *argp, CLIENT *clnt);
char ** deletew_1(char **argp, CLIENT *clnt);
char ** lookupw_1(char **argp, CLIENT *clnt);



void
rdictprog_1(CLIENT* clnt)
{
	
	
	char	word[MAXWORD+1];     /* space to hold word from input line	*/
	char	meaning[MAXWORD+1];  /* space to hold meaning from input line	*/
	char	cmd;
	int	wrdlen;		/* length of input word			*/

	while(1) {
		wrdlen = nextin(&cmd, word, meaning);
		if (wrdlen < 0)
			exit(0);
		switch (cmd) {
		case 'i': {	/* "insert" */

				dictionary* dict;	
				dict = (dictionary*) malloc(sizeof(dictionary));
				dict->word = (char*) malloc(sizeof(char) * strlen(word));
				strcpy(dict->word, word);
				dict->meaning = (char*) malloc(sizeof(char) * strlen(meaning));
				strcpy(dict->meaning, meaning);

				char** output = insertw_1(dict, clnt);
				if (output == (char **) NULL) {
					clnt_perror (clnt, "call failed");
				}
				printf("%s inserted.\n",word);
				break;
			}
		case 'r': {	/* "delete" */
				char** output = deletew_1( (char*[]) {word}, clnt);
				if (output == (char **) NULL) {
					clnt_perror (clnt, "call failed");
				}
				if(strcmp(*output,"") == 0){
					printf("Not found [%s] to delete", word);	
				} else {
					printf("%s deleted.\n",word);
				}	
				break;
			}
		case 'l': {	/* "lookup" */
				char** output = lookupw_1((char* []){word}, clnt);
				if (output == (char **) NULL) {
					clnt_perror (clnt, "call failed");
				}
				if(strcmp(*output,"") == 0){
					printf("%s was not found.\n",word);	
				} else {
					printf("Meaning: %s", *output);
				}
						
				break;
			}
		case 'q': {	/* quit */
			printf("program quits.\n");
			exit(0);
			}
		default: {	/* illegal input */
			printf("command %c invalid.\n", cmd);
			break;
			}
		}
	}
}

/*------------------------------------------------------------------------
 * main - insert, delete, or lookup words in a dictionary as specified
 *------------------------------------------------------------------------
 */

int
main (int argc, char *argv[])
{

      /* set up connection for remote procedure call  */
 
	clnt = clnt_create (RMACHINE, RDICTPROG, RDICTVERS, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (RMACHINE);
		exit (1);
	}

	
	/* Call this in a while loop */	
	rdictprog_1(clnt);


	/* Close the client connection */
	clnt_destroy (clnt);

}

/*------------------------------------------------------------------------
 * nextin - read a command and (possibly) a word from the next input line
 *------------------------------------------------------------------------
 */
int
nextin(char *cmd, char *word, char* meaning)
{

	printf("\n/*------------------------------------------------------------------------");
	printf("\n* Welcome to the dictionary simulation");
	printf("\n* Enter 'i' to insert a word and its meaning");
	printf("\n* Enter 'l' to lookup for the meaning of the given word");
	printf("\n* Enter 'r' to remove the word from the dictionary");
	printf("\n* Enter 'q' to quit");
	printf("\n* Note: Words and meaning cannot exceed 50 words");
	printf("\n/*------------------------------------------------------------------------");
	printf("\n\nOption:");
	int	i;
	char 	option[1];
	char    iword[MAXWORD + 1];
	char    imeaning[MAXWORD + 1];

	/* read the command first */
	scanf(" %[^\n]", option);
	strcpy(cmd, option);

	i = 0;
	if( 'i' == *cmd ) {
		printf("Enter the word:");
		scanf(" %[^\n]", iword);
		strcpy(word, iword);		
		
		printf("Enter the meaning:");
		scanf(" %[^\n]", imeaning);
		strcpy(meaning, imeaning);
		i++;
	} else {
		if(*cmd == 'l' || *cmd == 'r' ) {
			printf("Enter the word:");
			scanf(" %[^\n]", iword);
			strcpy(word, iword);
			i++;
		} else {
			if( *cmd == 'q' ) 
				i++;
		}
	}
	return i;
}

