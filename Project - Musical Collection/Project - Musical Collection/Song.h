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
	size_t ID; // used to direct pointers in playlists when loaded from files.
	std::string songName;
	std::string singerName;
	std::string albumName;
	size_t yearOfProduction;
	Genre genre;

	std::map<size_t, double> ratings; // map that contains the ID of the user who has rated and the rating given by him.
public:
	static size_t nextID;
	Song();
	Song(const std::string& songName, const std::string& singerName, const std::string& albumName, size_t yearOfProduction, const Genre& genre, const std::map<size_t, double>& ratings);
	
	const size_t getID() const;
	const std::string& getSongName() const;
	const std::string& getSingerName() const;
	const std::string& getAlbumName() const;
	const size_t getYearOfProduction() const;
	Genre getGenre() const;
	
	const double getRating() const;
	void rateSong(size_t ID, double rating);
	bool userIDhasRated(size_t ID);

	//setters
	void setID(size_t ID);
	void setSongName(const std::string& songName);
	void setSingerName(const std::string& singerName);
	void setAlbumName(const std::string& albumName);
	void setYearOfProduction(size_t yearOfProduction);
	void setGenre(const Genre& genre);
	void setGenre(int genre);

	friend std::ostream& operator<<(std::ostream& out, const Song& current);
	friend std::istream& operator>>(std::istream& in, Song& current);
};
