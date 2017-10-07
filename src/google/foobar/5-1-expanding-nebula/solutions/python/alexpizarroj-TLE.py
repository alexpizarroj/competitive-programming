#!/usr/bin/env python2.7
def answer(g):
    H = len(g) + 1
    W = len(g[0]) + 1

    dp_cur = [[-1 for j in xrange(1 << H)] for i in xrange(1 << H)]
    dp_prev = [[1 for j in xrange(1 << H)] for i in xrange(1 << H)]

    for col_idx in xrange(0, W - 1):
        for row_idx in xrange(H - 1, -1, -1):

            for last_row in xrange(1 << H):
                for cur_row in xrange(1 << row_idx):

                    ans = 0

                    if row_idx == 0:
                        ans += dp_prev[last_row][cur_row] + \
                            dp_prev[last_row][cur_row | 1]

                    else:
                        target = g[row_idx - 1][col_idx]

                        cursum = (
                            ((cur_row >> row_idx - 1) & 1)
                            + ((last_row >> row_idx) & 1)
                            + ((last_row >> (row_idx - 1)) & 1)
                        )

                        options = [
                            (cursum, cur_row),
                            (cursum + 1, cur_row | (1 << row_idx))
                        ]

                        for opt_sum, opt_cur_row in options:
                            if not ((opt_sum == 1) if target == 1 else (opt_sum != 1)):
                                continue

                            if row_idx == H - 1:
                                ans += dp_prev[opt_cur_row][0]
                            else:
                                ans += dp_prev[last_row][opt_cur_row]

                    dp_cur[last_row][cur_row] = ans

            dp_cur, dp_prev = dp_prev, dp_cur

    return sum(dp_prev[starting_row][0] for starting_row in xrange(1 << H))


def main():
    print answer([
        [True, False, True],
        [False, True, False],
        [True, False, True]
    ])
    print answer([
        [True, False, True, False, False, True, True, True],
        [True, False, True, False, False, False, True, False],
        [True, True, True, False, False, False, True, False],
        [True, False, True, False, False, False, True, False],
        [True, False, True, False, False, True, True, True]
    ])
    print answer([
        [True, True, False, True, False, True, False, True, True, False],
        [True, True, False, False, False, False, True, True, True, False],
        [True, True, False, False, False, False, False, False, False, True],
        [False, True, False, False, False, False, True, True, False, False]
    ])


if __name__ == '__main__':
    main()
