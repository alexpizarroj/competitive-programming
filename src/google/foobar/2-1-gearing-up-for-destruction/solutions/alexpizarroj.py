#!/usr/bin/env python2.7
def sign_alternating_sum_of_spaces(pegs):
    return sum((-1)**i * (pegs[i + 1] - pegs[i]) for i in xrange(len(pegs) - 1))


def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)


def simplify(a, b):
    g = gcd(a, b)
    return (a / g, b / g)


def works(pegs, ra, rb):
    for i in xrange(1, len(pegs)):
        c = pegs[i] - pegs[i - 1]
        a, b = c * rb - ra, rb
        if a < b:
            return False

        simplify(a, b)
        ra, rb = a, b

    return True


def answer(pegs):
    s = sign_alternating_sum_of_spaces(pegs)

    if s <= 0:
        return [-1, -1]

    a = 2 * s
    b = 2 - (-1)**(len(pegs) + 1)
    a, b = simplify(a, b)

    if a < b or not works(pegs, a, b):
        return [-1, -1]

    return [a, b]


def main():
    print answer([4, 30, 50])
    print answer([4, 17, 50])


if __name__ == '__main__':
    main()
