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
	this->user->addFavGenre(genre);
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
	for (size_t i = 0; i < Gplaylists.size(); i++)
	{
		if (Gplaylists[i].getName() == name)
		{
			this->user->addFavPlaylist(&Gplaylists[i]);
		}
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
		}
	}
}

void UserController::rateSong(size_t ID, double rating)
{
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

void UserController::generatePlaylistForUser()
{
	//TODO
}

void UserController::saveCurrentPlaylist(const std::string& name)
{
	if (this->currentPlaylist == nullptr)
	{
		std::cout << "Generate playlist first!" << std::endl;
		return;
	}
	
	this->currentPlaylist->setName(name);
	Gplaylists.push_back(*this->currentPlaylist);
}

void UserController::loadPlaylistByName(const std::string& name)
{
	for (size_t i = 0; i < Gplaylists.size(); i++)
	{
		if (Gplaylists[i].getName() == name)
		{
			this->currentPlaylist = &Gplaylists[i];
			return;
		}
	}
}

void UserController::sortPlaylist()
{
	if (this->currentPlaylist == nullptr)
	{
		std::cout << "There is no loaded playlists!" << std::endl;
		return;
	}

	this->currentPlaylist->sortByAlfOrder();
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
