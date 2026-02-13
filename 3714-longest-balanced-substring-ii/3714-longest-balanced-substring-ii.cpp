class Solution {
public:
    int longestBalanced(string s) {
        int n = s.length();
        if (n <= 2) return n;   
        
        int ans = 1;

        // 1. Longest single character streak
        char prev = s[0];
        int count = 1;
        for (int i = 1; i < n; i++) {
            if (s[i] == prev) {
                count++;
                ans = max(ans, count);
            } else {
                count = 1;
                prev = s[i];
            }
        }

        // 2. Two-character case
        vector<pair<char, char>> pairs = {
            {'a', 'b'}, {'b', 'c'}, {'a', 'c'}
        };

        for (auto p : pairs) {
            char c1 = p.first;
            char c2 = p.second;
            char other = 'a' + 'b' + 'c' - c1 - c2;

            unordered_map<int, int> mp;
            mp[0] = -1;
            int diff = 0;

            for (int i = 0; i < n; i++) {
                if (s[i] == other) {
                    mp.clear();
                    mp[0] = i;
                    diff = 0;
                } else {
                    if (s[i] == c1) diff++;
                    else diff--;

                    if (mp.count(diff)) {
                        ans = max(ans, i - mp[diff]);
                    } else {
                        mp[diff] = i;
                    }
                }
            }
        }

        // 3. Three-character case
        vector<int> f(3, 0);
        map<vector<int>, int> mp3;
        mp3[{0, 0, 0}] = -1;

        for (int i = 0; i < n; i++) {
            f[s[i] - 'a']++;

            int mn = min({f[0], f[1], f[2]});
            vector<int> key = {
                f[0] - mn,
                f[1] - mn,
                f[2] - mn
            };

            if (mp3.count(key)) {
                ans = max(ans, i - mp3[key]);
            } else {
                mp3[key] = i;
            }
        }

        return ans;
    }
};