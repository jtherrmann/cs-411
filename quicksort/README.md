# Quicksort

Jake Herrmann\
CS 411\
13 Dec 2020

Known to work with Python 3.8.

Run the unit tests:

```
python3 test_quicksort.py
```

Run `python3` from this directory and then test quicksort interactively:

```
>>> from quicksort import quicksort
>>> from random import randint
>>> arr = [randint(0, 100) for _ in range(20)]
>>> arr
[51, 66, 91, 12, 33, 15, 78, 51, 36, 63, 85, 11, 42, 9, 12, 36, 68, 8, 4, 61]
>>> quicksort(arr)  # returns number of key comparisons
78
>>> arr
[4, 8, 9, 11, 12, 12, 15, 33, 36, 36, 42, 51, 51, 61, 63, 66, 68, 78, 85, 91]
```
