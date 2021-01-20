#pragma once
#include "User.h"
#include "Playlist.h"
#include "Song.h"
#include <vector>
#include <iostream>
#include <fstream>
#include "UserController.h"

extern std::vector<User> Gusers;
extern std::vector<Playlist> Gplaylists;
extern std::vector<Song> Gsongs;
//outputs the data into 3 seperate txt files for each vector
void writeFiles();
void fileWriteUsers();
void fileWriteSongs();
void fileWritePlaylists();
//inputs the data from the txt files into the global vectors
void readFiles();
void fileReadSongs();
Song* findSongByID(int songID); //returns song By id from Gsongs
void fileReadPlaylists();
Playlist* findPlaylistByName(std::string name); // returns playlist by name from Gplaylists
void fileReadUsers();

void listAllSongs(); //outputs all songs in the database to the console
void listAllPlaylists(); // outputs all playlists to the console.