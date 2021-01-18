//Inclusao das bibliotecas necessarias.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "midia.h"
#include "album.h"
#include "playlist.h"
#include "texto.h"

//Definicoes de constantes para facilitar a leitura do codigo.
#define MAXTAM 50

// DEFINICAO DAS FUNCOES EM "midia.h"
struct midia {
    int tipo;
    char nome[MAXTAM];
    int quantart;
    char artista[3][MAXTAM];
    char album[50];
    int quantcom;
    char compositor[3][MAXTAM];
    char genero[MAXTAM];
    char gravadora[MAXTAM];
    int duracao; //em segundos 
};

Midia* CriaMidia (int tipo, char *nome, char *artista, char *album, char *compositor, char *genero, char *gravadora, int duracao){
    Midia *m = (Midia *)malloc(sizeof(Midia));
    
    m->tipo = tipo; //implementa tipo.
    strcpy(m->nome, nome); //implementa nome.

    //implementa artista:
    char a[MAXTAM] = ""; //auxiliar p/ artista + sua inicializacao.
    int j = 0;
    m->quantart=0;
    for(int i=0; i < strlen(artista); i++, j++) {
        if(artista[i] == ','){
            a[j] = '\0', strcpy(m->artista[m->quantart++], a), j = 0, i++;
            if(artista[i] == ' ') i++; //verifica se ha espaco apos a virgula.
        }
        
        a[j] = artista[i];
    }
    a[j] = '\0';
    strcpy(m->artista[m->quantart++], a);

    strcpy(m->album, album); //implementa album.

    //implementa compositor:
    char c[MAXTAM] = ""; //auxiliar p/ compositor + sua inicializacao.
    j = 0;
    m->quantcom = 0;
    for(int i=0; i < strlen(compositor); i++, j++) {
        if(compositor[i] == ','){
            c[j] = '\0', strcpy(m->compositor[m->quantcom++], c), j = 0, i++;
            if(compositor[i] == ' ') i++; //verifica se ha espaco apos a virgula.
        }
        c[j] = compositor[i];
    }
    c[j] = '\0';
    strcpy(m->compositor[m->quantcom++], c);

    strcpy(m->genero, genero); //implementa genero.
    strcpy(m->gravadora, gravadora); //implementa gravadora.
    m->duracao = duracao; //implementa duracao.

    return m;
}

void AtualizaMidia (Midia* m, int tipo, char *nome, char *artista, char *album, char *compositor, char *genero, char *gravadora, int duracao){
    m->tipo = tipo; //atualiza tipo.
    strcpy(m->nome, nome); //atualiza nome.

    //atualiza artista:
    char a[MAXTAM] = ""; //auxiliar p/ artista + sua inicializacao.
    int j = 0;
    m->quantart=0;
    for(int i=0; i < strlen(artista); i++, j++) {
        if(artista[i] == ','){
            a[j] = '\0', strcpy(m->artista[m->quantart++], a), j = 0, i++;
            if(artista[i] == ' ') i++; //verifica se ha espaco apos a virgula.
        }
        a[j] = artista[i];
    }
    a[j] = '\0';
    strcpy(m->artista[m->quantart++], a);

    strcpy(m->album, album); //atualiza album.
    
    //atualiza compositor:
    char c[MAXTAM] = ""; //auxiliar p/ compositor + sua inicializacao.
    j = 0;
    m->quantcom = 0;
    for(int i=0; i < strlen(compositor); i++, j++) {
        if(compositor[i] == ','){
            c[j] = '\0', strcpy(m->compositor[m->quantcom++], c), j = 0, i++;
            if(compositor[i] == ' ') i++; //verifica se ha espaco apos a virgula.
        }
        c[j] = compositor[i];
    }
    c[j] = '\0';
    strcpy(m->compositor[m->quantcom++], c);

    strcpy(m->genero, genero); //atualiza genero.
    strcpy(m->gravadora, gravadora); //atuaiza gravadora.
    m->duracao = duracao; //atualiza duracao. 
}

void ApagaMidia(Midia **minhasMidias, int posicao, int quantMidias){
    int i=0;

    for(i=posicao; i<quantMidias-1; i++){
        minhasMidias[i]=minhasMidias[i+1];
    }
    free(minhasMidias[quantMidias-1]);
}

