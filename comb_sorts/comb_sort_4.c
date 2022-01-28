#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

#define N 10
#define NBWORD 150000
#define NB_INT 500000
#define MAX 11


typedef int big_tableau[NB_INT];


typedef char tab_word[NBWORD][MAX];

int nombre, letters;

int nb_permut;
int nb_cmp;
int nb_permut_word;
int nb_cmp_word;

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
  nb_permut_word++;
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
            nb_cmp_word++;
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
            nb_cmp_word++;
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

/**
 * @brief cette procédure affiche le tableau de longueur MAX du tableau
 * 
 * @param tab 
 */
void affiche_tab_wd(tab_word tab){
    int i;
    for (i=0; i<NBWORD; i++){
        printf("%s ", tab[i]);    
    }
    printf("\n");
}


/**
 * @brief cette procédure prend en paramètre d'entré un tableau et le rempli de nombre 
 *        aléatoire entre   1 et 9999 jusqu'à la taille MAX du tableau
 * 
 * @param tab tableau d'entier
 */
void alea_nb(big_tableau tab){
  int i, j, nb_alea;
  srand(time(NULL)); // mise en place sur l'horloge interne
  for (i=0; i<NB_INT; i++){
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
void tri_peigne_croissant_nb(big_tableau tab, int limite){
    int compteur, i;
    bool trouver;
    compteur = limite; // taille du tableau
    trouver = false; // mise en place d'un booléen pour condition d'arrêt
    while (( trouver) || (compteur>1)){ // booléen pour permettre d'arrêter le tri si le tableau est déjà trié
        trouver = false;
        compteur = compteur / 1.3;
        if (compteur<1) compteur=1;
        for (i=0; i<limite-compteur; i++) {
            nb_cmp++;
            if (tab[i]>tab[i+compteur]){ 
                trouver = true; // condition d'arrêt
                /*
                ces permutations permettes d'échanger deux valeurs du tableau
                */
                int temp = tab[i];
                tab[i] = tab[i+compteur];  
                tab[i+compteur] = temp;
                nb_permut++;
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
void tri_peigne_decroissant_nb(big_tableau tab, int limite){
    int compteur, i;
    bool trouver;
    compteur = limite;
    trouver = false; // mise en place d'un booléen pour condition d'arrêt
    while (( trouver) || (compteur>1)){ // booléen pour permettre d'arrêter le tri si le tableau est déjà trié
        trouver = false;
        compteur = compteur / 1.3;
        if (compteur<1) compteur=1;
        for (i=0; i<limite-compteur; i++) {
            nb_cmp++;
            if (tab[i]<tab[i+compteur]){ 
                trouver = true; // condition d'arrêt
                /*
                ces permutations permettes d'échanger deux valeurs du tableau
                */
                int temp = tab[i];
                tab[i] = tab[i+compteur];   
                tab[i+compteur] = temp;
                nb_permut++;
            }
        }
    }
}

/**
 * @brief cette procédure affiche le tableau de longeur MAX
 * 
 * @param tab_nb 
 */
void affiche_tab_nb(big_tableau tab_nb){
    int i;
    for (i=0; i<NB_INT; i++){
        printf("%d ", tab_nb[i]);    
    }
    printf("\n");
}

int main(){
    char choix1[10];
    char choix[10];
    system("clear");
    printf("quel tyoe de tableau voulez vous trier : mots / nombres ");
    scanf("%s", choix1);
    if (strcmp(choix1, "nombres") == 0){
        big_tableau tab_nb = {};
        alea_nb(tab_nb);
        printf("tableau avant le tri :\n");
        affiche_tab_nb(tab_nb);
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
                tri_peigne_croissant_nb(tab_nb, NB_INT);
            }
        else{
                printf("tableau après le tri :\n");
                tri_peigne_decroissant_nb(tab_nb, NB_INT);
            }
        clock_t end = clock();
        double tempCPU = (end - start)*1.0 / CLOCKS_PER_SEC;
        affiche_tab_nb(tab_nb);

        
        
        
        printf("\nTemps CPU du tri : %.3f sec\n", tempCPU);
        printf("\nnombre de permutations : %d\n", nb_permut);
        printf("\nnombre de comparaisons : %d\n", nb_cmp);
    }
    else if (strcmp(choix1, "mots") == 0){
        tab_word tab_w = {};
        alea_wd(tab_w);
        printf("tableau avant le tri :\n");
        affiche_tab_wd(tab_w);
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
                tri_peigne_croissant_wd(tab_w, NBWORD);
            }
        else{
                printf("tableau après le tri :\n");
                tri_peigne_decroissant_wd(tab_w, NBWORD);
            }
        clock_t end = clock();
        double tempCPU = (end - start)*1.0 / CLOCKS_PER_SEC;
        affiche_tab_wd(tab_w);
        printf("\n");

        printf("\nTemps CPU du tri : %.3f sec\n", tempCPU);
        printf("\nnombre de permutations : %d\n", nb_permut_word);
        printf("\nnombre de comparaisons : %d\n", nb_cmp_word);

    }

    printf("\n");
    return EXIT_SUCCESS;
}
