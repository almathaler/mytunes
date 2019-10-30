#include <stdlib.h>
#include <stdio.h>
#include "list.h"
#include "library.h"

int makeIndex(char letter){
  int index;
  if (letter > 90){//lower case
    index = letter-97;
  }else(
    index = letter-65;
  )
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
  int index = makeIndex(artist[0]); //where in array we will access
  print_list(findArtist(table[index], artist));
}
//
void printLib(struct song_node **table){
  int i;
  for (i = 0; i<27; i++){
    printLetter(table, i);
  }
}
