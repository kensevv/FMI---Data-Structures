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
	Song(const std::string& songName, const std::string& singerName, const std::string& albumName, size_t yearOfProduction, std::vector<Genre> genres, double rating);
	
};