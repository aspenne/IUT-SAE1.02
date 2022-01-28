#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

#define N 10
#define NB_INT 50 

typedef int big_tableau[NB_INT];

void alea(big_tableau tab){
  int i, nb_alea;
  srand(time(NULL)); 
  for (i=0; i<NB_INT; i++){
    nb_alea = rand() % RAND_MAX;    
    nb_alea++;
    tab[i] = nb_alea;
  }
}

void exchange(int tab_limit[], int i, int j){
    int indice_tmp,
        compteur_echange;
        compteur_echange = 0;
        indice_tmp = tab_limit[i];
        tab_limit[i] = tab_limit[j];
        tab_limit[j] = indice_tmp;
        compteur_echange ++;
}

void insertion_croissant(int tab_limit[], int limite){
    int i, j, min, imin;
    for (i=0; i<limite-1; i++){
        min=tab_limit[i];  
        imin = i; 
        for (j=i+1; j<limite; j++){
            if (tab_limit[j] < min){
                min = tab_limit[j];
                imin = j;
            }
        }
        exchange(tab_limit, i, imin); 
    }
}

void insertion_decroissant(int tab_limit[], int limite){
    int i, j, min, imin;
    for (i=0; i<limite-1; i++){
        min=tab_limit[i];  
        imin = i; 
        for (j=i+1; j < limite; j++){
            if (tab_limit[j] > min){
                min = tab_limit[j];
                imin = j;
            }
        }
        exchange(tab_limit, i, imin); 
    }
}

void affiche_tab_limite(big_tableau tab, int limite, int tab_limit[]){
    int i;
    for (i=0; i<limite; i++){
        tab_limit[i] = tab[i];
        printf("%d ", tab_limit[i]);
    }
}

void affiche_tab(int tab_limit[], int limite){
    int i;
    for (i=0; i<limite; i++){
        printf("%d ", tab_limit[i]);
    }
}




int main(){
    int limite;
    char choix[10];
    system("clear");
    printf("Combien de nombre voulez-vous afficher ?\n");
    scanf("%d", &limite);
    big_tableau tab = {};
    int tab_limit[limite];
    alea(tab);
    printf("tableau avant le tri :\n");
    affiche_tab_limite(tab, limite, tab_limit);
    printf("\n");
    printf("Quel tri voulez vous faire : croissant / decroissant\n");
    scanf("%s", choix);
    while (((strcmp(choix, "croissant") != 0) && (strcmp(choix, "decroissant") != 0))){
            printf("ressaisissez entre croissant et decroissant\n");
            scanf("%s", choix);
    }
    if (strcmp(choix, "croissant") == 0){
            printf("tableau après le tri :\n");
            insertion_croissant(tab_limit, limite);
        }
    else{
            printf("tableau après le tri :\n");
            insertion_decroissant(tab_limit, limite);
        }
    affiche_tab(tab_limit, limite);
    printf("\n");
    return EXIT_SUCCESS;
}

