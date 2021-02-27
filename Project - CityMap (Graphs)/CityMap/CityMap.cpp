// CityMap.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Map.h"
#include "Controller.h"
#include "doctest.h"

void loadMap();
bool Exit = false;
Controller* controller = nullptr;

int main()
{
	//doctest::Context().run();
    loadMap();
}

void loadMap()
{
    if (controller != nullptr)
    {
        std::cout << "There is already a map loaded! Close first!" << std::endl;
        return;
    }
    do
    {
        std::ifstream MyFile;
        std::cout << "Enter file name/path" << std::endl
            << ">";
        std::string file;
        std::getline(std::cin, file);
        MyFile.open(file);
        if (MyFile.is_open())
        {
            controller = new Controller(MyFile);
            MyFile.close();
            std::cout << "\nSuccessfully opened " << file << "\nMap loaded!\n"<< std::endl;
            break;
        }
        else
        {
            std::cout << "ERROR! File with such path/name doesn't exist, try again." << std::endl;
        }
    } while (true);
}
