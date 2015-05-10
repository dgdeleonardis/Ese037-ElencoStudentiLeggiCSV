#include <stdio.h>
#include <stdlib.h>

#define MAX_STRLEN 30
#define MAX_FNAMELEN 255

struct s_studente {
    char nome[MAX_STRLEN+1];
    char cognome[MAX_STRLEN+1];
    int eta;
    char classe[MAX_STRLEN+1];
};

typedef struct s_studente studente;
int main(int argc, char** argv) {
    studente studente;
    int i;
    char fileName[MAX_FNAMELEN+1];
    FILE *puntaFile;
    
    printf("Inserisci il nome del file da aprire (max %d) : ", MAX_FNAMELEN);
    scanf("%s", fileName);
    
    puntaFile = fopen(fileName, "r");
    
    if(puntaFile == NULL) {
        fprintf(stderr, "ERRORE : Impossibile aprire il file %s\n", fileName);
        exit(1);
    }
    else {
        printf("File aperto correttamente \n");
    }
    
    fscanf(puntaFile, "%[^;];%[^;];%[^;];%[^;\n]\n", studente.nome, studente.cognome, studente.nome, studente.classe);
    
    i=0;
    fscanf(puntaFile, "%[^;];%[^;];%d;%[^;\n]\n", studente.nome, studente.cognome, &(studente.eta), studente.classe);
    while(!feof(puntaFile)) {
        i++;
        printf("Studente %d\nNome: %s\nCognome: %s\nEta': %d\nClasse: %s\n\n",
                i,
                studente.nome,
                studente.cognome,
                studente.eta,
                studente.classe);
        fscanf(puntaFile, "%[^;];%[^;];%d;%[^;\n]\n", studente.nome, studente.cognome, &(studente.eta), studente.classe);
    }
    fclose(puntaFile);
    
    return (EXIT_SUCCESS);
}
