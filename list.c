#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"
//insert front
struct song_node * insert_front(struct song_node *pointer, char *name, char *artist){
  struct song_node *front = malloc(sizeof(struct song_node));
  front->name = name;
  front->artist = artist;
  front->next = pointer;
  return front;
}
//print -- assumption is last element will point to NULL
void print_list(struct song_node *pointer){
  if (pointer == NULL){
    printf("empty library");
  }
  while(pointer != NULL){
    printf("|%s: %s| ", pointer->name, pointer->artist);
    pointer = pointer->next;
  }
  printf("\n");
}
//freeing list
struct song_node * free_list(struct song_node *pointer){
  if (pointer->next == NULL){
    //printf("freeing base: ");
    //printNode(pointer);
    free(pointer); //empty this space
    pointer = NULL;
  }else{
    //printf("not yet at bottom, am here: ");
    //printNode(pointer);
    free_list(pointer->next); //go to the next node to free it
    //printf("freeing: ");
    //printNode(pointer);
    free(pointer);
    pointer = NULL;
  }
  return pointer;
}
//removing particular node
struct song_node * listRemove(struct song_node *front, char *name, char *artist){
  //go thru list to find data, keep previous node in a POINTER/
  //once you find the first instance of data, assign previous node.next = this.next
  //then free current POINTER
  //return front, which should be untouched
  struct song_node *iterator = front;
  struct song_node *behindIterator = NULL;
  while(iterator != NULL){
    if(strcmp(iterator->name, name) == 0 && strcmp(iterator->artist, artist) == 0){
      //printf("found data! removing at ");
      //printNode(iterator);
      if (behindIterator == NULL){
        front = iterator->next; //if you're removing the first piece, there's no back. so  just skip over this
      }else{
        behindIterator->next = iterator->next;
      }
      free(iterator);
      iterator=NULL;
      //printf("now the surrounding pointers look like: ");
      //printNode(behindIterator);
      //printNode(behindIterator->next);
    }else{
      behindIterator = iterator;
      iterator = iterator->next;
    }
  }
  return front;
}
//add addOrdered
struct song_node * addOrdered(struct song_node *front, char *name, char *artist){
  if (front == NULL){
    front = insert_front(front, name, artist);
    return front;
  }
  struct song_node *current = front;
  struct song_node *previous = NULL;
  while (strcmp(current->artist, artist)<0){
    previous = current;
    current = current->next;
  } // YOU HAVE TO GO BACKWARDS FOR SECOND STEP BECAUSE ABOVE LOOP
  //STOPS RIGHT WHEN YOU HIT THE ARTSIT YOU WON'T ADD TO. SO GO BACKWARDS!@
  //once this ends, means you are at the right artist area
  while (strcmp(current->name, name) < 0){
    previous = current;
    current = current->next;
  } //once this stops, you got it!
  if (previous!=NULL){//if you're not adding to the front, link them
    previous->next = insert_front(current, name, artist);
    return front;
  }
  return insert_front(current, name, artist);
}
