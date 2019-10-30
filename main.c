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
  printf("\n--testing print list on an empty list:--\n");
  print_list(front);

  printf("\n--now going to add 8 songs, will print list each time:--\n");
  front = addOrdered(front, "ventura highway", "america");
  //print_list(front);
  front = addOrdered(front, "horse with no name", "america");
  //print_list(front);
  front = addOrdered(front, "one of these nights", "eagles");
  //print_list(front);
  front = addOrdered(front, "big empty", "stone temple pilots");
  //print_list(front);
  front= addOrdered(front, "little wing", "jimi hendrix");
  //print_list(front);
  front = addOrdered(front, "southern man", "neil young");
  //print_list(front);
  front = addOrdered(front, "drive", "incubus");
  //print_list(front);
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

  printf("\n--testing find (first of artist)--\n");
  printf("finding america\n");
  pointer = findArtist(front, "america");
  print_list(pointer);
  printf("adding another song by stp to test this again\n");
  front = addOrdered(front, "plush", "stone temple pilots");
  printf("finding stone temple pilots\n");
  pointer = findArtist(front, "stone temple pilots");
  print_list(pointer);

  printf("\n--finding random--\n");
  int i;
  for (i=0; i<3; i++){
    printf("random #%d\n", i);
    print_list(randomSong(front));
  }
  //NOW array
  struct song_node * table[27];
  for (i=0; i<27; i++){
    table[i] = NULL;
  }
  printf("\n\n------TESTING LIBRARY------\n\n");
  printf("adding songs\n");
  /*
  for (i=97; i<123; i++){
    char *pointer = &(i);
    char *pointer2 = &(i);
    addLib(table, pointer, pointer2);
  }
  addLib(table, "a", "a");
  addLib(table, "b", "b");
  addLib(table, "y", "y");
  addLib(table, "z", "z");
  */
  addLib(table, "ventura highway", "america");
  addLib(table, "horse with no name", "america");
  addLib(table, "dream on", "aerosmith");
  addLib(table, "layla", "derek and the dominos");
  addLib(table, "cocaine", "eric clapton");
  addLib(table, "interstate love song", "stone temple pilots");
  addLib(table, "plush", "stone temple pilots");
  addLib(table, "big empty", "stone temple pilots");
  addLib(table, "one of these nights", "eagles");
  addLib(table, "hotel california", "eagles");
  addLib(table, "if you think im sexy", "rod stewart");
  addLib(table, "angie", "rolling stones");
  addLib(table, "wild horses", "rolling stones");
  addLib(table, "if you really want to be my friend", "rolling stones");
  addLib(table, "walk on the wild side", "lou reede");
  addLib(table, "just because", "janes addiction");
  addLib(table, "black", "pearl jam");
  printLib(table);

  printf("\n--TESTING PRINT ARTIST AND FIND ARTIST (print artist uses find)--\n");
  printf("\nNow going to print out all the stone temple pilots:\n");
  printArtist(table, "stone temple pilots");
  printf("And all the america songs:\n");
  printArtist(table, "america");

  printf("\n--TESTING PRINTLETTER--\n");
  printf("and now, all the 'a' songs:\n");
  printLetter(table, 'a');
  printf("and all the 'b' songs:\n");
  printLetter(table, 'b');
  printf("all the 'p' songs:\n");
  printLetter(table, 'p');

  printf("\n--TESTING FIND SONG (will print that node only, and then that node in list)--\n");
  printf("finding hotel california, will print that node then it's position:\n");
  struct song_node *p = findLib(table, "hotel california", "eagles");
  printNode(p);
  printf("\n");
  print_list(p);
  printf("finding black by pearl jam\n");
  p = findLib(table, "black", "pearl jam");
  printNode(p);
  printf("\n");
  print_list(p);
  printf("find a song not in the library, little wing by jimi hendrix\n");
  p = findLib(table, "little wing", "jimi hendrix");
  printNode(p);
  printf("\n");
  print_list(p);
  printf("\n--TESTING SHUFFLE (will print 5 songs randomly)--\n");
  shuffle(table);

  //
  return 0;
}
