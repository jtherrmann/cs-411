// Jake Herrmann
// CS 411
// 28 Sep 2020
//
// build.h
// Header file for the exhaustive-search bridge-building algorithm.

#ifndef BRIDGES_BUILD_H
#define BRIDGES_BUILD_H

#include <vector>
using std::vector;

using Bridge = vector<int>;

int build(int w, int e, const vector<Bridge> & bridges);

#endif //BRIDGES_BUILD_H