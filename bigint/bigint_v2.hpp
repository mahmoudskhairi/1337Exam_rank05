#ifndef _BIGINT_HPP_
#define _BIGINT_HPP_

#include <iostream>
#include <deque>

class bigint{
private:
    std::deque<int> _num;
public:
    bigint()
    {}
    bigint(size_t num)
    {
        while (num)
        {
            _num.push_back(num % 10);
            num = num / 10;
        }
    }
    bigint(const bigint &other)
    {
        this->_num = other._num;
    }
    bigint &operator=(const bigint &other)
    {
        if (this != &other)
        {
            this->_num = other._num;
        }
        return *this;
    }
    size_t  dequeToInt() const
    {
        int tot = 0;
        for (int i = _num.size() - 1; i >= 0; i--)
        {
            tot = (tot * 10) + _num.at(i);
        }
        return tot;
    }
    ~bigint()
    {
    }
    friend std::ostream &operator<<(std::ostream &out, const bigint &other)
    {
        out << other.dequeToInt();
        return out;
    }

    bigint  operator+(const bigint &other) const
    {
        bigint tmp;
        size_t maxSize = (this->_num.size() > other._num.size())? this->_num.size(): other._num.size();
        int rest = 0;
        int a, b;
        for (size_t i = 0; i < maxSize; i++)
        {
            a = (i < this->_num.size()) ? this->_num.at(i): 0; 
            b = (i < other._num.size()) ? other._num.at(i): 0; 
            rest += (a + b);
            tmp._num.push_back(rest % 10);
            rest = rest / 10;
        }
        if (rest)
        {
            tmp._num.push_back(rest);
        }
        return tmp;
    }
    
    bigint &operator+=(const bigint &other)
    {
        this->operator=(this->operator+(other));
        return *this;
    }
    bigint &operator++(void)
    {
        this->operator+=(1);
        return *this;
    }
    bigint operator++(int)
    {
        bigint tmp(*this);
        this->operator+=(1);
        return tmp;
    }
    bigint operator>>(int shift) const
    {
        bigint tmp(*this);
        while (shift)
        {
            tmp._num.pop_front();
            shift--;
        }
        return tmp;
    }
    bigint &operator>>=(const bigint& other)
    {
        this->operator=(this->operator>>(other.dequeToInt()));
        return *this;
    }
    bigint operator<<(int shift) const
    {
        bigint tmp(*this);
        while (shift)
        {
            tmp._num.push_front(0);
            shift--;
        }
        return tmp;
    }
    bigint &operator<<=(int shift)
    {
        this->operator=(this->operator<<(shift));
        return *this;
    }
    bool    operator<(const bigint& other) const
    {
        return (this->dequeToInt() < other.dequeToInt());
    }
    bool    operator>=(const bigint& other) const
    {
        return !this->operator<(other);
    }
    bool    operator>(const bigint& other) const
    {
        return (this->dequeToInt() > other.dequeToInt());
    }
    bool    operator<=(const bigint& other) const
    {
        return !this->operator>(other);
    }
    bool    operator==(const bigint& other) const
    {
        return (this->dequeToInt() == other.dequeToInt());
    }
    bool    operator!=(const bigint& other) const
    {
        return !this->operator==(other);
    }
};

#endif