#!/usr/bin/env python2.7
def numberfy(lst):
    sum = 0
    for x in lst:
        sum = sum * 10 + x
    return sum


def try_remove_1one(lst):
    n = len(lst)
    for i in xrange(n - 1, -1, -1):
        if lst[i] % 3 == 1:
            return lst[0:i] + lst[i + 1:n]
    return []


def try_remove_1two(lst):
    n = len(lst)
    for i in xrange(n - 1, -1, -1):
        if lst[i] % 3 == 2:
            return lst[0:i] + lst[i + 1:n]
    return []


def try_remove_2ones(lst):
    return try_remove_1one(try_remove_1one(lst))


def try_remove_2twos(lst):
    return try_remove_1two(try_remove_1two(lst))


def answer(l):
    l.sort(reverse=True)
    if l[0] == 0:
        return 0

    value = numberfy(l)
    if value % 3 == 0:
        return value

    rem = value % 3

    if rem == 1:
        value1 = numberfy(try_remove_1one(l))
        if value1 > 0:
            return value1

        value2 = numberfy(try_remove_2twos(l))
        if value2 > 0:
            return value2

    elif rem == 2:
        value1 = numberfy(try_remove_1two(l))
        if value1 > 0:
            return value1

        value2 = numberfy(try_remove_2ones(l))
        if value2 > 0:
            return value2

    return 0


def main():
    print answer([3, 1, 4, 1])
    print answer([3, 1, 4, 1, 5, 9])


if __name__ == '__main__':
    main()
