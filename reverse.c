/*******************************************************************/
/* Käyttäjärjestelmät ja systeemiohjelmointi
 * Harjoitusprojekti: Project 1 
 * Tekijät: Kukonlehto Joonas, Ruuskanen Santeri
 * Päivämäärä: 30.3.2021
 * Yhteistyö ja lähteet:
 */
/*******************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
#define BUFFSIZE 100
/*

void read(char *argv[]){
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    FILE *fp;
    
    if (fp = NULL){
    	fprintf(stderr, "Unable to open file \n");
    	//perror("Unable to open file\n");
    	exit(1);
    }
    
    char *words[MAX];

    fp = fopen(argv[0],"r");
    
    while ((read = getline(&line, &len, fp)) != -1) {
        printf("Retrieved line of length %zu:\n", read);
        printf("%s", line);
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
    int i, count = 0, slen; /* can replace size_t with int if you prefer */

    /* loops only for three input strings */
    for (i = 0; strcmp(buffer, "0"); i++) {

        /* read input of one string, with error checking */
        //printf("Enter a word: ");
        if (fgets(buffer, BUFFSIZE, stdin) == NULL) {
            fprintf(stderr, "Error reading string into buffer.\n");
            exit(EXIT_FAILURE);
        }

        /* removing newline from buffer, along with checking for overflow from buffer */
        slen = strlen(buffer);
        if (slen > 0) {
            if (buffer[slen-1] == '\n') {
                buffer[slen-1] = '\0';
            } else {
                printf("Exceeded buffer length of %d.\n", BUFFSIZE);
                exit(EXIT_FAILURE);
            }
        } 

        /* checking if nothing was entered */
        if (!*buffer) {
            printf("No string entered.\n");
            exit(EXIT_FAILURE);
        }

        /* allocate space for `words[i]` and null terminator */
        words[count] = malloc(strlen(buffer));

        /* checking return of malloc, very good to do this */
        if (!words[count]) {
            printf("Cannot allocate memory for string.\n");
            exit(EXIT_FAILURE);
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
    	
    	
    	
    	
    	





	

int main(int argc, char *argv[]) {

    if (argc == 1){
    	read_write_stdout_stdin();
    }
    
    //MULLA TULEE STRCMP(ARGV[1], ARGV[2]) JOKU VITUN SEGMENTATION ERROR ENKÄ YMMÄRRÄ MIKÄ SAATANA TOSSA ON
    //VÄÄRIN. OON YRITTÄNY TALLENTAA NOIT MUUTTUJII JA VAIKKA PERSEREIKÄÄ MUT EI SAATANA SKULAA
    //SAATTAA OLLA TÄS LINUXIS TOI VIKA EN USKO ET TULEE TOTA VITTUA JOS LAITTAA VSCODEE
   
    
    /*
    if ( ! strcmp(argv[1], argv[2])) {
    	fprintf(stderr, "Input and output file must differ\n");
        exit(1);
    }
*/
    if (argc > 2) {
        fprintf(stderr, "Usage: reverse <input> <output>\n");
        exit(1);
    }
    
    if (argc == 2){
    	//read(argv[1])
    }
    
    
    printf("Kiitos ohjelman käytöstä.\n");
    return 0;
}


