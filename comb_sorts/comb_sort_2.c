#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define N 10
#define MAX 50 // taille du tableau

typedef int big_tableau[MAX];

/**
 * @brief cette procédure prend en paramètre d'entré un tableau et le rempli de nombre 
 *        aléatoire entre   1 et 9999 jusqu'à la taille MAX du tableau
 * 
 * @param tab tableau d'entier
 */
void alea(big_tableau tab){
  int i, j, nb_alea;
  srand(time(NULL)); // mise en place sur l'horloge interne
  for (i=0; i<MAX; i++){
    nb_alea = rand() % RAND_MAX; // de 0 à RAND_MAX-1
    nb_alea++; // pour passer de 0 / RAND_MAX-1 à 1 / RAND_MAX
    tab[i] = nb_alea;
  }
}

/**
 * @brief cette procédure tri de manière croissant un tableau donné en entré
 *        paramètres d'entré, de manière peigne
 * 
 * @param tab tableau de 50 entiers
 */
void tri_peigne_croissant(int tab_temp[], int limite){
    int compteur, i;
    bool trouver;
    compteur = limite; // taille du tableau
    trouver = false; // mise en place d'un booléen pour condition d'arrêt
    while (( trouver) || (compteur>1)){ // booléen pour permettre d'arrêter le tri si le tableau est déjà trié
        trouver = false;
        compteur = compteur / 1.3;
        if (compteur<1) compteur=1;
        for (i=0; i<limite-compteur; i++) {
            if (tab_temp[i]>tab_temp[i+compteur]){ 
                trouver = true; // condition d'arrêt
                /*
                ces permutations permettes d'échanger deux valeurs du tableau
                */
                int temp = tab_temp[i];
                tab_temp[i] = tab_temp[i+compteur];  
                tab_temp[i+compteur] = temp;
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
void tri_peigne_decroissant(int tab_temp[], int limite){
    int compteur, i;
    bool trouver;
    compteur = limite;
    trouver = false; // mise en place d'un booléen pour condition d'arrêt
    while (( trouver) || (compteur>1)){ // booléen pour permettre d'arrêter le tri si le tableau est déjà trié
        trouver = false;
        compteur = compteur / 1.3;
        if (compteur<1) compteur=1;
        for (i=0; i<limite-compteur; i++) {
            if (tab_temp[i]<tab_temp[i+compteur]){ 
                trouver = true; // condition d'arrêt
                /*
                ces permutations permettes d'échanger deux valeurs du tableau
                */
                int temp = tab_temp[i];
                tab_temp[i] = tab_temp[i+compteur];   
                tab_temp[i+compteur] = temp;
            }
        }
    }
}

/**
 * @brief cette fonction prend en paramètre d'entrée un tableau et permet
 *        de resortir un tableau d'un certain nombre d'entier
 * 
 * @param tab nouveau de tableau de [limite] caractères 
 * @param limite nombre de caractères à afficher
 * @param tab_temp tableau trié
 */
void affiche_tab_limite(big_tableau tab, int limite, int tab_temp[]){
    int i;
    for (i=0; i<limite; i++){
        tab_temp[i] = tab[i];
        printf("%d ", tab_temp[i]);  
    }
}

void affiche_tab(int tab_temp[], int limite){
    int i;
    for (i=0; i<limite; i++){
        printf("%d ", tab_temp[i]);    
    }
}


int main(){
    int limite; // longueur du tableau trié à affiché
    char choix[10]; // choix pour le tri du tableau
    system("clear");
    big_tableau tab = {};
    printf("Combien de nombre voulez-vous afficher ?\n");
    scanf("%d", &limite);
    printf("tab_templeau avant le tri :\n");
    int tab_temp[limite]; 
    alea(tab);
    affiche_tab_limite(tab, limite, tab_temp);
    printf("\n");
    printf("Quel tri voulez vous faire : croissant / decroissant\n");
    scanf("%s", choix);
    while (((strcmp(choix, "croissant") != 0) && (strcmp(choix, "decroissant") != 0))){
            printf("ressaisissez entre croissant et decroissant\n");
            scanf("%s", choix);
        }
    if (strcmp(choix, "croissant") == 0){
            printf("tableau après le tri :\n");
            tri_peigne_croissant(tab_temp, limite);
        }
        else if (strcmp(choix, "decroissant") == 0){
            printf("tableau après le tri :\n");
            tri_peigne_decroissant(tab_temp, limite);
        }
    affiche_tab(tab_temp, limite);
    printf("\n");
    return EXIT_SUCCESS;
}