#include "Song.h"

size_t Song::nextID = 0;

Song::Song()
{
    this->ID = ++Song::nextID;
    this->songName = "Default SongName";
    this->singerName = "Default SingerName";
    this->albumName = "Default AlbumName";
    this->yearOfProduction = 0;
    this->genre = defaultGenre;
}

Song::Song(const std::string& songName, const std::string& singerName, const std::string& albumName, size_t yearOfProduction, const Genre& genre, const std::map<std::string, double>& ratings)
{
    this->songName = songName;
    this->singerName = singerName;
    this->albumName = albumName;
    this->yearOfProduction = yearOfProduction;
    this->genre = genre;
    this->ratings = ratings;
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
    return this->ID;
}

const std::string& Song::getAlbumName() const
{
    return this->albumName;
}

const size_t Song::getYearOfProduction() const
{
    return this->yearOfProduction;
}

Genre Song::getGenre() const
{
    return this->genre;
}

const double Song::getRating() const
{
    double sumRatings = 0;
    for (const auto& it : this->ratings)
    {
        sumRatings += it.second;
    }
    return sumRatings / this->ratings.size();
}

void Song::rateSong(std::string username, double rating)
{
    this->ratings.insert(std::pair<std::string, double>(username, rating));
}

bool Song::usernameHasRated(std::string username)
{
    for (const auto& it : this->ratings)
    {
        if (username == it.first)
        {
            return true;
        }
    }
    return false;
}

const std::map<std::string, double>& Song::getMAPratings() const
{
    return this->ratings;
}

void Song::setSongName(const std::string& songName)
{
    this->songName = songName;
}

void Song::setSingerName(const std::string& singerName)
{
    this->singerName = singerName;
}

void Song::setAlbumName(const std::string& albumName)
{
    this->albumName = albumName;
}

void Song::setID(size_t ID)
{
    this->ID = ID;
}

void Song::setYearOfProduction(size_t yearOfProduction)
{
    this->yearOfProduction = yearOfProduction;
}

void Song::setGenre(const Genre& genre)
{
    this->genre = genre;
}

void Song::setGenre(int genre)
{
    this->genre = (Genre)genre;
}

std::ostream& operator<<(std::ostream& out, const Song& current)
{
    out << current.singerName << " - " << current.songName << std::endl
        << "Album: " << current.albumName << "; " << "Year: " <<current.yearOfProduction << std::endl
        << "Genre: ";
    switch (current.genre)
    {
    case 0:
        out << "Default";
        break;
    case 1:
        out << "Pop";
        break;
    case 2:
        out << "Rap";
        break;
    case 3:
        out << "HipHop";
        break;
    case 4:
        out << "Rock";
        break;
    case 5:
        out << "Metal";
        break;
    case 6:
        out << "Jazz";
        break;
    case 7:
        out << "Folk";
        break;
    case 8:
        out << "Classical";
        break;
    case 9:
        out << "Country";
        break;
    case 10:
        out << "Electronic";
        break;
    case 11:
        out << "Techno";
        break;
    case 12:
        out << "House";
        break;
    default:
        break;
    }
    out << " Rating: ";
    if (!current.ratings.empty()) out << current.getRating() << std::endl;
    else out << "Non-Rated" << std::endl;

    return out;
}

std::istream& operator>>(std::istream& in, Song& current)
{
    std::string input;
    std::cout << "Song Name: ";
    std::getline(std::cin, input);
    current.setSongName(input);

    std::cout << "Singer Name: ";
    std::getline(std::cin, input);
    current.setSingerName(input);

    std::cout << "Album Name: ";
    std::getline(std::cin, input);
    current.setAlbumName(input);

    std::cout << "Year of production: ";
    in >> current.yearOfProduction;
    std::cout << "Genre: ";
    int genre;
    in >> genre;
    current.setGenre(genre);

    return in;
}
