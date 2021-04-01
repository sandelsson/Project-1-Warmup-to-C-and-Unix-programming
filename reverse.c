/*******************************************************************/
/* Käyttäjärjestelmät ja systeemiohjelmointi
 * Harjoitusprojekti: Project 1 
 * Tekijät: Kukonlehto Joonas, Ruuskanen Santeri
 * Päivämäärä: 30.3.2021
 * Yhteistyö ja lähteet: Toimiiko tämä?
 */
/*******************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000				//We used 1000 as we thought it would cover all cases
#define BUFFSIZE 1000


//When no files are supplied by user --> input is read from stdin and output is wrote on screen.
//source: https://stackoverflow.com/questions/41518039/how-to-input-strings-into-an-array-in-c

void  read_write_stdout_stdin(){
    char *words[MAX];
    char buffer[BUFFSIZE];
    int i, count = 0, slen;

    /* loops until input is '0' */
    fprintf(stdout, "Input as many lines as you want and end with '0' (zero).\n\n");
    for (i = 0; strcmp(buffer, "0"); i++) {

        /* read input of one string, with error checking */
        if (fgets(buffer, BUFFSIZE, stdin) == NULL) {
            fprintf(stderr, "Error reading string into buffer.\n");
            exit(1);
        }

        /* removing newline from buffer, along with checking for overflow from buffer */
        slen = strlen(buffer);
        if (slen > 0) {
            if (buffer[slen-1] == '\n') {
                buffer[slen-1] = '\0';
            } else {
                printf("Exceeded buffer length of %d.\n", BUFFSIZE);
                exit(1);
            }
        } 

        /* checking if nothing was entered */
        if (!*buffer) {
            printf("No string entered.\n");
            exit(1);
        }

        /* allocate space for `words[i]` and null terminator */
        words[count] = malloc(strlen(buffer));

        /* checking return of malloc, very good to do this */
        if (!words[count]) {
            printf("Cannot allocate memory for string.\n");
            exit(1);
        }

        /* if everything is fine, copy over into your array of pointers */
        strcpy(words[count], buffer);

        /* increment count, ready for next space in array */
        count++;
    }
    
    
    //int length = sizeof(words)/sizeof(words[0]);
    
       
    printf("\n");    
    printf("Reverse order: \n\n");    
    //Loop through the array in reverse order    
    for (i = count-2; i >= 0; i--) {
        printf("%s\n", words[i]);
        free(words[i]);
        words[i] = NULL;
    }  

    printf("\n");
}
    	
    	

//When input is supplied by user --> input is read from file and output is printed on screen.

void read_print(FILE *fp){
	char line[MAX][MAX];
	int count = 0;
	int total = 0;	
	char *list[200];

	
	//Reading file line by line and adding lines to array	
	while(fgets(line[count], MAX, fp)){
		line[count][strlen(line[count]) - 1] = '\0';		
		count++;
		
	}
	
	//Printing array to screen on reversed order
    	total = count;     
    	for(count = total - 1; count >= 0; count--) {
   		printf(" %s\n", line[count]);
	}
	printf("\n");	

}

//When input and output is supplied --> input is read from a file and written in output file reversely.

/*
void read_write(FILE *fp){
	char line[MAX][MAX];
	int count = 0;
	int total = 0;	
	char *list[200];
	
	while(fgets(line[count], MAX, fp)){
		
		//strcpy(list[count], line);
		line[count][strlen(line[count]) - 1] = '\0';		
		count++;
		
	}

    	total = count;     
    	for(count = total - 1; count >= 0; count--) {
   		printf(" %s\n", line[count]);
	}
	printf("\n");
	
	
	for (int i = count-2; i >= 0; i--) {
        	printf("%s\n", list[i]);
        	free(list[i]);
        	list[i] = NULL;
    }
		


}


*/

int main(int argc, char *argv[]) {

    //char file_read[] = "";
    //char file_write[] = "";
    
    

    if (argc == 1){
    	read_write_stdout_stdin();
    }
    
    
     
    if (argc == 2){
    	FILE *fp = NULL;
    	fp = fopen(argv[1], "r");
	if (fp == NULL) {
		fprintf(stderr, "error: cannot open file '%s'\n", argv[1]); 	
		exit (1);
	}
    	read_print(fp);
    	fclose(fp);
    }
    if ((argc > 2) &&(strcmp(argv[1], argv[2])==0)){
    	fprintf(stderr, "Input and output file must differ\n");
        exit(1);
    }
    

    if (argc > 3) {
    	printf("%d", argc);
        fprintf(stderr, "usage: reverse <input> <output>\n");
        exit(1);
    }
    
    if (argc == 3){
    	fprintf(stdout, "Lit nyt annoit inputin ja outputin ja joudun koodaa äijälle niin vitusti funktioit :CC \n");
    }
    
    printf("Thank you for using our program!\n");
    return 0;
}


