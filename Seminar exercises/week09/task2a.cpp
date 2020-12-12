#include <iostream>
#include <stack>
#include <cassert>
const size_t MAX_SIZE = 4;

int lab[MAX_SIZE][MAX_SIZE] = { {0, 0, 0, 1},
                                {0, 1, 1, 0},
                                {0, 1, 1, 0},
                                {0, 0, 0, 0} };

struct Position
{
    int row;
    int column;

    bool operator==(Position other)
    {
        return row == other.row && column == other.column;
    }

    Position down()
    {
        return Position{row + 1, column};
    }
    Position right()
    {
        return Position{row, column + 1};
    }   

    friend std::ostream& operator<<(std::ostream& out, const Position& obj); 

};

std::ostream& operator<<(std::ostream& out, const Position& obj) {
    out << "(" << obj.row << ", " << obj.column << ")";
    return out;
}

bool downstairs(Position start, Position end)
{
    if(start == end)
    {
        return true;
    }


    std::stack<Position> s;
    s.push(start);
    while(!s.empty())
    {
        Position current = s.top();
        s.pop();
        
        if(current == end)
        {
            return true;
        }


        if(current.column + 1 < MAX_SIZE && lab[current.row][current.column + 1] == 0)
        {
            s.push(current.right());
        }
        if(current.row + 1 < MAX_SIZE && lab[current.row + 1][current.column] == 0)
        {
            s.push(current.down());
        }
    }
    return false;
}

int main()
{
    assert(downstairs({0, 0}, {3, 3}) == false);
    // assert(downstairs({1, 0}, {3, 3}) == false);
    
    return 0;
}