#include <algorithm>

struct Powers {
    int num_of_two;
    int num_of_five;
    
    Powers() : num_of_two(0), num_of_five(0) { }
    
    int getNumberOfTrailingZeroes() const {
        return min(num_of_two, num_of_five);
    }
};

bool operator<(const Powers& lhs, const Powers& rhs) {
    int lhsValue = lhs.getNumberOfTrailingZeroes();
    int rhsValue = rhs.getNumberOfTrailingZeroes();
    if (lhsValue != rhsValue) return lhsValue < rhsValue;
    
    int lhsMax = max(lhs.num_of_two, lhs.num_of_five);
    int rhsMax = max(rhs.num_of_two, rhs.num_of_five);
    return lhsMax < rhsMax;
}

Powers operator+(const Powers& lhs, const Powers& rhs) {
    Powers p;
    p.num_of_two = lhs.num_of_two + rhs.num_of_two;
    p.num_of_five = lhs.num_of_five + rhs.num_of_five;
    return p;
}

Powers getPowers(int x) {
    Powers p;
    
    if (x == 0) return p;
    
    while (x % 2 == 0) {
        p.num_of_two += 1;
        x /= 2;
    }
    
    while (x % 5 == 0) {
        p.num_of_five += 1;
        x /= 5;
    }
    
    return p;
}

int solution(vector< vector<int> > &A) {
    if (A[0][0] == 0) return 1;
    
    const int n = A.size();
    
    vector< vector<Powers> > B(n, vector<Powers>(n));
    bool matrixHasZeroes = false;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (A[i][j] == 0) matrixHasZeroes = true;
            
            B[i][j] = getPowers(A[i][j]);
        }
    }
    
    vector< vector<Powers> > dp(n, vector<Powers>(n));
    vector< vector<bool> > solved(n, vector<bool>(n, true));
    
    dp[0][0] = B[0][0];
    
    auto isValidOption = [&](int x, int y) -> bool {
      return (0 <= x && x < n) && (0 <= y && y < n) && (solved[x][y]); 
    };
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == 0 && j == 0) continue;
            
            const int x1 = i - 1, y1 = j;
            const int x2 = i, y2 = j - 1;
            
            if (A[i][j] == 0) {
                solved[i][j] = false;
                continue;
            }
            
            if (isValidOption(x1, y1) && isValidOption(x2, y2))
                dp[i][j] = min(dp[x1][y1] + B[i][j], dp[x2][y2] + B[i][j]);
            else if (isValidOption(x1, y1))
                dp[i][j] = dp[x1][y1] + B[i][j];
            else if (isValidOption(x2, y2))
                dp[i][j] = dp[x2][y2] + B[i][j];
            else
                solved[i][j] = false;
        }
    }
    
    int answer;
    
    if (solved[n-1][n-1])
        answer = dp[n-1][n-1].getNumberOfTrailingZeroes();
    else
        answer = 1000000007;
    
    if (matrixHasZeroes)
        answer = min(1, answer);
    
    return answer;
}