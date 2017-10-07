
//package com.google.challenges; 
import java.util.Arrays;

public class Answer {
    public static int answer(boolean[][] g) {
        int H = g.length + 1, W = g[0].length + 1;

        int[][][] dp = new int[2][1 << H][1 << H];
        int cur = 0, prev = 1;

        for (int i = 0; i < (1 << H); ++i) {
            Arrays.fill(dp[prev][i], 1);
        }

        for (int col_idx = 0; col_idx < W - 1; ++col_idx) {
            for (int row_idx = H - 1; row_idx >= 0; --row_idx) {
                // Solve states
                for (int last_row = 0; last_row < (1 << H); ++last_row) {
                    for (int cur_row = 0; cur_row < (1 << row_idx); ++cur_row) {

                        if (row_idx == 0) {
                            dp[cur][last_row][cur_row] =
                                dp[prev][last_row][cur_row] +
                                dp[prev][last_row][cur_row | 1];
                            continue;
                        }

                        boolean target = g[row_idx - 1][col_idx];

                        int cursum = (
                            ((cur_row >> row_idx - 1) & 1) +
                            ((last_row >> row_idx) & 1) + 
                            ((last_row >> (row_idx - 1)) & 1)
                        );

                        int ans = 0;

                        if (target ? cursum == 1 : cursum != 1) {
                            if (row_idx == H - 1)
                                ans += dp[prev][cur_row][0];
                            else
                                ans += dp[prev][last_row][cur_row];
                        }

                        if (target ? cursum + 1 == 1 : cursum + 1 != 1) {
                            int new_cur_row = cur_row | (1 << row_idx);
                            if (row_idx == H - 1)
                                ans += dp[prev][new_cur_row][0];
                            else
                                ans += dp[prev][last_row][new_cur_row];
                        }

                        dp[cur][last_row][cur_row] = ans;
                    }
                }

                // Update memo
                prev = cur;
                cur = 1 - cur;
            }
        }

        int result = 0;
        for (int i = 0; i < (1 << H); ++i)
            result += dp[prev][i][0];
        return result;
    }
}
