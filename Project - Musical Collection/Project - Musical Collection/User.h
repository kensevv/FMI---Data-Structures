#pragma once
#include <string>
#include <vector>
#include "Genre.h"
#include "Date.h"
#include "Playlist.h"

class User
{
private:
	std::string username;
	std::string password;
	std::string fullName;
	Date birthday;
	std::vector<Genre> favGenres;
	std::vector<Playlist*> playlists;
public:
	User(); // default initialization.
	//setters and getters.
	void setUsername(const std::string& username);
	void setPassword(const std::string& password);
	void setFullName(const std::string& fullName);
	void setBirthday(const Date& birthday);
	const std::string& getUsername() const;
	const std::string& getPassword() const;
	const std::string& getFullName() const;
	const Date& getBirthday() const;
	const std::vector<Genre>& getFavGenres() const;
	const std::vector<Playlist*>& getPlaylists() const;

	bool login(const std::string& username, const std::string& password); // used in the controller to login. Checks if the username and password are correct for the exact instance of the class.

	void addFavGenre(const Genre& genre); // adds a favourite Genre
	void addFavPlaylist(Playlist* playlist); // adds a pointer to playlist.

	void removeFavGenre(const Genre& genre);
	void removeFavPlaylist(Playlist* playlist);

	friend std::ostream& operator<<(std::ostream& out, const User& current);
	friend std::istream& operator>>(std::istream& in, User& current);
};