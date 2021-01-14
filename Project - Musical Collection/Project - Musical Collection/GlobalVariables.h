#pragma once
#include "User.h"
#include "Playlist.h"
#include "Song.h"
#include <vector>
#include <iostream>
#include <fstream>

extern std::vector<User> Gusers;
extern std::vector<Playlist> Gplaylists;
extern std::vector<Song> Gsongs;

void writeFiles();
void fileWriteUsers();
void fileWriteSongs();
void fileWritePlaylists();

void readFiles();
void fileReadSongs();
Song* findSongByID(int songID);
void fileReadPlaylists();
Playlist* findPlaylistByName(std::string name);
void fileReadUsers();