#include "Playlist.h"
#include <algorithm>

Playlist::Playlist()
{
	this->name = "Default Name";
}

std::vector<Song*>& Playlist::getSongs()
{
	return this->songs;
}

void Playlist::setName(const std::string& name)
{
	this->name = name;
}

const std::string& Playlist::getName() const
{
	return this->name;
}

void Playlist::addSong(Song* song)
{
	songs.push_back(song);
}

void Playlist::removeSong(Song* song)
{
	for (size_t i = 0; i < songs.size(); i++)
	{
		if (songs[i] == song)
		{
			this->songs.erase(songs.begin() + i);
		}
	}
}

void Playlist::sortByAlfOrder()
{
	std::sort(this->songs.begin(), this->songs.end(), [](Song* left, Song* right) {
		return left->getSingerName() < right->getSingerName();
		});
}

std::ostream& operator<<(std::ostream& out, const Playlist& current)
{
	out << "PLAYLIST: '" << current.getName() << "' has " << current.songs.size() << " songs:" << std::endl;
	for (size_t i = 0; i < current.songs.size(); i++)
	{
		std::cout << i+1 << ") "<< *current.songs[i] << std::endl;
	}
	return out;
}
