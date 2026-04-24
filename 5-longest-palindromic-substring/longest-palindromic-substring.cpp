class Solution {
public:
    string expand(string &s, int l, int r) {
        while(l >= 0 && r < s.size() && s[l] == s[r]) {
            l--; r++;
        }
        return s.substr(l + 1, r - l - 1);
    }

    string longestPalindrome(string s) {
        string res = "";
        
        for(int i = 0; i < s.size(); i++) {
            string s1 = expand(s, i, i);       // odd length
            string s2 = expand(s, i, i + 1);   // even length
            
            if(s1.size() > res.size()) res = s1;
            if(s2.size() > res.size()) res = s2;
        }
        return res;
    }
};