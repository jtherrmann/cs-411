// Jake Herrmann
// CS 411
// 12 Oct 2020
//
// inversions.hpp
// Header file for the inversions-counting algorithm.

// The mergeSort and stableMerge algorithms were taken from code written by
// Glenn G. Chappell, 9 Oct 2015, and modified to count the number of inversions.


#ifndef INVERSIONS_INVERSIONS_HPP
#define INVERSIONS_INVERSIONS_HPP


#include <vector>
using std::vector;

#include <algorithm>
using std::copy;

#include <iterator>
using std::distance, std::advance;

#include <type_traits>
using std::remove_reference;

#include <cstddef>


template <typename FDIter>
size_t mergeSort(FDIter first, FDIter last);

template <typename FDIter>
size_t stableMerge(FDIter first, FDIter middle, FDIter last);


template<typename RAIter>
size_t inversions(RAIter first, RAIter last)
{
    return mergeSort(first, last);
}


template <typename FDIter>
size_t mergeSort(FDIter first, FDIter last)
{
    size_t size = distance(first, last);
    if (size <= 1)
        return 0;

    FDIter middle = first;
    advance(middle, size/2);

    size_t skipped = 0;
    skipped += mergeSort(first, middle);
    skipped += mergeSort(middle, last);

    return skipped + stableMerge(first, middle, last);
}


template <typename FDIter>
size_t stableMerge(FDIter first, FDIter middle, FDIter last)
{
    using Value = typename remove_reference<decltype(*first)>::type;
    vector<Value> buffer(distance(first, last));

    FDIter in1 = first;
    FDIter in2 = middle;
    auto out = buffer.begin();

    size_t skipped = 0;
    while (in1 != middle && in2 != last)
    {
        if (*in2 < *in1)
        {
            *out++ = *in2++;

            // Number of items skipped is the number of items remaining
            // in the first half.
            skipped += distance(in1, middle);
        }
        else
            *out++ = *in1++;
    }

    copy(in1, middle, out);
    copy(in2, last, out);
    copy(buffer.begin(), buffer.end(), first);

    return skipped;
}

#endif //INVERSIONS_INVERSIONS_HPP
