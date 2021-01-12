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
	Playlist(std::string name, std::vector<Song*> songs);
	
	std::vector<Song*>& getSongs();

	void setName(const std::string& name);
	const std::string& getName() const;
	
	void addSong(Song* song);
	void removeSong(Song* song);

	void sortByAlfOrder();

	friend std::ostream& operator<<(std::ostream& out, const Playlist& current);
};