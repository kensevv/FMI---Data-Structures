// Project - Musical Collection.cpp :  Kenan Yusein 71947
// This file contains the main.cpp from where the program will be executed

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <fstream>
#include "Date.h"
#include "Genre.h"
#include "Song.h"
#include "Playlist.h"
#include "User.h"
#include "UserController.h"
#include "Database.h"
#include "algorithms.h"

void signInorUp();
void Menu();
void outputUserOptions();
void userOptions(std::string str);
void Register();
void Login();
bool successfulLogin(std::string username, std::string password);
void Logout();

bool Exit = false;
UserController userController;

int main()
{
	readFiles(); // loads database
	while (!Exit)
	{
		if (userController.getUser() == nullptr) signInorUp();
		else Menu();
	}
	writeFiles(); //updates files
	std::cout << "Database updated succesfully, all changes have been saved!\nExiting . . ." << std::endl;
}

void signInorUp()
{
	std::cout << "Input Exit to exit and SAVE!" << std::endl
		<< "Login or Register to continue." << std::endl
		<< ">";
	std::string input;
	std::getline(std::cin, input);
	if (toLower(input) == "login")
	{
		Login();
	}
	else if (toLower(input) == "register")
	{
		Register();
	}
	else if (toLower(input) == "exit")
	{
		Exit = true;
	}
	else 
	{
		std::cout << "Wrong input. Select 'login', 'register' or 'exit'" << std::endl;
	}
}

void Menu()
{
	outputUserOptions();
	std::cout << ">";
	std::string input; std::getline(std::cin, input);
	clearScreen();
	userOptions(input);
}

void outputUserOptions()
{
	int i = 18; // for easy adding
	std::cout << "(" << i << ") Show profile information " << std::endl
		<< "(" << i-- << ") List all songs." << std::endl
		<< "(" << i-- << ") List existing playlists." << std::endl
		<< "(" << i-- << ") [+] favourite genre." << std::endl
		<< "(" << i-- << ") [-] favourite genre." << std::endl
		<< "(" << i-- << ") [+] favourite playlist " << std::endl
		<< "(" << i-- << ") [-] favourite playlist" << std::endl
		<< "(" << i-- << ") Rate Song" << std::endl
		<< "(" << i-- << ") Add Song" << std::endl
		<< "(" << i-- << ") Manually create new playlist" << std::endl
		<< "(" << i-- << ") Generate playlist by criterias" << std::endl
		<< "(" << i-- << ") Load playlist" << std::endl
		<< "(" << i-- << ") Show current playlist information" << std::endl
		<< "(" << i-- << ") Sort playlist" << std::endl
		<< "(" << i-- << ") [+]Add song to current playlist" << std::endl
		<< "(" << i-- << ") [-]Remove song from current playlist" << std::endl
		<< "(" << i-- << ") Rename current playlist" << std::endl
		<< "(" << i-- << ") DELETE current playlist" << std::endl
		<< "(" << i-- << ") Logout." << std::endl;
}

void userOptions(std::string str)
{
	int input  = validateStringToInt(str);
	switch (input)
	{
	case 0:
		std::cout << *userController.getUser() << std::endl;
		break;
	case 1:
		listAllSongs();
		break;
	case 2:
		listAllPlaylists();
		break;
	case 3:
		userController.addFavGenre(genreInput());
		break;
	case 4:
		userController.removeFavGenre(genreInput());
		break;
	case 5:
		userController.addFavPlaylist();
		break;
	case 6:
		userController.removeFavPlaylist();
		break;
	case 7:
		userController.rateSong();
		break;
	case 8: 
		userController.addSong();
		std::cout << "Added!" << std::endl;
		break;
	case 9:
		userController.createPlaylist();
		break;
	case 10:
		userController.generatePlaylistForUser();
		break;
	case 11:
		userController.loadPlaylistByName();
		break;
	case 12:
		std::cout << "Currently loaded playlist:" << std::endl;
		userController.showCurrPlaylistInfo();
		break;
	case 13:
		userController.sortPlaylist();
		break;
	case 14:
		userController.addSongToCurrentPlaylist();
		break;
	case 15:
		userController.removeSongFromCurrentPlaylist();
		break;
	case 16:
		userController.renameCurrentPlaylist();
		break;
	case 17:
		userController.deleteCurrentPlaylist();
		break;
	case 18:
		userController.logout();
		std::cout << "Logged out!" << std::endl;
		break;
	default:
		std::cout << "Wrong input." << std::endl;
		break;
	}
}

void Register()
{
	User newuser;
	std::cin >> newuser;
	Gusers.push_back(newuser);
	clearScreen();
	std::cout << "Succesfully registered. Sign in next to continue!" << std::endl;
}

void Login()
{
	std::string username, password;
	std::cout << "Please sign in to your account to continue." << std::endl
		<< "Username: ";
	std::getline(std::cin, username);
	std::cout << "Password: ";
	std::getline(std::cin, password);
	if (successfulLogin(username, password))
	{
		clearScreen();
		std::cout << "Welcome " << userController.getUser()->getFullName() << "! You have succesfuly logged in!" << std::endl;
	}
	else
	{
		std::cout << "Wrong username or password!" << std::endl;
	}
}

bool successfulLogin(std::string username, std::string password)
{
	for (int i = 0; i < Gusers.size(); i++)
	{
		if (toLower(Gusers[i].getUsername()) == toLower(username) && Gusers[i].getPassword() == password)
		{
			userController.setUser(&Gusers[i]);
			return true;
		}
	}
	return false;
}

void Logout()
{
	userController.logout();
	std::cout << "Logged out!.";
}