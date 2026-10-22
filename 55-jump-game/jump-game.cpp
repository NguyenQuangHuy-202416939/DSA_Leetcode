class Solution {
public:
    bool canJump(vector<int>& nums) {
       int n = nums.size();
	int next_point[n];
	for( int i = 0; i < n; i++){
		next_point[i] = i + nums[i];
	}
	int index = 0;
	while(index < n){
		int max_space = 0;
		int mark = index;
		int limit = min(n-1, next_point[index]);
		if( limit == n - 1)
			return true;
		for( int i = index; i <= limit ; i++){
			if( max_space < next_point[i]){
				max_space = next_point[i];
				mark = i;
			}
		}
		if( mark == index)
			return 0;
		index = mark;
	}    
	return false;  
    }
};