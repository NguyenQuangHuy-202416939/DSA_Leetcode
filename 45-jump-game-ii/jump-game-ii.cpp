class Solution {
public:
    int jump(vector<int>& nums) {
       int n = nums.size();\
    if(n == 1)
		return 0;
	int next_point[n];
	for( int i = 0; i < n; i++){
		next_point[i] = i + nums[i];
	}
	int index = 0;
	int count = 0;
	while(index < n){
		int max_space = 0;
		int mark = index;
		int limit = min(n-1, next_point[index]);
		if( limit == n - 1)
			break;
		for( int i = index; i <= limit ; i++){
			if( max_space < next_point[i]){
				max_space = next_point[i];
				mark = i;
			}
		}
		index = mark;
		count++;
	} 
	return count + 1; 
    }
};