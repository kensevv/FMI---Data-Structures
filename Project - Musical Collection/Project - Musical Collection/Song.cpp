#include "Song.h"

Song::Song()
{
}

Song::Song(const std::string& songName, const std::string& singerName, const std::string& albumName, size_t yearOfProduction, const Genre& genre, double rating)
{
}

const std::string& Song::getSongName() const
{
    return this->songName;
}

const std::string& Song::getSingerName() const
{
    return this->singerName;
}

const size_t Song::getID() const
{
    return size_t();
}

const std::string& Song::getAlbumName() const
{
    return this->albumName;
}

const size_t Song::getYearOfProduction() const
{
    return size_t();
}

Genre Song::getGenre() const
{
    return this->genre;
}

const double Song::getRaiting() const
{
    return this->raiting;
}

void Song::rateSong(double rating)
{
}

void Song::setSongName(const std::string& songName)
{
}

void Song::setSingerName(const std::string& singerName)
{
}

void Song::setAlbumName(const std::string& albumName)
{
}

void Song::setID(size_t ID)
{
}

void Song::setYearOfProduction(size_t yearOfProduction)
{
}

void Song::setGenre(const Genre& genre)
{
}

std::ostream& operator<<(std::ostream& out, const Song& current)
{

    return out;
}

std::istream& operator>>(std::istream& in, Song& current)
{

    return in;
}
