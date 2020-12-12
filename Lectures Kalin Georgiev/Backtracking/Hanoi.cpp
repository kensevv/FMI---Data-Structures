#include <iostream>
#include <vector>

struct Tower {
    char name;
    int number_of_disks;
};

void drawTowers(Tower& source, Tower& temp, Tower& dest) {
    int linePos = 14;

    for(size_t i = 0; i < 3; i++){
        for(size_t j = 0; j < 50; j++) {
            
            if(j >= 14 && j % 14 == 0) {
                std::cout << "|";
            }
            std::cout << " ";
        }
        std::cout << std::endl;
    }


}


void playHanoi(int k,Tower& source, Tower& temp, Tower& dest) {
    if(k == 1) {
        std::cout << "Moved disk from tower " << source.name << " to tower " << dest.name << std::endl;
        return;
    }

    playHanoi(k-1,source,dest,temp);
    std::cout << "Moved disk from tower " << source.name << " to tower " << dest.name << std::endl;
    source.number_of_disks--;
    dest.number_of_disks++;
    playHanoi(k-1,temp,source,dest);
}

int main () {
    Tower A{'A',3};
    Tower B{'B',0};
    Tower C{'C',0};

    playHanoi(3,A,B,C);
    drawTowers(A,B,C);
}