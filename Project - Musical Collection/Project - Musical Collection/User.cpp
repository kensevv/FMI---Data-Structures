#include "User.h"

User::User()
{
    this->username = "Default username";
    this->password = "Default password";
    this->fullName = "Default name";
}

User::User(const std::string& username, const std::string& password, const std::string& fullName, const Date& birthday)
{
    this->username = username;
    this->password = password;
    this->fullName = fullName;
    this->birthday = birthday;
}

void User::setUsername(const std::string& username)
{
    this->username = username;
}

void User::setPassword(const std::string& password)
{
    this->password = password;
}

void User::setFullName(const std::string& fullName)
{
    this->fullName = fullName;
}

void User::setBirthday(const Date& birthday)
{
    this->birthday = birthday;
}

const std::string& User::getUsername() const
{
    return this->username;
}

const std::string& User::getPassword() const
{
    return this->password;
}

const std::string& User::getFullName() const
{
    return this->fullName;
}

const Date& User::getBirthday() const
{
    return this->birthday;
}

const std::vector<Genre>& User::getFavGenres() const
{
    return this->favGenres;
}

const std::vector<Playlist*>& User::getPlaylists() const
{
    return this->playlists;
}

bool User::login(const std::string& username, const std::string& password)
{
    return this->username == username && this->password == password;
}

void User::addFavGenre(const Genre& genre)
{
    this->favGenres.push_back(genre);
}

void User::addFavPlaylist(Playlist* playlist)
{
    this->playlists.push_back(playlist);
}

void User::removeFavGenre(const Genre& genre)
{
    for (size_t i = 0; i < favGenres.size(); i++)
    {
        if (favGenres[i] == genre)
        {
            this->favGenres.erase(favGenres.begin() + i);
        }
    }
}

void User::removeFavPlaylist(Playlist* playlist)
{
    for (size_t i = 0; i < playlists.size(); i++)
    {
        if (playlists[i] == playlist)
        {
            this->playlists.erase(playlists.begin() + i);
        }
    }
}

std::ostream& operator<<(std::ostream& out, const User& current)
{
    out << current.fullName << " - " << current.username << ". " << std::endl <<
        current.birthday << std::endl <<
        "Favourite genres: ";
    for (size_t i = 0; i < current.getFavGenres().size(); i++)
    {
        printGenre(current.getFavGenres()[i]);
        std::cout << "; ";
    }
    std::cout << std::endl << "Playlists: ";
    for (size_t i = 0; i < current.getPlaylists().size(); i++)
    {
        std::cout << current.getPlaylists()[i]->getName() << "; ";
    }
    std::cout << std::endl;
    return out;
}

std::istream& operator>>(std::istream& in, User& current)
{
    std::string input;
    std::cout << "Username: ";
    std::getline(std::cin, input);
    current.setUsername(input);

    std::cout << "Password: ";
    std::getline(std::cin, input);
    current.setPassword(input);

    std::cout << "Full Name: ";
    std::getline(std::cin, input);
    current.setFullName(input);

    in >> current.birthday;

    return in;
}
