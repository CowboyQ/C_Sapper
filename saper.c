#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void latwy(int tab[11][11]);
void gra(int tab[11][11]);

int main(void){
	int size;
	printf("\n ---------------------------------- \n\n Wybierz poziom trudnosci:\n -Latwy (9x9)\n -Sredni (16x16)\n -Trudny (16x30)\n (Wybierz 1, 2 lub 3)\n\n ---------------------------------- \n\n");
	scanf("%d", &size);
	printf("\n");
	int tab[11][11];
	if(size == 1){
		latwy(tab);
		gra(tab);
	}
	else{
		printf("No.");
		return 0;
	}
	return 0;
}

/*
	0- zakryte
	1, 2, 3, 4 - okolice bomby
	5 - bomba
	6 - poza skala, border
*/


void gra(int tab[11][11]){
	int wygrana = 0;
	int i, j;
	int x, y;
	int pom = 1;
	int bombcounter = 81;
	
	int tab2[11][11];
	for(i = 0; i < 11; i++){
		for(j = 0; j < 11; j++){
			tab2[i][j] = 0;	
		}
	}
	
	
	while(wygrana == 0){
		if(bombcounter == 10){
			printf("\n\n\nGratulacje, wygrales!!!");
			return 0;
		}
		START:
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");	
		printf("_____1___2___3___4___5___6___7___8___9__");
		printf("\n________________________________________\n");
		
		for(i = 1; i < 10; i++){
			for(j = 1; j < 10; j++){
				if(j == 1){
					printf("%d || ", pom);
					pom++;
				}
				if(tab2[i][j] == 0){
					printf("X | ");
				}
				else{
					printf("%d | ", tab[i][j]);
				}
			}
			printf("\n----------------------------------------\n");
		}
		printf("\n\nPodaj rzad i kolumne w ktora chcesz strzelic: ");
		scanf("%d %d", &x, &y);

		if(x > 9 || y > 9 || x < 1 || y < 1){
			printf("Zly wybor!");
			goto START;
		}
		else if(tab[x][y] == 5){
			printf("Przykro mi, przegrales!");
			return 0;	
		}
		else{
			tab2[x][y] = 1;
			bombcounter--;
		}
		pom = 1;
	}
}



void latwy(int tab[11][11]){	
	int i, j; // basic loops
	int x, y; // bomb placements
	int m, n; // 2'nd loop, number placement
	int bombcounter = 0; // number of bombs in proximity
	srand(time(NULL));
		
	for(i = 0; i < 11; i++){
		for(j = 0; j < 11; j++){
			if(i == 0 || j == 0 || i == 10 || j == 10){
				tab[i][j] = 6;
			}
			else{
				tab[i][j] = 0;
			}
		}
	}
	
	i = 0;
	
	while(i != 10){
		x = rand() % 9 + 1;
		y = rand() % 9 + 1;
		if(tab[x][y] != 5){
			tab[x][y] = 5;
			i++;
		}
	}
	
	for(i = 1; i < 10; i++){
		for(j = 1; j < 10; j++){
			if(tab[i][j] != 5){
				for(n = i - 1; n <= i + 1; n++){
					for(m = j - 1; m <= j + 1; m++){
						if(tab[n][m] == 5){
							bombcounter++;
						}
					}
				}
				tab[i][j] = bombcounter;
				bombcounter = 0;
			}	
		}
	}	
/*	
	for(i = 0; i < 11; i++){
		for(j = 0; j < 11; j++){
			printf("%d | ", tab[i][j]);
		}
		printf("\n-------------------------------------------\n");
	}
*/	
}
