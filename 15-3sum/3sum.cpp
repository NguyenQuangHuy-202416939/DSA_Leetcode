class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> arr;
    int n = nums.size();
    int index = 0;
    sort(nums.begin(), nums.end());
    while( index < n && nums[index] <= 0 ){
    	if( index > 0 && nums[index] == nums[index-1]){
    		index++;
    		continue;
		}
    	int left = index + 1;
    	int right = n - 1;
    	while(left < right){
    		int sum = nums[left] + nums[right] + nums[index];
    		if( sum == 0){
    			arr.push_back({nums[index], nums[left], nums[right]});
    			right--;
    			left++;
                 while(left < right && nums[left] == nums[left - 1])
                    left++;

                while(left < right && nums[right] == nums[right + 1])
                    right--;
			}
			else if( sum > 0){
				right--;
			}
			else{
				left++;
			}
		}
		index++;
	}
	return arr;
    }
};