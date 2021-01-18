//Inclusao das bibliotecas necessarias.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "texto.h"
#include "midia.h"
#include "album.h"
#include "playlist.h"

//Definicoes de constantes para facilitar a leitura do codigo.
#define MAXTAM 50

int main(){
    FILE * arquivo;

    int decisao, loop=0;
    Midia *minhasMidias[200];
    Album *meusAlbuns[15]; 
    Playlist *minhasPlaylists[15];
    int quantMidias=0, quantAlbuns=0, quantPlaylists=0;
    char aux[MAXTAM];

    arquivo = fopen(arquivo, "r");
    if(arquivo == NULL){
        printf("\nNao foi possivel carregar arquivo\n");
    }
    else{
        printf("\nArquivo carregado\n");
        CarregarMidias(arquivo, minhasMidias, quantMidias);
        CarregarAlbuns(arquivo, meusAlbuns, quantAlbuns);
        CarregarPlaylists(arquivo, minhasPlaylists, quantPlaylists);
    }

    bemvindo();

    while(loop==0){ //Deixa o programa em loop. Para sair pressione CTRL+C
        int novadecisao;

        menuPrincipal();
        scanf("%d", &decisao);

        while(decisao>3 || decisao<1){ //caso entre com o numero errado
            printf("\nNao e possivel prosseguir. Tente novamente: ");
            scanf("%d", &decisao);
        }

        if(decisao == 1){ //MIDIAS

            menuMidia();
            scanf("%d", &novadecisao);

            while(novadecisao>5 || novadecisao<1){ //caso entre com o numero errado
            printf("\nNao e possivel prosseguir. Tente novamente: ");
            scanf("%d", &novadecisao);
            }

            if(novadecisao == 1){ //ADICIONAR MIDIA 
                int tip, dur;
                char nom[MAXTAM], art[4*MAXTAM], alb[50], com[4*MAXTAM], gen[MAXTAM], gra[MAXTAM];

                printf("Para adicionar uma midia, preencha seus dados a seguir.\n");
                PedeTipo();
                scanf("%d", &tip);
                scanf("%*c");
                printf("\n");
                PedeNome();
                gets(nom);
                PedeArtista();
                gets(art);
                PedeAlbum();
                gets(alb);
                PedeCompositor();
                gets(com);
                PedeGenero();
                gets(gen);
                PedeGravadora();
                gets(gra);
                PedeDuracao();
                scanf("%d", &dur);
               
                minhasMidias[quantMidias] = CriaMidia (tip, nom, art, alb, com, gen, gra, dur);

                quantMidias+=1;

                if (!verificaSeAlbumExiste (alb, meusAlbuns, quantAlbuns)){ //Cria Album caso ainda nao exista
                    meusAlbuns[quantAlbuns] = CriaAlbum (alb, nom);
                    quantAlbuns++;
                }
                else{ //Adiciona midia em Album existente
                    AtualizaAlbum(retornaAlbum(meusAlbuns, quantAlbuns, alb), nom); 
                }

                printf("\nMidia adicionada com sucesso! Retornando ao menu...\n");
            }

            if(novadecisao==2){ //ATUALIZAR MIDIA
                int tip, dur, num;
                char nom[MAXTAM], art[4*MAXTAM], alb[50], com[4*MAXTAM], gen[MAXTAM], gra[MAXTAM];

                if(quantMidias<1){ //Se nao houver midias.
                    printf("\nNao ha midias para atualizar. Retornando ao menu...\n");
                }

                else {
                    printf("Para atualizar uma midia, informe seu numero: ");

                    scanf("%d", &num);

                    while (num>quantMidias || num<1){ //caso entre com o numero errado
                        printf("\nNao foi possivel acessar essa midia. Tente outra: ");
                        scanf("%d", &num);
                    }

                    PedeTipo();
                    scanf("%d", &tip);
                    scanf("%*c");
                    printf("\n");
                    PedeNome();
                    gets(nom);
                    PedeArtista();
                    gets(art);
                    PedeAlbum();
                    gets(alb);
                    PedeCompositor();
                    gets(com);
                    PedeGenero();
                    gets(gen);
                    PedeGravadora();
                    gets(gra);
                    PedeDuracao();
                    scanf("%d", &dur);

                    AtualizaMidia (minhasMidias[num-1], tip, nom, art, alb, com, gen, gra, dur);

                    printf("\nMidia atualizada com sucesso! Retornando ao menu...\n");
                }
            }

            if(novadecisao == 3){ //APAGAR MIDIA 
                int num;

                if(quantMidias<1){ //Se nao houver midias.
                    printf("\nNao ha midias para apagar. Retornando ao menu...\n");
                }

                else {
                    printf("\nDigite o numero da midia que deseja apagar: ");
                    scanf("%d", &num);
                    while (num>quantMidias || num<0){ //caso entre com o numero errado
                        printf("\nNao foi possivel apagar essa midia. Tente outra: ");
                        scanf("%d", &num);
                    }
                    ApagaMidia(minhasMidias, num-1, quantMidias);
                    quantMidias--;
                    printf("\nMidia apagada com sucesso. Retornando ao menu...\n");
                }
            }

            if(novadecisao == 4){ //LISTAR MIDIAS
                if(quantMidias<1){ //Se nao houver midias.
                    printf("\nNao ha midias. Retornando ao menu...\n");
                }
                else{
                    ListaMidias(minhasMidias, quantMidias);
                }
            }

            if(novadecisao==5){ //PESQUISA MIDIA
                int categoria;

                if(quantMidias<1){ //Se nao houver midias.
                    printf("\nNao ha midias para pesquisar. Retornando ao menu...\n");
                }

                else{
                    menuPesquisaMidia();
                    scanf("%d", &categoria);
                    scanf("%*c");

                    PesquisaMidia (categoria, minhasMidias, quantMidias);
                }
            }
        }

        if(decisao == 2){ //ALBUNS

            menuAlbum();
            scanf("%d", &novadecisao);

            while(novadecisao>2 || novadecisao<1){ //caso entre com o numero errado
            printf("\nNao e possivel prosseguir. Tente novamente: ");
            scanf("%d", &novadecisao);
            }

            if(novadecisao==1){ //LISTAR ALBUNS
                if(quantAlbuns<1){ //Se nao houver albuns.
                    printf("\nNao ha albuns. Retornando ao menu...\n");
                }
                else{
                    ListaAlbuns(meusAlbuns, quantAlbuns);
                }
            }

            if(novadecisao==2){ //APAGAR ALBUM 

                printf("\nATENCAO!!! Apagar um Album tambem apagara todas as midias contidas nele.\n");
               
                if(quantAlbuns<1){ //Se nao houver albuns.
                    printf("\nNao ha albuns para apagar. Retornando ao menu...\n");
                }
                else{
                    int num;
                    char *nomedoAlbum;

                    printf("\nDigite o numero do album que deseja apagar: ");
                    scanf("%d", &num);
                    while (num>quantAlbuns || num<0){
                        printf("\nNao foi possivel apagar esse album. Tente outro: ");
                        scanf("%d", &num);
                    }
                    ApagaAlbum(meusAlbuns, num-1, quantAlbuns);
                    quantAlbuns--;
                    nomedoAlbum = retornaNomeDoAlbum(meusAlbuns, num-1);
                    for(int i=0; i<quantMidias; i++){ //apagar midias pertencentes ao album apagado
                        if(midiaEstaContidaNoAlbum(nomedoAlbum, minhasMidias[i], quantMidias)){
                            ApagaMidia(minhasMidias, i, quantMidias);
                            quantMidias--;
                        }
                    }
                    printf("\nAlbum apagado com sucesso. Retornando ao menu...\n");
                }
            }
        }

        if (decisao == 3){ //PLAYLISTS

            menuPlaylist();
            scanf("%d", &novadecisao);

            while(novadecisao>4 || novadecisao<1){ //caso entre com o numero errado
            printf("\nNao e possivel prosseguir. Tente novamente: ");
            scanf("%d", &novadecisao);
            }

            if(novadecisao==1){ //CRIAR PLAYLIST
                char nome[MAXTAM], usu[3*MAXTAM];
                int mid;

                printf("\nPara adicionar uma playlist, preencha seus dados a seguir.\n");
                scanf("%*c");
                printf("\n");
                PedeNome();
                gets(nome);
                PedeUsuario();
                gets(usu);

                minhasPlaylists[quantPlaylists] = CriaPlaylist (nome, usu);
                quantPlaylists++;

                printf("\nPlaylist adicionada com sucesso! Retornando ao menu...\n");
            }

            if(novadecisao==2){ //EDITAR PLAYLIST

                if(quantPlaylists<1){ //Se nao houver Playlists.
                    printf("\nNao ha playlists para editar. Retornando ao menu...\n");
                }

                else{
                    int editar, outradecisao;

                    scanf("%*c");
                    printf("\nDigite o numero da Playlist que deseja editar: ");
                    scanf("%d", &editar);
                    while (editar>quantPlaylists || editar<1){ //caso entre com o numero errado
                        printf("\nNao foi possivel acessar essa playlist. Tente outra: ");
                        scanf("%d", &editar);
                    }
                    editar=editar-1;
                    menuEditarPlaylist();
                    scanf("%d", &outradecisao);
                    while (outradecisao>2 || outradecisao<1){ //caso entre com o numero errado
                        printf("\nNao foi possivel completar essa acao. Tente novamente: ");
                        scanf("%d", &outradecisao);
                    }

                    if(outradecisao==1){ //ATUALIZAR NOME
                        char nome[MAXTAM], usu[3*MAXTAM];

                        printf("\n");
                        scanf("%*c");
                        PedeNome();
                        gets(nome);
                        PedeUsuario();
                        gets(usu);

                        AtualizaPlaylist(minhasPlaylists[editar], nome, usu);
                    }

                    if(outradecisao==2){ //ADICIONAR MIDIAS
                        int numDaMidia;
                        char *nomEart;

                        printf("Digite o numero da midia que deseja adicionar a playlist e pressione 'ENTER'.\n");
                        printf("Para parar de adicionar midias digite '0'(zero).\n");
                        printf("Atencao! Maximo de 50 midias na playlist!\n");
                        while(numDaMidia!=0){
                            scanf("%d", &numDaMidia);
                            if(numDaMidia!=0){
                                nomEart = pegaNomeEArtistaDaMidia(minhasMidias, numDaMidia-1);
                                AdicionaMidiaNaPlaylist(minhasPlaylists, editar, nomEart);
                            }
                        }
                    }
                    printf("\nPlaylist editada com sucesso! Retornando ao menu...\n");
                }
            }

            if(novadecisao==3){ //APAGAR PLAYLIST
                int num;

                if(quantPlaylists<1){ //Se nao houver Playlists.
                    printf("\nNao ha playlists para apagar. Retornando ao menu...\n");
                }
                else{
                    printf("\nDigite o numero da playlist que deseja apagar: ");
                    scanf("%d", &num);
                    while (num>quantPlaylists || num<0){ //caso entre com o numero errado
                        printf("\nNao foi possivel apagar essa playlist. Tente outra: ");
                        scanf("%d", &num);
                    }
                    ApagaPlaylist(minhasPlaylists, num-1, quantPlaylists);
                    quantPlaylists--;
                    printf("\nPlaylist apagada com sucesso. Retornando ao menu...\n");
                }
            }

            if(novadecisao==4){ //LISTAR PLAYLISTS
                if(quantPlaylists<1){ //Se nao houver Playlists.
                    printf("\nNao ha playlists. Retornando ao menu...\n");
                }
                else{
                    ListaPlaylists(minhasPlaylists, quantPlaylists);
                }
            }
        }
    }

    arquivo = fopen(arquivo, "w");
    if(arquivo==NULL){
        printf("\nNao foi possivel carregar arquivo\n");
    }
    else{
        SalvarMidias(arquivo, minhasMidias, quantMidias);
        SalvarAlbuns(arquivo, meusAlbuns, quantAlbuns);
        SalvarPlaylists(arquivo, minhasPlaylists, quantPlaylists);
    }

    return 0;
}