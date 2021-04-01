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
#define MAX 1000
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


void read_write(FILE *fp_read, FILE *fp_write){
	char line[MAX][MAX];
	int count = 0;
	int total = 0;	
	char *list[200];
	

	//reading input file into array
	while(fgets(line[count], MAX, fp_read)){
		
		//strcpy(list[count], line);
		line[count][strlen(line[count]) - 1] = '\0';		
		count++;
		
	}
	

	
	//printing the array in reverse
	for (int i = count-1; i >= 0; i--) {
		fprintf(fp_write, "%s\n", line[i]);
		//fprintf(stdout, "%s\n", list[i]);
		//fprintf(fp_write, "\n");
        	
    }
		


}




int main(int argc, char *argv[]) {
    
    
    
    //no arguments given --> input from keyboard and output on stdout
    if (argc == 1){
    	read_write_stdout_stdin();
    }
    
    
    //one argument give --> assuming its the input file --> read the input file and print it in reverse on stdout 
    if (argc == 2){
    	FILE *fp = NULL;
    	fp = fopen(argv[1], "r");
    	read_print(fp);
    	fclose(fp);
    }
    
    //input and output files given but they are identical
    if ((argc > 2) &&(strcmp(argv[1], argv[2])==0)){
    	fprintf(stderr, "Input and output file must differ\n");
        exit(1);
    }
    
    //too many arguments
    if (argc > 3) {
    	printf("%d", argc);
        fprintf(stderr, "Usage: reverse <input> <output>\n");
        exit(1);
    }
    
    //input and output file given correctly, input read from file and output written in reverse in output file
    if (argc == 3){
    	FILE *fp_read = NULL;
    	FILE *fp_write = NULL;
    	fp_read = fopen(argv[1], "r");
    	fp_write = fopen(argv[2], "w");
    	read_write(fp_read, fp_write);
    	fclose(fp_read);
    	fclose(fp_write);
    }
    
    printf("Thank you so much for using our great great program\n-Sandelsson\n-Joonas69\nXO\n");
    return 0;
}


