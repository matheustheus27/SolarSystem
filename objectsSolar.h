//Estruturas
typedef struct{
	float Translacao;
	float Rotacao;
	int Faces;
	int TamanhoTranslacao;
	GLuint Texture;
	bool Estado;
}Corpo;

typedef struct{
	int X;
	int Y;
	int Z;
}EixoINT;

typedef struct{
	float X;
	float Y;
	float Z;
}EixoFLOAT;

typedef struct{
	float Largura;
	float Altura;
}Janela;

//Variaveis dos Corpos
Corpo sun;
Corpo mercury;
Corpo venus;
Corpo earth;
Corpo mars;
Corpo jupiter;
Corpo uranus;
Corpo neptune;
Corpo saturn;
Corpo space;

//Variaveis de Luz
float difusa;
float especular;
float posicional;
float global;
float matrizAD[] = {1.0, 1.0, 1.0, 1.0};
float matrizEspecular[] = {1.0, 1.0, 1,0, 1.0};
float matrizBrilho[] = {50};
EixoFLOAT luzBranca;

 
//Variaveis de Controle
int horizonteEventos = 1;//Espaço Visivel
EixoINT cursor;
EixoINT mouse;
Janela janela;
bool podeBrilhar = true;
bool podeOrbitar = false;

//Variaveis da Camera
int modoCamera = 1;
float anguloCameraA = 90;
float anguloCameraB = 0;
EixoFLOAT camera;

//Variaveis de Musica
Mix_Chunk *startingOdyssey;

