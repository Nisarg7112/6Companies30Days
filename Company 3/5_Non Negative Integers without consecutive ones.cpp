class Solution {
public:
    int findIntegers(int n) {
        // add extra 1 for 0
        // find the count of valid integers in the range [1, n]
        return 1 + countValidInts(1, n);
    }
    
private:
    int countValidInts(int integer, int limit) {
        // do not add to total count if current integer exceeds limit
        if (integer > limit) {
            return 0;
        }
        
        if (integer & 1) {
         
            
            return 1 + countValidInts((integer << 1) | 0, limit);
        } else {
            
            return 1 + countValidInts((integer << 1) | 0, limit) + countValidInts((integer << 1) | 1, limit);
        }
    }
};
