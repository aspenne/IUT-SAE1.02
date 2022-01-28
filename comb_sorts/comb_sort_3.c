#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

#define NBWORD 150
#define MAX 11

typedef char tab_word[NBWORD][MAX];

int nombre, letters;

void alea_wd(tab_word tab){
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


void swap_wd(char a[11], char b[11]){
  char temp[11];
  strcpy(temp,a);      
  strcpy(a,b);
  strcpy(b,temp);
}


/**
 * @brief cette procédure tri de manière croissant un tableau donné en entré
 *        paramètres d'entré, de manière peigne
 * 
 * @param tab tableau de 50 entiers
 */
void tri_peigne_croissant_wd(tab_word tab, int limite){
    int compteur, i;
    bool trouver;
    compteur = limite; // taille du tableau
    trouver = false; // mise en place d'un booléen pour condition d'arrêt
    while (( trouver) || (compteur>1)){ // booléen pour permettre d'arrêter le tri si le tableau est déjà trié
        trouver = false;
        compteur = compteur / 1.3;
        if (compteur<1) compteur=1;
        for (i=0; i<limite-compteur; i++) {
            if (strcmp(tab[i],tab[i+compteur])>0){ 
                trouver = true; // condition d'arrêt
                /*
                ces permutations permettes d'échanger deux valeurs du tableau
                */
                swap_wd(tab[i],tab[i+compteur]);
            }
        }
    }
}

/**
 * @brief cette procédure tri de manière décroissante un tableau donné en entré
 *        paramètres d'entré, de manière peigne
 * 
 * @param tab tableau de 50 entiers 
 */
void tri_peigne_decroissant_wd(tab_word tab, int limite){
    int compteur, i;
    bool trouver;
    compteur = limite;
    trouver = false; // mise en place d'un booléen pour condition d'arrêt
    while ((trouver) || (compteur>1)){ // booléen pour permettre d'arrêter le tri si le tableau est déjà trié
        trouver = false;
        compteur = compteur / 1.3;
        if (compteur<1){
          compteur=1;
          } 
        for (i=0; i<limite-compteur; i++) {
            if (strcmp(tab[i], tab[i+compteur])<0){ 
                trouver = true; // condition d'arrêt
                /*
                ces permutations permettes d'échanger deux valeurs du tableau
                */
                swap_wd(tab[i],tab[i+compteur]);
            }
        }
    }
}


void affiche_tab_wd(tab_word tab){
    int i;
    for (i=0; i<NBWORD; i++){
        printf("%s ", tab[i]);    
    }
    printf("\n");
}


int main(){
    char choix[10]; // choix pour le tri du tableau
    system("clear");
    tab_word tab = {};
    printf("tableau avant le tri :\n");
    alea_wd(tab);
    printf("\n");
    affiche_tab_wd(tab);

    printf("Quel tri voulez vous faire : croissant / decroissant\n");
    scanf("%s", choix);
    while (((strcmp(choix, "croissant") != 0) && (strcmp(choix, "decroissant") != 0))){
            printf("ressaisissez entre croissant et decroissant\n");
            scanf("%s", choix);
        }
    if (strcmp(choix, "croissant") == 0){
            printf("tableau après le tri :\n");
            tri_peigne_croissant_wd(tab, NBWORD);
        }
        else if (strcmp(choix, "decroissant") == 0){
            printf("tableau après le tri :\n");
            tri_peigne_decroissant_wd(tab, NBWORD);
        }
    printf("\n TABLEAU APRES LE TRI\n");
    affiche_tab_wd(tab);
    printf("\n");
    return EXIT_SUCCESS;
}