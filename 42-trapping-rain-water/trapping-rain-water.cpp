class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
	int sum = 0;
	int l = 0;
	int r = n - 1;
	int max_left = 0;
	int max_right = 0;
	while( l < r){
		if( height[l] <= height[r]){
			if(height[l] > max_left){
				max_left = height[l];
			}
			else{
				sum += max_left - height[l];
			}
			l++;
		}
		else{
			if(height[r] > max_right){
				max_right = height[r];
			}
			else{
				sum += max_right - height[r];
			}
			r--;
		}
	}
	return sum;
    }
};