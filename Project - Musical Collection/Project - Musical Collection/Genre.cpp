#include "Genre.h"
#include <iostream>



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