int midiaEstaContidaNoAlbum (char *nomedoAlbum, Midia *midia, int quantMidias){
    if(strcmp(midia->album, nomedoAlbum)==0){
        return 1;
    }
    return 0;
}

void ListaMidias(Midia **minhasMidias, int quantMidias){ 
    for(int i=0; i<quantMidias; i++){
        printf("\nMidia Numero [%d]\n", i+1);
        printf("TIPO: ");
        if(minhasMidias[i]->tipo==1){
            printf("MUSICA\n");
        }
        if(minhasMidias[i]->tipo==2){
            printf("PODCAST\n");
        }
        if(minhasMidias[i]->tipo==3){
            printf("VIDEO\n");
        }
        printf("NOME: %s\n", minhasMidias[i]->nome);
        printf("ARTISTA(S): ");
        for(int j=0; j<minhasMidias[i]->quantart; j++){
            printf("%s ", minhasMidias[i]->artista[j]);
        }
        printf("\n");
        printf("ALBUM: %s\n", minhasMidias[i]->album);
        printf("COMPOSITOR(ES): ");
        for(int j=0; j<minhasMidias[i]->quantcom; j++){
            printf("%s ", minhasMidias[i]->compositor[j]);
        }
        printf("\n");
        printf("GENERO: %s\n", minhasMidias[i]->genero);
        printf("GRAVADORA: %s\n", minhasMidias[i]->gravadora);
        printf("DURACAO: %ds\n", minhasMidias[i]->duracao);
    }
}

void MostraApenasUmaMidia(Midia **minhasMidias, int i){
    printf("\nMidia Numero [%d]\n", i+1);
    printf("TIPO: ");
    if(minhasMidias[i]->tipo==1){
        printf("MUSICA\n");
    }
    if(minhasMidias[i]->tipo==2){
        printf("PODCAST\n");
    }
    if(minhasMidias[i]->tipo==3){
        printf("VIDEO\n");
    }
    printf("NOME: %s\n", minhasMidias[i]->nome);
    printf("ARTISTA(S): ");
    for(int j=0; j<minhasMidias[i]->quantart; j++){
        printf("%s ", minhasMidias[i]->artista[j]);
    }
    printf("\n");
    printf("ALBUM: %s\n", minhasMidias[i]->album);
    printf("COMPOSITOR(ES): ");
    for(int j=0; j<minhasMidias[i]->quantcom; j++){
        printf("%s ", minhasMidias[i]->compositor[j]);
    }
    printf("\n");
    printf("GENERO: %s\n", minhasMidias[i]->genero);
    printf("GRAVADORA: %s\n", minhasMidias[i]->gravadora);
    printf("DURACAO: %ds\n", minhasMidias[i]->duracao);
}

