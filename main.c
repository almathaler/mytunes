/*
Write a program in C that implements a music library organizer.
The data structure should consist of an array of 27 slots (one for each letter from 'a' to 'z',
and another for other symbols). Each slot will contain a linked list of all the artists that
have names that start with the corresponding letter. When you add a song, it should go on to
a linked list at the appropriate array slot in the correct position alphabetically. Assume no
duplicate songs.
*/
#include <stdlib.h>
#include <stdio.h>
#include "list.h"

int main(){
  struct song_node *pointer = NULL;
  print_list(pointer);
  pointer = insert_front(pointer, "ventura highway", "america");
  pointer = insert_front(pointer, "angie", "the rolling stones");
  pointer = insert_front(pointer, "hallelujah", "alpha beta");
  print_list(pointer);
  pointer = listRemove(pointer, "angie", "the rolling stones");
  print_list(pointer);
  pointer = listRemove(pointer, "hallelujah", "alpha beta");
  print_list(pointer);
  pointer = insert_front(pointer, "you can do magic", "america");
  pointer = insert_front(pointer, "southern man", "neil young");
  print_list(pointer);
  pointer = free_list(pointer);
  print_list(pointer);
  return 0;
}
