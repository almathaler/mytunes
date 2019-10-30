#include <stdlib.h>
#include <stdio.h>
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
  int index = makeIndex(artist[0]); //where in array we will access
  print_list(findArtist(table[index], artist));
}
//
void printLib(struct song_node **table){
  int i;
  for (i = 0; i<27; i++){ //like letters
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
}
//
void clearLib(struct song_node **table){
  int i;
  for (i=0; i<27; i++){
    free_list(table[i]);
  }
}
//
void shuffle(struct song_node **table){
  //loop 5 times
  int i;
  int k;
  for (i=0; i<5; i++){
    k = rand()%26;
    printNode(randomSong(table[k]));
  }
}
