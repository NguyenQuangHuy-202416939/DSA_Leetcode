class Solution {
public:
    string longestPalindrome(string s) {
    	int n = s.length();
		vector<vector<bool>> dp(n, vector<bool>(n, false));
		//string has a word 
		for( int i = 0; i < n; i++){
			dp[i][i] = true;
		}   
		int start = 0;
		int maxlen = 1;
		//nhieu word
		for( int len = 2; len <= n; len++){
			// khoang rong cua chuoi
			for( int i = 0; i <= n - len; i++){
				int j = i + len - 1;
				if(s[i] == s[j]){
					if( len <= 2)
						dp[i][j] = true;
					else
						dp[i][j] = dp[i+1][j-1];
				}
				if( dp[i][j] && len > maxlen){
					start = i;
					maxlen = len;
				}
			}
		}
		return s.substr(start, maxlen);
    }
};