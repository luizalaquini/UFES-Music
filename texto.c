//Inclusao das bibliotecas necessarias.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "texto.h"

//DEFINICAO DAS FUNCOES EM "texto.h"

void bemvindo(){
    printf("\nBem-vindo ao UFES Music! O mais recente servico de streamming de musica, podcast e video.\n");
}

void menuPrincipal(){
    printf("\n");
    printf("|---------------------------------------------------------|\n");
    printf("|                     MENU PRINCIPAL                      |\n");
    printf("|---------------------------------------------------------|\n");
    printf("| Escolha um dos itens a seguir para ver opcoes avancadas |\n");
    printf("|---------------------------------------------------------|\n");
    printf("|     MIDIAS(1)    |     ALBUNS(2)    |    PLAYLISTS(3)   |\n");
    printf("|---------------------------------------------------------|\n");
    printf("\nSua escolha: ");
}

void menuMidia(){
    printf("\n");
    printf("|---------------------|\n");
    printf("|     MENU MIDIAS     |\n");
    printf("|---------------------|\n");
    printf("| Adicionar Midia (1) |\n");
    printf("| Atualizar Midia (2) |\n");
    printf("|   Apagar Midia (3)  |\n");
    printf("|  Listar Midias (4)  |\n");
    printf("| Pesquisar Midia (5) |\n");
    printf("|---------------------|\n");
    printf("\nSua escolha: ");
}

void menuAlbum(){
    printf("\n");
    printf("|---------------------|\n");
    printf("|     MENU ALBUNS     |\n");
    printf("|---------------------|\n");
    printf("|  Listar Albuns (1)  |\n");
    printf("|   Apagar Album (2)  |\n");
    printf("|---------------------|\n");
    printf("\nSua escolha: ");
}

void menuPlaylist(){
    printf("\n");
    printf("|------------------------|\n");
    printf("|     MENU PLAYLISTS     |\n");
    printf("|------------------------|\n");
    printf("| Adicionar Playlist (1) |\n");
    printf("|   Editar Playlist (2)  |\n");
    printf("|   Apagar Playlist (3)  |\n");
    printf("|  Listar Playlists (4)  |\n");
    printf("|------------------------|\n");
    printf("\nSua escolha: ");
}

void menuPesquisaMidia(){
    printf("\n");
    printf("|---------------------------------|\n");
    printf("|        Pesquisar Midias         |\n");
    printf("|---------------------------------|\n");
    printf("| Escolha por qual categoria voce |\n");
    printf("|   deseja pesquisar uma midia    |\n");
    printf("|---------------------------------|\n");
    printf("|             Nome (1)            |\n");
    printf("|           Artista (2)           |\n");
    printf("|            Album (3)            |\n");
    printf("|          Compositor (4)         |\n");
    printf("|            Genero (5)           |\n");
    printf("|          Gravadora (6)          |\n");
    printf("|---------------------------------|\n");
    printf("\nSua escolha: ");
}

void menuEditarPlaylist(){
    printf("\n");
    printf("|-----------------------|\n");
    printf("|    Editar Playlist    |\n");
    printf("|-----------------------|\n");
    printf("|   Atualizar Nome (1)  |\n");
    printf("|  Adicionar Midias (2) |\n");
    printf("|   Remover Midias (3)  |\n");
    printf("|-----------------------|\n");
    printf("\nSua escolha: ");
}

void PedeTipo(){
    printf("Qual sera o tipo da sua midia?\nMusica(digite 1), Podcast(digite 2) ou Video(digite 3): ");
}

void PedeNome(){
    printf("Nome: ");
}

void PedeArtista(){
    printf("Artista - Caso tenha mais de um, separe os nomes por virgulas: ");
}

void PedeAlbum(){
    printf("Album a qual pertence: ");
}

void PedeCompositor(){
    printf("Compositor - Caso tenha mais de um, separe os nomes por virgulas: ");
}

void PedeGenero(){
    printf("Genero: ");
}

void PedeGravadora(){
    printf("Gravadora: ");
}

void PedeDuracao(){
    printf("Duracao (em segundos) - apenas numeros: ");
}

void PedeUsuario(){
    printf("Usuario - Caso tenha mais de um, separe os nomes por virgulas: ");
}

void PedeMidias(){
    printf("Adicione Midias a sua playist (Max: 50 midias).\n");
    printf("Para cada midia a ser adicionada, digite seu numero e pressione 'ENTER'. Para finalizar, digite 0 (zero).\n");
}
    


