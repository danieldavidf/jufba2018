#include <stdio.h>
#include <string.h>

char PS[20][5];
char EQUIPES[20][50];
char PTS[20][5];
char V[20][5];
char E[20][5];
char D[20][5];
char GP[20][5];
char GC[20][5];
char SG[20][5];

int time = -1;
int nro_times = 0;

int achouEquipes = 0;
int achouPts = 0;
int achouV = 0;
int achouE = 0;
int achouD = 0;
int achouGP = 0;
int achouGC = 0;
int achouSG = 0;

int main() {
	int i, j;
	char texto[255];
	FILE * fp = fopen("clas.txt", "r");

	while(1) {
		fgets(texto, 255, fp);
		//printf("%s",texto);
		
		time++;
		
		if ( strcmp(texto, "Ps.\n")==0 ){
			printf("******** achou Ps\n"); time--;

		}
		else if ( strcmp(texto, "EQUIPE\n")==0 ){
			printf("******** achou EQUIPE\n");
			achouEquipes = 1; nro_times = time; time--;
		}
		else if ( strcmp(texto, "Pts\n")==0 ){
			printf("******** achou Pts\n"); time--;
			achouPts = 1;
		}
		else if ( strcmp(texto, "V\n")==0 ){
			printf("******** achou V\n"); time--;
			achouV = 1;
		}
		else if ( strcmp(texto, "E\n")==0 ){
			printf("******** achou E\n"); time--;
			achouE = 1;
		}
		else if ( strcmp(texto, "D\n")==0 ){
			printf("******** achou D\n"); time--;
			achouD = 1;
		}
		else if ( strcmp(texto, "GP\n")==0 ){
			printf("******** achou GP\n"); time--;
			achouGP = 1;
		}
		else if ( strcmp(texto, "GC\n")==0 ){
			printf("******** achou GC\n"); time--;
			achouGC = 1;
		}
		else if ( strcmp(texto, "SG\n")==0 ){
			printf("******** achou SG\n"); time--;
			achouSG = 1;
		}
		
		else {
		
			if (achouEquipes == 0){
				strcpy(PS[time%6], texto);
			}
			else if (achouEquipes == 1 && achouPts == 0){
				strcpy(EQUIPES[time%6], texto);
			}
			else if (achouEquipes == 1 && achouPts == 1 && achouV == 0){
				strcpy(PTS[time%6], texto);
			}
			else if (achouEquipes == 1 && achouPts == 1 && achouV == 1 && achouE == 0){
				strcpy(V[time%6], texto);
			}
			else if (achouEquipes == 1 && achouPts == 1 && achouV == 1 && achouE == 1 && achouD == 0){
				strcpy(E[time%6], texto);
			}
			else if (achouEquipes == 1 && achouPts == 1 && achouV == 1 && achouE == 1 && achouD == 1 && achouGP == 0){
				strcpy(D[time%6], texto);
			}
			else if (achouEquipes == 1 && achouPts == 1 && achouV == 1 && achouE == 1 && achouD == 1 && achouGP == 1 && achouGC == 0){
				strcpy(GP[time%6], texto);
			}
			else if (achouEquipes == 1 && achouPts == 1 && achouV == 1 && achouE == 1 && achouD == 1 && achouGP == 1 && achouGC == 1 && achouSG == 0){
				strcpy(GC[time%6], texto);
			}
			else if (achouEquipes == 1 && achouPts == 1 && achouV == 1 && achouE == 1 && achouD == 1 && achouGP == 1 && achouGC == 1 && achouSG == 1){
				strcpy(SG[time%6], texto);
			}
		}

		if (feof(fp)) break;
	}
	fclose(fp);
	//nro_times--;
	
	printf("Tem %d times.\n", nro_times);
	for(i = 0; i < nro_times; i++) {
		printf("%ld : %s", strlen(PS[i]), PS[i]);
	}
	
	for(i = 0; i < nro_times; i++) {
		printf("%ld : %s", strlen(EQUIPES[i]), EQUIPES[i]);
	}
	
	for(i = 0; i < nro_times; i++) {
		printf("%ld : %s", strlen(PTS[i]), PTS[i]);
	}
	for(i = 0; i < nro_times; i++) {
		printf("%ld : %s", strlen(V[i]), V[i]);
	}
	
	for(i = 0; i < nro_times; i++) {
		printf("%ld : %s", strlen(E[i]), E[i]);
	}
	
	for(i = 0; i < nro_times; i++) {
		printf("%ld : %s", strlen(D[i]), D[i]);
	}
	for(i = 0; i < nro_times; i++) {
		printf("%ld : %s", strlen(GP[i]), GP[i]);
	}
	
	for(i = 0; i < nro_times; i++) {
		printf("%ld : %s", strlen(GC[i]), GC[i]);
	}
	
	for(i = 0; i < nro_times; i++) {
		printf("%ld : %s", strlen(SG[i]), SG[i]);
	}
	printf("\n- - - - - - - - - - - - -\n");
	///*
	for(i = 0; i < nro_times; i++) {
		printf("<tr>\n");
		printf("\t<td>");
		
		for(j=0; j < strlen(PS[i])-1; j++)
			printf("%c",PS[i][j]);
			
		printf("</td>\n");
		printf("\t<td>");
		
		for(j=0; j<strlen(EQUIPES[i])-1; j++)
			printf("%c",EQUIPES[i][j]);
			
		printf("</td>\n");
		printf("\t<td>");
		
		for(j=0; j<strlen(PTS[i])-1; j++)
			printf("%c",PTS[i][j]);

		printf("</td>\n");
		printf("\t<td>");
		
		for(j=0; j<strlen(V[i])-1; j++)
			printf("%c",V[i][j]);

		printf("</td>\n");
		printf("\t<td>");
		
		for(j=0; j<strlen(E[i])-1; j++)
			printf("%c",E[i][j]);

		printf("</td>\n");
		printf("\t<td>");
		
		for(j=0; j<strlen(D[i])-1; j++)
			printf("%c",D[i][j]);

		printf("</td>\n");
		printf("\t<td>");
		
		for(j=0; j<strlen(GP[i])-1; j++)
			printf("%c",GP[i][j]);

		printf("</td>\n");
		printf("\t<td>");
		
		for(j=0; j<strlen(GC[i])-1; j++)
			printf("%c",GC[i][j]);

		printf("</td>\n");
		printf("\t<td>");
		
		for(j=0; j<strlen(SG[i])-1; j++)
			printf("%c",SG[i][j]);

		printf("</td>\n");
		printf("</tr>\n");
	}
	
	printf("Tem %d times.\n", nro_times);

	return 0;      
}
