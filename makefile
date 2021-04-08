all:
	@echo "Preparando o Lançamento..."
	gcc SistemaSolar.c -o solar -lGL -lGLU -lglut -lSOIL -lSDL -lSDLmain -lSDL_image -lSDL_mixer -lm
install-libraries:
	@echo "Construindo a Nave..."
	sudo apt-get update
	sudo apt-get install libsoil-dev 
	sudo apt-get install libsdl1.2-dev libsdl-image1.2-dev libsdl-mixer1.2-dev libsdl-ttf2.0-dev
	sudo apt-get install freeglut3-dev
run:
	@echo "Aperte o cinto e curta a viagem..."
	./solar
clean:
	@echo "Retornando para Casa..."
	rm solar
