//
// Created by jth on 10/11/20.
//

#ifndef GCS_CONTIGSUM_HPP
#define GCS_CONTIGSUM_HPP

#include <algorithm>
using std::max;

#include <tuple>
using std::tuple, std::get;


template<typename RAIter>
tuple<int, int, int, int> contigSumRec(RAIter first, RAIter last);


template<typename RAIter>
int contigSum(RAIter first, RAIter last) {
    if (first == last)
        return 0;
    return get<0>(contigSumRec(first, last));
}


template<typename RAIter>
tuple<int, int, int, int> contigSumRec(RAIter first, RAIter last) {
    auto length = last - first;
    if (length == 1) {
        auto gcs = max(0, *first);
        return {gcs, gcs, gcs, *first};
    }

    RAIter mid = first + length / 2;
    auto [A1, B1, C1, D1] = contigSumRec(first, mid);
    auto [A2, B2, C2, D2] = contigSumRec(mid, last);

    auto A = max({A1, A2, C1 + B2});
    auto B = max(B1, D1 + B2);
    auto C = max(C2, D2 + C1);
    auto D = D1 + D2;

    return {A, B, C, D};
}


#endif //GCS_CONTIGSUM_HPP
