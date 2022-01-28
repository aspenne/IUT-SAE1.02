#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

#define N 10
#define NB_INT 500000
#define NBWORD 150000
#define MAX 11  

typedef char tab_word[NBWORD][MAX];

int nombre, letters;

typedef int big_tableau[NB_INT];

int nb_permut;
long int nb_cmp;
int nb_permut_word;
int nb_cmp_word;


void alea(big_tableau tab){
  int i, nb_alea;
  srand(time(NULL)); 
  for (i=0; i<NB_INT; i++){
    nb_alea = rand() % RAND_MAX;    
    nb_alea++;
    tab[i] = nb_alea;
  }
}

void exchange(big_tableau tab, int i, int j){
    int indice_tmp;
        indice_tmp = tab[i];
        tab[i] = tab[j];
        tab[j] = indice_tmp;
}

void insertion_croissant(big_tableau tab){
    int i, j, min, imin;
    for (i=0; i<NB_INT-1; i++){
        min=tab[i];  
        imin = i; 
        for (j=i+1; j<NB_INT; j++){
            if (tab[j] < min){
                min = tab[j];
                imin = j;
                nb_cmp++;
            }
        }
        exchange(tab, i, imin); 
        nb_permut++;
    }
}

void insertion_decroissant(big_tableau tab){
    int i, j, min, imin;
    for (i=0; i<NB_INT-1; i++){
        min=tab[i];  
        imin = i; 
        for (j=i+1; j < NB_INT; j++){
            if (tab[j] > min){
                min = tab[j];
                imin = j;
                nb_cmp++;
                
            }
        }
        exchange(tab, i, imin); 
        nb_permut++;
    }
}

void affiche_tab(big_tableau tab){
    int i;
    for (i=0; i<NB_INT; i++){
        tab[i] = tab[i];
        printf("%d ", tab[i]);
    }
}


void alea_word(tab_word tab){
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


void insertion_croissant_word(tab_word tab, int limite){
    int i, j, imin;
    char min[11];
    for (i=0; i<limite-1; i++){
        strcpy(min,tab[i]);
        imin = i; 
        for (j=i+1; j<limite; j++){
            if (strcmp(tab[j],min)<0){
                strcpy(min,tab[j]);
                imin = j;
                nb_cmp_word++;
            }
        }
        swap(tab[i],tab[imin]); 
        nb_permut_word++;
    }
}

void insertion_decroissant_word(tab_word tab, int limite){
    int i, j, imin;
    char min[11];
    for (i=0; i<limite-1; i++){
        strcpy(min,tab[i]);
        imin = i; 
        for (j=i+1; j < limite; j++){
            if (strcmp(tab[j],min)>0){
                strcpy(min,tab[j]);
                imin = j;
                nb_cmp_word++;
                
            }
        }
        swap(tab[i],tab[imin]); 
        nb_permut_word++;
    }
}


void affiche_tab_word(tab_word tab){
    int i;
    for (i=0; i<NBWORD; i++){
        printf("%s ", tab[i]);
    }
}

int main(){
    char choix1[10];
    char choix[10];
    
    system("clear");
    printf("quel tyoe de tableau voulez vous trier : mots / nombres ");
    printf("\n");
    scanf("%s", choix1);
    while ((strcmp(choix1, "nombres") != 0 ) && (strcmp(choix1, "mots") != 0)){
        printf("quel type de tableau voulez vous trier : mots / nombres ");
        printf("\n");
        scanf("%s", choix1);
    }
        if (strcmp(choix1, "nombres") == 0){
            big_tableau tab = {};
            alea(tab);
            printf("tableau avant le tri :\n");
            affiche_tab(tab);
            printf("\n");
            printf("Quel tri voulez vous faire : croissant / decroissant\n");
            scanf("%s", choix);
            while (((strcmp(choix, "croissant") != 0) && (strcmp(choix, "decroissant") != 0))){
                    printf("ressaisissez entre croissant et decroissant\n");
                    scanf("%s", choix);
            }
            clock_t start = clock();
            if (strcmp(choix, "croissant") == 0){
                    printf("tableau après le tri :\n");
                    insertion_croissant(tab);
                }
            else{
                    printf("tableau après le tri :\n");
                    insertion_decroissant(tab);
                }
            clock_t end = clock();
            double tempCPU = (end - start)*1.0 / CLOCKS_PER_SEC;
            affiche_tab(tab);

            
            
            
            printf("\nTemps CPU du tri : %.3f sec\n", tempCPU);
            printf("\nnombre de permutations : %d\n", nb_permut);
            printf("\nnombre de comparaisons : %ld\n", nb_cmp);
        }

        else{
            tab_word tab_w = {};
            alea_word(tab_w);
            printf("tableau avant le tri :\n");
            affiche_tab_word(tab_w);
            printf("\n");
            printf("Quel tri voulez vous faire : croissant / decroissant\n");
            scanf("%s", choix);
            while (((strcmp(choix, "croissant") != 0) && (strcmp(choix, "decroissant") != 0))){
                    printf("ressaisissez entre croissant et decroissant\n");
                    scanf("%s", choix);
            }
            clock_t start = clock();
            if (strcmp(choix, "croissant") == 0){
                    printf("tableau après le tri :\n");
                    insertion_croissant_word(tab_w, NBWORD);
                }
            else{
                    printf("tableau après le tri :\n");
                    insertion_decroissant_word(tab_w, NBWORD);
                }
            clock_t end = clock();
            double tempCPU = (end - start)*1.0 / CLOCKS_PER_SEC;
            affiche_tab_word(tab_w);
            printf("\n");

            printf("\nTemps CPU du tri : %.3f sec\n", tempCPU);
            printf("\nnombre de permutations : %d\n", nb_permut_word);
            printf("\nnombre de comparaisons : %d\n", nb_cmp_word);

            }
    printf("\n");
    return EXIT_SUCCESS;
}