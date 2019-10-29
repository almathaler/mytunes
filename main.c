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
  printf("testing print list on an empty list:\n");
  print_list(pointer);
  printf("now going to add 10 songs, will print list each time:\n");
  pointer = addOrdered(pointer, "ventura highway", "america");
  print_list(pointer);
  pointer = addOrdered(pointer, "horse with no name", "america");
  print_list(pointer);
  pointer = addOrdered(pointer, "one of these nights", "eagles");
  print_list(pointer);
  pointer = addOrdered(pointer, "big empty", "stone temple pilots");
  print_list(pointer);
  pointer= addOrdered(pointer, "little wing", "jimi hendrix");
  print_list(pointer);
  pointer = addOrdered(pointer, "southern man", "neil young");
  print_list(pointer);
  pointer = addOrdered(pointer, "drive", "incubus");
  print_list(pointer);
  pointer = addOrdered(pointer, "how long", "ace");
  print_list(pointer);
  return 0;
}
