#ifndef _ALBUM
#define _ALBUM

//Tipo Album.
typedef struct album Album;

/*Inicializa um novo album
* inputs: nome do album
* output: ponteiro para o album inicializado
* pre-condicao: -
* pos-condicao: album de retorno existe 
*/
Album* CriaAlbum(char *nomeDoAlbum, char *midia);

/*Insere midias em album
* inputs: ponteiro pro album, string com midia a ser adicionada
* output: -
* pre-condicao: album deve existir
* pos-condicao: album atualizado 
*/
void AtualizaAlbum (Album *a, char *midia);

/*Apaga um album existente
* inputs: ponteiro para vetor de albuns, inteiro para posicao do album no vetor, inteiro para quantidade total de albuns
* output: -
* pre-condicao: album deve existir
* pos-condicao: album nao existe 
*/
void ApagaAlbum(Album **meusAlbuns, int posicao, int quantAlbuns);

/*Retorna nome do Album
* inputs: ponteiro para vetor de albuns, inteiro para posicao do album no vetor
* output: -
* pre-condicao: album deve existir
* pos-condicao: -
*/
char* retornaNomeDoAlbum(Album **meusAlbuns, int posicao);

/*Exibe albuns armazenados
* inputs: ponteiro pro vetor de albuns, inteiro para a quantidade total de albuns
* output: albuns e suas informacoes
* pre-condicao: pelo menos um album deve existir
* pos-condicao: -
*/
void ListaAlbuns(Album **meusAlbuns, int quantAlbuns);

/*Verifica se determinado album ja existe
* inputs: ponteiro para string com nome do album ponteiro para vetor de albuns, inteiro para quantidade total de albuns
* output: 1(Album existe) ou 0(Album nao existe)
* pre-condicao: -
* pos-condicao: -
*/
int verificaSeAlbumExiste (char *nome, Album **meusAlbuns, int quantAlbuns);

/*Retorna album existente
* inputs: ponteiro para vetor de albuns, inteiro para quantidade total de albuns, ponteiro pra string com nome do album
* output: retorno do album
* pre-condicao: album deve existir
* pos-condicao: -
*/
Album* retornaAlbum (Album **meusAlbuns, int quantAlbuns, char *nomeDoAlbum);

//GUARDAR INFORMACOES DESSE TAD
void SalvarAlbuns(FILE *arquivo, Album **meusAlbuns, int quantAlbuns);

//CARREGAR INFORMACOES DESSE TAD
void CarregarAlbuns(FILE *arquivo, Album **meusAlbuns, int quantAlbuns);

#endif /*_ALBUM*/