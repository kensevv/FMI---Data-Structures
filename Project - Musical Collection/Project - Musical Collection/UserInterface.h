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
	User user;
	std::vector<Playlist> playlists;
	std::vector<Song> songs;
public:
	UserInterface();
	UserInterface(const User& user, const std::vector<Playlist>& playlists, const std::vector<Song>& songs);
};