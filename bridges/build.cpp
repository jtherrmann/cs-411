// Jake Herrmann
// CS 411
// 28 Sep 2020
//
// Source file for the exhaustive-search bridge-building algorithm.


#include "build.h"

#include <cstddef>
using std::size_t;


int get_toll(size_t subset, const vector<Bridge> & bridges);

void fill_bridge_indices(size_t subset, vector<size_t> & indices);

bool conflict(const Bridge & first, const Bridge & second);


int build(int w, int e, const vector<Bridge> & bridges) {
    // Return the maximum total toll that can be collected from a legal set of bridges.

    (void)w;
    (void)e;

    int max = 0;
    auto n = bridges.size();

    for (size_t subset = 0; subset < 1u << n; ++subset) {
        auto toll = get_toll(subset, bridges);
        if (toll > max)
            max = toll;
    }
    return max;
}


int get_toll(size_t subset, const vector<Bridge> & bridges) {
    // Return the total toll for the given subset of bridges, or -1 if the subset is illegal.

    vector<size_t> indices;
    fill_bridge_indices(subset, indices);

    int toll = 0;

    for (auto i = indices.begin(); i != indices.end(); ++i) {
        for (auto j = i + 1; j != indices.end(); ++j) {
            if (conflict(bridges[*i], bridges[*j]))
                return -1;
        }
        toll += bridges[*i][2];
    }
    return toll;
}


void fill_bridge_indices(size_t subset, vector<size_t> & indices) {
    // Convert the given subset to a list of bridge indices.
    for (size_t index = 0; subset != 0; ++index) {
        if (subset & 1u)
            indices.push_back(index);
        subset >>= 1u;
    }
}


bool conflict(const Bridge & first, const Bridge & second) {
    // Check whether two bridges conflict.
    return first[0] == second[0]
            || first[1] == second[1]
            || (first[0] < second[0] && first[1] > second[1])
            || (first[0] > second[0] && first[1] < second[1]);
}