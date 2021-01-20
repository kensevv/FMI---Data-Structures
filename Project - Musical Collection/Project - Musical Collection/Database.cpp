#include "Database.h"
// declaring the extern (global) variables.
std::vector<User> Gusers;
std::vector<Playlist> Gplaylists;
std::vector<Song> Gsongs;

void writeFiles()
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
			output << Gusers[i].getUsername() << std::endl;
			output << Gusers[i].getPassword() << std::endl;
			output << Gusers[i].getFullName() << std::endl;
			//date
			output << Gusers[i].getBirthday().day << std::endl;
			output << Gusers[i].getBirthday().month << std::endl;
			output << Gusers[i].getBirthday().year << std::endl;
			//favgenres - vector
			output << Gusers[i].getFavGenres().size() << std::endl;
			for (size_t j = 0; j < Gusers[i].getFavGenres().size(); j++)
			{
				output << Gusers[i].getFavGenres()[j] << std::endl;
			}
			//playlists - vector
			output << Gusers[i].getPlaylists().size() << std::endl;
			for (size_t j = 0; j < Gusers[i].getPlaylists().size(); j++)
			{
				output << Gusers[i].getPlaylists()[j]->getName() << std::endl;
			}
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

			//map ratings
			output << Gsongs[i].getMAPratings().size() << std::endl;
			for (const auto& x : Gsongs[i].getMAPratings())
			{
				output << x.first << std::endl;
				output << x.second << std::endl;
			}
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
			output << Gplaylists[i].getName() << std::endl;
			output << Gplaylists[i].getSongs().size() << std::endl;
			for (size_t j = 0; j < Gplaylists[i].getSongs().size(); j++)
			{
				output << Gplaylists[i].getSongs()[j]->getID() << std::endl;
			}
		}
	}
	output.close();
}

void readFiles()
{
	fileReadSongs();
	fileReadPlaylists();
	fileReadUsers();
}
void fileReadSongs()
{
	Gsongs.reserve(50); // bug fix for memory location change when resizing capacity of vector
	std::ifstream input("songs.txt");
	if (input.is_open())
	{
		size_t numberSongs;
		input >> numberSongs;
		input.get();
		for (size_t i = 0; i < numberSongs; i++)
		{
			Song newSong;
			//song ID
			int ID; input >> ID;
			newSong.setID(ID);
			input.get();

			std::string stringinputs;
			//song name
			std::getline(input, stringinputs);
			newSong.setSongName(stringinputs);
			//singer name
			std::getline(input, stringinputs);
			newSong.setSingerName(stringinputs);
			//album name
			std::getline(input, stringinputs);
			newSong.setAlbumName(stringinputs);

			//year of production
			int year; input >> year; input.get();
			newSong.setYearOfProduction(year);
			//genre
			int genre; input >> genre; input.get();
			newSong.setGenre(genre);
			//map ratings
			int mapsize; input >> mapsize; input.get();
			for (size_t i = 0; i < mapsize; i++)
			{
				std::string username;
				double rating;
				std::getline(input, username);
				input >> rating; input.get();

				newSong.getMAPratings().insert(std::pair<std::string, double>(username, rating));
			}
			Gsongs.push_back(newSong);
		}
		input.close();
	}
}

Song* findSongByID(int songID)
{
	for (size_t i = 0; i < Gsongs.size(); i++)
	{
		if (Gsongs[i].getID() == songID)
		{
			return &Gsongs[i];
		}
	}
}

void fileReadPlaylists()
{
	Gplaylists.reserve(20); // bug fix for memory location change when resizing capacity of vector
	std::ifstream input("playlists.txt");
	if (input.is_open())
	{
		int numberPlaylists;
		input >> numberPlaylists; input.get();
		for (size_t i = 0; i < numberPlaylists; i++)
		{
			Playlist newPlaylist;
			std::string name;
			std::getline(input, name);
			newPlaylist.setName(name);
			int numberSongsin; input >> numberSongsin; input.get();
			for (size_t j = 0; j < numberSongsin; j++)
			{
				int songID;
				input >> songID; input.get();
				newPlaylist.addSong(findSongByID(songID));
			}
			Gplaylists.push_back(newPlaylist);
		}
		input.close();
	}

}

Playlist* findPlaylistByName(std::string name)
{
	for (size_t i = 0; i < Gplaylists.size(); i++)
	{
		if (Gplaylists[i].getName() == name)
		{
			return &Gplaylists[i];
		}
	}
}

void fileReadUsers()
{
	Gusers.reserve(20); // bug fix for memory location change when resizing capacity of vector
	std::ifstream input("users.txt");
	if (input.is_open())
	{
		int userCount; input >> userCount; input.get();
		for (size_t i = 0; i < userCount; i++)
		{
			User newUser;
			std::string stringInput;
			std::getline(input, stringInput);
			newUser.setUsername(stringInput);
			std::getline(input, stringInput);
			newUser.setPassword(stringInput);
			std::getline(input, stringInput);
			newUser.setFullName(stringInput);
			//date
			int day; input >> day; input.get();
			int month; input >> month; input.get();
			int year; input >> year; input.get();
			newUser.setBirthday(Date(year, month, day));
			//favourite genres - vector
			int favGenresCount; input >> favGenresCount; input.get();
			for (int i = 0; i < favGenresCount; i++)
			{
				int genre; input >> genre; input.get();
				newUser.addFavGenre((Genre)genre);
			}
			//playlists - vector
			int playlistsCount; input >> playlistsCount; input.get();
			for (int i = 0; i < playlistsCount; i++)
			{
				std::string playlistName;
				std::getline(input, playlistName);
				newUser.addFavPlaylist(findPlaylistByName(playlistName));
			}
			Gusers.push_back(newUser);
		}

		input.close();
	}
}

void listAllSongs()
{
	for (size_t i = 0; i < Gsongs.size(); i++)
	{
		std::cout << Gsongs[i] << std::endl;
	}
}

void listAllPlaylists()
{
	for (size_t i = 0; i < Gplaylists.size(); i++)
	{
		std::cout << Gplaylists[i] << std::endl;
	}
}
