// Jake Herrmann
// CS 411
// 14 Nov 2020
//
// build.hpp
// Header file for the dynamic programming bridge-building algorithm.

#ifndef BRIDGES_BUILD_H
#define BRIDGES_BUILD_H

#include <vector>

using Bridge = std::vector<int>;

int build(int w, int e, const std::vector<Bridge> & bridges);

#endif //BRIDGES_BUILD_H