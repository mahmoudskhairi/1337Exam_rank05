#pragma once

#include "array_bag.hpp"
#include "searchable_bag.hpp"
class searchable_array_bag : public array_bag ,public searchable_bag
{
private:
    /* data */
public:
    searchable_array_bag(/* args */) {}
    searchable_array_bag(const searchable_array_bag&other): array_bag(other){}
    searchable_array_bag& operator=(const searchable_array_bag&other){
        if (this != &other)
            array_bag::operator=(other);
        return *this;
    }
    ~searchable_array_bag(){}
	bool    has(int num) const
    {
        for (int i = 0; i < size; i++)
        {
            if (this->data[i] == num)
                return 1;
        }
        return 0;
    }
};
