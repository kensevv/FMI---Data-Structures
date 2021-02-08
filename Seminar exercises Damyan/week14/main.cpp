#include <iostream>
#include <string>
#include <cassert>
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
    
    HashMap<std::string, int> hashMap(stringHashFunc);
    
    

    hashMap.addNewElement(std::make_pair("traicho", 6));

    // hashMap.addNewElement(std::make_pair("rtaicho", 3));

    assert((*hashMap.contains("traicho")).first == "traicho");
    assert((*hashMap.contains("traicho")).second == 6);

    assert(hashMap.contains("pencho") == hashMap.end());
    
    hashMap.addNewElement(std::make_pair("pencho", 12));

    try {
        hashMap.addNewElement(std::make_pair("pencho", 16));
    } catch (addingExistingElementException& exc) {
        // 
    } catch(...) {
        assert(false);
    }
        
//    hashMap.addNewElement("traicho", 6);

    for(auto element : hashMap) {
        std::cout << element.first << ": " << element.second << "\n";
    }


    return 0;
}


