#include "Genre.h"
#include <iostream>
#include <string>
#include "algorithms.h"

void printGenre(Genre genre)
{
    switch (genre)
    {
    case 0:
        std::cout << "Default";
        break;
    case 1:
        std::cout << "Pop";
        break;
    case 2:
        std::cout << "Rap";
        break;
    case 3:
        std::cout << "HipHop";
        break;
    case 4:
        std::cout << "Rock";
        break;
    case 5:
        std::cout << "Metal";
        break;
    case 6:
        std::cout << "Jazz";
        break;
    case 7:
        std::cout << "Folk";
        break;
    case 8:
        std::cout << "Classical";
        break;
    case 9:
        std::cout << "Country";
        break;
    case 10:
        std::cout << "Electronic";
        break;
    case 11:
        std::cout << "Techno";
        break;
    case 12:
        std::cout << "House";
        break;
    default:
        break;
    }
}

Genre genreInput()
{
    std::cout << "Choose genre: (1)Pop, (2)Rap, (3)HipHop, (4)Rock, (5)Metal, (6)Jazz, (7)Folk"
        << "(8)Classical, (9)Country, (10)Electronic, (11)Techno, (12)House" << std::endl
        << ">";
    std::string option;
    std::getline(std::cin, option);
    int genre = validateStringToInt(option);
    if (genre == -1)
    {
        std::cout << "Wrong input, genre set to default genre." << std::endl;
        return (Genre)0;
    }
    return (Genre)genre;
}
