#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>


int importa(int tab[20][20]){ //Temos que especificar uma das dimensões da tabela, não me lembro se a primeira ou a segunda
	//Esta função estáa funcionar.
	char buffer[4];
	int fd = 0;
	fd = open("matrix.txt", O_RDONLY);
	if(fd == -1) exit(-1);
	int i = 0;
	int j = 0;
	for(i = 0; i < 20; i++){
		for(j = 0; j < 20; j++){
			read(fd, buffer, (size_t)3);
			tab[i][j] = atoi(buffer);

		}
	}
	return 0;
}

int escreve(int tab[20][20]){
	//Esta função serve para ver se a função de importação funciona
	//Esta função está a funcionar.
	int i, j;
	for(i = 0; i < 20; i++){
		for(j = 0; j < 20; j++){
			printf("%3d", tab[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}

int simples(int tab[20][20]){
	//Esta função deverá resolver o problema sem recursividade
	//Depois de testada, esta função devolve, de facto, a resposta correcta.
	int max = 0;
	int temp = 1;
	int temp2 = 0;
	int i, j;

	//Horizontais
	for(i = 0; i < 20; i++){
		for(j = 0; j < 17; j++){
			temp = tab[i][j]*tab[i][j+1]*tab[i][j+2]*tab[i][j+3];
			if(temp > temp2) temp2 = temp;
		}
	}
	if(temp2 > max) max = temp2; 
	
	//Verticais
        for(i = 0; i < 17; i++){
                for(j = 0; j < 20; j++){
                        temp = tab[i][j]*tab[i+1][j]*tab[i+2][j]*tab[i+3][j];
                        if(temp > temp2) temp2 = temp;
                }
        }
	if(temp2 > max) max = temp2;

	//Diagonais: descendentes
        for(i = 0; i < 17; i++){
                for(j = 0; j < 17; j++){
                        temp = tab[i][j]*tab[i+1][j+1]*tab[i+2][j+2]*tab[i+3][j+3];
                        if(temp > temp2) temp2 = temp;
                }
        }
	if(temp2 > max) max = temp2;
	//Diagonais: ascendentes
        for(i = 3; i < 20; i++){
                for(j = 0; j < 20; j++){
                        temp = tab[i][j]*tab[i-1][j+1]*tab[i-2][j+2]*tab[i-3][j+3];
                        if(temp > temp2) temp2 = temp;
                }
        }
	if(temp2 > max) max = temp2;

	//Retorna o valor encontrado:
	return max;
}

int main(){
	int tab[20][20];
	importa(tab);
	//escreve(tab);
	printf("O valor máximo que consigo determinar é %d\n", simples(tab));
	return 0;
}
