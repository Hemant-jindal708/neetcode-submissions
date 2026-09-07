class Solution {
public:
    int getSum(int a, int b) {
        return ((a & b) << 1) + (unsigned int)(a ^ b);
    }
};
