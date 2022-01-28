
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

char choix[20];


void echange(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int partition_dec(int tab[], int deb, int fin) {
  
  int pivot = tab[fin];
  
  int i = (deb - 1);


  //on compare avec le pivot tous les elements du tab
  for (int j = deb; j < fin; j++) {
    if (tab[j] >= pivot) {
        
      // si un element plus petit que le pivot
      // on l'échange avec avec l'élément le plsu grand
      // echange it with the greater element pointed by i
      i++;
      echange(&tab[i], &tab[j]);
    }
  }

  // echange the pivot element with the greater element at i
  // on échange le pivot avec l'element plus grand d'indice i
  echange(&tab[i + 1], &tab[fin]);
  
  // on délivre l'indice du "point de partition_dec_dec"
  return (i + 1);
}
int partition_cr(int tab[], int deb, int fin) {
  
  int pivot = tab[fin];
  
  int i = (deb - 1);


  //on compare avec le pivot tous les elements du tab
  for (int j = deb; j < fin; j++) {
    if (tab[j] <= pivot) {
        
      // si un element plus petit que le pivot
      // on l'échange avec avec l'élément le plsu grand
      // echange it with the greater element pointed by i
      i++;
      echange(&tab[i], &tab[j]);
    }
  }

  // echange the pivot element with the greater element at i
  // on échange le pivot avec l'element plus grand d'indice i
  echange(&tab[i + 1], &tab[fin]);
  
  // on délivre l'indice du "point de partition_dec_dec"
  return (i + 1);
}

void quickSort(int tab[], int deb, int fin) {
  if (deb < fin){
    
    // trouver le pivot tel que les élements plsu petit que le pivot sont à sa          gauche, et les éléments à sa droite soit plus grand 
    if (strcmp(choix,"croissant")==0){
      int pi = partition_cr(tab, deb, fin);

      // appel récursif sur la partie à gauche du pivot
      quickSort(tab, deb, pi - 1);
      //appel récursif sur la partie à droite du pivot
      quickSort(tab, pi + 1, fin);
    }
    else{
      int pi = partition_dec(tab, deb, fin);

      // appel récursif sur la partie à gauche du pivot
      quickSort(tab, deb, pi - 1);
      //appel récursif sur la partie à droite du pivot
      quickSort(tab, pi + 1, fin);
    }
    
    
    
    
    
  }
}

void afficheTab(int tab[], int taille) {
  for (int i = 0; i < taille; ++i) {
    printf("%d  ", tab[i]);
  }
  printf("\n");
}

int main() {
  int tab[MAX] = {99, 47, 54, 12, 25, 39, 18, 26, 81, 39};
  //int tab_fav[MAX] = {12, 18, 25, 26, 39, 39, 47, 54, 81, 99}; 
  //int tab_defav[MAX] = {99, 81, 54, 47, 39, 39, 26, 25, 18, 12};

  printf("\t\t TRI RAPIDE\n");
  printf("\n");
    
  printf("tableau avant le tri :\n");
  afficheTab(tab, MAX);
  printf("\n");
  
  printf("Quel tri voulez-vous faire ? croissant/décroissant : \n");
  scanf("%s", choix);
  printf("\n");
  while (strcmp(choix,"croissant") != 0 && (strcmp(choix,"décroissant")!=0)){
    printf("Saisir croissant ou décroissant \n");
    scanf("%s", choix);
  }
  quickSort(tab, 0, MAX -1);
  
  printf("tableau après le tri :\n");
  afficheTab(tab, MAX);
}