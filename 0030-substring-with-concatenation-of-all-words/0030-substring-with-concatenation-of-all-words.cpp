class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.size();
        int m = words.size(), w = words[0].size();
        
        unordered_map<string,int> chars;
        for(auto &it: words){
            chars[it]++;
        }
        
        vector<int> ans;
        for(int i=0; i<w; i++){
            unordered_map<string,int> mpp;
            string t = "";
            for(int j=i,k=i; k<n; k++){
                t += s[k];
                if(t.size()==w){
                    mpp[t]++;
                    t = "";
                }
                if(k-j+1 == m*w){
                    if(chars == mpp) ans.push_back(j);
                    string remove = s.substr(j,w);
                    if(mpp[remove] > 1) mpp[remove]--;
                    else mpp.erase(remove);
                    j += w;
                }
            }
        }
        return ans;
    }
};