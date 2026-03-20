class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> res(n-k+1, vector<int>(m-k+1));

        for (int i = 0; i <= n-k; i++) {
            vector<int> Element;

            for (int j = 0; j <= m-k; j++) {
                if (j == 0) {
                    // First window: build from scratch
                    Element.clear();
                    for (int r = i; r < i+k; r++)
                        for (int c = 0; c < k; c++)
                            Element.push_back(grid[r][c]);
                } else {
                    // Slide right: remove left column (j-1), add right column (j+k-1)
                    for (int r = i; r < i+k; r++) {
                        auto it = find(Element.begin(), Element.end(), grid[r][j-1]);
                        if (it != Element.end()) Element.erase(it);
                    }
                    for (int r = i; r < i+k; r++)
                        Element.push_back(grid[r][j+k-1]);
                }

                // Sort a COPY — original must stay unsorted for next slide
                vector<int> temp = Element;
                sort(temp.begin(), temp.end());
                temp.erase(unique(temp.begin(), temp.end()), temp.end());

                if (temp.size() <= 1) { res[i][j] = 0; continue; }

                int diff = INT_MAX;
                for (int x = 0; x < (int)temp.size()-1; x++)
                    diff = min(diff, temp[x+1] - temp[x]);

                res[i][j] = diff;
            }
        }
        return res;
    }
};