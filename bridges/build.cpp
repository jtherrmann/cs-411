#include "build.h"

#include <cstddef>
using std::size_t;

int get_toll(size_t subset, const vector<Bridge> & bridges);
vector<size_t> get_bridge_indices(size_t subset);
bool conflict(const Bridge & first, const Bridge & second);

int build(int w, int e, const vector<Bridge> & bridges) {
    (void)w;
    (void)e;
    int max = 0;
    auto n = bridges.size();
    for (size_t subset = 0; subset < 1u<<n; ++subset) {
        auto toll = get_toll(subset, bridges);
        if (toll > max)
            max = toll;
    }
    return max;
}

int get_toll(size_t subset, const vector<Bridge> & bridges) {
    int toll = 0;
    // TODO iterate through indices without converting to vector first?
    auto indices = get_bridge_indices(subset);
    for (auto i = indices.begin(); i != indices.end(); ++i) {
        for (auto j = i + 1; j != indices.end(); ++j) {
            if (conflict(bridges[*i], bridges[*j]))
                return -1;
        }
        toll += bridges[*i][2];
    }
    return toll;
}

// TODO do not return a copy of the vector
vector<size_t> get_bridge_indices(size_t subset) {
    vector<size_t> indices;
    for (size_t index = 0; subset != 0; ++index) {
        if (subset & 1u)
            indices.push_back(index);
        subset >>= 1u;
    }
    return indices;
}

// TODO pass values separately
bool conflict(const Bridge & first, const Bridge & second) {
    return first[0] == second[0]
            || first[1] == second[1]
            || (first[0] < second[0] && first[1] > second[1])
            || (first[0] > second[0] && first[1] < second[1]);
}