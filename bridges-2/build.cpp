// Jake Herrmann
// CS 411
// 14 Nov 2020
//
// build.cpp
// Source file for the dynamic programming bridge-building algorithm.


#include <algorithm>
using std::max;

#include "build.hpp"
using std::vector;


int build(int w, int e, const vector<Bridge> & bridges) {
    auto tolls = vector<vector<int>>(w + 1, vector<int>(e + 1, 0));

    // Store the individual bridge tolls in the table.
    for(const auto & bridge : bridges) {
        auto row = bridge[0] + 1;
        auto col = bridge[1] + 1;
        auto toll = bridge[2];

        // There may be multiple possible bridges between the same two cities.
        tolls[row][col] = max(toll, tolls[row][col]);
    }

    // Fill up the table with the max cumulative tolls.
    for(int row = 1; row <= w; ++row) {
        for(int col = 1; col <= e; ++col) {
            tolls[row][col] = max({
                tolls[row - 1][col],
                tolls[row][col - 1],
                tolls[row - 1][col - 1] + tolls[row][col]
            });
        }
    }
    return tolls[w][e];
}
