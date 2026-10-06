class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       if( nums1.size() > nums2.size())
		swap(nums1, nums2);
	int n = nums1.size();
	int m = nums2.size();
	
	int left = 0;
	int right = n;
	
	int total_left = ( n + m + 1 ) / 2;
	while( left <= right){
		int i = (left + right) / 2;
		int j = total_left - i;
		
		int A_left = (i == 0) ? INT_MIN : nums1[i-1];
		int A_right = (i == n) ? INT_MAX : nums1[i];
		
		int B_left = (j == 0) ? INT_MIN : nums2[j-1];
		int B_right = (j == m) ? INT_MAX : nums2[j];
		
		if( A_left <= B_right && B_left <= A_right){
			if( (m + n) % 2 != 0){
				return max(A_left, B_left);
			}
			else{
				return (max(A_left, B_left) + min(A_right, B_right))/2.0;
			}
		}
		else if( A_left > B_right)
			right = i - 1;
		else 
			left = i + 1;
	}
	return 0.0;
    }
};