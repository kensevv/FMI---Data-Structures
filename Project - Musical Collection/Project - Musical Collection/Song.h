#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "Genre.h"
class Song
{
protected:
	
private:
	static size_t nextID; // Used to generate the Unique ID. 
	size_t ID; // unique identified. Used to direct pointers in playlists or as selector.
	std::string songName;
	std::string singerName;
	std::string albumName;
	size_t yearOfProduction;
	Genre genre;
	std::map<std::string, double> ratings; // map that contains the Username of the user who has rated and the rating given by him.

public:
	Song();

	double getRating() const; // calculates the average rating.
	void rateSong(std::string username, double rating); // rates the song: each user can vote only once.

	//setters and getters
	const size_t getID() const;
	const std::string& getSongName() const;
	const std::string& getSingerName() const;
	const std::string& getAlbumName() const;
	const size_t getYearOfProduction() const;
	Genre getGenre() const;
	std::map<std::string, double>& getMAPratings();

	void setID(size_t ID);
	void setSongName(const std::string& songName);
	void setSingerName(const std::string& singerName);
	void setAlbumName(const std::string& albumName);
	void setYearOfProduction(size_t yearOfProduction);
	void setGenre(const Genre& genre);
	void setGenre(int genre);

	friend std::ostream& operator<<(std::ostream& out, const Song& current);
	friend std::istream& operator>>(std::istream& in, Song& current);	
private:
	bool usernameHasRated(std::string username); // checks if given user has already rated this song.
};
