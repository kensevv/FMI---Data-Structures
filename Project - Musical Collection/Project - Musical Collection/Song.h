#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Genre.h"
class Song
{
private:
	std::string songName;
	std::string singerName;
	std::string albumName;
	size_t yearOfProduction;
	std::vector<Genre> genres;
	double raiting;
public:
	Song();
	Song(const std::string& songName, const std::string& singerName, const std::string& albumName, size_t yearOfProduction, const std::vector<Genre>& genres, double rating);
	
	const std::string& getSongName() const;
	const std::string& getSingerName() const;
	const std::string& getAlbumName() const;
	const size_t getYearOfProduction() const;
	const std::vector<Genre>& getGenres() const;
	
	const double getRaiting() const;
	void rateSong(double rating);

	//setters
	void setSongName(const std::string& songName);
	void setSingerName(const std::string& singerName);
	void setAlbumName(const std::string& albumName);
	void setYearOfProduction(size_t yearOfProduction);
	void setGenres(const std::vector<Genre>& genres);

};