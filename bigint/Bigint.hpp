#pragma once

#include <iostream>
#include <deque>


class bigint{
	std::deque<int> data;

	public:
		bigint(){}
		bigint(size_t nb){
			int left = 0;
			while (nb){
				left = nb % 10;
				data.push_back(left);
				nb /= 10;
			}
			// std::cout << *this << std::endl;
		}
		bigint(const std::string &nb){
			for (size_t i = 0; i < nb.size(); i++)
			{
				if(!isdigit(nb[i]))
					exit(1);
				data.push_front(nb[i] - 48);
			}
			// std::cout << *this << std::endl;
		}
		bigint(const bigint &oth):data(oth.data){}
		bigint &operator=(const bigint &oth){
			if (this != &oth){
				data = oth.data;
			}
			return *this;
		}
		bigint	operator+(const bigint &oth)const{
			bigint res;
			int carry = 0;
			size_t max = std::max(data.size(), oth.data.size());
			for (size_t i = 0; i < max; i++)
			{
				int a = (i < data.size()) ? data[i] : 0;
				int b = (i < oth.data.size()) ? oth.data[i] : 0;
				int sum = a + b + carry;
				carry = sum / 10;
				sum %= 10;
				res.data.push_back(sum);
			}
			if (carry)
				res.data.push_back(carry);
			return res;
		}
		bigint &operator+=(const bigint &oth){
			*this = *this + oth;
			return *this;
		}
		bigint &operator++(){//"000666"
			*this = *this + bigint(1);
			return *this;
		}
		bigint operator++(int){
			bigint tmp(*this);
			++(*this);
			return tmp;
		}
		bigint operator<<(int nb){
			bigint tmp(*this);
			while (nb--)
				tmp.data.push_front(0);
			return tmp;
		}
		bigint &operator<<=(int nb){
			*this = *this << nb;
			return *this;
		}
		bigint operator>>(int nb){
			bigint tmp(*this);
			while (nb--)
				tmp.data.pop_front();
			return tmp;
		}
		int to_int(const bigint &nb){
			int res = 0;
			if (nb.data.size() == 0)
				return 0;
			for (int i = nb.data.size() - 1; i >= 0; i--)
				res = res * 10 + nb.data[i];
			return res;
		}
		bigint &operator>>=(const bigint &nb){
			*this = *this >> to_int(nb);
			return *this;
		}
		bool operator<(const bigint &nb) const{
			if (data.size() < nb.data.size())
				return true;
			else if (data.size() == nb.data.size()){
				for (int i = nb.data.size() - 1; i >= 0; i--){
					if (data[i] < nb.data[i])
						return true;
					else
						return false;
				}
			}
			return false;
		}

		bool operator>(const bigint &nb) const{
			if (data.size() > nb.data.size())
				return true;
			else if (data.size() == nb.data.size()){
				for (int i = nb.data.size() - 1; i >= 0; i--){
					if (data[i] > nb.data[i])
						return true;
					else
						return false;
				}
			}
			return false;
		}
		bool operator<=(const bigint &nb) const{
			return !operator>(nb);
		}
		bool operator>=(const bigint &nb) const{
			return !operator<(nb);
		}
		bool operator==(const bigint &nb)const{
			(void)nb;
			if (data.size() != nb.data.size())
				return false;
			for (size_t i = 0; i < data.size(); i++)
			{
				if ((size_t)data[i] != nb.data.size())
					return false;
			}
			return true;
		}
		bool operator!=(const bigint &nb)const{
			return !operator==(nb);
		}

		bigint operator-(const bigint &nb)const{
			(void)nb;
			return bigint(0);
		}

		friend std::ostream &operator<<(std::ostream &out, const bigint &nb){
			if (nb.data.size() == 0)
				out << 0 ;
			for (int i = nb.data.size() - 1; i >= 0; i--)
				out << nb.data[i];
			return out;
		}
};
