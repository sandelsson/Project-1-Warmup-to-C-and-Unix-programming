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

void read(argv[1]){
    char read_file[50] = argv[1];
    FILE *file;
    
    char *list;

    file = fopen(read_file,"r");
}

int main(int argc, char *argv[]) { 

    if (argv[1] == argv[2]) {
        fprintf(stderr, "Input and output file must differ\n");
        exit(1);
    }

    if (argc > 2) {
        fprintf(stderr, "Usage: reverse <input> <output>\n");
        exit(1);
    }

    char *list = read(argv[1]);
    for (int i = 0,, i++) {
        printf(list[i]"\n");
    }



    printf("Kiitos ohjelman käytöstä.\n");
    return 0;
}