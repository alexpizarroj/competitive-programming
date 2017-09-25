// https://leetcode.com/problems/rectangle-area/

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int x1 = abs(B - D), y1 = abs(A - C);
        int x2 = abs(F - H), y2 = abs(E - G);
        
        int x3 = getIntersectionLength(min(B, D), max(B, D), min(F, H), max(F, H));
        int y3 = getIntersectionLength(min(A, C), max(A, C), min(E, G), max(E, G));
        
        long long result = 0;
        result += (long long)x1 * y1;
        result += (long long)x2 * y2;
        result -= (long long)x3 * y3;
        
        return (int)result;
    }
private:
    // Intersection length of two intervals [a, b] and [c, d]
    int getIntersectionLength(int a, int b, int c, int d) {
        int result = 0;
        
        if (a <= c) {
            result = (c <= b ? min(b, d) - c : 0);
        } else {
            result = (a <= d ? min(b, d) - a : 0);
        }
        
        return result;
    }
};
