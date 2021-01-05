#include "Playlist.h"

Playlist::Playlist()
{
}

Playlist::Playlist(std::string name)
{
}

const std::vector<Song*>& Playlist::getSongs() const
{
	return this->songs;
}

void Playlist::setName(const std::string& name)
{
}

const std::string& Playlist::getName() const
{
	return this->name;
}

void Playlist::addSong(const Song* song)
{
}

void Playlist::removeSong(const Song* song)
{
}

void Playlist::sortByAlfOrder()
{
}
