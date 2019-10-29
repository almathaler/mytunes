/*
You should start by making your linked lists work with the following functionality:
insert nodes at the front (*)
insert nodes in order
alphabetical by Artist then by Song
print the entire list (*)
find and return a pointer to a node based on artist and song name
find and return a pointer to the first song of an artist based on artist name
Return a pointer to random element in the list.
remove a single specified node from the list (*)
free the entire list (*)
*/
#ifndef list_h
#define list_h
//the struct
struct song_node{
  char *name;
  char *artist;
  struct song_node *next;
};
//functions defined in list.c
struct song_node * insert_front(struct song_node *pointer, char *name, char *artist);

void print_list(struct song_node *pointer);

struct song_node * free_list(struct song_node *pointer);

struct song_node * listRemove(struct song_node *front, char *name, char *artist);


#endif
