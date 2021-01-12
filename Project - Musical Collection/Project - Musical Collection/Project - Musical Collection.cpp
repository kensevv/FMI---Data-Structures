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

#include "GlobalVariables.h"

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
		output << Gusers.size() << std::endl;
		for (size_t i = 0; i < Gusers.size(); i++)
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
		output << Gsongs.size() << std::endl;
		for (size_t i = 0; i < Gsongs.size(); i++)
		{
			output << Gsongs[i].getID() << std::endl;
			output << Gsongs[i].getSongName() << std::endl;
			output << Gsongs[i].getSingerName() << std::endl;
			output << Gsongs[i].getAlbumName() << std::endl;
			output << Gsongs[i].getYearOfProduction() << std::endl;
			output << Gsongs[i].getGenre() << std::endl;
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
		output << Gplaylists.size() << std::endl;
		for (size_t i = 0; i < Gplaylists.size(); i++)
		{
			output << Gplaylists[i].getSongs().size();
			for (size_t j = 0; j < Gplaylists[i].getSongs().size(); j++)
			{
				output << Gplaylists[i].getSongs()[j]->getID();
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
