class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count_max = 0;
        int count = 0;
        for( int num : nums){
            if( num == 1){
                count++;
                count_max = max(count_max, count);
            }
            else
                count = 0;
        }
        return count_max;
    }
};