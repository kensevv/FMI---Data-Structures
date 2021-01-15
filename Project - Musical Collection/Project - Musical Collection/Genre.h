#pragma once
enum Genre
{
	defaultGenre = 0,
	Pop,
	Rap,
	HipHop,
	Rock,
	Metal,
	Jazz,
	Folk,
	Classical,
	Country,
	Electronic,
	Techno,
	House
};
void printGenre(Genre genre);
Genre genreInput();