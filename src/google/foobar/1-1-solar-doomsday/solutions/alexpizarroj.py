#!/usr/bin/env python2.7
def square_root(x):
    lo, hi = 0, x + 1

    while hi - lo > 1:
        mid = lo + (hi - lo) / 2

        if mid * mid <= x:
            lo = mid
        else:
            hi = mid

    return lo


def answer(area):
    squares = []

    while area >= 4:
        root = square_root(area)
        square = root * root
        squares.append(square)
        area -= square

    squares = squares + ([1] * area)

    return squares


def main():
    print answer(12)
    print answer(15324)


if __name__ == '__main__':
    main()
