class Solution {
public:
    int prefixCount(uint64_t p, int n, int mask) {
        if (p > n) return 0;
        if (p != n / mask) return 1 + 10 * prefixCount(p * 10 + 0, n, mask / 10);
        int res = 1;
        for (int i = 0; i < 10; ++i) res += prefixCount(p * 10 + i, n, mask / 10);
        return res;
    }
    int prefixCount(uint64_t  p, int n) {
        uint64_t mask = 1;
        while (p * mask <= n) mask *= 10;
        return prefixCount(p, n, mask / 10);
    }
    
    int findKthNumber(int n, int k) {
        --k;
        int prefix = 1;
        while (k) {
            int c = prefixCount(prefix, n);
            if (k < c) { //current prefix is good, refine it
                --k;
                prefix *= 10;
            } else { //current prefix is too small, move to next prefix
                k -= c;
                prefix++;
            }
        }
        return prefix;
    }
};
