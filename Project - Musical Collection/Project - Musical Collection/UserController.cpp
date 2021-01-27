#include "UserController.h"

UserController::UserController()
{
	this->user = nullptr;
	this->currentPlaylist = nullptr;
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
			if (toLower(Gplaylists[i].getName()) == toLower(name))
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
	showAllPlaylistsbyName();
	std::string name;
	std::cout << "[-]Playlist name: ";
	std::getline(std::cin, name);
	for (size_t i = 0; i < Gplaylists.size(); i++)
	{
		if (toLower(Gplaylists[i].getName()) == toLower(name))
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
	std::cout << "Create new Playlist by name: ";
 	std::string name; std::getline(std::cin, name);
	Playlist newPlaylist;
	newPlaylist.setName(name);
	Gplaylists.push_back(newPlaylist);
	this->currentPlaylist = &Gplaylists[Gplaylists.size()-1];
	std::cout << name << " has been created and loaded as current playlist. Now you can modify it!" << std::endl;
}

void UserController::generatePlaylistForUser()
{
	bool Exit = false;
	int size = INT_MAX;
	int rating = 0;
	std::vector<Genre> genres;
	int yearPref = 0;
	while (true)
	{
		if (Exit == true) break;
		std::cout << "Select which criterias to adjust." << std::endl
			<< "(0) Playlist size; (1) rating; (2) adjust genres; (3) year preference; (4) DONE - generate playlist." << std::endl;
		std::string input; std::getline(std::cin, input);
		int option = validateStringToInt(input);
		// set criterias
		if (input == "0")
		{
			std::string sizeString;
			std::cout << "Maximum playlist size: ";
			std::getline(std::cin, sizeString);
			size = validateStringToInt(sizeString);
			std::cout << "Max playlist size set to " << size << "." << std::endl;
		}
		else if (input == "1")
		{
			std::string ratingString;
			std::cout << "minimum rating: ";
			std::getline(std::cin, ratingString);
			rating = validateStringToInt(ratingString);
			std::cout << "Minimum rating set to " << rating << "." << std::endl;
		}
		else if (input == "2")
		{
			filterGenres(genres);
			std::cout << "Genres filter: ";
			for (size_t i = 0; i < genres.size(); i++)
			{
				printGenre(genres[i]);
				std::cout << "; ";
			}
			std::cout << std::endl;
		}
		else if (input == "3")
		{
			std::string yearString;
			std::cout << "Min. Year preference: ";
			std::getline(std::cin, yearString);
			yearPref = validateStringToInt(yearString);
			std::cout << "Year preference is set above " << yearPref << "." << std::endl;
		}
		else if (input == "4")
		{
			Exit = true;
		}
		else
		{
			std::cout << "Wrong input!" << std::endl;
		}
	}
	// generate playlist from the criterias
	std::vector<Song*> fittingSongs;
	generatePlaylistByCriterias(fittingSongs, size, rating, genres, yearPref);
	Playlist newPlaylist;
	for (size_t i = 0; i < fittingSongs.size(); i++)
	{
		newPlaylist.addSong(fittingSongs[i]);
	}
	Gplaylists.push_back(newPlaylist);
	this->currentPlaylist = &Gplaylists[Gplaylists.size() - 1];
	
	std::cout << "Playlist generated: " << std::endl;
	showCurrPlaylistInfo();
	std::cout << "Save playlist by name: ";
	std::string name;
	std::getline(std::cin, name);
	currentPlaylist->setName(name);
	std::cout << name << " has been generated and saved succesfully!\nYou can add it to your favourites and modify it." << std::endl;
}
void UserController::generatePlaylistByCriterias(std::vector<Song*>& fittingSongs, int size, int rating, std::vector<Genre>& genres, int yearPref)
{
	bool filterByGenres = genres.size() > 0;
	for (auto& song : Gsongs)
	{
		if (size == 0)
		{
			return;
		}
		if (song.getRating() >= rating && song.getYearOfProduction() >= yearPref)
		{	
			if (filterByGenres && !(std::find(genres.begin(), genres.end(), song.getGenre()) == genres.end()))
			{
				fittingSongs.push_back(&song);
				--size;
			}
			else if (!filterByGenres)
			{
				fittingSongs.push_back(&song);
				--size;
			}
		}
	}
}
void UserController::filterGenres(std::vector<Genre>& genres)
{
	std::cout << "Currently chosen genres: ";
	for (size_t i = 0; i < genres.size(); i++)
	{
		printGenre(genres[i]);
		std::cout << "; ";
	}
	std::cout << std::endl;
	genres.push_back(genreInput());
}
void UserController::loadPlaylistByName()
{
	showAllPlaylistsbyName();
	std::cout << "Playlist name: ";
	std::string name; 
	std::getline(std::cin, name);
	
	for (size_t i = 0; i < Gplaylists.size(); i++)
	{
		if (toLower(Gplaylists[i].getName()) == toLower(name))
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

void UserController::renameCurrentPlaylist()
{
	if (this->currentPlaylist == nullptr)
	{
		std::cout << "There is no loaded playlists!" << std::endl;
		return;
	}
	std::string newName;
	std::cout << "Enter new name: ";  std::getline(std::cin, newName);
	this->currentPlaylist->setName(newName);
	std::cout << "Renamed!" << std::endl;
}

void UserController::deleteCurrentPlaylist()
{
	if (this->currentPlaylist == nullptr)
	{
		std::cout << "There is no loaded playlists!" << std::endl;
		return;
	}
	
	for (size_t i = 0; i < Gplaylists.size(); i++)
	{
		if (&Gplaylists[i] == this->currentPlaylist)
		{
			Gplaylists.erase(Gplaylists.begin() + i);
		}
	}
	std::cout << "Playlist has been deleted from database!" << std::endl;
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
