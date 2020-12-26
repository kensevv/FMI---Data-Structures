#include "Song.h"

Song::Song()
{
}

Song::Song(const std::string& songName, const std::string& singerName, const std::string& albumName, size_t yearOfProduction, const std::vector<Genre>& genres, double rating)
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

const std::string& Song::getAlbumName() const
{
    return this->albumName;
}

const size_t Song::getYearOfProduction() const
{
    return size_t();
}

const std::vector<Genre>& Song::getGenres() const
{
    return this->genres;
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

void Song::setYearOfProduction(size_t yearOfProduction)
{
}

void Song::setGenres(const std::vector<Genre>& genres)
{
}
