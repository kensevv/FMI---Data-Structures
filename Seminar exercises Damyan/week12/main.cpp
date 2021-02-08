#include <iostream>
#include <string>
#include "HashMap.h"

int main()
{
    auto stringHashFunc = [](const std::string& s) -> size_t {
        size_t sum = 0;
        for(int i = 0; i < s.size(); i++)
        {
            sum += s[i];
        }
        return sum;
    };
    
    HashMap<std::string, char> hashMap(stringHashFunc);
        
    std::cout << "Finished\n";
    return 0;
}

