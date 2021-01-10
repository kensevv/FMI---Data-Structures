// Project - Musical Collection.cpp :  Kenan Yusein 71947

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <fstream>
#include "Date.h"
#include "Genre.h"
#include "Song.h"
#include "Playlist.h"
#include "User.h"
#include "UserInterface.h"

#include <map>

std::vector<User> users;
std::vector<Playlist> playlists;
std::vector<Song> songs;

void fileWrite();
void fileWriteUsers();
void fileWriteSongs();
void fileWritePlaylists();

void fileRead();
void fileReadUsers();
void fileReadSongs();
void fileReadPlaylists();

void Register();
void Login();
void Logout();
//todo


void Menu();
//todo

#include <algorithm>
bool compare(Song* left, Song* right) {
	return left->getSingerName() < right->getSingerName();
}
int main()
{

}

void fileWrite()
{
	fileWriteUsers();
	fileWriteSongs();
	fileWritePlaylists();
}

void fileWriteUsers()
{
	std::ofstream output("users.txt");
	if (output.is_open())
	{
		output << users.size() << std::endl;
		for (size_t i = 0; i < users.size(); i++)
		{

		}
	}
	output.close();
}

void fileWriteSongs()
{
	std::ofstream output("songs.txt");
	if (output.is_open())
	{
		output << songs.size() << std::endl;
		for (size_t i = 0; i < songs.size(); i++)
		{
			output << songs[i].getID() << std::endl;
			output << songs[i].getSongName() << std::endl;
			output << songs[i].getSingerName() << std::endl;
			output << songs[i].getAlbumName() << std::endl;
			output << songs[i].getYearOfProduction() << std::endl;
			output << songs[i].getGenre() << std::endl;
			// todo map ratings
		}
	}
	output.close();
}

void fileWritePlaylists()
{
	std::ofstream output("playlists.txt");
	if (output.is_open())
	{
		output << playlists.size() << std::endl;
		for (size_t i = 0; i < playlists.size(); i++)
		{
			output << playlists[i].getSongs().size();
			for (size_t j = 0; j < playlists[i].getSongs().size(); j++)
			{
				output << playlists[i].getSongs()[j]->getID();
			}
		}
	}
	output.close();
}

void fileRead()
{
	fileReadUsers();
	fileReadSongs();
	fileReadPlaylists();
}

void fileReadUsers()
{
	std::ifstream input("users.txt");
	size_t size;
	input >> size;
	input.get();
	for (size_t i = 0; i < size; i++)
	{

	}
	input.close();
}

void fileReadSongs()
{
	std::ifstream input("songs.txt");
	size_t size;
	input >> size;
	input.get();
	for (size_t i = 0; i < size; i++)
	{

	}
	input.close();
}

void fileReadPlaylists()
{
	std::ifstream input("playlists.txt");
	size_t size;
	input >> size;
	input.get();
	for (size_t i = 0; i < size; i++)
	{

	}
	input.close();
}

void Register() 
{
}

void Login()
{
}

void Logout()
{
}

void Menu()
{
}
