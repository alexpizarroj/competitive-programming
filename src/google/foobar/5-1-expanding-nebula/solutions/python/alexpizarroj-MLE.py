#!/usr/bin/env python2.7
H = 0
W = 0
G = None
memo = None


def mget(mask, i):
    return ((mask >> i) & 1)


def is_viable(target, cursum):
    return (cursum == 1) if target == 1 else (cursum != 1)


def solve(row_idx, col_idx, last_row, cur_row):
    if row_idx == H - 1:
        return 1

    if memo[row_idx][col_idx][last_row][cur_row] != -1:
        return memo[row_idx][col_idx][last_row][cur_row]

    if col_idx == 0:
        # Try placing both zero and one
        res = solve(row_idx, col_idx + 1, last_row, cur_row)
        res += solve(row_idx, col_idx + 1, last_row, cur_row | 1)
        return res

    # Next step setup
    next_row_idx = row_idx
    next_col_idx = col_idx + 1

    if next_col_idx == W:
        next_col_idx = 0
        next_row_idx += 1

    target = G[row_idx][col_idx - 1]
    cursum = mget(cur_row, col_idx - 1) + \
        mget(last_row, col_idx) + mget(last_row, col_idx - 1)

    # Prune placings
    res = 0
    options = [(cursum, cur_row), (cursum + 1, cur_row | (1 << col_idx))]

    for opt_sum, opt_cur_row in options:
        if not is_viable(target, opt_sum):
            continue

        if next_row_idx == row_idx:
            res += solve(next_row_idx, next_col_idx, last_row, opt_cur_row)
        else:
            res += solve(next_row_idx, next_col_idx, opt_cur_row, 0)

    # Save and return
    memo[row_idx][col_idx][last_row][cur_row] = res

    return res


def answer(g):
    global H, W, G, memo
    H = len(g[0]) + 1
    W = len(g) + 1
    G = [[(1 if g[j][H - i - 2] == True else 0)
          for j in xrange(W - 1)] for i in xrange(H - 1)]
    memo = [[[[-1 for a4 in xrange(1 << W)] for a3 in xrange(1 << W)]
             for a2 in xrange(W)] for x1 in xrange(H)]

    return sum(solve(0, 0, starting_row, 0) for starting_row in xrange(1 << W))


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
