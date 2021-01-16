#include "UserController.h"

UserController::UserController()
{
	this->user = nullptr;
	this->currentPlaylist = nullptr;
}

UserController::UserController(User* user)
{
	this->user = user;
}

void UserController::setUser(User* user)
{
	this->user = user;
}

User* UserController::getUser()
{
	return this->user;
}

void UserController::addFavGenre(const Genre& genre)
{
	if (!alreadyAdded(genre))
	{
		this->user->addFavGenre(genre);
		printGenre(genre); std::cout << " added to your favorite genres!" << std::endl;
	}
	else
	{
		std::cout << "You already have ";
		printGenre(genre);
		std::cout << " in your favorites!" << std::endl;
	}
}

void UserController::removeFavGenre(const Genre& genre)
{
	this->user->removeFavGenre(genre);
}

void UserController::addFavPlaylist()
{
	showAllPlaylistsbyName();
	std::cout << ">";
	std::string name;
	std::cout << "[+]Playlist name: ";
	std::getline(std::cin, name);

	if (!alreadyAdded(name))
	{
		for (size_t i = 0; i < Gplaylists.size(); i++)
		{
			if (Gplaylists[i].getName() == name)
			{
				this->user->addFavPlaylist(&Gplaylists[i]);
				std::cout << name << " added to your favorite playlists!" << std::endl;
			}
		}
	}
	else
	{
		std::cout << "You already have " << name << " in your favorites";
	}
}

void UserController::removeFavPlaylist()
{
	std::string name;
	std::cout << "[-]Playlist name: ";
	std::getline(std::cin, name);
	for (size_t i = 0; i < Gplaylists.size(); i++)
	{
		if (Gplaylists[i].getName() == name)
		{
			this->user->removeFavPlaylist(&Gplaylists[i]);
			std::cout << name << " removed from your favorite playlists!" << std::endl;
		}
	}
}

bool UserController::alreadyAdded(Genre genre)
{
	for (size_t i = 0; i < this->user->getFavGenres().size(); i++)
	{
		if (this->user->getFavGenres()[i] == genre)
		{
			return true;
		}
	}
	return false;
}

bool UserController::alreadyAdded(std::string name) // playlist
{
	for (size_t i = 0; i < this->user->getPlaylists().size(); i++)
	{
		if (this->user->getPlaylists()[i]->getName() == name)
		{
			return true;
		}
	}
	return false;
}

void UserController::rateSong()
{
	listAllSongs(); 
	std::cout << "Select song to rate by ID: ";
	std::string input; std::getline(std::cin, input);
	int ID = validateStringToInt(input);
	std::cout << "Rating(0-5): ";
	//double rating; std::cin >> rating;
	std::getline(std::cin, input);
	double rating = (double)validateStringToInt(input);
	
	for (size_t i = 0; i < Gsongs.size(); i++)
	{
		if (Gsongs[i].getID() == ID)
		{
			Gsongs[i].rateSong(this->user->getUsername(), rating);
		}
	}
}

void UserController::addSong()
{
	Song newSong;
	std::cout << "ADD new Song." << std::endl;
	std::cin >> newSong;
	
	Gsongs.push_back(newSong);
}

void UserController::createPlaylist()
{

}

void UserController::generatePlaylistForUser()
{
	//TODO
}

void UserController::saveCurrentPlaylist()
{
	if (this->currentPlaylist == nullptr)
	{
		std::cout << "Generate or load playlist first!" << std::endl;
		return;
	}
	std::cout << "Save currently loaded playlist by name: ";
	std::string name;
	std::getline(std::cin, name);
	this->currentPlaylist->setName(name);
	Gplaylists.push_back(*this->currentPlaylist);
	std::cout << "Playlist has been saved! You can add it to your favourites!" << std::endl;
}

void UserController::loadPlaylistByName()
{
	showAllPlaylistsbyName();
	std::cout << "Playlist name: ";
	std::string name; 
	std::getline(std::cin, name);
	for (size_t i = 0; i < Gplaylists.size(); i++)
	{
		if (Gplaylists[i].getName() == name)
		{
			this->currentPlaylist = &Gplaylists[i];
			std::cout << name << " has been loaded!" << std::endl;
			return;
		}
	}
	std::cout << "Playlist not found!" << std::endl;
}

void UserController::addSongToCurrentPlaylist()
{
	if (this->currentPlaylist == nullptr)
	{
		std::cout << "There is no loaded playlists!" << std::endl;
		return;
	}
	listAllSongs();
	std::cout << "Select song to ADD to playlist by ID: ";
	std::string input; std::getline(std::cin, input);
	int ID = validateStringToInt(input);

	this->currentPlaylist->addSong(findSongByID(ID));
	std::cout << "Added!" << std::endl;
}

void UserController::removeSongFromCurrentPlaylist()
{
	if (this->currentPlaylist == nullptr)
	{
		std::cout << "There is no loaded playlists!" << std::endl;
		return;
	}
	showCurrPlaylistInfo();
	std::cout << "Select song to remove from playlist by ID: ";
	std::string input; std::getline(std::cin, input);
	int ID = validateStringToInt(input);

	this->currentPlaylist->removeSong(findSongByID(ID));
	std::cout << "Removed!" << std::endl;
}

Song* UserController::findSongByID(size_t ID)
{
	for (size_t i = 0; i < Gsongs.size(); i++)
	{
		if (Gsongs[i].getID() == ID)
		{
			return &Gsongs[i];
		}
	}
	return nullptr;
}

void UserController::sortPlaylist()
{
	if (this->currentPlaylist == nullptr)
	{
		std::cout << "There is no loaded playlists!" << std::endl;
		return;
	}

	this->currentPlaylist->sortByAlfOrder();
	std::cout << "Sorted by alphabetical order!" << std::endl;
}

void UserController::showCurrPlaylistInfo()
{
	if (this->currentPlaylist == nullptr)
	{
		std::cout << "There is no loaded playlist!" << std::endl;
		return;
	}
	std::cout << *this->currentPlaylist;
}

void UserController::showAllPlaylistsbyName()
{
	for (size_t i = 0; i < Gplaylists.size(); i++)
	{
		std::cout << i + 1 << ") " << Gplaylists[i].getName() << std::endl;
	}
}

void UserController::listUserFavGenres()
{
	std::cout << "Favourite genres: ";
	for (size_t i = 0; i < this->user->getFavGenres().size(); i++)
	{
		printGenre(this->user->getFavGenres()[i]);
		std::cout << "; ";
	}
}

void UserController::logout()
{
	if (this->user == nullptr)
	{
		std::cout << "There is no account logged in!" << std::endl;
		return;
	}
	this->user = nullptr;
	this->currentPlaylist = nullptr;
}
