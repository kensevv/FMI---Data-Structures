#pragma once
#include "User.h"
#include "Playlist.h"
#include "Date.h"
#include "Genre.h"
#include "Song.h"
#include <iostream>
#include <string>
#include <vector>
#include "GlobalVariables.h"

class UserInterface
{
private:
	User* user;
	Playlist* currentPlaylist;
public:
	UserInterface();
	UserInterface(User*& user);
	
	
	void addFavGenre(const Genre& genre);
	void removeFavGenre(const Genre& genre); 
	void rateSong(size_t ID, double rating);
	void addSong();
	void generatePlaylistForUser();
	void saveCurrentPlaylist(const std::string& name);
	void loadPlaylistByName(const std::string& name);
	void sortPlaylist(); // criteria
	void showCurrPlaylistInfo(); // info for songs in current playlist
	void showAllPlaylistsbyName();

	void logout(); // logout from user and unload all data from the global containers
};