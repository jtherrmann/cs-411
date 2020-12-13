from random import randint

from quicksort import quicksort, pivot_median_of_three, pivot_random


def main():
    data = [('n',
             'shuffled.left', 'sorted.left', 'reversed.left', 'rotated.left',
             'shuffled.median', 'sorted.median', 'reversed.median', 'rotated.median',
             'shuffled.random', 'sorted.random', 'reversed.random', 'rotated.random')]

    # TODO eliminate tail call in quicksort, increase max n
    for n in range(0, 901, 5):
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

        data.append((
            n,

            quicksort(shuffled_arr.copy()),
            quicksort(sorted_arr.copy()),
            quicksort(reversed_arr.copy()),
            quicksort(rotated_arr.copy()),

            quicksort(shuffled_arr.copy(), move_pivot=pivot_median_of_three),
            quicksort(sorted_arr.copy(), move_pivot=pivot_median_of_three),
            quicksort(reversed_arr.copy(), move_pivot=pivot_median_of_three),  # TODO quadratic?
            quicksort(rotated_arr.copy(), move_pivot=pivot_median_of_three),

            quicksort(shuffled_arr.copy(), move_pivot=pivot_random),
            quicksort(sorted_arr.copy(), move_pivot=pivot_random),
            quicksort(reversed_arr.copy(), move_pivot=pivot_random),
            quicksort(rotated_arr.copy(), move_pivot=pivot_random),
        ))

    with open('data.csv', 'w+') as f:
        f.write('\n'.join(','.join(map(str, row)) for row in data))


if __name__ == '__main__':
    main()
