#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define N 10
typedef int tableau[N];

/**
 * @brief cette procédure permet d'échanger deux valeurs en en utili
 * 
 * @param tab 
 * @param i 
 * @param j 
 */
void exchange(tableau tab, int i, int j){
    int indice_tmp,
        compteur_echange;
    compteur_echange = 0;
    indice_tmp = tab[i];
    tab[i] = tab[j];
    tab[j] = indice_tmp;
    compteur_echange ++;
}

void insertion_croissant(tableau tab){
    int i, j, min, imin;
    for (i=0; i<N-1; i++){
        min=tab[i];  
        imin = i; 
        for (j=i+1; j < N; j++){
            if (tab[j] < min){
                min = tab[j];
                imin = j;
            }
        }
        exchange(tab, i, imin); 
    }
}

void insertion_decroissant(tableau tab){
    int i, j, min, imin;
    for (i=0; i<N-1; i++){
        min=tab[i];  
        imin = i; 
        for (j=i+1; j < N; j++){
            if (tab[j] > min){
                min = tab[j];
                imin = j;
            }
        }
        exchange(tab, i, imin); 
    }
}

void affiche_tab(tableau tab){
    int i;
    for (i=0; i<N; i++){
        printf("%d, ", tab[i]);
    }
}

int main(){
    char choix[10];
    system("clear");
    tableau tab = {99, 47, 54, 12, 25, 39, 18, 26, 81, 39};
    // tableau tab_fav = {12, 18, 25, 26, 39, 39, 47, 54, 81, 99};
    // tableau tab_defav = {99, 81, 54, 47, 39, 39, 26, 25, 18, 12};
    printf("\t\tTRI PAR SELECTION\n");
    printf("\n");
    printf("tableau avant le tri :\n");
    affiche_tab(tab);
    printf("\n\n");
    printf("Quel tri voulez vous faire : croissant / decroissant\n");
    scanf("%s", choix);
    printf("\n");
    while (((strcmp(choix, "croissant") != 0) && (strcmp(choix, "decroissant") != 0))){
            printf("ressaisissez entre croissant et decroissant\n");
            scanf("%s", choix);
        }
    if (strcmp(choix, "croissant") == 0){
            printf("tableau après le tri :\n");
            insertion_croissant(tab);
        }
    else{
            printf("tableau après le tri :\n");
            insertion_decroissant(tab);
        }
    affiche_tab(tab);
    printf("\n");
    return EXIT_SUCCESS;
}