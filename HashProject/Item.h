#pragma once
#include <iostream>
#include <stdlib.h>

using namespace std;

template<class K, class D>
class Item {
public:
	K key;
	D data;
	Item* next = NULL;

	Item() {};
};
