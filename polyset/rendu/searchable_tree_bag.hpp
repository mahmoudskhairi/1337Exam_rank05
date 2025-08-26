#pragma once

#include "./tree_bag.hpp"
#include "./searchable_bag.hpp"
class searchable_tree_bag: public tree_bag, public searchable_bag
{
public:
    searchable_tree_bag(/* args */){}
    searchable_tree_bag(const searchable_tree_bag &other): tree_bag(other){}
    searchable_tree_bag& operator=(const searchable_tree_bag &other){
        if (this != &other)
            tree_bag::operator=(other);
        return *this;
    }
	bool has(int num) const
    {
        node *tmp = this ->tree;
        while (tmp)
        {
            if (num == tmp->value)
                return 1;
            else if (num < tmp->value)
                tmp = tmp->l;
            else if (num > tmp->value)
                tmp = tmp->r;
        }
        return 0;
    }
    ~searchable_tree_bag(){}
};
