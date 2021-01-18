//Inclusao das bibliotecas necessarias.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "midia.h"
#include "playlist.h"


//Definicoes de constantes para facilitar a leitura do codigo.
#define MAXTAM 50

// DEFINICAO DAS FUNCOES EM "playlist.h"
struct playlist{
    char nome[MAXTAM];
    char midias[50][MAXTAM];
    int quantmid;
    char usuario[2][MAXTAM];
    int quantusu;
};

Playlist* CriaPlaylist(char *nome, char *usuario){
    Playlist *p = (Playlist *)malloc(sizeof(Playlist));
    
    strcpy(p->nome, nome); //implementa nome.

    //implementa usuario:
    char u[MAXTAM] = ""; //auxiliar p/ usuario + sua inicializacao.
    int j = 0;
    p->quantusu = 0;
    for(int i=0; i < strlen(usuario); i++, j++) {
        if(usuario[i] == ','){
            u[j] = '\0', strcpy(p->usuario[p->quantusu++], u), j = 0, i++;
            if(usuario[i] == ' ') i++; //verifica se ha espaco apos a virgula.
        }
        u[j] = usuario[i];
    }
    u[j] = '\0';
    strcpy(p->usuario[p->quantusu++], u);

    p->quantmid=0;

    return p;
}

void AtualizaPlaylist (Playlist *p, char *nome, char *usuario){
    strcpy(p->nome, nome); //atualiza nome

    //atualiza usuario
    char u[MAXTAM] = ""; //apenas uma inicializacao. 
    int j = 0;
    p->quantusu = 0;
    for(int i=0; i < strlen(usuario); i++, j++) {
        if(usuario[i] == ','){
            u[j] = '\0', strcpy(p->usuario[p->quantusu++], u), j = 0, i++;
            if(usuario[i] == ' ') i++; //verifica se ha espaco apos a virgula.
        }
        u[j] = usuario[i];
    }
    u[j] = '\0';
    strcpy(p->usuario[p->quantusu++], u);
}

void ApagaPlaylist(Playlist **minhasPlaylists, int posicao, int quantPlaylists){
    int i=0;

    for(i=posicao; i<quantPlaylists-1; i++){
        minhasPlaylists[i]=minhasPlaylists[i+1];
    }
    free(minhasPlaylists[quantPlaylists-1]);
}

void ListaPlaylists(Playlist **minhasPlaylists, int quantPlaylists){
    for(int i=0; i<quantPlaylists; i++){
        printf("\nPlaylist Numero [%d]\n", i+1);
        printf("NOME: %s\n", minhasPlaylists[i]->nome);
        printf("USUARIO(S):");
        for(int j=0; j<minhasPlaylists[i]->quantusu; j++){
            printf(" %s", minhasPlaylists[i]->usuario[j]);
        }
        printf("\n"); 
        printf("MIDIAS:\n");
        for(int k=0; k<minhasPlaylists[i]->quantmid; k++){
            printf(" > %s\n", minhasPlaylists[i]->midias[k]);
        }
    }
}

void AdicionaMidiaNaPlaylist(Playlist **minhasPlaylists, int editar, char *midia){
    int i = minhasPlaylists[editar]->quantmid;
    strcpy(minhasPlaylists[editar]->midias[i], midia);

    minhasPlaylists[editar]->quantmid+=1;
}

void SalvarPlaylists(FILE *arquivo, Playlist **minhasPlaylists, int quantPlaylists){
    int i, j;

    fprintf(arquivo, "%d\n", quantPlaylists);
    for(i=0; i<quantPlaylists; i++){
        fprintf(arquivo, "%s\n", minhasPlaylists[i]->nome);
        fprintf(arquivo, "%d\n", minhasPlaylists[i]->quantmid);
        for(j=0; j<minhasPlaylists[i]->quantmid; j++){
            fprintf(arquivo, "%s\n", minhasPlaylists[i]->midias[j]);
        }
        fprintf(arquivo, "%d\n", minhasPlaylists[i]->quantusu);
        for(j=0; j<minhasPlaylists[i]->quantusu; j++){
            fprintf(arquivo, "%s\n", minhasPlaylists[i]->usuario[j]);
        }
    }
}

void CarregarPlaylists(FILE *arquivo, Playlist **minhasPlaylists, int quantPlaylists){
    int i, j;

    fscanf(arquivo, "%d\n", &quantPlaylists);
    for(i=0; i<quantPlaylists; i++){
        fscanf(arquivo, "%s\n", minhasPlaylists[i]->nome);
        fscanf(arquivo, "%d\n", &minhasPlaylists[i]->quantmid);
        for(j=0; j<minhasPlaylists[i]->quantmid; j++){
            fscanf(arquivo, "%s\n", minhasPlaylists[i]->midias[j]);
        }
        fscanf(arquivo, "%d\n", &minhasPlaylists[i]->quantusu);
        for(j=0; j<minhasPlaylists[i]->quantusu; j++){
            fscanf(arquivo, "%s\n", minhasPlaylists[i]->usuario[j]);
        }
    }
}