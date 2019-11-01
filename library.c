#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"
#include "library.h"

int makeIndex(char letter){
  int index;
  if (letter > 90){//lower case
    index = letter-97;
  }else{
    index = letter-65;
  }
  if (index > 26){
    index = 26;
  }
  return index;
}

void printLetter(struct song_node **table, char letter){
  //note a = 97
  int index = makeIndex(letter);
  print_list(table[index]);
}
//
void printArtist(struct song_node **table, char *artist){
  //THERE IS A PROBLEM WITH THIS -- WILL EVEN PRINT WHAT'S AFTER THIS
  struct song_node *pointer = findArtistLib(table, artist);
  if (pointer == NULL){
    printf("|  |");
  }
  while(pointer!=NULL && strcmp(pointer->artist, artist) == 0){
    printNode(pointer);
    printf(" ");
    pointer = pointer->next;
  }
  printf("\n");
}
//
void printLib(struct song_node **table){
  int i;
  for (i = 0; i<27; i++){ //like letters
    printf("printing out table[%d], points to %p, which has value: \n", i, table[i]);
    print_list(table[i]);
  }
}
//
void addLib(struct song_node **table, char *name, char *artist){
  int index = makeIndex(artist[0]);
  //printf("INDEX for %s: %d\n", name, index);
  table[index] = addOrdered(table[index], name, artist);
}
//
struct song_node * findLib(struct song_node **table, char *name, char *artist){
  int index = makeIndex(artist[0]);
  return find(table[index], name, artist);
}
//
struct song_node * findArtistLib(struct song_node **table, char *artist){
  int index = makeIndex(artist[0]);
  return findArtist(table[index], artist);
}
void deleteSong(struct song_node **table, char*name, char*artist){
  int index = makeIndex(artist[0]);
  table[index] = listRemove(table[index], name, artist);
  //return table;
}
//
void clearLib(struct song_node **table){
  int i;
  for (i=0; i<27; i++){
      printf("going to free table[%d]\n", i);
      printf("pointer of table[%d]: %p\n", i, table[i]);
      free_list(table[i]);
      printf("freed table[%d]\n", i);
  }
  table = NULL;
}
//
void shuffle(struct song_node **table){
  //loop 5 times
  int i;
  int k;
  for (i=0; i<5; i++){
    k = rand()%26;
    while (table[k] == NULL){
      k=(k+1)%26;
    }
    //printf("\nk = %d, ", k);
    printNode(randomSong(table[k]));
    printf(" ");
  }
}
