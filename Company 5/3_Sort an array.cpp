class Solution {
public:
    void merge(vector<int>& nums, int p, int q, int r) {

    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1], M[n2];

    for (int i = 0; i < n1; i++)
        L[i] = nums[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = nums[q + 1 + j];

    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    // Until we reach either end of either L or M, pick larger among
    // elements L and M and place them in the correct position at A[p..r]
    while (i < n1 && j < n2) {
        if (L[i] <= M[j]) {
            nums[k] = L[i];
            i++;
        } else {
            nums[k] = M[j];
            j++;
        }
        k++;
    }

    // When we run out of elements in either L or M,
    // pick up the remaining elements and put in A[p..r]
    while (i < n1) {
        nums[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        nums[k] = M[j];
        j++;
        k++;
    }
    
    }

    void MergeSort(vector<int>& nums,int p,int r){
    if(p >= r) 
        return;
    int q = (p+r)/2;
    MergeSort(nums, p, q);
    MergeSort(nums, q+1, r);
    merge(nums, p, q, r);
    }   

    vector<int> sortArray(vector<int>& nums) {
        MergeSort(nums,0,nums.size()-1);

        return nums;
    }
};
