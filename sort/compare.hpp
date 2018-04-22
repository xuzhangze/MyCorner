#pragma once

#include <iostream>
using namespace std;
#include <cassert>
#include <ctime>
#include <cstdlib>



template <typename T>
struct Less
{
	bool operator()(T &left, T &right)const
	{
		return left < right;
	}
};

template <typename T>
struct Greater
{
	bool operator()(T &left, T &right)const
	{
		return left > right;
	}
};
