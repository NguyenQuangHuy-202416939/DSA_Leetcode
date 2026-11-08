class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> st;
    bool visited[26] = {false};
    int count_char[26] = {0};
    int n = s.length();
    string ans = "";
    for( int i = 0; i < n; i++){
    	count_char[s[i] - 'a']++;
	}
	for( int i = 0; i < n; i++){
		if(!visited[s[i] - 'a']){
			while( !st.empty() && s[i] < st.top() && count_char[st.top() - 'a'] > 0){
				visited[st.top() - 'a'] = false;
				st.pop();
			}
			st.push(s[i]);
			visited[s[i] - 'a'] = true;
		}
		count_char[s[i] - 'a']--;
	}
	while(!st.empty()){
		ans += st.top();
		st.pop();
	}
	reverse(ans.begin(), ans.end());
	return ans;
    }
};