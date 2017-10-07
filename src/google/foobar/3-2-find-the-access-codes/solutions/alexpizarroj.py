#!/usr/bin/env python2.7
def answer(l):
    n = len(l)
    a, b = [0] * n, [0] * n

    for i in xrange(n):
        for j in xrange(i + 1, n):
            if l[j] % l[i] == 0:
                a[i] += 1

    for i in xrange(n):
        for j in xrange(i + 1, n):
            if l[j] % l[i] == 0:
                b[i] += a[j]

    return sum(b[i] for i in xrange(n))


def main():
    print answer([1, 1, 1])
    print answer([1, 2, 3, 4, 5, 6])


if __name__ == '__main__':
    main()
