#include <stdio.h>
#include <string.h>

char gol[1000][5];
char nome[1000][50];
char time[1000][50];

int jogador = -1;
int nro_jogadores = 0;

int achouNomes = 0;
int achouEquipes = 0;

int main() {
	int i, j;
	char texto[255];
	FILE * fp = fopen("art.txt", "r");

	while(1) {
		fgets(texto, 255, fp);
		//printf("%s",texto);
		
		jogador++;
		
		if ( strcmp(texto, "GOLS\n")==0 ){
			printf("******** achou gols\n"); jogador--;

		}
		else if ( strcmp(texto, "NOME\n")==0 ){
			printf("******** achou nome\n");
			achouNomes = 1; nro_jogadores = jogador; jogador = -1;
		}
		else if ( strcmp(texto, "EQUIPE\n")==0 ){
			printf("******** achou equipe\n"); jogador = -1;
			achouEquipes = 1;
		}
		else {
		
			if (achouNomes == 0){
				strcpy(gol[jogador], texto);
			}
			else if (achouNomes == 1 && achouEquipes == 0){
				strcpy(nome[jogador], texto);
			}
			else if (achouNomes == 1 && achouEquipes == 1){
				strcpy(time[jogador], texto);
			}
		
		
		}

		if (feof(fp)) break;
	}
	fclose(fp);
	nro_jogadores--;
	/*
	for(i = 0; i < nro_jogadores; i++) {
		printf("%ld : %s", strlen(gol[i]), gol[i]);
	}
	
	for(i = 0; i < nro_jogadores; i++) {
		printf("%ld : %s", strlen(nome[i]), nome[i]);
	}
	
	for(i = 0; i < nro_jogadores; i++) {
		printf("%ld : %s", strlen(time[i]), time[i]);
	}
	*/
	printf("\n- - - - - - - - - - - - -\n");
	///*
	for(i = 0; i < nro_jogadores; i++) {
		//printf("%ld : %s", strlen(equipe[i]), equipe[i]);
		printf("<tr>\n");
		printf("\t<td>");
		//printf("tamanh odo primemir gol:  %ld", strlen(gol[i]));
		
		for(j=0; j < strlen(gol[i])-1; j++)
			printf("%c",gol[i][j]);
			
		printf("</td>\n");
		
		printf("\t<td>");
		for(j=0; j<strlen(nome[i])-1; j++)
			printf("%c",nome[i][j]);
		printf("</td>\n");
		
		printf("\t<td>");
		for(j=0; j<strlen(time[i])-1; j++)
			printf("%c",time[i][j]);
		printf("</td>\n");
		printf("</tr>\n");
	}
	//*/
	/*
	// modelo teste:
	<tr>
        <td>2</td>
        <td>Jaimilson Barros Vieira</td>
        <td>Ed. Física 2</td>
    </tr>
	*/
	
	printf("Tem %d jogadores.\n", nro_jogadores);

	return 0;      
}
