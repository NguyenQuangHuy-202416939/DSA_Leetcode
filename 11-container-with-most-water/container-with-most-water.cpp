class Solution {
public:
    int maxArea(vector<int>& height) {
       int n = height.size();
    int max_area = 0;
    int left = 0; 
	int right = n - 1;
	while( left < right){
		int min_height = min(height[left], height[right]);
		int area = ( right - left) * min_height;
		if( area > max_area)
			max_area = area;
		if( min_height == height[left])
			left++;
		else
			right--;
	} 
	return max_area; 
    }
};