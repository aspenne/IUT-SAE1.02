
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 1000

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
      int pivot = partition_cr(tab, deb, fin);

      // appel récursif sur la partie à gauche du pivot
      quickSort(tab, deb, pivot - 1);
      //appel récursif sur la partie à droite du pivot
      quickSort(tab, pivot + 1, fin);
    }
    else{
      int pivot = partition_dec(tab, deb, fin);

      // appel récursif sur la partie à gauche du pivot
      quickSort(tab, deb, pivot - 1);
      //appel récursif sur la partie à droite du pivot
      quickSort(tab, pivot + 1, fin);
    }
  }
}


void alea(int tab[], int taille){
  srand(time(NULL));
  int rand_int;
  for (int j=0;j<MAX;j++){
     rand_int = rand() % 99;
     rand_int++;
     tab[j]=rand_int;
  }
}

// affiche 20 premiers elements
void afficheTabLimite(int tab[], int lim){
  for(int i=0;i<lim;i++){
    printf("%d ", tab[i]);
  }
  printf("\n");
}

int main() {
  int tab[MAX];

  int lim;

  system("clear");
  
  alea(tab, MAX);
  printf("Combien de valeurs du tableau voulez-vous afficher ? \n");
  scanf("%d", &lim);
  while ( lim<=0 && lim>MAX){
    printf("nombre de valeurs > 0 et < 500000");
    scanf("%d", &lim);
  }

  printf("tableau avant le tri :\n");
  afficheTabLimite(tab, lim);
  
  printf("Quel tri voulez-vous faire ? croissant/décroissant : \n");
  scanf("%s", choix);

  while (strcmp(choix,"croissant") != 0 && (strcmp(choix,"décroissant")!=0)){
    printf("Saisir croissant ou décroissant \n");
    scanf("%s", choix);
  }

  clock_t begin = clock();
  quickSort(tab, 0, MAX -1);
  clock_t end = clock();

  long int millis = (end-begin) * 1000 / CLOCKS_PER_SEC;

  
  printf("tableau après le tri :\n");
  afficheTabLimite(tab, lim);

  printf("Trié en %ld ms \n", millis);
  
}