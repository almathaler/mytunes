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
#include <time.h>
#include "list.h"
#include "library.h"

int main(){
  srand(time(NULL));
  struct song_node *front = NULL;
  printf("\n\n--TESTING LIST PORTION--\n\n");
  printf("\n--testing print list on an empty list:--\n");
  print_list(front);

  printf("\n--now going to add 8 songs randomly, then print (should be alphabetical)--\n");
  front = add_ordered(front, "ventura highway", "america");
  //print_list(front);
  front = add_ordered(front, "horse with no name", "america");
  //print_list(front);
  front = add_ordered(front, "one of these nights", "eagles");
  //print_list(front);
  front = add_ordered(front, "big empty", "stone temple pilots");
  //print_list(front);
  front= add_ordered(front, "little wing", "jimi hendrix");
  //print_list(front);
  front = add_ordered(front, "southern man", "neil young");
  //print_list(front);
  front = add_ordered(front, "drive", "incubus");
  //print_list(front);
  front = add_ordered(front, "how long", "ace");
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

  printf("\n--going to free whole list, should print |   |--\n");
  front = free_list(front);
  print_list(front);

  printf("\n--rebuilding list, should print same list of 8 again--\n");
  front = add_ordered(front, "ventura highway", "america");
  front = add_ordered(front, "horse with no name", "america");
  front = add_ordered(front, "one of these nights", "eagles");
  front = add_ordered(front, "big empty", "stone temple pilots");
  front= add_ordered(front, "little wing", "jimi hendrix");
  front = add_ordered(front, "southern man", "neil young");
  front = add_ordered(front, "drive", "incubus");
  front = add_ordered(front, "how long", "ace");
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

  printf("\n--testing find (first of artist)--\n");
  printf("finding america\n");
  pointer = find_artist(front, "america");
  print_list(pointer);
  printf("adding another song by stp to test this again\n");
  front = add_ordered(front, "plush", "stone temple pilots");
  printf("finding stone temple pilots\n");
  pointer = find_artist(front, "stone temple pilots");
  print_list(pointer);

  printf("\n--finding random--\n");
  int i;
  for (i=0; i<3; i++){
    printf("random #%d\n", i);
    print_list(random_song(front));
  }
  //NOW array
  struct song_node * table[27];
  for (i=0; i<27; i++){
    table[i] = NULL;
  }
  printf("\n\n------TESTING LIBRARY------\n\n");
  printf("adding songs, then will print:\n");
  /*
  for (i=97; i<123; i++){
    char *pointer = &(i);
    char *pointer2 = &(i);
    add_lib(table, pointer, pointer2);
  }
  add_lib(table, "a", "a");
  add_lib(table, "b", "b");
  add_lib(table, "y", "y");
  add_lib(table, "z", "z");
  */
  add_lib(table, "ventura highway", "america");
  add_lib(table, "horse with no name", "america");
  add_lib(table, "dream on", "aerosmith");
  add_lib(table, "layla", "derek and the dominos");
  add_lib(table, "cocaine", "eric clapton");
  add_lib(table, "interstate love song", "stone temple pilots");
  add_lib(table, "plush", "stone temple pilots");
  add_lib(table, "big empty", "stone temple pilots");
  add_lib(table, "one of these nights", "eagles");
  add_lib(table, "hotel california", "eagles");
  add_lib(table, "if you think im sexy", "rod stewart");
  add_lib(table, "angie", "rolling stones");
  add_lib(table, "wild horses", "rolling stones");
  add_lib(table, "if you really want to be my friend", "rolling stones");
  add_lib(table, "walk on the wild side", "lou reede");
  add_lib(table, "just because", "janes addiction");
  add_lib(table, "black", "pearl jam");
  print_lib(table);

  printf("\n--TESTING PRINT ARTIST AND FIND ARTIST (print artist uses find)--\n");
  printf("\nNow going to print out all the stone temple pilots:\n");
  print_artist(table, "stone temple pilots");
  printf("And all the america songs:\n");
  print_artist(table, "america");

  printf("\n--TESTING print_letter--\n");
  printf("and now, all the 'a' songs:\n");
  print_letter(table, 'a');
  printf("and all the 'b' songs:\n");
  print_letter(table, 'b');
  printf("all the 'p' songs:\n");
  print_letter(table, 'p');

  printf("\n--TESTING FIND SONG (will print that node only, and then that node in list)--\n");
  printf("finding hotel california, will print that node then it's position:\n");
  struct song_node *p = find_lib(table, "hotel california", "eagles");
  print_node(p);
  printf("\n");
  print_list(p);
  printf("finding black by pearl jam\n");
  p = find_lib(table, "black", "pearl jam");
  print_node(p);
  printf("\n");
  print_list(p);
  printf("find a song not in the library, little wing by jimi hendrix\n");
  p = find_lib(table, "little wing", "jimi hendrix");
  print_node(p);
  printf("\n");
  print_list(p);
  printf("\n--TESTING SHUFFLE (will print 5 songs randomly)--\n");
  shuffle(table);

  printf("\n--TESTING DELETE AND CLEAR LIB--\n");
  printf("going to delete aerosmith: dream on\n");
  delete_song(table, "dream on", "aerosmith");
  print_lib(table);
  printf("going to delete interestate love song, but just print the 's' list\n");
  delete_song(table, "interstate love song", "stone temple pilots");
  print_letter(table, 's');
  printf("trying to delete something not there, spooky by atlanta rhythym section\n");
  delete_song(table, "spooky", "atlanta rhythym section");
  print_letter(table, 'a');
  printf("lastly, deleting rolling stones: wild horses\n");
  delete_song(table, "wild horses", "rolling stones");
  print_letter(table, 'r');
  printf("now going to clear entire list\n");
  clear_lib(table);
  printf("now going to see print empty list:\n");
  print_lib(table);
  printf("\n--THANK YOU!--\n");
  //
  return 0;
}
