#pragma once

#include <iostream>
class vect2
{
private:
    int _x;
    int _y;
public:
    vect2(/* args */): _x(0), _y(0){}
    vect2(int x, int y): _x(x), _y(y){}
    vect2(const vect2 &other): _x(other._x), _y(other._y){}
    vect2&  operator=(const vect2& other)
    {
        if (this != &other)
        {
            this->_x = other._x;
            this->_y = other._y;
        }
        return *this;
    }
    vect2 &operator++(void)
    {
        this->_x++;
        this->_y++;
        return *this;
    }
    vect2 operator++(int)
    {
        vect2 tmp(*this);
        this->_x++;
        this->_y++;
        return tmp;
    }
    vect2 &operator--(void)
    {
        this->_x--;
        this->_y--;
        return *this;
    }
    vect2 operator--(int)
    {
        vect2 tmp(*this);
        this->_x--;
        this->_y--;
        return tmp;
    }
    vect2 &operator+=(const vect2& other)
    {
        this->_x += other._x;
        this->_y += other._y;
        return* this;
    }
    vect2 &operator-=(const vect2& other)
    {
        this->_x -= other._x;
        this->_y -= other._y;
        return* this;
    }
    vect2 operator+(const vect2& other) const
    {
        return vect2(this->_x + other._x, this->_y + other._y);
    }
    vect2 operator-(const vect2& other) const
    {
        return vect2(this->_x - other._x, this->_y - other._y);
    }
    int operator[](int index) const
    {
        if (index == 0)
            return _x;
        return _y;
    }
    int &operator[](int index)
    {
        if (index == 0)
            return _x;
        return _y;
    }
    vect2 operator-(void) const
    {
        return vect2(-this->_x , -this->_y);
    }
    bool operator==(const vect2&other) const
    {
        return (this->_x == other._y);
    }
    bool operator!=(const vect2&other) const
    {
        return !(this->_x == other._y);
    }
    vect2 operator*(int num) const
    {
        return vect2( this->_x * num, this->_y * num);
    }
    friend  vect2 operator*(int num, const vect2& other)
    {
        return vect2( other._x * num, other._y * num);
    }
    vect2 &operator*=(int num)
    {
        this->_x += num;
        this->_y += num;
        return *this;
    }
    friend std::ostream& operator<<(std::ostream &out, const vect2 &other)
    {
        out << "{" << other._x << ", " << other._y << "}";
        return out;
    }
    ~vect2(){}
};

