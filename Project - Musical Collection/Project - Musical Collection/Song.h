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
	std::vector<Genre> genres;
	std::string albumName;
	size_t yearOfProducing;
	double raiting;
};