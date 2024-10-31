#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <ctype.h>
#include <signal.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


void SignalHandler(int sig) {

	if(sig == SIGINT) {
		printf("\nViszlát!\n");
		exit(0);
	}
	else if(sig == SIGUSR1) {
		printf("A fájlon keresztüli küldés nem elérhető!\n");
	}
	else if(sig == SIGALRM) {
		printf("A szerver nem válaszol (időkereten belül)!\n");
		exit(29);
	}


}

int Measurement(int **Values) {

	srand(time(NULL)); 
	time_t ido; 
	struct tm *ido_egysegek; 
	time(&ido); 
	ido_egysegek = localtime(&ido); 
	int darabszam; 
	int* terulet; 
	float eldonto;

	if((*ido_egysegek).tm_min <= 15) { 
		if(((((*ido_egysegek).tm_min)*60) + (*ido_egysegek).tm_sec) > 100) { 
			darabszam = ((((*ido_egysegek).tm_min)*60) + (*ido_egysegek).tm_sec); 
			terulet = (int*)malloc(darabszam * sizeof(int));
			terulet[0] = 0;
			for(int i = 1; i < darabszam; i++) { 
				eldonto = (float)rand()/RAND_MAX;
				if(eldonto <= 0.428571) { 
					terulet[i] = terulet[i-1]+1;
				}
				else if(eldonto > 0.428571 && eldonto <= 0.783371){
					terulet[i] = terulet[i-1]-1; 
				}
				else {
					terulet[i] = terulet[i-1];
				}
			}
		}
		else {
			darabszam = 100; 
			terulet = (int*)malloc(darabszam * sizeof(int)); 
			terulet[0] = 0;
			for(int i = 1; i < darabszam; i++) { 
				eldonto = (float)rand()/RAND_MAX;
				if(eldonto <= 0.428571) { 
					terulet[i] = terulet[i-1]+1;
				}
				else if(eldonto > 0.428571 && eldonto < 0.783371){
					terulet[i] = terulet[i-1]-1;
				}
				else {
					terulet[i] = terulet[i-1];
				}
			}
		}
	}
	else if((*ido_egysegek).tm_min <= 30) { 
		if(((((15-(*ido_egysegek).tm_min)*60)*(-1) + (*ido_egysegek).tm_sec)) > 100) {
			darabszam = (((15-(*ido_egysegek).tm_min)*60)*(-1) + (*ido_egysegek).tm_sec);
			terulet = (int*)malloc(darabszam * sizeof(int));
			terulet[0] = 0;
			for(int i = 1; i < darabszam; i++) { 
				eldonto = (float)rand()/RAND_MAX;
				if(eldonto <= 0.428571) { 
					terulet[i] = terulet[i-1]+1;
				}
				else if(eldonto > 0.428571 && eldonto < 0.783371){
					terulet[i] = terulet[i-1]-1; 
				}
				else {
					terulet[i] = terulet[i-1];
				}
			}
		}
		else {
			darabszam = 100;
			terulet = (int*)malloc(darabszam * sizeof(int));
			terulet[0] = 0;
			for(int i = 1; i < darabszam; i++) { 
				eldonto = (float)rand()/RAND_MAX;
				if(eldonto <= 0.428571) { 
					terulet[i] = terulet[i-1]+1;
				}
				else if(eldonto > 0.428571 && eldonto < 0.783371){
					terulet[i] = terulet[i-1]-1;
				}
				else {
					terulet[i] = terulet[i-1];
				}
			}
		}
	}
	else if((*ido_egysegek).tm_min <= 45) { 
		if(((((30-(*ido_egysegek).tm_min)*60)*(-1) + (*ido_egysegek).tm_sec)) > 100) {
			darabszam = (((30-(*ido_egysegek).tm_min)*60)*(-1) + (*ido_egysegek).tm_sec);
			terulet = (int*)malloc(darabszam * sizeof(int));
			terulet[0] = 0;
			for(int i = 1; i < darabszam; i++) { 
				eldonto = (float)rand()/RAND_MAX;
				if(eldonto <= 0.428571) { 
					terulet[i] = terulet[i-1]+1;
				}
				else if(eldonto > 0.428571 && eldonto < 0.783371){
					terulet[i] = terulet[i-1]-1; 
				}
				else {
					terulet[i] = terulet[i-1];
				}
			}
		}
		else {
			darabszam = 100;
			terulet = (int*)malloc(darabszam * sizeof(int));
			terulet[0] = 0;
			for(int i = 1; i < darabszam; i++) { 
				eldonto = (float)rand()/RAND_MAX;
				if(eldonto <= 0.428571) { 
					terulet[i] = terulet[i-1]+1;
				}
				else if(eldonto > 0.428571 && eldonto < 0.783371){
					terulet[i] = terulet[i-1]-1; 
				}
				else {
					terulet[i] = terulet[i-1];
				}
			}
		}
	}
	else {
		if(((((45-(*ido_egysegek).tm_min)*60)*(-1) + (*ido_egysegek).tm_sec)) > 100) {
			darabszam = (((45-(*ido_egysegek).tm_min)*60)*(-1) + (*ido_egysegek).tm_sec);
			terulet = (int*)malloc(darabszam * sizeof(int));
			terulet[0] = 0;
			for(int i = 1; i < darabszam; i++) { 
				eldonto = (float)rand()/RAND_MAX;
				if(eldonto <= 0.428571) { 
					terulet[i] = terulet[i-1]+1;
				}
				else if(eldonto > 0.428571 && eldonto < 0.783371){
					terulet[i] = terulet[i-1]-1;
				}
				else {
					terulet[i] = terulet[i-1];
				}
			}
		}
		else {
			darabszam = 100;
			terulet = (int*)malloc(darabszam * sizeof(int));
			terulet[0] = 0;
			for(int i = 1; i < darabszam; i++) { 
				eldonto = (float)rand()/RAND_MAX;
				if(eldonto <= 0.428571) { 
					terulet[i] = terulet[i-1]+1;
				}
				else if(eldonto > 0.428571 && eldonto < 0.783371){
					terulet[i] = terulet[i-1]-1;
				}
				else {
					terulet[i] = terulet[i-1];
				}
			}
		}
	}
	
	*Values = terulet;
	return darabszam;
}


