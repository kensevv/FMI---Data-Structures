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
	User* user; // we can log and work with 1 account using the controller.
	Playlist* currentPlaylist; // interactively we can select a playlist to load and work with.

public:
	UserController();
	//setters and getters
	void setUser(User* user);
	User* getUser();
	// used to modify currently logged user's favourite playlists/genres
	void addFavGenre(const Genre& genre);
	void removeFavGenre(const Genre& genre); 
	void addFavPlaylist();
	void removeFavPlaylist(); 

	void rateSong(); // used to rate song selected by ID
	void addSong(); // Used to add song to global vector of songs
	void createPlaylist(); // User can manually create new playlist and modify it afterwards.
	void generatePlaylistForUser(); // generates playlist for used, filtered by diffirent criterias
	void loadPlaylistByName(); // used to load 'currentplaylist' pointer.
	void addSongToCurrentPlaylist(); // adds a song by id to current playlist
	void removeSongFromCurrentPlaylist();  // removes a song by id from current playlist.
	void sortPlaylist(); // calls sort function in playlist / sorts current playlist.
	void renameCurrentPlaylist(); // If it's loaded, renames the playlist
	void deleteCurrentPlaylist(); // if it's loaded, deletes the current playlist
	void showCurrPlaylistInfo();  // If loaded, outputs information for the current playlist only.
	void showAllPlaylistsbyName(); // outputs the names only of all playlists.
	void listUserFavGenres(); // outputs user's all favourite genres
	void logout(); // logout from user - resets the pointers to nullptr.

private:
	bool alreadyAdded(Genre genre); // for genre
	bool alreadyAdded(std::string name); // override for playlist
	void generatePlaylistByCriterias(std::vector<Song*>& fittingSongs, int size, int rating, std::vector<Genre>& genres, int yearPref); // interactive function setting up the criterias to filter by
	void filterGenres(std::vector<Genre>& genres);
	Song* findSongByID(size_t ID); // returns song from global vector, found by ID
};