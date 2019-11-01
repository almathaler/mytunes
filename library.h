/*
DO NOT WORK ON THIS PART UNTIL YOUR LINKED LIST IS COMPLETE
Then create your array of linked lists for the full program to have the following functions:
Add song nodes. (*)
Search for a song given song and artist name (return a pointer).  (*)
Search for an artist. (*)
Print out all the entries under a certain letter. (*)
Print out all the songs of a certain artist (*)
Print out the entire library. (*)
Shuffle - print out a series of randomly chosen songs (*)
Delete a song (*)
Clear the library. (*)
*/
#ifndef library_h
#define library_h
//struct song_node * table[27]
int make_index(char letter);
//
void print_letter(struct song_node **table, char letter);
//
void print_artist(struct song_node **table, char *artist);
//
void print_lib(struct song_node **table);
//
void add_lib(struct song_node **table, char *name, char *artist);
//
struct song_node * find_lib(struct song_node **table, char *name, char *artist);
//
struct song_node * find_artist_lib(struct song_node **table, char *artist);
//
void delete_song(struct song_node **table, char*name, char*artist);
//
void clear_lib(struct song_node **table);
//
void shuffle(struct song_node **table);//going to print out 5 random songs
//
#endif
