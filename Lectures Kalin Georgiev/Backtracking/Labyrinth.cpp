#include <iostream>
#include <stack>

const int LAB_SIZE = 8;
int labyrinth[LAB_SIZE][LAB_SIZE] = { {0, 1, 0, 0, 0, 0, 0, 0},
                                      {0, 1, 0, 0, 0, 0, 0, 0},
                                      {0, 1, 0, 0, 0, 0, 0, 0},
                                      {0, 1, 0, 0, 0, 0, 0, 0},
                                      {0, 1, 0, 1, 1, 1, 0, 0},
                                      {0, 1, 0, 0, 0, 1, 0, 0},
                                      {0, 1, 0, 0, 0, 1, 0, 0},
                                      {0, 1, 0, 0, 0, 0, 0, 0} };

struct Position {
    int x,y;

    bool operator== (const Position& other) {
        return x == other.x && y == other.y;
    }

    Position down() {
        return Position{x,y+1};
    }

    Position up() {
        return Position{x,y - 1};
    }

    Position right() {
        return Position{x + 1,y};
    }

    Position left() {
        return Position{x - 1,y};
    }
};

bool viablePosition(const Position& pos) {
    return pos.x >= 0 && 
           pos.y >= 0 && 
           pos.x < LAB_SIZE && 
           pos.y < LAB_SIZE && 
           labyrinth[pos.x][pos.y] == 0;
}

bool way (Position current, Position goal) {

    if(current == goal){
        return true;
    } 
    
    if(!viablePosition(current)) {
        return false;
    }

    labyrinth[current.x][current.y] = 9; //маркира къде сме били;

    bool found = way(current.down(),goal) ||
                 way(current.right(),goal) || 
                 way(current.up(),goal) ||
                 way(current.left(),goal);


    labyrinth[current.x][current.y] = 0; //нулира лабиринта;

    return found;

}

bool wayStack(Position start, Position end) {
    std::stack<Position> s;

    s.push(start);

    while(!s.empty()) {
        Position current = s.top(); s.pop();

        if(current == end) {
            return true;
        }

        if(viablePosition(current)) {
            labyrinth[current.x][current.y] = 9;

            s.push(current.left());
            s.push(current.up());
            s.push(current.right());
            s.push(current.down());
        }
        
    }

    return false;
}

void printLab() {
     for(size_t i = 0; i < LAB_SIZE; i++) {
        for(size_t j = 0; j < LAB_SIZE; j++) {
            std::cout << labyrinth[i][j] << "  ";
        }   
        std::cout << std::endl;
    }
}


int main () {
    Position start{0,0};
    Position goal{7,7};
    
    std::cout << way(start,goal) << std::endl;
    
    std::cout << wayStack(start,goal) << std::endl;
    
    std::cout << way(start,goal) << std::endl;


}