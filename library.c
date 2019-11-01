#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"
#include "library.h"

int make_index(char letter){
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

void print_letter(struct song_node **table, char letter){
  //note a = 97
  int index = make_index(letter);
  print_list(table[index]);
}
//
void print_artist(struct song_node **table, char *artist){
  //THERE IS A PROBLEM WITH THIS -- WILL EVEN PRINT WHAT'S AFTER THIS
  struct song_node *pointer = find_artist_lib(table, artist);
  if (pointer == NULL){
    printf("|  |");
  }
  while(pointer!=NULL && strcmp(pointer->artist, artist) == 0){
    print_node(pointer);
    printf(" ");
    pointer = pointer->next;
  }
  printf("\n");
}
//
void print_lib(struct song_node **table){
  int i;
  for (i = 0; i<27; i++){ //like letters
    //printf("printing out table[%d], points to %p, which has value: \n", i, table[i]);
    print_list(table[i]);
  }
}
//
void add_lib(struct song_node **table, char *name, char *artist){
  int index = make_index(artist[0]);
  //printf("INDEX for %s: %d\n", name, index);
  table[index] = add_ordered(table[index], name, artist);
}
//
struct song_node * find_lib(struct song_node **table, char *name, char *artist){
  int index = make_index(artist[0]);
  return find(table[index], name, artist);
}
//
struct song_node * find_artist_lib(struct song_node **table, char *artist){
  int index = make_index(artist[0]);
  return find_artist(table[index], artist);
}
void delete_song(struct song_node **table, char*name, char*artist){
  int index = make_index(artist[0]);
  table[index] = listRemove(table[index], name, artist);
  //return table;
}
//
void clear_lib(struct song_node **table){
  int i;
  for (i=0; i<27; i++){
      //printf("going to free table[%d]\n", i);
      //printf("pointer of table[%d]: %p\n", i, table[i]);
      free_list(table[i]);
      //printf("freed table[%d]\n", i);
      //printf("where table[%d} points to now: %p\n", i, table[i]);
  }
  for(i=0; i<27; i++){
    table[i] = NULL;
  }
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
    print_node(random_song(table[k]));
    printf(" ");
  }
}
