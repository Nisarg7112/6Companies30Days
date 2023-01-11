
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        // size of vector nums
        int len=nums.size();
        
        // leftMin to store the minimum element from left till ith element 
        // rightMax to store the maximum element from right till the ith element
        vector<int>leftMin(len,0),rightMax(len,0);
        
        // initialize leftMin and rightMax
        leftMin[0]=nums[0];
        rightMax[len-1]=nums[len-1];
        
        for(int i=1;i<len;i++){
            leftMin[i]=min(leftMin[i-1],nums[i]);
        }
        
        for(int i=len-2;i>=0;i--){
            rightMax[i]=max(rightMax[i+1],nums[i]);
        }
        
        for(int i=1;i<len-1;i++){
            // check for every current element for which there exist a number in the left having value less than current element and a number in the right having value greater than current element 
            if(nums[i]>leftMin[i-1] and nums[i]<rightMax[i+1]){
                return true;
            }
        }
        return false;
    }
    
};
