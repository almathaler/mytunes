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
  pointer = addOrdered(pointer, "pets", "porno for pyros");
  print_list(pointer);
  //printf("first\n");
  pointer = addOrdered(pointer, "angie", "rolling stones");
  //printf("second\n");
  pointer = addOrdered(pointer, "ventura highway", "america");
  //printf("third\n");
  //should print as [ventura highway, america], [pets, porno for pyros], [angie, rolling stones]
  print_list(pointer);
  return 0;
}