void BMPcreator(int* Values, int NumValues) {

	unsigned char header[] = {0x42, 0x4d, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
							0x3e, 0x00, 0x00, 0x00, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00,
							0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00,
							0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x61, 0x0f,
							0x00, 0x00, 0x61, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
							0x00, 0x00, 0x00, 0x00, 0x06, 0x5b, 0x93, 0xff, 0x04, 0xf7,
							0xf8, 0xff};

	int szelesseg = NumValues;
    int magassag = NumValues;
    
   	if(szelesseg % 32 != 0) {
   		while(szelesseg % 32 != 0) {
   			szelesseg++;
   		}
   	}

    int paddingelt_szelesseg = szelesseg / 8;
	unsigned char pixel[magassag*paddingelt_szelesseg];
	
	int kozep;
	if(magassag % 2 == 0) {
		kozep = paddingelt_szelesseg * ((magassag / 2) -1); 
	}
	else {
		kozep = paddingelt_szelesseg * ((magassag / 2) + 1);
	}
	
	for(int i = 0; i < magassag*paddingelt_szelesseg; i++) {
			pixel[i] = 0x00;	
	}
	
	int poz;
	for(int i = 0; i < NumValues; i++) {
		poz =  kozep + (Values[i] * paddingelt_szelesseg);
		if(poz < 0) {
			poz = 0;
		}
		else if(poz >= NumValues * paddingelt_szelesseg) {
			poz = (NumValues -1) * paddingelt_szelesseg;
		}
		poz = poz + (i / 8);
		pixel[poz] |= 1 << (((sizeof(char) * 8) - 1) - i % (sizeof(char) * 8)) ;
	}
	
	
	
	int teljesmeret = sizeof(header) + sizeof(pixel);

	unsigned char fajl_meret[4];
	unsigned char szelesseg_headerbe[4];
	unsigned char magassag_headerbe[4];
	
	
			fajl_meret[0] = (teljesmeret >> 24) & 0xFF;
			szelesseg_headerbe[0] = (NumValues >> 24) & 0xFF;
			magassag_headerbe[0] = (NumValues >> 24) & 0xFF;
		
			fajl_meret[1] = (teljesmeret >> 16) & 0xFF;
			szelesseg_headerbe[1] = (NumValues >> 16) & 0xFF;
			magassag_headerbe[1] = (NumValues >> 16) & 0xFF;
		
			fajl_meret[2] = (teljesmeret >> 8) & 0xFF;
			szelesseg_headerbe[2] = (NumValues >> 8) & 0xFF;
			magassag_headerbe[2] = (NumValues >> 8) & 0xFF;
		
			fajl_meret[3] = teljesmeret & 0xFF;
			szelesseg_headerbe[3] = NumValues & 0xFF;
			magassag_headerbe[3] = NumValues & 0xFF;
		
	
	
	header[2] = fajl_meret[3];
	header[3] = fajl_meret[2];
	header[4] = fajl_meret[1];
	header[5] = fajl_meret[0];
	
	header[18] = szelesseg_headerbe[3];
	header[19] = szelesseg_headerbe[2];
	header[20] = szelesseg_headerbe[1];
	header[21] = szelesseg_headerbe[0];
	
	header[22] = magassag_headerbe[3];
	header[23] = magassag_headerbe[2];
	header[24] = magassag_headerbe[1];
	header[25] = magassag_headerbe[0];
	

	int f = open("chart.bmp",O_CREAT | O_WRONLY | O_TRUNC, S_IROTH | S_IRUSR | S_IWUSR);
	write(f,&header,sizeof(header));
	write(f,&pixel,sizeof(pixel));
	close(f);


}
int FindPID() {
	
	int PID;
	DIR* mappa;
	DIR* proc;
	struct dirent* rekord; 
	int seged = 0;
	
	putenv("PATH=/");
	mappa = opendir(getenv("PATH"));
	while((rekord=readdir(mappa))!=NULL){
    		if(strcmp((*rekord).d_name,"proc") == 0)
      			proc = opendir("/proc");
    		}
	closedir(mappa);
	
	
	putenv("PATH=/proc");
	DIR* adott_mappa;
	struct dirent* adott_mappa_rekord;
	while((rekord = readdir(proc)) != NULL) {
		if(isdigit((*rekord).d_name[0])) {
			char eleresi[100] = "/proc/";
			strcat(eleresi,(*rekord).d_name);
			adott_mappa = opendir(eleresi);
			while((adott_mappa_rekord = readdir(adott_mappa)) != NULL) {
				if(strcmp((*adott_mappa_rekord).d_name,"status") == 0) {
					char sor[500];
					strcat(eleresi,"/status");
					FILE* status_file = fopen(eleresi,"r");
					fgets(sor,500,status_file);
					if(strcmp(sor,"Name:\tchart\n") != 0) {
						continue; 
					}
					else { 
						while(fgets(sor,500,status_file) != NULL) { 
							if(!strstr(sor,"PPid:") && !strstr(sor,"TracerPid:") && strstr(sor,"Pid:")) { 
								PID = atoi(strtok(sor,"Pid:\t")); 
								if(getpid() != PID) {
									fclose(status_file); 
									closedir(adott_mappa);
									closedir(proc);
									return PID;
								}
								else {
									continue;
								}
								
							}
							
						}
					}
					
				}
			}
			
		}
		
	}
	closedir(adott_mappa);
	closedir(proc);
	return -1;
	

}


