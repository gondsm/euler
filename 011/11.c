#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>


int import(int tab[20][20]){
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

int calculateLargestSum(int tab[20][20]){
	int max = 0;
	int temp = 1;
	int temp2 = 0;
	int i, j;

	// Horizontal
	for(i = 0; i < 20; i++){
		for(j = 0; j < 17; j++){
			temp = tab[i][j]*tab[i][j+1]*tab[i][j+2]*tab[i][j+3];
			if(temp > temp2) temp2 = temp;
		}
	}
	if(temp2 > max) max = temp2; 
	
	// Vertical
		for(i = 0; i < 17; i++){
				for(j = 0; j < 20; j++){
						temp = tab[i][j]*tab[i+1][j]*tab[i+2][j]*tab[i+3][j];
						if(temp > temp2) temp2 = temp;
				}
		}
	if(temp2 > max) max = temp2;

	// Descending diagonals
		for(i = 0; i < 17; i++){
				for(j = 0; j < 17; j++){
						temp = tab[i][j]*tab[i+1][j+1]*tab[i+2][j+2]*tab[i+3][j+3];
						if(temp > temp2) temp2 = temp;
				}
		}
	if(temp2 > max) max = temp2;
	// Ascending diagonals
		for(i = 3; i < 20; i++){
				for(j = 0; j < 20; j++){
						temp = tab[i][j]*tab[i-1][j+1]*tab[i-2][j+2]*tab[i-3][j+3];
						if(temp > temp2) temp2 = temp;
				}
		}
	if(temp2 > max) max = temp2;

	return max;
}

int main(){
	int tab[20][20];
	import(tab);
	printf("Largest sum: %d.\n", calculateLargestSum(tab));
	return 0;
}
