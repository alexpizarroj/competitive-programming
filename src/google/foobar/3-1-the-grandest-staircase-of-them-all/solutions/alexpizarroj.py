#!/usr/bin/env python2.7
DP_BRICKS_UBOUND = 201
dp_filled = False

# dp[# of bricks left][min. # of bricks next staircase step must start with]
dp = [[-1] * (DP_BRICKS_UBOUND + 1) for x in xrange(DP_BRICKS_UBOUND)]


def fill_dp_impl():
    for i in xrange(DP_BRICKS_UBOUND + 1):
        dp[0][i] = 1

    for b in xrange(1, DP_BRICKS_UBOUND):
        for m in xrange(DP_BRICKS_UBOUND - 1, -1, -1):
            dp[b][m] = 0
            for used_bricks in xrange(m, b + 1):
                dp[b][m] += dp[b - used_bricks][used_bricks + 1]


def fill_dp():
    global dp_filled
    if dp_filled:
        return
    dp_filled = True
    fill_dp_impl()


def answer(n):
    fill_dp()
    global dp
    return (dp[n][1] - 1)


def main():
    print answer(3)
    print answer(200)


if __name__ == '__main__':
    main()
