Projeto de TP2 para Computação Gráfica - Sistema Solar

	Docente: Glender Brás
	Discentes: Filipe Bicalho, Maria Eduarda, Matheus Thiago e Thiago Freitas

Comandos:
    Mouse - Movimenta a perspectiva da câmera
    Tecla V - Ativa/Desativa o rastro de orbita
    Tecla F - Ativa/Desativa a fonte de luz
    Tecla E - Aumenta/Diminui o tamanho dos planetas
    Teclas 1 e 2 - Muda o modo de câmera (1 - Modo Livre | 2 Modo Fixo)
    Teclas W,S,A e D - Movimenta a câmera no Modo Livre


Bibliotecas Utilizadas:

	SDL, SDL_image, SDL_mixer: 
		sudo apt-get install libsdl1.2-dev libsdl-image1.2-dev libsdl-mixer1.2-dev libsdl-ttf2.0-dev 
	SOIL: 
		sudo apt-get install libsoil-dev
    Freeglut: 
		sudo apt-get install freeglut3-dev


linhas de compilação e Execução:

	---- Manual ----
		gcc SistemaSolar.c -o solar -lGL -lGLU -lglut -lSOIL -lSDL -lSDLmain -lSDL_image -lSDL_mixer -lm
		./solar

	---- MakeFile ----
		make install-libraries  - Instalar as bibliotecas utilizadas
		make all				- Compilar o projeto
		make run				- Executar o projeto já compilado
		make clean				- Remove o arquivo compilado

Recursos Implementados:

        Sol e Planeta - Sistema com Objeto no centro e os outros orbitando ao seu redor
        Câmeras - Duas visões diferentes que podem ser alternadas pelas teclas '1' ou '2'
        Fonte de Luz - Fonte de Luz a partir do Sol e que pode ser ativada/desativada pela tecla 'f'
        Skybox - Tudo ocorre de um recipiente que simula o que há distante do sistema solar e sua perspectiva muda de a cordo com o movimento do mouse
        Orbitas Visiveis - Pela tecla 'v' é possivel ativar/destivar a trajetoria dos planetas
        Reshape - É possivel redimensionar o tamanho da janela sem achatar os objetos
        Redimensionamento dos Objetos - É possivel aumentar/diminuir o tamanho dos planetas através da tecla 'e', alterando a escala, sendo uma mais fiel ao tamanho em relação ao Sol e outra mais facil de se ver
        Movimento de Câmera - É possivel se movimentar a câmera através das teclas 'w', 's', 'a' e 'd'
        Musica de Fundo - Embarque nessa viagem ouvindo uma boa musica

Video de Demonstração:

    https://youtu.be/0CxvImeWSNA
