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
#include "algorithms.h"

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
	void rateSong();
	void addSong();
	void createPlaylist();
	void generatePlaylistForUser();
	void loadPlaylistByName();
	void addSongToCurrentPlaylist();
	void removeSongFromCurrentPlaylist(); 
	void sortPlaylist();
	void renameCurrentPlaylist();
	void deleteCurrentPlaylist();
	void showCurrPlaylistInfo(); 
	void showAllPlaylistsbyName();
	void listUserFavGenres();
	void logout(); // logout from user and unload all data from the global containers

private:
	bool alreadyAdded(Genre genre); // for genre
	bool alreadyAdded(std::string name); // override for playlist
	void generatePlaylistByCriterias(std::vector<Song*>& fittingSongs, int size, int rating, std::vector<Genre>& genres, int yearPref);
	void filterGenres(std::vector<Genre>& genres);
	Song* findSongByID(size_t ID);
};