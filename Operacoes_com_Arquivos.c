//Luis Fernando da Silva Serafim

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


void Troca(int *A, int i, int  j){
	int aux;
	aux= *(A+i);
	*(A+i)= *(A+j);
	*(A+j)= aux;
	return;
}

void QuickSort(int *A, int ini, int fim){
   int pivo, i, j, meio;
   i = ini;
   j = fim;
   meio = (i + j)/2;
   pivo = *(A+meio);
   do{
      while (*(A+i) < pivo)  i++;
      while (*(A+j) > pivo)  j--;
      if(i <= j){
         Troca(A, i, j);
         i++;
         j--;
      }
   }while(j > i);
   if(ini < j) QuickSort(A, ini, j);
   if(i < fim) QuickSort(A, i, fim);
   return;   
}

void Random(int *A, int N){
	int i;
	clock_t semente;
	semente = clock();
	srand((unsigned)semente);
  	for (i = 0; i < N; i++)
     	*(A+i)= (rand() % 100);
     	return;
}



int criaarq(int Ty, char No[], int N){
	
	int A[N], i;
    Random(A, N);
    QuickSort(A, 0, N);
    FILE *f;

	if(Ty=='t'){
		char ext[4]= {'.', 't', 'x', 't'};
		strcat(No, ext);
  		f = fopen(No, "w");
  		if (f == NULL) {
      		printf ("Houve um erro ao abrir o arquivo.\n");
       		return 0;
    	}
    	for(i=0; i<N; i++)
    	fprintf(f, "%d  ", A[i]);
    }
	else if(Ty=='b'){
		char ext[4]= {'.', 'b', 'i', 'n'};
		strcat(No, ext);
		f = fopen(No, "w"); 
  		if (f == NULL) {
       		printf ("Houve um erro ao abrir o arquivo %s.\n", No);
       		return 0;
   		}
   		for(i=0; i<N; i++)
    	fprintf(f, "%d  ", A[i]);
	}
	fclose(f);
   	printf("O arquivo %s foi criado com sucesso!", No);
}

void DescrevePrograma(){
		printf(" Para criar arquivos:\n");
		printf(" TPP05.exe Tipo NomeDoArquivo Numero_de_termos\n");
		printf(" Tipo: t = Cria arquivos do tipo TEXTO\n");
		printf("       b = Cria arquivos do tipo BINARIO\n\n");

		printf(" Para mostrar os elementos de um arquivo:\n");
		printf(" TPP05.exe Tipo NomeDoArquivo\n\n");
		printf(" Tipo: t = Mostra os elementos do arquivo do tipo TEXTO\n");
		printf("       b = Lista os elementos do arquivo do tipo BINARIO\n\n");
		

		printf(" Para Operacoes: \n");
		printf(" TPP05.exe Tipo N_Operacao Nomearq1 Nomearq2 Nomearq3 \n\n");
		printf(" Tipo: t - Para operacoes com arquivos tipo TEXTO\n");
		printf("       b - Para operacoes com arquivos tipo BINARIO\n\n");
		printf(" Operacao: 1 - Para Interseccao\n");
		printf("           2 - Para Uniao\n");
		printf("           3 - Para Diferenca\n\n");

	
	system("pause");
	return;
}

int MostraConteudo(char Ty, char No[]){
	if(Ty=='t'){
		FILE *f;
		char ext[4]= {'.', 't', 'x', 't'};
		strcat(No, ext);
 		f = fopen(No, "rt");
 		if(f == NULL){
    		printf("Erro, nao foi possivel abrir o %s\n", No);
    		return 0;
    	}
    	char ch;
    	while( (ch=fgetc(f))!= EOF )
  			putchar(ch);
  		fclose(f);
 	}
 	else if(Ty=='b'){
 		FILE *f;
		char ext[4]= {'.', 'b', 'i', 'n'};
		strcat(No, ext);
		f = fopen(No, "rt");
 		if(f == NULL){
    		printf("Erro, nao foi possivel abrir o %s\n", No);
    		return 0;
    	}
    	int c;
    	while(1){
			c=fgetc(f);
			if (c==EOF)
			break;
			printf("%c",c);
		}
    	
 		
	 }
 	return 1;
}


