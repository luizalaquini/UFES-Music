//TAD PARA COMUNICACAO DO PROGRAMA COM O USUARIO.
#ifndef _TEXTO
#define _TEXTO

void bemvindo(); //Primeira mensagem. Da inicio ao programa.

void menuPrincipal(); //Menu Principal.

void menuMidia(); //Menu de acoes que se aplicam as midias.

void menuAlbum(); //Menu de acoes que se aplicam aos albuns.

void menuPlaylist(); //Menu de acoes que se aplicam as playlists.

void menuPesquisaMidia(); //Menu de categorias para que se possa pesquisar por midia.

void menuEditarPlaylist(); //Menu de possiveis edicoes nas Playlists.

void PedeTipo(); //Pede tipo da midia;

void PedeNome(); //Pede nome da midia/ do album/ da playlist.

void PedeArtista(); //Pede artistas da midia (MAX: 3).

void PedeAlbum(); //Pede nome do Album a qual a midia pertence.

void PedeCompositor(); //Pede compositores da midia (MAX: 3).

void PedeGenero(); //Pede genero da midia.

void PedeGravadora(); //Pede gravadora da midia.

void PedeDuracao(); //Pede duracao da midia em segundos.

void PedeUsuario(); //Pede usuarios da playlist.

void PedeMidias(); //Pede numeros das midias a serem adicionadas em uma playlist.

#endif /*_TEXTO*/
