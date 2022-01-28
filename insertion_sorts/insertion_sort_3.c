#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

#define NBWORD 150
#define MAX 11

typedef char tab_word[NBWORD][MAX];

int nombre, letters;

void alea(tab_word tab){
  int i, j, taille;
  srand(time(NULL)); 
  for (i=0; i<NBWORD; i++){
    taille = 6 + rand() % 5;
    for (j=0; j<taille; j++){
        tab[i][j] = 'a' + rand() % 26; 
    }
    tab[i][j] = '\0';
  }
}

void swap(char a[11], char b[11]){
  char temp[11];
  strcpy(temp,a);      
  strcpy(a,b);
  strcpy(b,temp);
}


void insertion_croissant(tab_word tab, int limite){
    int i, j, imin;
    char min[11];
    for (i=0; i<limite-1; i++){
        strcpy(min,tab[i]);
        imin = i; 
        for (j=i+1; j<limite; j++){
            if (strcmp(tab[j],min)<0){
                strcpy(min,tab[j]);
                imin = j;
            }
        }
        swap(tab[i],tab[imin]); 
    }
}

void insertion_decroissant(tab_word tab, int limite){
    int i, j, imin;
    char min[11];
    for (i=0; i<limite-1; i++){
        strcpy(min,tab[i]);
        imin = i; 
        for (j=i+1; j < limite; j++){
            if (strcmp(tab[j],min)>0){
                strcpy(min,tab[j]);
                imin = j;
            }
        }
        swap(tab[i],tab[imin]); 
    }
}


void affiche_tab(tab_word tab, int limite){
    int i;
    for (i=0; i<limite; i++){
        printf("%s ", tab[i]);
    }
}




int main(){
    int limite;
    char choix[10];
    system("clear");
    printf("Combien de mots voulez-vous afficher ?\n");
    scanf("%d", &limite);
    int save_limite = limite;
    tab_word tab = {};
    alea(tab);
    printf("tableau avant le tri :\n");
    affiche_tab(tab,limite);
    printf("\n");
    printf("Quel tri voulez vous faire : croissant / decroissant\n");
    scanf("%s", choix);
    while (((strcmp(choix, "croissant") != 0) && (strcmp(choix, "decroissant") != 0))){
            printf("ressaisissez entre croissant et decroissant\n");
            scanf("%s", choix);
    }
    if (strcmp(choix, "croissant") == 0){
            printf("tableau après le tri :\n");
            insertion_croissant(tab, NBWORD);
        }
    else{
            printf("tableau après le tri :\n");
            insertion_decroissant(tab, NBWORD);
        }
    affiche_tab(tab, save_limite);
    printf("\n");
    return EXIT_SUCCESS;
}