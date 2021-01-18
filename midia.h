#ifndef _MIDIA
#define _MIDIA

//Tipo Midia.
typedef struct midia Midia; 

/*Inicializa uma nova midia
* inputs: infos da midia (tipo, nome, artistas, albums, compositores, genero, gravadora, duracao)
* output: ponteiro para a midia inicializada
* pre-condicao: -
* pos-condicao: midia de retorno existe 
*/
Midia* CriaMidia (int tipo, char *nome, char *artista, char *album, char *compositor, char *genero, char *gravadora, int duracao);

/*Atualiza uma midia existente
* inputs: ponteiro pra midia a ser atualizada + infos (tipo, nome, artistas, albums, compositores, genero, gravadora, duracao)
* output: -
* pre-condicao: midia deve existir
* pos-condicao: midia atualizada 
*/
void AtualizaMidia (Midia* m, int tipo, char *nome, char *artista, char *album, char *compositor, char *genero, char *gravadora, int duracao);

/*Apaga uma midia existente
* inputs: ponteiro pras midias, indice da midia a ser apagada, quantidade total de midias 
* output: -
* pre-condicao: midia deve existir
* pos-condicao: midia nao existe 
*/
void ApagaMidia(Midia **minhasMidias, int posicao, int quantMidias);

/*Informa se uma midia especifica esta contida em um album especifico 
* inputs: ponteiro pra string com nome do album, ponteiro pra midia especifica, inteiro para quantidade total de midias
* output: 1(Esta contida) ou 0(Nao esta contida)
* pre-condicao: Midia e Album devem existir
* pos-condicao: -
*/
int midiaEstaContidaNoAlbum (char *nomedoAlbum, Midia *midia, int quantMidias);

/*Exibe midias armazenadas
* inputs: ponteiro pro vetor de midias, inteiro pra quantidade de midias existentes
* output: midias e suas informacoes
* pre-condicao: pelo menos uma midia deve existir
* pos-condicao: -
*/
void ListaMidias(Midia **minhasMidias, int quantMidias);

/*Exibe uma midia especifica (CRIADA PARA AUXILIAR NA PESQUISA DE MIDIAS)
* inputs: ponteiro pro vetor de midias, indice da midia especifica
* output: midia e suas informacoes
* pre-condicao: a midia deve existir
* pos-condicao: -
*/
void MostraApenasUmaMidia(Midia **minhasMidias, int i);

/*Exibe midias referentes a pesquisa do usuario
* inputs: categoria da pesquisa (nome, artista, etc), ponteiro pro vetor de midias, inteiro pra quantidade de midias existentes
* output: midias correspondentes a pesquisa 
* pre-condicao: pelo menos uma midia deve existir
* pos-condicao: -
*/
void PesquisaMidia(int categoria, Midia **minhasMidias, int quantMidias);

/*Copia Nome da Midia e seu primeiro artista para uma string unica que ira receber a funcao.
* inputs:ponteiro para vetor de midias existentes, inteiro para indice de uma midia especifica.
* output: -
* pre-condicao: midia deve existir
* pos-condicao: existe string com a informacao passada pela funcao
*/
char* pegaNomeEArtistaDaMidia(Midia **minhasMidias, int num);

//GUARDAR INFORMACOES DESSE TAD
void SalvarMidias(FILE *arquivo, Midia **minhasMidias, int quantMidias);

//CARREGAR INFORMACOES DESSE TAD
void CarregarMidias(FILE *arquivo, Midia **minhasMidias, int quantMidias);

#endif /*_MIDIA*/