class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
                int i, j = 1;

        for (i = 0; i < nums1.size() && j < nums2.size(); j++)
            i += nums1[i] > nums2[j];

        return j - i - 1;
    }
};