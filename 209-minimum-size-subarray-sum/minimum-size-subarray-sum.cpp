class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
       vector<int> frefix_sum;
       frefix_sum.push_back(0);
       int n = nums.size();
       long long sum = 0;
       for( int i = 0; i < n; i++){
            sum += nums[i];
            frefix_sum.push_back(sum);
       }
       int l = 1, r = 1;
       int min_length = 1e6;
       while( l <= n && r <= n){
            int s = frefix_sum[r] - frefix_sum[l-1];
            if( s >= target){
                int space = r - l + 1;
                if(space < min_length)
                    min_length = space;
                l++;
            }
            else{
                r++;
            }
       }
       if( min_length == 1e6)
            return 0;
        return min_length; 
    }
};