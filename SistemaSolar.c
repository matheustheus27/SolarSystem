#include <SDL/SDL.h>
#include "SDL/SDL_opengl.h"
#include "SDL/SDL_image.h"
#include <SDL/SDL_mixer.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <SOIL/SOIL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>
#include <math.h>
#include "objectsSolar.h"

//---------------------------------------------------- Carregamento de Texturas ------------------------------------------------------------
GLuint carregaTextura(const char* arquivo) {
  GLuint idTextura = SOIL_load_OGL_texture(
                     arquivo,
                     SOIL_LOAD_AUTO,
                     SOIL_CREATE_NEW_ID,
                     SOIL_FLAG_INVERT_Y
                    );

  if (idTextura == 0) {
    printf("Erro do SOIL: '%s' - '%s'\n", arquivo, SOIL_last_result());
  }

  return idTextura;
} 

//---------------------------------------------------- Renderização ------------------------------------------------------------
void criaSphere(float radius, int stacks, int columns){
    GLUquadric* quadObj = gluNewQuadric();
    gluQuadricDrawStyle(quadObj, GLU_FILL);
    gluQuadricNormals(quadObj, GLU_SMOOTH);
    gluQuadricTexture(quadObj, GL_TRUE);
    gluSphere(quadObj, radius, stacks, columns);
    gluDeleteQuadric(quadObj);
}
void renderizaAstroRei(){
	glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, sun.Texture);
    	glPushMatrix();
	        glRotatef(sun.Translacao, 0, 1, 0);
	        glRotatef(90, 1, 0, 0);
	        criaSphere(100 , sun.Faces, sun.Faces);
   		 glPopMatrix();
	glDisable(GL_TEXTURE_2D);
}
void renderizaCorpos(){
	glEnable(GL_TEXTURE_2D);
		//Espaço
		glBindTexture(GL_TEXTURE_2D, space.Texture);
	    glPushMatrix();
	        glTranslatef(cursor.X, cursor.Y, cursor.Z); 
	        criaSphere(7000, sun.Faces, sun.Faces);
	    glPopMatrix();
	    /*Corpos Celestes*/
		//Mercurio
		glBindTexture(GL_TEXTURE_2D, mercury.Texture);
		glPushMatrix();
	        glRotatef(mercury.Translacao, 0, 1, 0);
	        glTranslatef(mercury.TamanhoTranslacao, 0.0, 0);
	        glRotatef(mercury.Rotacao, 0, 1, 0);
	        glRotatef(97, 1, 0, 0); 
	        criaSphere(0.5 * horizonteEventos, mercury.Faces, mercury.Faces);
	    glPopMatrix();
	    //Venus
	    glBindTexture(GL_TEXTURE_2D, venus.Texture);   
	    glPushMatrix();
	        glRotatef(venus.Translacao, 0, 1, 0);
	        glTranslatef(venus.TamanhoTranslacao, 0.0, 0);
	        glRotatef(venus.Rotacao, 0, 1, 0);
	        glRotatef(-267, 1, 0, 0);        
	        criaSphere(0.95 * horizonteEventos, venus.Faces, venus.Faces);
	    glPopMatrix();
	    //Terra
	    glBindTexture(GL_TEXTURE_2D, earth.Texture);   
	    glPushMatrix();
	        glRotatef(earth.Translacao, 0, 1, 0);
	        glTranslatef(earth.TamanhoTranslacao, 0.0, 0);
	        glRotatef(earth.Rotacao, 0, 1, 0);
	        glRotatef(-133.5, 1, 0, 0);        
	        criaSphere(1 * horizonteEventos, earth.Faces, earth.Faces);
	    glPopMatrix();
	    //Marte
	    glBindTexture(GL_TEXTURE_2D, mars.Texture);   
	    glPushMatrix();
	        glRotatef(mars.Translacao, 0, 1, 0);
	        glTranslatef(mars.TamanhoTranslacao, 0.0, 0);
	        glRotatef(mars.Rotacao, 0, 1, 0);
	        glRotatef(115, 1, 0, 0);        
	        criaSphere(0.53 * horizonteEventos, mars.Faces, mars.Faces);
	    glPopMatrix();
	    //Jupiter
	    glBindTexture(GL_TEXTURE_2D, jupiter.Texture);   
	    glPushMatrix();
	        glRotatef(jupiter.Translacao, 0, 1, 0);
	        glTranslatef(jupiter.TamanhoTranslacao, 0.0, 0);
	        glRotatef(jupiter.Rotacao, 0, 1, 0);
	        glRotatef(93, 1, 0, 0);        
	        criaSphere(9.2 * horizonteEventos, jupiter.Faces, jupiter.Faces);
	    glPopMatrix();
	    //Urano
	    glBindTexture(GL_TEXTURE_2D, uranus.Texture);   
	    glPushMatrix();
	        glRotatef(uranus.Translacao, 0, 1, 0);
	        glTranslatef(uranus.TamanhoTranslacao, 0.0, 0);
	        glRotatef(uranus.Rotacao, 0, 1, 0);
	        glRotatef(-188, 1, 0, 0);        
	        criaSphere(4.1 * horizonteEventos, uranus.Faces, uranus.Faces);
	    glPopMatrix();
	    //Netuno
	    glBindTexture(GL_TEXTURE_2D, neptune.Texture);   
	    glPushMatrix();
	        glRotatef(neptune.Translacao, 0, 1, 0);
	        glTranslatef(neptune.TamanhoTranslacao, 0.0, 0);
	        glRotatef(neptune.Rotacao, 0, 1, 0);
	        glRotatef(120, 1, 0, 0);        
	        criaSphere(3.88 * horizonteEventos, neptune.Faces, neptune.Faces);
	    glPopMatrix();
	    //Saturno
	    glBindTexture(GL_TEXTURE_2D, saturn.Texture);   
	    glPushMatrix();
	        glRotatef(saturn.Translacao, 0, 1, 0);
	        glTranslatef(saturn.TamanhoTranslacao, 0.0, 0);
	        glRotatef(saturn.Rotacao, 0, 1, 0);
	        glRotatef(117, 1, 0, 0);        
	        criaSphere(7.45 * horizonteEventos, saturn.Faces, saturn.Faces);
	    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}
