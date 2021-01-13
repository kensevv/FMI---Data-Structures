#pragma once
struct position
{
    int x, y;

    bool operator ==(const position& p)
    {
        return x == p.x && y == p.y;
    }
    bool operator !=(const position& p)
    {
        return x != p.x || y != p.y;
    }
    position down()
    {
        return position{ x,y + 1 };
    }
    position up()
    {
        return position{ x,y - 1 };
    }
    position left()
    {
        return position{ x - 1,y };
    }
    position right()
    {
        return position{ x + 1,y };
    }
    position rightup()
    {
        return position{x+1,y-1};
    }
    position rightdown()
    {
        return position{x+1, y+1};
    }
    position leftup()
    {
        return position{x-1,y-1};
    }
    position leftdown()
    {
        return position{x-1, y+1};
    }
};

