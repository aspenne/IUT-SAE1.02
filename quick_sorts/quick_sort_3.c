#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 2
char choix[20];


typedef char tab_word[100][11];

int count, wordLength;


void echange(char a[11], char b[11]) {
  char t[11];
  strcpy(t,a);
  strcpy(a,b);
  strcpy(b,t);
}


void alea_wd(tab_word tab){
  int i, j, taille;
  srand(time(NULL)); 
  for (i=0; i<100; i++){
    taille = 6 + rand() % 5;
    for (j=0; j<taille; j++){
        tab[i][j] = 'a' + rand() % 26; 
    }
    tab[i][j] = '\0';
  }
}


int partition_dec(char randomWord[count][wordLength], int deb, int fin) {
  
  char pivot[11];
  strcpy(pivot, randomWord[fin]);
  
  int i = (deb - 1);


  //on compare avec le pivot tous les elements du tab
  for (int j = deb; j < fin; j++){
    if (strcmp(randomWord[j],pivot)>0){
        
      // si un element plus petit que le pivot
      // on l'échange avec avec l'élément le plus grand
      i++;
      echange(randomWord[i], randomWord[j]);
    }
  }

  // echange the pivot element with the greater element at i
  // on échange le pivot avec l'element pluru'h s grand d'indice i
  echange(randomWord[i + 1], randomWord[fin]);
  
  // on délivre l'indice du "point de partition_dec_dec"
  return (i + 1);
}
int partition_cr(char randomWord[count][wordLength], int deb, int fin) {
  
  char pivot[11];
  strcpy(pivot,randomWord[fin]);
  
  int i = (deb - 1);


  //on compare avec le pivot tous les elements du tab
  for (int j = deb; j < fin; j++){
    if (strcmp(randomWord[j],pivot)<0){
        
      // si un element plus petit que le pivot
      // on l'échange avec avec l'élément le plsu grand
      i++;
      echange(randomWord[i], randomWord[j]);
    }
  }

  // echange the pivot element with the greater element at i
  // on échange le pivot avec l'element plus grand d'indice i
  echange(randomWord[i + 1], randomWord[fin]);
  
  // on délivre l'indice du "point de partition_dec_dec"
  return (i + 1);
}

void quickSort(char randomWord[count][wordLength], int deb, int fin) {
  if (deb < fin){
    
    // trouver le pivot tel que les élements plsu petit que le pivot sont à sa          gauche, et les éléments à sa droite soit plus grand 
    if (strcmp(choix,"croissant")==0){
      int pi = partition_cr(randomWord, deb, fin);

      // appel récursif sur la partie à gauche du pivot
      quickSort(randomWord, deb, pi - 1);
      // appel récursif sur la partie à droite du pivot
      quickSort(randomWord, pi + 1, fin);
    }
    else{
      int pi = partition_dec(randomWord, deb, fin);

      // appel récursif sur la partie à gauche du pivot
      quickSort(randomWord, deb, pi - 1);
      // appel récursif sur la partie à droite du pivot
      quickSort(randomWord, pi + 1, fin);
    }
  }
}



void afficheTabLimite(tab_word randomWord, int lim){
  for (int i = 0; i<lim;i++){
    printf("%s \n", randomWord[i]);
  }
  printf("\n");
}

int main() {
  tab_word randomWord; 
  int lim=-1; // -1 sert à vérifier qu'une valeur sera bien saisi dans lim pour éviter de saisir une chaine de caractère amsi que le programme continu

  srand(time(NULL));
  

  system("clear");
  alea_wd(randomWord);
  printf("Combien de valeurs du tableau voulez-vous afficher ? \n");
  scanf("%d", &lim);
  while ((lim<=0) && lim>MAX){
    printf("nombre de valeurs > 0 et < %d", MAX);
    scanf("%d", &lim);
  }
  printf("          TRI RAPIDE\n");
  printf("tableau avant le tri :\n");
  afficheTabLimite(randomWord, lim);
  
  printf("Quel tri voulez-vous faire ? croissant/décroissant : \n");
  scanf("%s", choix);

  while (strcmp(choix,"croissant") != 0 && (strcmp(choix,"décroissant")!=0)){
    printf("Saisir croissant ou décroissant \n");
    scanf("%s", choix);
  }

  quickSort(randomWord, 0, MAX -1);
  printf("tableau après le tri :\n");
  afficheTabLimite(randomWord, lim);


}