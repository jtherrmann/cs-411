import os
import shutil
from random import randint

from quicksort import quicksort, pivot_left, pivot_median_of_three, pivot_random


def main():
    if os.path.exists('results'):
        shutil.rmtree('results')
    os.mkdir('results')

    data = [('n',
             'shuffled.left', 'sorted.left', 'reversed.left', 'rotated.left',
             'shuffled.median', 'sorted.median', 'reversed.median', 'rotated.median',
             'shuffled.random', 'sorted.random', 'reversed.random', 'rotated.random')]

    pivots = (pivot_left, pivot_median_of_three, pivot_random)

    # Max n is limited by quicksort hitting Python's max recursion depth.
    for n in range(0, 1901, 5):
        if n % 100 == 0:
            print(f'n = {n}')

        shuffled_arr = [randint(-2**32, 2**32) for _ in range(n)]
        sorted_arr = sorted(shuffled_arr)
        reversed_arr = list(reversed(sorted_arr))

        if n != 0:
            rotated_arr = sorted_arr.copy()
            rotated_arr.append(rotated_arr[0])
            rotated_arr.pop(0)
        else:
            rotated_arr = []

        arrays = (shuffled_arr, sorted_arr, reversed_arr, rotated_arr)

        counts = tuple(quicksort(arr.copy(), move_pivot=pivot)
                       for pivot in pivots for arr in arrays)
        data.append((n, *counts))

    with open(os.path.join('results', 'data.csv'), 'w+') as f:
        f.write('\n'.join(','.join(map(str, row)) for row in data))


if __name__ == '__main__':
    main()
