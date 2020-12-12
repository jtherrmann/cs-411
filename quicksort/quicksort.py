# Jake Herrmann
# CS 411
# TODO date
#
# quicksort.py
# Source file for quicksort algorithm.

# Adapted from Anany Levitin's
# Introduction to the Design and Analysis of Algorithms, 3rd ed.


def quicksort(arr):
    _quicksort(arr, 0, len(arr) - 1)


def _quicksort(arr, left, right):
    # Quicksort, adapted from Levitin, p. 176
    if left < right:
        split = _partition(arr, left, right)
        _quicksort(arr, left, split - 1)
        _quicksort(arr, split + 1, right)


def _partition(arr, left, right):
    # Hoare Partition, adapted from Levitin, p. 178

    # TODO configurable pivot function
    pivot = arr[left]
    i, j = left, right + 1

    while True:
        while True:
            i += 1
            if i == len(arr) - 1 or arr[i] >= pivot: break

        while True:
            j -= 1
            if arr[j] <= pivot: break

        _swap(arr, i, j)

        if i >= j: break

    _swap(arr, i, j)  # undo last swap
    _swap(arr, left, j)
    return j


def _swap(arr, first, second):
    arr[first], arr[second] = arr[second], arr[first]
