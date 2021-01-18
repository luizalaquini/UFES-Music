//Inclusao das bibliotecas necessarias.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "midia.h"
#include "album.h"

//Definicoes de constantes para facilitar a leitura do codigo.
#define MAXTAM 50

// DEFINICAO DAS FUNCOES EM "album.h"
struct album{
    char nome[MAXTAM];
    int quantmid;
    char midias[20][MAXTAM];
};

Album* CriaAlbum(char *nomeDoAlbum, char *midia){
    Album *a = (Album *)malloc(sizeof(Album)); //aloca espaco
    strcpy(a->nome, nomeDoAlbum); //implementa nome
    strcpy(a->midias[0], midia); //implementa primeira midia
    a->quantmid=1;
    return a;
}

void AtualizaAlbum (Album *a, char *midia){
    a->quantmid++;
    strcpy(a->midias[a->quantmid-1], midia); 
}

void ApagaAlbum(Album **meusAlbuns, int posicao, int quantAlbuns){
    int i=0;

    for(i=posicao; i<quantAlbuns-1; i++){
        meusAlbuns[i]=meusAlbuns[i+1];
    }
    free(meusAlbuns[quantAlbuns-1]);
}

char* retornaNomeDoAlbum(Album **meusAlbuns, int posicao){
    char *aux = malloc(50*sizeof(char));
  
    strcpy(aux, meusAlbuns[posicao]->nome);

    return aux;
}

void ListaAlbuns(Album **meusAlbuns, int quantAlbuns){
    for(int i=0; i<quantAlbuns; i++){
        printf("\nAlbum Numero [%d]\n", i+1);
        printf("NOME: %s\n", meusAlbuns[i]->nome);
        for(int j=0; j<meusAlbuns[i]->quantmid; j++){
            printf(" - %s\n", meusAlbuns[i]->midias[j]);
        }
    }
}

int verificaSeAlbumExiste (char *nome, Album **meusAlbuns, int quantAlbuns){
    for(int i=0; i<quantAlbuns; i++){
        if (strcmp(meusAlbuns[i]->nome, nome)==0){
            return 1;
        }
        else{
            return 0;
        }
    }
}

Album* retornaAlbum (Album **meusAlbuns, int quantAlbuns, char *nomeDoAlbum){
    for(int i=0; i< quantAlbuns; i++){
        if (strcmp(meusAlbuns[i]->nome, nomeDoAlbum)==0){
            return meusAlbuns[i];
        }
    }
}

void SalvarAlbuns(FILE *arquivo, Album **meusAlbuns, int quantAlbuns){
    int i, j;

    fprintf(arquivo, "%d\n", quantAlbuns);
    for(i=0; i<quantAlbuns; i++){
        fprintf(arquivo, "%s\n", meusAlbuns[i]->nome);
        fprintf(arquivo, "%d\n", meusAlbuns[i]->quantmid);
        for(j=0; j<meusAlbuns[i]->quantmid; j++){
            fprintf(arquivo, "%s\n", meusAlbuns[i]->midias[j]);
        }
    }
}

void CarregarAlbuns(FILE *arquivo, Album **meusAlbuns, int quantAlbuns){
    int i, j;

    fscanf(arquivo, "%d\n", &quantAlbuns);
    for(i=0; i<quantAlbuns; i++){
        fscanf(arquivo, "%s\n", meusAlbuns[i]->nome);
        fscanf(arquivo, "%d\n", &meusAlbuns[i]->quantmid);
        for(j=0; j<meusAlbuns[i]->quantmid; j++){
            fscanf(arquivo, "%s\n", meusAlbuns[i]->midias[j]);
        }
    }
}