int Uniao(char Ty, char arq1[], char arq2[], char arq3[]){
	int aux1, aux2;
	if (Ty=='t'){
		FILE *f1;
		FILE *f2;
		FILE *f3;
		char ext[4]={'.','t','x', 't'};
		strcat(arq1, ext);
		strcat(arq2, ext);
		strcat(arq3, ext);
		f1 = fopen(arq1, "rt");
		if (f1 == NULL) {
    		printf("Erro na abertura do arquivo %s", arq1);
    		exit(1);
    	}
    	f2 = fopen(arq2, "rt");
		if (f2 == NULL) {
    		printf("Erro na abertura do arquivo %s", arq2);
    		exit(1);
    	}
    	f3 = fopen(arq3, "aw");
		if (f3 == NULL) {
    		printf("Erro na abertura do arquivo %s", arq3);
    		exit(1);
    	}
    	
    	fscanf(f1,"%d",&aux1);   //Passando o arq1 para o arq3
    	while(!feof(f1)){
        	fprintf(f3,"%d   ",aux1);
			fscanf(f1,"%d",&aux1);
    	}
    	fscanf(f2,"%d",&aux2);  //Passando o arq2 para o arq3
   	 	while(!feof(f2)){
            fprintf(f3,"%d   ",aux2);
			fscanf(f2,"%d",&aux2);
    	}
    	
		fclose(f1);
		fclose(f2);
		fclose(f3);
    }
    if (Ty=='b'){
		FILE *f1;
		FILE *f2;
		FILE *f3;
		char ext[4]={'.','b','i', 'n'};
		strcat(arq1, ext);
		strcat(arq2, ext);
		strcat(arq3, ext);
		f1 = fopen(arq1, "rt");
		if (f1 == NULL) {
    		printf("Erro na abertura do arquivo %s", arq1);
    		exit(1);
    	}
    	f2 = fopen(arq2, "rt");
		if (f2 == NULL) {
    		printf("Erro na abertura do arquivo %s", arq2);
    		exit(1);
    	}
    	f3 = fopen(arq3, "aw");
		if (f3 == NULL) {
    		printf("Erro na abertura do arquivo %s", arq3);
    		exit(1);
    	}
    	fread(&aux1,sizeof(int),1, f1); 
		while(!feof(f1)){
			fwrite(&aux1,sizeof(int),1,f3);
			fread(&aux1,sizeof(int),1, f1);
		}
		fread(&aux2,sizeof(int),1, f2); 
		while(!feof(f2)){
			fwrite(&aux2,sizeof(int),1,f3);
			fread(&aux2,sizeof(int),1, f2);
		}
		fclose(f1);
		fclose(f2);
		fclose(f3);
	}
}

void Interseccao(char Ty, char arq1[], char arq2[], char arq3[]){
    int aux1, aux2, i=0;
    FILE *f1;
    FILE *f2;
    FILE *f3;
    if(Ty=='t'){
    	char ext[4]={'.','t','x', 't'};
    	strcat(arq1, ext);
    	strcat(arq2, ext);
    	strcat(arq3, ext);
    	
    	if((f1 = fopen(arq1,"rt")) == NULL){
        	printf("\nErro ao abrir o arquivo %s \n", arq1);
        	system("Pause");
        	exit(1);
    	}
    	if((f2 = fopen(arq2, "rt")) == NULL){
        	printf("\nErro ao abrir o arquivo %s \n", arq2);
        	system("Pause");
        	exit(1);
    	}
    	if((f3 = fopen(arq3,"w")) == NULL){
        	printf("\nErro ao criar o arquivo %s \n", arq3);
        	system("pause");
        	exit(1);
    }

    	while((fscanf(f1,"%d",&aux1))!= EOF){
			while((fscanf(f2,"%d",&aux2))!= EOF){
				if(aux1 == aux2) break;
			}
			rewind(f2); 
		if(aux1 == aux2)fprintf(f3,"%d\n",aux1); //se eles forem igyais, há uma intersecção
		}
	}
	else if(Ty=='b'){
		char ext[4]={'.','b','i', 'n'};
    	strcat(arq1, ext);
    	strcat(arq2, ext);
    	strcat(arq3, ext);
		if((f1 = fopen(arq1,"rb")) == NULL){
        printf("\nErro ao abrir o arquivo %s \n", arq1);
        system("Pause");
        exit(1);
    }
    if((f2 = fopen(arq2, "rb")) == NULL){
        printf("\nErro ao abrir o arquivo %s \n", arq2);
        system("Pause");
        exit(1);
    }
    if((f3 = fopen(arq3,"wb")) == NULL){
        printf("\nErro ao criar o arquivo %s \n", arq3);
        system("pause");
        exit(1);
    }
	while(!feof(f1)){
        fread(&aux1, sizeof(int),1,f1);
        while(!feof(f2)){
            fread(&aux2, sizeof(int), 1, f2);
            if(aux1==aux2) break;
        } 
		fseek(f2,0L,0);
        if(aux1 == aux2) 
		fwrite(&aux1,sizeof(int),1 , f3); 
    }
	}
	fclose(f1);
	fclose(f2);
	fclose(f3);
    printf("Operacao salva em: %s\n", arq3);
    system("pause");
	exit(1);
}

