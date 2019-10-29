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
  struct song_node *front = NULL;
  printf("\n--testing print list on an empty list:--\n");
  print_list(front);

  printf("\n--now going to add 8 songs, will print list each time:--\n");
  front = addOrdered(front, "ventura highway", "america");
  print_list(front);
  front = addOrdered(front, "horse with no name", "america");
  print_list(front);
  front = addOrdered(front, "one of these nights", "eagles");
  print_list(front);
  front = addOrdered(front, "big empty", "stone temple pilots");
  print_list(front);
  front= addOrdered(front, "little wing", "jimi hendrix");
  print_list(front);
  front = addOrdered(front, "southern man", "neil young");
  print_list(front);
  front = addOrdered(front, "drive", "incubus");
  print_list(front);
  front = addOrdered(front, "how long", "ace");
  print_list(front);

  printf("\n--now going to test removing a node--\n");
  front = listRemove(front, "big empty", "stone temple pilots");
  printf("removed big empty\n");
  print_list(front);
  front = listRemove(front, "how long", "ace");
  printf("removed how long\n");
  print_list(front);
  front = listRemove(front, "one of these nights", "eagles");
  printf("removed one of these nights\n");
  print_list(front);

  printf("\n--going to free whole list--\n");
  front = free_list(front);
  print_list(front);

  printf("\n--rebuilding list--\n");
  front = addOrdered(front, "ventura highway", "america");
  front = addOrdered(front, "horse with no name", "america");
  front = addOrdered(front, "one of these nights", "eagles");
  front = addOrdered(front, "big empty", "stone temple pilots");
  front= addOrdered(front, "little wing", "jimi hendrix");
  front = addOrdered(front, "southern man", "neil young");
  front = addOrdered(front, "drive", "incubus");
  front = addOrdered(front, "how long", "ace");
  print_list(front);

  printf("\n--testing find--\n");
  printf("will print list from front pointing to song\n");
  struct song_node *pointer = front;
  printf("finding ventura highway, printing from there:\n");
  pointer = find(front, "ventura highway", "america");
  print_list(pointer);
  printf("finding big empty, printing from there:\n");
  pointer = find(front, "big empty", "stone temple pilots");
  print_list(pointer);
  printf("finding how long, printing from there:\n");
  pointer = find(front, "how long", "ace");
  print_list(pointer);
  return 0;
}