void SendViaFile(int *Values, int NumValues) { 

	char* home_konyvt = getenv("HOME");
	strcat(home_konyvt,"/Measurement.txt");
	FILE* ertekek_file = fopen(home_konyvt,"w");
	
	for(int i = 0; i < NumValues; i++) {
		fprintf(ertekek_file,"%d\n",Values[i]);
	}
	fclose(ertekek_file);
	
	int PID = FindPID();
	
	if(PID == -1) {
		printf("Nem találok fogadó üzemmódban működő folyamatot!\n");
		exit(11);
		
	}
	else {
		kill(PID,SIGUSR1);
	}


}


void ReceiveViaFile(int sig) {

	
	char home_konyvt[100];
	strcpy(home_konyvt,getenv("HOME"));
	strcat(home_konyvt,"/Measurement.txt");
	FILE* file = fopen(home_konyvt,"r"); 
	int meret = 100; 
	int* ertekek = (int*)malloc(meret*sizeof(int));
	
	int index = -1; 
	do {
		index++; 
		if(index == meret) { 
			meret = meret * 2;
			ertekek = (int*)realloc(ertekek,meret*sizeof(int)); 
		}
		fscanf(file,"%d",&ertekek[index]);
	
	}
	while(!feof(file)); 
	
	meret = index; 
	ertekek = (int*)realloc(ertekek,meret*sizeof(int)); 
	
	BMPcreator(ertekek,meret); 
	free(ertekek); 
	fclose(file); 
	
}




