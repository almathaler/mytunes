#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "list.h"
//
void printNode(struct song_node *pointer){
  printf("|%s : %s|", pointer->artist, pointer->name);
}
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
    printf("|   |");
  }
  while(pointer != NULL){
    printf("|%s: %s| ", pointer->artist, pointer->name);
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
//
struct song_node * find(struct song_node *front, char *name, char* artist){
  //if it's not in the song, return null pointer
  struct song_node *current = front;
  while(current!=NULL && (strcmp(current->artist, artist) != 0 || strcmp(current->name, name) != 0)){
    current = current->next;
  }
  return current;
}
//
struct song_node * findArtist(struct song_node *front, char *artist){
  struct song_node *current = front;
  while(current!=NULL && strcmp(current->artist, artist) != 0){
    current = current->next;
  }
  return current;
}
//
int size(struct song_node *front){
  int toReturn = -1;
  while(front!=NULL){
    toReturn++;
    front = front->next;
  }
  //printf("INSIZE, returning: %d\n", toReturn);
  return toReturn;
}
//
struct song_node * randomSong(struct song_node *front){
  int times = rand()%size(front);
  //printf("IN RANDSONG: times = %d\n", times);
  while(times>=0){
    front=front->next;
    times--;
  }
  //printf("IN RANDSONG: at song %s\n", front->name);
  return front; //changes where 'front' points to but doesn't affect anything outside this method
}
//
struct song_node * addOrdered(struct song_node *front, char *name, char *artist){
  if (front == NULL){
    front = insert_front(front, name, artist);
    return front;
  }
  struct song_node *current = front;
  struct song_node *previous = NULL;
  while (current != NULL && strcmp(current->artist, artist)<0){ //once current is at null, means that you shoul just add to end, so set previous->next = this
    previous = current;
    current = current->next;
  }
  //once this ends, means you are at the right artist area
  //if you already have a song from that artist, it'll stop at the front of that (bc there, strcmp will yield 0)
  //if you don't, it'll stop right where it should be added
  //so if there isn't already one of that type of artist, just add. however if there is, you should go through that
  //and decide where to place it
  while (current != NULL && strcmp(current->name, name) < 0 && strcmp(current->artist, artist) == 0){
    //what this loop does is if you are where you should be and no other of that type of artist, skips this and j adds
    //however if you stopped right where there are other of your type, compare the names until your reach where to adds/
    //also, if you should add to the front, then this will allow you to
    previous = current;
    current = current->next;
  } //once this stops, you got it!
  if (previous!=NULL){//if you're not adding to the front, link them
    //this still works if you're adding to the back (current=NULL and previous is a node), because you can create a list out of null
    previous->next = insert_front(current, name, artist);
    return front;
  } //if you are adding to the front, set front = to adding to the front
  return insert_front(current, name, artist);
}
