#ifndef _PLAYLIST
#define _PLAYLIST

//Tipo Playlist.
typedef struct playlist Playlist;

/*Inicializa uma nova playlist
* inputs: infos da playlist (nome, usuarios aos quais pertence)
* output: ponteiro para a playlist inicializada
* pre-condicao: -
* pos-condicao: playlist de retorno existe 
*/
Playlist* CriaPlaylist(char *nome, char *usuario);

/*Atualiza uma playlist existente
* inputs: ponteiro pra playlist a ser atualizada + infos (nome, usuarios aos quais pertence)
* output: -
* pre-condicao: playlist deve existir
* pos-condicao: playlist atualizada 
*/
void AtualizaPlaylist (Playlist *p, char *nome, char *usuario);

/*Apaga uma playlist existente
* inputs: ponteiro pro vetor de playlists existentes, inteiro para posicao da playlist no vetor, inteiro para o total de playlists existentes
* output: -
* pre-condicao: playlist deve existir
* pos-condicao: playlist nao existe 
*/
void ApagaPlaylist(Playlist **minhasPlaylists, int posicao, int quantPlaylists);

/*Exibe playlists armazenadas
* inputs: ponteiro pro vetor de playlists, inteiro para o total de plpaylists 
* output: playlists e suas informacoes
* pre-condicao: pelo menos uma playlist deve existir
* pos-condicao: -
*/
void ListaPlaylists(Playlist **minhasPlaylists, int quantPlaylists);

/*Adiciona midia na playlist
* inputs: ponteiro para vetor de albuns, inteiro para posicao da playlist no vetor, ponteiro para string com o nome da midia
* output: -
* pre-condicao: Playlist deve existir, Midia a ser adicionada deve existir
* pos-condicao: Playlist contem a midia
*/
void AdicionaMidiaNaPlaylist(Playlist **minhasPlaylists, int editar, char *midia);

//GUARDAR INFORMACOES DESSE TAD
void SalvarPlaylists(FILE *arquivo, Playlist **minhasPlaylists, int quantPlaylists);

//CARREGAR INFORMACOES DESSE TAD
void CarregarPlaylists(FILE *arquivo, Playlist **minhasPlaylists, int quantPlaylists);

#endif /*_PLAYLIST*/