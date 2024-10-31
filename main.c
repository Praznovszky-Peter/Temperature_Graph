#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include "seged_dolgok.h"

int main(int argc, char* argv[]) {
	
	int* generalt_ertekek = (int*)malloc(sizeof(int));
	
	signal(SIGINT,SignalHandler);
	signal(SIGUSR1,SignalHandler);
	
	
	if(strcmp("./chart",argv[0]) != 0) {
		printf("A program nem a megfelelő néven lett futtatva!\n");
	}
	else if(argc == 1) {
		int darabszam = Measurement(&generalt_ertekek);
		SendViaFile(generalt_ertekek,darabszam);
	}
	else if(argc == 2) {
		if(strcmp("-send",argv[1]) == 0) {
			int darabszam = Measurement(&generalt_ertekek);
			SendViaFile(generalt_ertekek,darabszam);
			
		}
		else if(strcmp("-receive",argv[1]) == 0) {
			while(1) {
				signal(SIGUSR1,ReceiveViaFile);
			}
		}
		else if(strcmp("-file",argv[1]) == 0) {
			int darabszam = Measurement(&generalt_ertekek);
			SendViaFile(generalt_ertekek,darabszam);
		}
		else if(strcmp("-socket",argv[1]) == 0){
			int darabszam = Measurement(&generalt_ertekek);
			SendViaSocket(generalt_ertekek,darabszam);
		}
		else if(strcmp("--version",argv[1]) != 0 && strcmp("--help",argv[1]) != 0) {
			printf("Lehetséges kapcsolók, és azok jelentései:\n");
			printf("--version: A jelenlegi verziószámot, dátumot, és fejlesztőt tudjuk kiirattatni.\n");
			printf("--help: A programhoz tartozó manual.\n");
			printf("-send: A program 2 üzemmódja közül ebben a módban a program állítja elő és küldi el az adatokat (alapértelmezett).\n");
			printf("-receive: A program 2 üzemmódja közül ebben a módban a program ábrázolja a kapott adatokat.\n");
			printf("-file: A program 2 kommunikációs üzemmódja közül ebben file-on keresztül történik a kommunikáció (alapértelmezett).\n");
			printf("-socket: A program 2 kommunikációs üzemmódja közül ebben socket-en keresztül történik a kommunikáció.\n");
		}
		else {
			if(strcmp("--version",argv[1]) == 0) {
				printf("Version: 1.0\nDate: 2024.05.01\nDeveloper: Praznovszky Péter\n");
			}	
			else if(strcmp("--help",argv[1]) == 0){
				printf("Lehetséges kapcsolók, és azok jelentései:\n");
				printf("--version: A jelenlegi verziószámot, dátumot, és fejlesztőt tudjuk kiirattatni.\n");
				printf("--help: A programhoz tartozó manual.\n");
				printf("-send: A program 2 üzemmódja közül ebben a módban a program állítja elő és küldi el az adatokat (alapértelmezett).\n");
				printf("-receive: A program 2 üzemmódja közül ebben a módban a program ábrázolja a kapott adatokat.\n");
				printf("-file: A program 2 kommunikációs üzemmódja közül ebben file-on keresztül történik a kommunikáció (alapértelmezett).\n");
				printf("-socket: A program 2 kommunikációs üzemmódja közül ebben socket-en keresztül történik a kommunikáció.\n");
			}
		}
		
	}
	
	else if(argc == 3) {
		if(strcmp("-send",argv[1]) == 0 && strcmp("-file",argv[2]) == 0 || strcmp("-file",argv[1]) == 0 && strcmp("-send",argv[2]) == 0) {
			int darabszam = Measurement(&generalt_ertekek);
			SendViaFile(generalt_ertekek,darabszam);
		}
		else if(strcmp("-send",argv[1]) == 0 && strcmp("-socket",argv[2]) == 0 || strcmp("-socket",argv[1]) == 0 && strcmp("-send",argv[2]) == 0) {
			int darabszam = Measurement(&generalt_ertekek);
			SendViaSocket(generalt_ertekek,darabszam);
			
		}
		else if(strcmp("-receive",argv[1]) == 0 && strcmp("-file",argv[2]) == 0 || strcmp("-file",argv[1]) == 0 && strcmp("-receive",argv[2]) == 0) {
			while(1) {	
				signal(SIGUSR1,ReceiveViaFile);
			}
		}
		else if(strcmp("-receive",argv[1]) == 0 && strcmp("-socket",argv[2]) == 0 || strcmp("-socket",argv[1]) == 0 && strcmp("-receive",argv[2]) == 0) {
			ReceiveViaSocket();
		}
		
			
	}
	
	free(generalt_ertekek);
	return 0;
}








