class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
    sort(nums.begin(), nums.end());
    int min_space = 1e6;
    int closest_sum = 1e6;
    for( int i = 0; i < n; i++){
    	int left = i + 1;
    	int right = n - 1;
    	while( left < right){
    		int sum = nums[i] + nums[left] + nums[right];
    		if( abs(sum - target) < min_space){
    			min_space = abs(sum - target);
    			closest_sum = sum;
			}
			else if( sum < target){
				left++;
			}
			else
				right--;
		}
	}
	return closest_sum;
    }
};