void queHajaLuz(){
	if(podeBrilhar){
		float luzAmbiente[] = {0.0, 0.0, 0.0, 1.0};
	    float luzDifusa0[] = {difusa, difusa, difusa, 1.0};
	    float luzEpecular0[] = {especular, especular, especular, 1.0};
	    float luzPosicional0[] = {0.0, 0.0, 3.0, posicional};
	    float luzDE[] = {0.0, 1.0, 0.0, 1.0};
	    float luzPosicional1[] = {1.0, 2.0, 0.0, 1.0};
	    float luzGlobal[] = {global, global, global, 1.0};

	    glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
	    glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa0);
	    glLightfv(GL_LIGHT0, GL_SPECULAR, luzEpecular0);

	    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzGlobal);
	    glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, false);
	    glEnable(GL_LIGHT0);
	    glDisable(GL_LIGHTING);
	    glPushMatrix();
	        glRotatef(luzBranca.X, 1.0, 0.0, 0.0);
	        glRotatef(luzBranca.Y, 0.0, 1.0, 0.0);
	        glLightfv(GL_LIGHT0, GL_POSITION, luzPosicional0);
	        glTranslatef(luzPosicional0[0], luzPosicional0[1], luzPosicional0[2]);
	        glColor3f(difusa, difusa, difusa);
	        renderizaAstroRei();
	    glPopMatrix();
	}else{
		glDisable(GL_LIGHT0);
	}

	glEnable(GL_LIGHTING);

}

void exibeCamera(){
	camera.X = 800 * sin(anguloCameraA) * cos(anguloCameraB);
    camera.Y = 800 * sin(anguloCameraA);
    camera.Z = 800 * cos(anguloCameraA) * sin(anguloCameraB);
    switch(modoCamera){
    	case 1:
    		 gluLookAt(cursor.X+camera.X, camera.Y, cursor.Z+camera.Z, cursor.X+0, 0, cursor.Z+0, 0, 1, 0);
    	break;
    	case 2:
    		gluLookAt(0, 0, 1080, 0, 0, 0, 0, 1, 0);
    	break;
    }
}

void desenhoOrbitas(GLdouble tamanho){
	/*Orbita dos Planetas*/
	GLUquadric *disk;
    disk = gluNewQuadric(); 

    glPushMatrix();
    
        glRotatef(0, 0, -1, 0);
        glRotatef(90, 1, 0, 0);
        glTranslatef(0, 0, 0);
        gluDisk(disk, tamanho, tamanho+0.5, 600, 600);
    glPopMatrix();
    gluDeleteQuadric(disk);
}

//---------------------------------------------------- Estado de Execução ------------------------------------------------------------
void exibeOrbitas(){
	if(podeOrbitar){
		//Mercurio
	desenhoOrbitas(mercury.TamanhoTranslacao);
	//Venus
	desenhoOrbitas(venus.TamanhoTranslacao);
	//Terra
	desenhoOrbitas(earth.TamanhoTranslacao);
	//Marte
	desenhoOrbitas(mars.TamanhoTranslacao);
	//Jupiter
	desenhoOrbitas(jupiter.TamanhoTranslacao);
	//Urano
	desenhoOrbitas(uranus.TamanhoTranslacao);
	//Netuno
	desenhoOrbitas(neptune.TamanhoTranslacao);
	//Saturno
	desenhoOrbitas(saturn.TamanhoTranslacao);
	}
}

