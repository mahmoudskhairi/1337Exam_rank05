#pragma once

#include "searchable_array_bag.hpp"
#include "searchable_tree_bag.hpp"
class set
{
private:
    searchable_bag &mybag;
public:
    set(searchable_bag &other): mybag(other){}
    ~set(){}
    void insert (int num){
        if (!mybag.has(num))
            mybag.insert(num);
    }
    void insert (int *arr, int size){        
        for (int i = 0; i < size; i++)
        {
            if (!mybag.has(arr[i]))
                mybag.insert(arr[i]);
        }
    }
	void print() const{
        mybag.print();
    }
    bool has(int num) const{
        return mybag.has(num);
    }
    searchable_bag &get_bag() const
    {
        return mybag;
    }
	void clear() {
        mybag.clear();
    }
};

