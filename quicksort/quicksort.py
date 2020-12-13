# Jake Herrmann
# CS 411
# 13 Dec 2020
#
# quicksort.py
# Source file for quicksort algorithm.

# Adapted from Anany Levitin's
# Introduction to the Design and Analysis of Algorithms, 3rd ed.

from random import randint


# ----------------------------------------------------------------------
# Pivot functions
# ----------------------------------------------------------------------

# noinspection PyUnusedLocal
def pivot_left(arr, left, right):
    """Leave the leftmost element as the pivot."""
    pass


def pivot_median_of_three(arr, left, right):
    """Median-of-three pivot selection."""
    mid = (left + right) // 2
    if arr[left] < arr[mid] < arr[right] or arr[left] > arr[mid] > arr[right]:
        _swap(arr, left, mid)
    elif arr[left] < arr[right] < arr[mid] or arr[left] > arr[right] > arr[mid]:
        _swap(arr, left, right)
    elif arr[mid] == arr[right] != arr[left]:
        _swap(arr, left, mid)


def pivot_random(arr, left, right):
    """Random pivot selection."""
    _swap(arr, left, randint(left, right))


# ----------------------------------------------------------------------
# Quicksort public interface
# ----------------------------------------------------------------------

def quicksort(arr, move_pivot=pivot_left):
    """Run quicksort on the given array.

    If specified, the move_pivot argument must be a function that takes
    an array, left index, and right index, and moves the pivot element
    into the position specified by the left index.

    Returns the number of key comparisons performed (excluding pivot
    selection).
    """
    return _quicksort(arr, 0, len(arr) - 1, move_pivot)


# ----------------------------------------------------------------------
# Internal functions
# ----------------------------------------------------------------------

def _quicksort(arr, left, right, move_pivot):
    # Quicksort, adapted from Levitin, p. 176
    count = 0
    while left < right:
        split, partition_count = _partition(arr, left, right, move_pivot)
        count += partition_count
        count += _quicksort(arr, left, split - 1, move_pivot)
        left = split + 1
    return count


def _partition(arr, left, right, move_pivot):
    # Hoare Partition, adapted from Levitin, p. 178

    count = 0
    move_pivot(arr, left, right)
    pivot = arr[left]
    i, j = left, right + 1

    while True:
        while True:
            i += 1
            count += 1
            if i == len(arr) - 1 or arr[i] >= pivot: break

        while True:
            j -= 1
            count += 1
            if arr[j] <= pivot: break

        _swap(arr, i, j)
        if i >= j: break

    _swap(arr, i, j)  # undo last swap
    _swap(arr, left, j)
    return j, count


def _swap(arr, first, second):
    arr[first], arr[second] = arr[second], arr[first]
