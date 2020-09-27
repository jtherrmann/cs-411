#include "build.h"

#include <cmath>
using std::pow;

// TODO go through and see if should be using a larger int type than 'int'

int get_toll(int subset, const vector<Bridge> & bridges);
vector<int> get_bridge_indices(unsigned int subset);
bool conflict(const Bridge & first, const Bridge & second);

int build(int w, int e, const vector<Bridge> & bridges) {
    (void)w;
    (void)e;
    int max = 0;
    auto n = bridges.size();
    for (auto subset = 0; subset < pow(2, n); ++subset) {
        auto toll = get_toll(subset, bridges);
        if (toll > max)
            max = toll;
    }
    return max;
}

int get_toll(int subset, const vector<Bridge> & bridges) {
    int toll = 0;
    // TODO iterate through indices without converting to vector first?
    auto indices = get_bridge_indices(subset);
    for (auto i = 0; i < indices.size(); ++i) {
        for (auto j = i + 1; j < indices.size(); ++j) {
            if (conflict(bridges[indices[i]], bridges[indices[j]]))
                return -1;
        }
        toll += bridges[indices[i]][2];
    }
    return toll;
}

// TODO do not return a copy of the vector
vector<int> get_bridge_indices(unsigned int subset) {
    vector<int> indices;
    for (auto index = 0; subset != 0; ++index) {
        if (subset & (unsigned int)1)
            indices.push_back(index);
        subset >>= (unsigned int)1;
    }
    return indices;
}

bool conflict(const Bridge & first, const Bridge & second) {
    return first[0] == second[0]
            || first[1] == second[1]
            || (first[0] < second[0] && first[1] > second[1])
            || (first[0] > second[0] && first[1] < second[1]);
}