void SendViaSocket(int *Values, int NumValues) { 

                        
   int bytes;                    
   int flag;                         
   char on;                                     
   int kapott_darabszam;
   int kapott_bajtmeret;
   unsigned int server_size;      
   struct sockaddr_in server;        

  
   on   = 1;
   flag = 0;
   server.sin_family      = AF_INET; 
   server.sin_addr.s_addr = inet_addr("127.0.0.1"); 
   server.sin_port        = htons(3333); 
   server_size = sizeof server; 
  
   int s = socket(AF_INET, SOCK_DGRAM, 0 ); 
   setsockopt(s, SOL_SOCKET, SO_REUSEADDR, &on, sizeof on); 

   bytes = sendto(s, &NumValues, sizeof(int), flag, (struct sockaddr *) &server, server_size); 
   
   signal(SIGALRM,SignalHandler);
   alarm(1);
   
   bytes = recvfrom(s, &kapott_darabszam, sizeof(int), flag, (struct sockaddr *) &server, &server_size); 
    
   if(kapott_darabszam != NumValues) { 
   		printf("A kapott és elküldött értékek nem egyeznek meg!\n");
   		exit(5);
   }
   else { 
   		int kuldott_ertekek_biteban = sendto(s,Values, NumValues * sizeof(int), flag, (struct sockaddr *) &server, server_size); 
   		bytes = recvfrom(s, &kapott_bajtmeret, sizeof(int), flag, (struct sockaddr *) &server, &server_size); 
   		if(kapott_bajtmeret!= kuldott_ertekek_biteban) { 
   			printf("A kapott és elküldött értékek bájtban megadott mérete nem egyezik meg!\n");
   			exit(6);
   		}
   		
   }
   
   
   close(s); 

}
void ReceiveViaSocket() { 

	 
   int bytes;                       
   int err;                        
   int flag;                         
   char on;                          
   int darabszam;         
   unsigned int server_size;      
   unsigned int client_size;        
   struct sockaddr_in server;        
   struct sockaddr_in client;        

   
   on   = 1;
   flag = 0;
   server.sin_family = AF_INET; 
   server.sin_addr.s_addr = INADDR_ANY; 
   server.sin_port = htons(3333); 
   server_size = sizeof server;
   client_size = sizeof client;
   

  
   int s = socket(AF_INET, SOCK_DGRAM, 0 ); 
   setsockopt(s, SOL_SOCKET, SO_REUSEADDR, &on, sizeof on);
   setsockopt(s, SOL_SOCKET, SO_KEEPALIVE, &on, sizeof on);

  
   err = bind(s, (struct sockaddr *) &server, server_size); 

   while(1){ 
     
      bytes = recvfrom(s, &darabszam, sizeof(int), flag, (struct sockaddr *) &client, &client_size); 
      bytes = sendto(s, &darabszam, sizeof(int), flag, (struct sockaddr *) &client, client_size); 
      
      
      int* ertekek = (int*)malloc(darabszam*sizeof(int)); 
      
      bytes = recvfrom(s, ertekek, darabszam * sizeof(int), flag, (struct sockaddr *) &client, &client_size); 
      bytes = sendto(s, &bytes, sizeof(int), flag, (struct sockaddr *) &client, client_size); 
      BMPcreator(ertekek,darabszam);
      free(ertekek);
      
   }
	
}





































