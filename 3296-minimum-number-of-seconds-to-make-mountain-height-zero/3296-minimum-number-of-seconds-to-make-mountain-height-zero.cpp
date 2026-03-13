class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
                long long  lo = 1, hi = 1e16;

        while (lo < hi) {
            long long  mid = (lo + hi) >> 1;
            long long  tot = 0;
            for (int i = 0; i < workerTimes.size() && tot < mountainHeight; i++)
                tot += (long long)(sqrt((double)mid / workerTimes[i] * 2 + 0.25) - 0.5);
            if (tot >= mountainHeight)
                hi = mid;
            else
                lo = mid + 1;
        }

        return lo;
    }
};