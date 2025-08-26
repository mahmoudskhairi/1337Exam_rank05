#pragma once

#include <iostream>
#include <deque>

class bigint
{
private:
    /* data */
    std::deque<int> _number;
    // std::deque<char> _number;
    public:
    bigint(){}
    bigint(size_t num){
        for (; num; )
        {
            _number.push_back(num % 10);
            num = num / 10;
        }
    }
    bigint(const bigint &other){
        _number = other._number;
    }
    bigint &operator=(const bigint &other){
        if (this != &other)
        {
            _number = other._number;
        }
        return *this;
    }
    friend std::ostream &operator<<(std::ostream &out, const bigint &other)
    {
        if (other._number.size() == 0)
        {
            out << 0;
            return out;
        }
        for (int i = other._number.size() - 1; i >= 0; i--)
        {
            out << other._number.at(i);
        }
        return out;
    }

    bigint operator+(const bigint &other)const 
    {
        bigint tmp;
        size_t MaxSize = std::max(this->_number.size(), other._number.size());
        int rest = 0; 
        for (size_t i = 0; i < MaxSize; i++)
        {
            int a = (i < _number.size())? _number.at(i) : 0;
            int b = (i < other._number.size())? other._number.at(i) : 0;
            int total = a + b + rest;
            tmp._number.push_back(total % 10);
            rest = total / 10;
        }
        if (rest)
            tmp._number.push_back(rest);
        return tmp;
    }
    bigint &operator+=(const bigint& other)
    {
        *this = this->operator+(other);
        return *this;
    }
    bigint &operator++(void)
    {
        *this = this->operator+(bigint(1));
        return *this;
    }
    bigint  operator++(int)
    {
        bigint tmp(*this);
        *this = this->operator+(bigint(1));
        return tmp;
    }
    bigint operator>>(int shift)
    {
        bigint tmp(*this);
        while (shift)
        {
            if (tmp._number.size())
                tmp._number.pop_front();
            else
                break;
            shift--;
        }
        return tmp;
    }
    bigint operator<<(int shift)
    {
        bigint tmp(*this);
        while (shift)
        {
            tmp._number.push_front(0);
            shift--;
        }
        return tmp;
    }
    bigint operator>>=(int shift)
    {
        *this = this->operator>>(shift);
        return *this;
    }
    int DequeToInt(const bigint&other)
    {
        int num = 0;
        for (int i = other._number.size() -1 ; i >= 0; i--)
        {
            num = (num * 10) + other._number.at(i);
        }
        return num;
    }
    bigint operator>>=(const bigint&other)
    {
        int shift = DequeToInt(other);
        *this = this->operator>>(shift);
        return *this;
    }
    bigint operator<<=(int shift)
    {
        *this = this->operator<<(shift);
        return *this;
    }
    bool operator>(const bigint &other)
    {
        return (DequeToInt(*this) > DequeToInt(other))? 1: 0;
    }
    bool operator<(const bigint &other)
    {
        return (DequeToInt(*this) < DequeToInt(other))? 1: 0;
    }
    bool operator<=(const bigint &other)
    {
        return !this->operator>(other);
    }
    bool operator>=(const bigint &other)
    {
        return !this->operator<(other);
    }
    bool operator==(const bigint &other)
    {
        return (DequeToInt(*this) == DequeToInt(other))? 1: 0;
    }
    bool operator!=(const bigint &other)
    {
        return !this->operator==(other);
    }
    ~bigint(){}

};

