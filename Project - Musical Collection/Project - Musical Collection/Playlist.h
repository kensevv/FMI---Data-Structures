#pragma once
#include "Song.h"
#include <vector>
#include <string>

class Playlist
{
private:
	std::string name;
	std::vector<Song*> songs;

public:
	Playlist();
	Playlist(std::string name);
	
	const std::vector<Song*>& getSongs() const;

	void setName(const std::string& name);
	const std::string& getName() const;
	
	void addSong(const Song* song);
	void removeSong(const Song* song);

	void sortByAlfOrder();
};