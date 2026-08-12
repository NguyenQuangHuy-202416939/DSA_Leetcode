class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count_max = 0;
        int count = 0;
        int i = 0;
        for( int num : nums){
            if( nums[i++] == 1){
                count++;
                if( count_max < count){
                    count_max = count;
                }
                continue;
            }
            count = 0;
        }
        return count_max;
    }
};