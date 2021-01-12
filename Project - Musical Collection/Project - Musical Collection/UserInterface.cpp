#include "UserInterface.h"

UserInterface::UserInterface()
{
	this->user = nullptr;
	this->currentPlaylist = nullptr;
}

UserInterface::UserInterface(User*& user)
{
	this->user = user;
}

void UserInterface::addFavGenre(const Genre& genre)
{
	this->user->addFavGenre(genre);
}

void UserInterface::removeFavGenre(const Genre& genre)
{
	this->user->removeFavGenre(genre);
}

void UserInterface::rateSong(size_t ID, double rating)
{
	for (size_t i = 0; i < Gsongs.size(); i++)
	{
		if (Gsongs[i].getID() == ID)
		{
			Gsongs[i].rateSong(this->user->getUsername(), rating);
		}
	}
}

void UserInterface::addSong()
{
	Song newSong;
	std::cout << "ADD new Song." << std::endl;
	std::cin >> newSong;
	
	Gsongs.push_back(newSong);
}

void UserInterface::generatePlaylistForUser()
{
}

void UserInterface::saveCurrentPlaylist(const std::string& name)
{
	if (this->currentPlaylist == nullptr)
	{
		std::cout << "Generate playlist first!" << std::endl;
		return;
	}
	
	this->currentPlaylist->setName(name);
	Gplaylists.push_back(*this->currentPlaylist);
}

void UserInterface::loadPlaylistByName(const std::string& name)
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

void UserInterface::sortPlaylist()
{
}

void UserInterface::showCurrPlaylistInfo()
{
	if (this->currentPlaylist == nullptr)
	{
		std::cout << "There is no loaded playlist!" << std::endl;
		return;
	}

	std::cout << *this->currentPlaylist;
}

void UserInterface::logout()
{
	if (this->user == nullptr)
	{
		std::cout << "There is no account logged in!" << std::endl;
		return;
	}
	this->user = nullptr;
	this->currentPlaylist = nullptr;
}
