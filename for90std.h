#pragma once
#include <vector>

template<T>
struct forarray {
	int lb, ub;
	forarray slice(int fr, int to, int step = 1);
	char * c_array();
	std::vector<T> c_vector();

	forarray(int l, int u) lb(l), ub(u){}
protected:
	std::vector<T> m_arr;
	char * carr;
};

struct forcomplex {

};