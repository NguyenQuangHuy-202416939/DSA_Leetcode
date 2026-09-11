class Solution{
	public: 
		vector<int> twoSum(vector<int>&nums, int target){
			unordered_map<int,int> mp_nums;
			vector<int> ans;
			for(int i = 0;i < nums.size(); i ++){
				auto it = mp_nums.find(target - nums[i]);
				if(it != mp_nums.end()){
					ans.push_back(i);
					ans.push_back(it -> second);
				} 
				else mp_nums[nums[i]] = i;
			}
			return ans;
		}		
};