#pragma once
#include "User.h"
#include "Playlist.h"
#include "Date.h"
#include "Genre.h"
#include "Song.h"
#include <iostream>
#include <string>
#include <vector>

class UserInterface
{
private:
	User* user;
	std::vector<Playlist>* playlists;
	std::vector<Song>* songs;

	Playlist* currentPlaylist;
public:
	UserInterface();
	UserInterface(const User& user, const std::vector<Playlist>& playlists, const std::vector<Song>& songs);
	
	// rating song is done via class User
	// adding/removing fav genre is done by class user
	void addSong(); // add song to the database
	void generatePlaylistForUser(); // criterias
	void saveCurrentPlaylist(const std::string& name);
	void loadPlaylistByName(const std::string& name);
	void sortPlaylist(); // criteria
	void showCurrPlaylistInfo(); // info for songs in current playlist

	void loadData(); // not sure yet, may be done with constructor.
	void updateDatabase(); // write updated global containers back to the file
	void logout(); // logout from user and unload all data from the global containers
};