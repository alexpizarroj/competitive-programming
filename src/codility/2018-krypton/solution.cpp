#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

const int kInfinity = 1000000007;

struct PrimeFactorsOfTen {
    int powersOfTwo = 0;
    int powersOfFive = 0;
    
    PrimeFactorsOfTen() { }

    PrimeFactorsOfTen(unsigned int x) {
        if (x == 0) return;

        while (x % 2 == 0) {
            powersOfTwo += 1;
            x /= 2;
        }
        
        while (x % 5 == 0) {
            powersOfFive += 1;
            x /= 5;
        }
    }

    PrimeFactorsOfTen(int powersOfTwo, int powersOfFive) {
        this->powersOfTwo = powersOfTwo;
        this->powersOfFive = powersOfFive;
    }
    
    int getNumberOfTrailingZeroes() const {
        return min(powersOfTwo, powersOfFive);
    }
};

PrimeFactorsOfTen operator+(const PrimeFactorsOfTen& lhs, const PrimeFactorsOfTen& rhs) {
    return PrimeFactorsOfTen(lhs.powersOfTwo + rhs.powersOfTwo, lhs.powersOfFive + rhs.powersOfFive);
}

bool operator==(const PrimeFactorsOfTen& lhs, const PrimeFactorsOfTen& rhs) {
    return lhs.powersOfTwo == rhs.powersOfTwo && lhs.powersOfFive == rhs.powersOfFive;
}

bool operator!=(const PrimeFactorsOfTen& lhs, const PrimeFactorsOfTen& rhs) {
    return !(lhs == rhs);
}

bool isLesserByPowerOfTwoThenPowerOfFive(const PrimeFactorsOfTen& lhs, const PrimeFactorsOfTen& rhs) {
    if (lhs.powersOfTwo != rhs.powersOfTwo) return lhs.powersOfTwo < rhs.powersOfTwo;
    return lhs.powersOfFive < rhs.powersOfFive;
}

bool isLesserByPowerOfFiveThenPowerOfTwo(const PrimeFactorsOfTen& lhs, const PrimeFactorsOfTen& rhs) {
    if (lhs.powersOfFive != rhs.powersOfFive) return lhs.powersOfFive < rhs.powersOfFive;
    return lhs.powersOfTwo < rhs.powersOfTwo;
}

struct SolutionSet {
    vector<PrimeFactorsOfTen> values;

    bool empty() const {
        return values.empty();
    }

    int best() const {
        int answer = kInfinity;
        for (auto&& solution : values) {
            answer = min(solution.getNumberOfTrailingZeroes(), answer);
        }
        return answer;
    }

    void add(const PrimeFactorsOfTen& solution) {
        values.push_back(solution);
    }

    void prune() {
        if (values.size() < 2) return;

        PrimeFactorsOfTen bestBy2Then5 = PrimeFactorsOfTen(kInfinity, kInfinity);
        PrimeFactorsOfTen bestBy5Then2 = PrimeFactorsOfTen(kInfinity, kInfinity);

        for (auto&& solution : values) {
            if (isLesserByPowerOfTwoThenPowerOfFive(solution, bestBy2Then5)) {
                bestBy2Then5 = solution;
            }
            if (isLesserByPowerOfFiveThenPowerOfTwo(solution, bestBy5Then2)) {
                bestBy5Then2 = solution;
            }
        }

        values.clear();
        values.push_back(bestBy2Then5);
        if (bestBy2Then5 != bestBy5Then2) {
            values.push_back(bestBy5Then2);
        }
    }
};

int solution(vector< vector<int> > &A) {
    if (A[0][0] == 0) return 1;
    
    const int n = A.size();
    
    vector< vector<PrimeFactorsOfTen> > B(n);
    bool matrixHasZeroes = false;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (A[i][j] == 0) matrixHasZeroes = true;
            B[i].emplace_back(A[i][j]);
        }
    }
    
    vector< vector<SolutionSet> > dp(n, vector<SolutionSet>(n));
    
    auto isValidOption = [&](int x, int y) -> bool {
      return 0 <= x && x < n && 0 <= y && y < n;
    };

    dp[0][0].add(B[0][0]);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == 0 && j == 0) continue;
            
            if (A[i][j] == 0) continue;

            const int x1 = i - 1, y1 = j;
            if (isValidOption(x1, y1)) {
                for (auto&& previousSolution : dp[x1][y1].values) {
                    dp[i][j].add(previousSolution + B[i][j]);
                }
            }

            const int x2 = i, y2 = j - 1;
            if (isValidOption(x2, y2)) {
                for (auto&& previousSolution : dp[x2][y2].values) {
                    dp[i][j].add(previousSolution + B[i][j]);
                }
            }

            dp[i][j].prune();
        }
    }
    
    int answer = dp[n-1][n-1].best();
    if (matrixHasZeroes) answer = min(1, answer);
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n) {
        vector< vector<int> > input(n, vector<int>(n));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> input[i][j];
            }
        }

        cout << solution(input) << endl;
    }
}