void estadoExecucao(){
	Mix_PlayChannel(-1, startingOdyssey, -1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    exibeCamera();
   	glMaterialfv(GL_FRONT, GL_SHININESS, matrizBrilho);
    glColor3f(1, 1, 1);
    queHajaLuz();
    renderizaCorpos();
    exibeOrbitas();
    glutSwapBuffers();
}

void estadoAtualizacao(int time){
	glutPostRedisplay();
    glutTimerFunc(time, estadoAtualizacao, time);
}

//---------------------------------------------------- Processos de Execução ------------------------------------------------------------
void estadoRotacao(){
	sun.Rotacao = sun.Rotacao + 0.1f;
	mercury.Rotacao = mercury.Rotacao + 0.04f;
	venus.Rotacao = venus.Rotacao + 0.01f;
	earth.Rotacao = earth.Rotacao + 2.4f;
	mars.Rotacao = mars.Rotacao + 2.3f;
	jupiter.Rotacao = jupiter.Rotacao + 5.7f;
	uranus.Rotacao = uranus.Rotacao + 3.4f;
	neptune.Rotacao = neptune.Rotacao + 3.6f;
	saturn.Rotacao = saturn.Rotacao + 5.2f;
	glutPostRedisplay();
}

void estadoTranslacao(){
	mercury.Translacao = mercury.Translacao + 0.16f;
	venus.Translacao = venus.Translacao + 0.12f;
	earth.Translacao = earth.Translacao + 0.1f;
	mars.Translacao = mars.Translacao + 0.08f;
	jupiter.Translacao = jupiter.Translacao + 0.043f;
	uranus.Translacao = uranus.Translacao + 0.22f;
	neptune.Translacao = neptune.Translacao + 0.18f;
	saturn.Translacao = saturn.Translacao + 0.031f;
	estadoRotacao();
	glutPostRedisplay();
}

void estadoTeclado(unsigned char key, int x, int y){
	switch(key){
		case '1':
			modoCamera = 1;
		break;
		case '2':
			modoCamera = 2;
		break;
		case 27:
			exit(0);
		break;
		case 'w':
			cursor.X--;
		break;
		case 'W':
			cursor.X--;
		break;
		case 's':
			cursor.X++;
		break;
		case 'S':
			cursor.X++;
		break;
		case 'a':
			cursor.Z--;
		break;
		case 'A':
			cursor.Z--;
		break;
		case 'd':
			cursor.Z++;
		break;
		case 'D':
			cursor.Z++;
		break;
		case 'f':
			podeBrilhar = !podeBrilhar;
		break;
		case 'F':
			podeBrilhar = !podeBrilhar;
		break;
		case 'e':
			if(horizonteEventos == 1){
				horizonteEventos = 10;
			} else{
				horizonteEventos = 1;
			}
		break;
		case 'E':
			if(horizonteEventos == 1){
				horizonteEventos = 10;
			} else{
				horizonteEventos = 1;
			}
		break;
		case 'v':
			podeOrbitar = !podeOrbitar;
		break;
		case 'V':
			podeOrbitar = !podeOrbitar;
		break;
	}
}

//---------------------------------------------------- Configurações da Aplicação ------------------------------------------------------------
/*Define as configurações da janela*/
void confJanela(int w, int h){
	janela.Largura = w;
	janela.Altura = h;

	glEnable(GL_DEPTH_TEST);
    glViewport (0, 0, w, h);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (float)w/(float)h, 0.2, 2147483647.0);
    glMatrixMode(GL_MODELVIEW);
}
/*Define as configurações da camera*/
void confCamera(int x, int y){
	float altX = x - mouse.X;
	float altY = y - mouse.Y;

	anguloCameraA = anguloCameraA + altX/150;
	anguloCameraB = anguloCameraB + altY/150;

	if(anguloCameraB > 180){
		anguloCameraB = 180;
	}

	mouse.X = x;
	mouse.Y = y;
}

