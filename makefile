kliconsole: mkdirs complie build rmobj

dev: clean mkdirs complie build

clean: rmbin rmobj
	@echo "Cleaning!"

complie: functions.o helpers.o repl.o tempbuffers.o main.o 

build: 
	@echo "Building app";
	@gcc ./obj/*.o -o ./bin/kli_console -lm
	@echo "Done!"

mkdirs:
	@mkdir -p ./bin
	@mkdir -p ./obj

rmbin:
	@rm -rf ./bin

rmobj:
	@rm -rf ./obj

functions.o:
	@echo "Compliling functions.c"
	@gcc -I./include ./src/functions.c -c -o ./obj/functions.o

helpers.o:
	@echo "Compliling helpers.c"
	@gcc -I./include ./src/helpers.c -c -o ./obj/helpers.o

repl.o:
	@echo "Compliling repl.c"
	@gcc -I./include ./src/repl.c -c -o ./obj/repl.o

tempbuffers.o:
	@echo "Compliling tempbuffers.c"
	@gcc -I./include ./src/tempbuffers.c -c -o ./obj/tempbuffers.o

main.o:
	@echo "Compliling main.c"
	@gcc -I./include ./src/main.c -c -o ./obj/main.o