void Diferenca(char Ty, char arq1[], char arq2[], char arq3[]){
    int aux1, aux2, i=0;
    FILE *f1;
    FILE *f2;
    FILE *f3;
    if(Ty=='t'){
    	char ext[4]={'.','t','x', 't'};
    	strcat(arq1, ext);
    	strcat(arq2, ext);
    	strcat(arq3, ext);
    	
    	if((f1 = fopen(arq1,"rt")) == NULL){
        	printf("\nErro ao abrir o arquivo %s \n", arq1);
        	system("Pause");
        	exit(1);
    	}
    	if((f2 = fopen(arq2, "rt")) == NULL){
        	printf("\nErro ao abrir o arquivo %s \n", arq2);
        	system("Pause");
        	exit(1);
    	}
    	if((f3 = fopen(arq3,"w")) == NULL){
        	printf("\nErro ao criar o arquivo %s \n", arq3);
        	system("pause");
        	exit(1);
    }

    while(!feof(f1)){
            fscanf(f1,"%d",&aux1);
            while(!feof(f2)){
                fscanf(f2,"%d",&aux2);
                if(aux1 != aux2) break;
            } rewind(f2);
            if(aux1 != aux2)
			fprintf(f3,"%d\n",aux1); 
        }
    }
	else if(Ty=='b'){
		char ext[4]={'.','b','i', 'n'};
    	strcat(arq1, ext);
    	strcat(arq2, ext);
    	strcat(arq3, ext);
		if((f1 = fopen(arq1,"rb")) == NULL){
        printf("\nErro ao abrir o arquivo %s \n", arq1);
        system("Pause");
        exit(1);
    }
    if((f2 = fopen(arq2, "rb")) == NULL){
        printf("\nErro ao abrir o arquivo %s \n", arq2);
        system("Pause");
        exit(1);
    }
    if((f3 = fopen(arq3,"wb")) == NULL){
        printf("\nErro ao criar o arquivo %s \n", arq3);
        system("pause");
        exit(1);
    }
	while(!feof(f1)){
            fread(&aux1, sizeof(int),1,f1);
            while(!feof(f2)){
                fread(&aux2, sizeof(int), 1, f2);
                if(aux1 != aux2) break;
            } 
			rewind(f2);//fseek(f2,0L,0);
            if(aux1 != aux2) 
			fwrite(&aux1,sizeof(int),1,f3);
        }
    } 
	fclose(f1);
	fclose(f2);
	fclose(f3);
    printf("Operacao salva em: %s\n", arq3);
    system("pause");
	exit(1);
}


	

int main(int argc, char *argv[]) { 
	int i=1;
	
	if(argc==1){
		DescrevePrograma();
	}
	if(argc==3){
		MostraConteudo(*argv[1], argv[2]);		
	}
	if(argc==4){
		criaarq(*argv[1], argv[2], atoi(argv[3]));
	}
	if(argc==6){
		char Op= *argv[2];
			if(Op=='1')
				Interseccao(*argv[1], argv[3], argv[4], argv[5]);
			else if(Op=='2')
					Uniao(*argv[1], argv[3], argv[4], argv[5]);
				else if(Op=='3')
					Diferenca(*argv[1], argv[3], argv[4], argv[5]);
		}
	return(1);
}
