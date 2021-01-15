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
void outputMenuBars();
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
		if (userController.getUser() == nullptr)
		{
			signInorUp();
		}
		else
		{

			Menu();
		}
	}
	writeFiles(); //updates files
	std::cout << "Database updated succesfully, all changes have been saved!\nExiting . . ." << std::endl;
}

void signInorUp()
{
	std::cout << "Input Exit to exit" << std::endl
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
	outputMenuBars();
	std::cout << ">";
	std::string input; std::getline(std::cin, input);
	userOptions(input);
}

void outputMenuBars()
{
	std::cout << "(0) Show profile information " << std::endl
		<< "(1) List all songs." << std::endl
		<< "(2) List existing playlists." << std::endl
		<< "(3) [+] favourite genre." << std::endl
		<< "(4) [-] favourite genre." << std::endl
		<< "(5) [+] favourite playlist " << std::endl
		<< "(6) [-] favourite playlist" << std::endl
		<< "(7) Rate Song" << std::endl
		<< "(8) Add Song" << std::endl
		<< "(9) Generate playlist" << std::endl
		<< "(10) Save current playlist" << std::endl
		<< "(11) Load playlist" << std::endl
		<< "(12) Show current playlist information" << std::endl
		<< "(13) Sort playlist" << std::endl
		<< "(14) Logout." << std::endl;
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

		break;
	case 8:

		break;
	case 9:

		break;
	case 10:

		break;
	case 11:

		break;
	case 12:

		break;
	case 13:

		break;
	case 14:
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