/*Define estado inicial dos componentes*/
void defineBase(){
	glClearColor(0,0,0, 0.0);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    /*Configurações da Luz*/
    difusa = 1;
	especular = 1;
	posicional = 1;
	global = 0.2;
	luzBranca.X = 0;
	luzBranca.Y = 0;

	/*Configurações do Cursor*/
	cursor.X = 0;
	cursor.Y = 0;
	cursor.Z = 0;

	/*Configurações do Mouse*/
	mouse.X = 0;
	mouse.Y = 0;
	mouse.Z = 0;

    /*Configurações dos Corpos*/
    //SOL
	sun.Texture = carregaTextura("resources/textures/sun.jpg");
	sun.Translacao = 0;
	sun.Faces = 200;
	sun.Estado = true;
	sun.Rotacao = 0;

	//MERCURIO
	mercury.Texture = carregaTextura("resources/textures/mercury.jpg");
	mercury.Translacao = 90;
	mercury.Rotacao = 10;
	mercury.TamanhoTranslacao = 126;
	mercury.Faces = 200;
	mercury.Estado = true;

	//VENUS
	venus.Texture = carregaTextura("resources/textures/venus.jpg");
	venus.Translacao = 30;
	venus.Rotacao = 10;
	venus.TamanhoTranslacao = 166;
	venus.Faces = 200;
	venus.Estado = true;

	//TERRA
	earth.Texture = carregaTextura("resources/textures/earth.jpg");
	earth.Translacao = 90;
	earth.Rotacao = 90;
	earth.TamanhoTranslacao = 200;
	earth.Faces = 200;
	earth.Estado = true;

	//MARTE
	mars.Texture = carregaTextura("resources/textures/mars.jpg");
	mars.Translacao = 10;
	mars.Rotacao = 10;
	mars.TamanhoTranslacao = 264;
	mars.Faces = 200;
	mars.Estado = true;

	//JUPITER
	jupiter.Texture = carregaTextura("resources/textures/jupiter.jpg");
	jupiter.Translacao = 78;
	jupiter.Rotacao = 10;
	jupiter.TamanhoTranslacao = 500;
	jupiter.Faces = 200;
	jupiter.Estado = true;

	//URANO
	uranus.Texture = carregaTextura("resources/textures/uranus.jpg");
	uranus.Translacao = 10;
	uranus.Rotacao = 10;
	uranus.TamanhoTranslacao = 900;
	uranus.Faces = 200;
	uranus.Estado = true;

	//NETUNO
	neptune.Texture = carregaTextura("resources/textures/neptune.jpg");
	neptune.Translacao = 10;
	neptune.Rotacao = 90;
	neptune.TamanhoTranslacao = 1000;
	neptune.Faces = 200;
	neptune.Estado = true;

	//Saturno
	saturn.Texture = carregaTextura("resources/textures/saturn.jpg");
	saturn.Translacao = 10;
	saturn.Rotacao = 10;
	saturn.TamanhoTranslacao = 670;
	saturn.Faces = 200;
	saturn.Estado = true;

	//Espaço
	space.Texture = carregaTextura("resources/textures/space.jpg");

	//Musica de Fundo
	startingOdyssey = Mix_LoadWAV("resources/sounds/startingOdyssey.wav");

	/*Configurações do Material*/
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, matrizAD);
    glMaterialfv(GL_FRONT, GL_SPECULAR, matrizEspecular);
    glMaterialfv(GL_FRONT, GL_SHININESS, matrizBrilho);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}




int main(int argc, char* args[]){ //Nossa querida e tão aguardada (Pela Linguagem C), Main
	printf("Commands:\n  Move the mouse to change the perspective in Free Mode\n  Press 'V' to view Orbits\n  Press 'F' to turn ON/OFF the light\n  Press 'E' to change the size of the planets\n  Press '1' or '2' to change the camera mode (1 - Free Mode | 2 - Fixed Mode)\n  Press 'W', 'S', 'A' or 'D' to move the camera in Free Mode\n  Press 'ESC' to exit\n");
	SDL_Init(SDL_INIT_EVERYTHING); //Inicia o SDL
	glutInit(&argc, args);
	glutInitContextVersion(1, 1);
    glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);
    //Configurações da Janela
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH); //Modo
    glutInitWindowSize(1400, 840);//Dimensão
    glutInitWindowPosition (0, 0);//Posição
    glutCreateWindow("Solar System"); //Nome     
	Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 4096); //Define os parâmetros do canal de audio (Frequência, Formato, Canal - Stereo, Buffer)

	//Chama nossas funções principais
	glutDisplayFunc(estadoExecucao);//Execução
	glutReshapeFunc(confJanela);
	glutTimerFunc(10, estadoAtualizacao, 10); //Taxa de Atualização
	glutKeyboardFunc(estadoTeclado);
	glutPassiveMotionFunc(confCamera);
	glutIdleFunc(estadoTranslacao);
	defineBase(); //Processos Iniciais
	glutMainLoop();//Loop
	Mix_CloseAudio(); //Encerra o canal de audio
	SDL_Quit();	//Encerra o SDL

	return 0;
}