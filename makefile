kliconsole: mkdirs complie build rmobj

clean: rmbin rmobj

complie: clifunctions.o helpers.o tempbuffers.o main.o 

build: 
	@echo "Building app";
	@gcc ./obj/clifunctions.o ./obj/helpers.o ./obj/tempbuffers.o ./obj/main.o -o ./bin/kli_console -lm
	@echo "Done!"

mkdirs:
	@mkdir -p ./bin
	@mkdir -p ./obj

rmbin:
	@rm -rf ./bin

rmobj:
	@rm -rf ./obj

clifunctions.o:
	@echo "Compliling clifunctions.c"
	@gcc -I./include ./src/clifunctions.c -c -o ./obj/clifunctions.o

helpers.o:
	@echo "Compliling helpers.c"
	@gcc -I./include ./src/helpers.c -c -o ./obj/helpers.o

tempbuffers.o:
	@echo "Compliling tempbuffers.c"
	@gcc -I./include ./src/tempbuffers.c -c -o ./obj/tempbuffers.o

main.o:
	@echo "Compliling main.c"
	@gcc -I./include ./src/main.c -c -o ./obj/main.o
