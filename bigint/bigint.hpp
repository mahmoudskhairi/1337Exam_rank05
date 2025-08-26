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
    bigint(){
    }
    bigint(size_t num)
    {
        for (; num ;)
        {
            _number.push_front(num % 10);
            num = num / 10;
        }
        printDeque();
    }
    bigint(bigint &other)
    {
        _number = other._number;
    }
    bigint &operator=(const bigint &other)
    {
        if (this != &other)
        {
            _number = other._number;
        }
        return *this;
    }
    bigint operator+(const bigint &other) const
    {
        bigint tmp;
        size_t max = std::max(this->_number.size(), other._number.size());
        int rest = 0;
        for (size_t i = 0; i < max; i++)
        {
            int a = (i < _number.size()) ? _number.at(i): 0;
            int b = (i < other._number.size()) ? other._number.at(i): 0;
            int tot = a + b + rest;
            tmp._number.push_back(tot % 10);
            rest = tot / 10;
        }
        if (rest)
            tmp._number.push_back(rest);
        return tmp;
    }
    bigint operator+=(const bigint &other)
    {
        *this = this->operator+(other);
        return *this;
    }
    bigint &operator++()
    {
        *this = this->operator+(bigint(1));
        return *this;
    }
    bigint operator++(int)
    {
        bigint tmp;
        tmp = this->operator+(bigint(1));
        *this = this->operator+(bigint(1));
        return tmp;
    }
    bigint operator<<(int shift)
    {
        bigint tmp(*this);
        while (shift >= 0)
        {
            tmp._number.push_front(0);
            shift--;
        }
        return tmp;
    }
    bigint operator>>(int shift)
    {
        bigint tmp(*this);
        while (shift >= 0)
        {
            tmp._number.pop_front();
            shift--;
        }
        return tmp;
    }
    void    printDeque()
    {
        for (size_t i = 0; i < _number.size(); i++)
        {
            std::cout << _number.at(i);
        }
        std::cout << std::endl;
    }
    void    normalize()
    {
        for (size_t i = 0; i < _number.size(); i++)
        {
            if (_number.at(i) != 0)
                break;
            else
                _number.pop_front();
        }
    }
    friend  std::ostream &operator<<(std::ostream &out, const bigint& other)
    {
        
        if (other._number.size() == 0)
        {
            out << 0;
            return out;
        }
        for (size_t i = 0; i < other._number.size(); i++)
        {
            out << other._number.at(i);
        }
        return out;
    }
    ~bigint(){}
};

