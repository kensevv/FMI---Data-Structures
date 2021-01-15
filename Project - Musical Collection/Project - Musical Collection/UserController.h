#pragma once
#include "User.h"
#include "Playlist.h"
#include "Date.h"
#include "Genre.h"
#include "Song.h"
#include <iostream>
#include <string>
#include <vector>
#include "Database.h"

class UserController
{
private:
	User* user;
	Playlist* currentPlaylist;
public:
	UserController();
	UserController(User* user);
	
	void setUser(User* user);
	User* getUser();

	void addFavGenre(const Genre& genre);
	void removeFavGenre(const Genre& genre); 
	void addFavPlaylist();
	void removeFavPlaylist();
	void rateSong(size_t ID, double rating);
	void addSong();
	void generatePlaylistForUser();
	void saveCurrentPlaylist(const std::string& name);
	void loadPlaylistByName(const std::string& name);
	void sortPlaylist(); // criteria

	void showCurrPlaylistInfo(); // info for songs in current playlist
	void showAllPlaylistsbyName();
	void listUserFavGenres();

	void logout(); // logout from user and unload all data from the global containers
};