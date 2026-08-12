class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;
        vector<bool> map(n+1, false);
        for( int i = 0; i < n; i++){
            if( map[nums[i]] == 1){
                result.push_back(nums[i]);
            }
            else
                map[nums[i]] = 1;
        }
        for( int i = 1; i <= n; i++){
            if( map[i] == 0){
                result.push_back(i);
            }
        }
        return result;
    }
};