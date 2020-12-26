#include "User.h"

User::User()
{
}

User::User(const std::string& username, const std::string& password, const std::string& fullName, const Date& birthday)
{
}

void User::setUsername(const std::string& username)
{
}

void User::setPassword(const std::string& password)
{
}

void User::setFullName(const std::string& fullName)
{
}

void User::setBirthday(const Date& birthday)
{
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
    return false;
}

void User::addFavGenre(const Genre& genre)
{
}

void User::addFavPlaylist(Playlist* playlist)
{
}

void User::removeFavGenre(const Genre& genre)
{
}

void User::removeFavPlaylist(Playlist* playlist)
{
}
