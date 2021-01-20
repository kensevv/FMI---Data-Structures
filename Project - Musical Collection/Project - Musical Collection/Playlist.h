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
	Playlist(); // default initialization
	//setters and getters
	void setName(const std::string& name);
	std::vector<Song*>& getSongs();
	const std::string& getName() const;
	
	void addSong(Song* song); // adds song by reference to the vector
	void removeSong(Song* song); 

	void sortByAlfOrder(); // sorts the playlist by alphabetical order.

	friend std::ostream& operator<<(std::ostream& out, const Playlist& current); // output playlist to console
};