void PesquisaMidia(int categoria, Midia **minhasMidias, int quantMidias){
    char pesquisa[50];
    int i, j;

    if (categoria==1){ //NOME
        printf("Digite o nome pelo qual deseja pesquisar: \n");
        gets(pesquisa);
        printf("\nMIDIAS ENCONTRADAS:\n");
        for(i=0; i<quantMidias; i++){
            if(strcmp(pesquisa, minhasMidias[i]->nome)==0){
                MostraApenasUmaMidia(minhasMidias, i);
            }
        }
    }

    if (categoria==2){ //ARTISTA
        printf("Digite o(a) artista pelo(a) qual deseja pesquisar: \n");
        gets(pesquisa);
        printf("\nMIDIAS ENCONTRADAS:\n");
        for(i=0; i<quantMidias; i++){
            for(j=0; j<3; j++){
                if(strcmp(pesquisa, minhasMidias[i]->artista[j])==0){
                    MostraApenasUmaMidia(minhasMidias, i);
                }
            }
        }
    }

    if (categoria==3){ //ALBUM
        printf("Digite o album pelo qual deseja pesquisar: \n");
        gets(pesquisa);
        printf("\nMIDIAS ENCONTRADAS:\n");
        for(i=0; i<quantMidias; i++){
            if(strcmp(pesquisa, minhasMidias[i]->album)==0){
                MostraApenasUmaMidia(minhasMidias, i);
            }
        }
    }

    if (categoria==4){ //COMPOSITOR
        printf("Digite o(a) compositor(a) pelo(a) qual deseja pesquisar: \n");
        gets(pesquisa);
        printf("\nMIDIAS ENCONTRADAS:\n");
        for(i=0; i<quantMidias; i++){
            for(j=0; j<3; j++){
                if(strcmp(pesquisa, minhasMidias[i]->compositor[j])==0){
                    MostraApenasUmaMidia(minhasMidias, i);
                }
            }
        }
    }

    if (categoria==5){ //GENERO
        printf("Digite o genero pelo qual deseja pesquisar: \n");
        gets(pesquisa);
        printf("\nMIDIAS ENCONTRADAS:\n");
        for(i=0; i<quantMidias; i++){
            if(strcmp(pesquisa, minhasMidias[i]->genero)==0){
                MostraApenasUmaMidia(minhasMidias, i);
            }
        }
    }

    if (categoria==6){ //GRAVADORA
        printf("Digite a gravadora pelo(a) qual deseja pesquisar: \n");
        gets(pesquisa);
        printf("\nMIDIAS ENCONTRADAS:\n");
        for(i=0; i<quantMidias; i++){
            if(strcmp(pesquisa, minhasMidias[i]->gravadora)==0){
                MostraApenasUmaMidia(minhasMidias, i);
            }
        }
    }

    printf("\nFim da pesquisa. Retornando ao Menu Principal...\n");
}

char* pegaNomeEArtistaDaMidia(Midia **minhasMidias, int num){
    char *aux = malloc(50*sizeof(char));

    strcpy(aux, minhasMidias[num]->nome);
    strcat(aux, " - ");
    strcat(aux, minhasMidias[num]->artista[0]);

    return aux;    
}

void SalvarMidias(FILE *arquivo, Midia **minhasMidias, int quantMidias){
    int i, j;

    fprintf(arquivo, "%d\n", quantMidias);
    for(i=0; i<quantMidias; i++){
        fprintf(arquivo, "%d\n", minhasMidias[i]->tipo);
        fprintf(arquivo, "%s\n", minhasMidias[i]->nome);
        fprintf(arquivo, "%d\n", minhasMidias[i]->quantart);
        for(j=0; j<minhasMidias[i]->quantart; j++){
            fprintf(arquivo, "%s\n", minhasMidias[i]->artista[j]);
        }
        fprintf(arquivo, "%s\n", minhasMidias[i]->album);
        fprintf(arquivo, "%d\n", minhasMidias[i]->quantcom);
        for(j=0; j<minhasMidias[i]->quantcom; j++){
            fprintf(arquivo, "%s\n", minhasMidias[i]->compositor[j]);
        }
        fprintf(arquivo, "%s\n", minhasMidias[i]->genero);
        fprintf(arquivo, "%s\n", minhasMidias[i]->gravadora);
        fprintf(arquivo, "%d\n", minhasMidias[i]->duracao);
    }
}

void CarregarMidias(FILE *arquivo, Midia **minhasMidias, int quantMidias){
    int i, j;

    fscanf(arquivo, "%d\n", &quantMidias);
    for(i=0; i<quantMidias; i++){
        fscanf(arquivo, "%d\n", &minhasMidias[i]->tipo);
        fscanf(arquivo, "%s\n", minhasMidias[i]->nome);
        fscanf(arquivo, "%d\n", &minhasMidias[i]->quantart);
        for(j=0; j<minhasMidias[i]->quantart; j++){
            fscanf(arquivo, "%s\n", minhasMidias[i]->artista[j]);
        }
        fscanf(arquivo, "%s\n", minhasMidias[i]->album);
        fscanf(arquivo, "%d\n", &minhasMidias[i]->quantcom);
        for(j=0; j<minhasMidias[i]->quantcom; j++){
            fscanf(arquivo, "%s\n", minhasMidias[i]->compositor[j]);
        }
        fscanf(arquivo, "%s\n", minhasMidias[i]->genero);
        fscanf(arquivo, "%s\n", minhasMidias[i]->gravadora);
        fscanf(arquivo, "%d\n", &minhasMidias[i]->duracao);
    }
}


