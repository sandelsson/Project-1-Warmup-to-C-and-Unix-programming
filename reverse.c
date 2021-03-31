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
#define MAX 100
#define BUFFSIZE 100

/*
void read(){
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    FILE *fp;
    int count = 0;
    
    if (fp = NULL){
    	fprintf(stderr, "Unable to open file \n");
    	//perror("Unable to open file\n");
    	exit(1);
    }
    
    char *list[MAX];

    fp = fopen("pikkukalle.txt","r"); //EN SAA PASSATTUU TOT SAATANAN CMDL ARGUMENTTII
    
    while ((read = getline(&line, &len, fp)) != -1) {
    	
        strcpy(list[count], line);
        count++;
    }
    
        printf("\n");    
    printf("Reverse order: \n\n");    
    //Loop through the array in reverse order    
    for (int i = count-2; i >= 0; i--) {
        printf("%s\n", list[i]);
        free(list[i]);
        list[i] = NULL;
    }  

    fclose(fp);
    if (line){
        free(line);
    }
    exit(EXIT_SUCCESS); 
    
}
*/

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
        //printf("Enter a word: ");
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
    	
    	
    	
    	
//void read_and_write(char* file_read)

//TÄÄ ANTAA JOSTAIN SYYSTÄ SEGMENTATION ERRORII EN TIIÄ MIKS EI PYSTY OIKEE TÄS LINUXIS EES DEBUGGAA KU LÄMÄÄ SEN SAMANTIEN
void read_and_print(FILE *fp)
{
    printf("debugreal1");
  
    char *line[MAX];
    //FILE *fp; 
    int i = 0;
    int count = 0;
    int tot = 0;
    printf("debug1");	

    //fp = fopen("pikkukalle.txt", "r");
    while(fgets(line[count], MAX, fp)) 
	{
        line[count][strlen(line[count]) - 1] = '\0';
        count++;
    }
    printf("debug2");
    tot = count; 
    for(count = 0; count < tot; ++i){
        printf(" %s\n", line[count]);
    }
    printf("\n");
    printf("debug3");
    
    for (int i = count-2; i >= 0; i--) {
        printf("%s\n", line[i]);
        free(line[i]);
        line[i] = NULL;
    }  
  
} 

void read_print(FILE *fp){
	char line[MAX];
	
	while(fgets(line, MAX, fp)!=NULL){
		printf("%s\n", line);
	}
	printf("\n");
		


}


	

int main(int argc, char *argv[]) {

    //char file_read[] = "";
    //char file_write[] = "";
    
    

    if (argc == 1){
    	read_write_stdout_stdin();
    }
    
    
     
    if (argc == 2){
    	fprintf(stdout, "its lit u got one parameter jes vittuuuu!!!");
    	//strcpy(file_read, argv[1]);
    	//read_and_write(file_read);
    	FILE *fp;
    	fp = fopen(argv[1], "r");
    	//read_and_print(fp);
    	read_print(fp);
    	fclose(fp);
    }
    if ((argc > 2) &&(strcmp(argv[1], argv[2])==0)){
    	fprintf(stderr, "Input and output file must differ\n");
        exit(1);
    }
    

    if (argc > 3) {
    	printf("%d", argc);
        fprintf(stderr, "Usage: reverse <input> <output>\n");
        exit(1);
    }
    
    if (argc == 3){
    	fprintf(stdout, "Lit nyt annoit inputin ja outputin ja joudun koodaa äijälle niin vitusti funktioit :CC \n");
    }
    
    printf("Kiitos ohjelman käytöstä.\n");
    return 0;
}


