class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        int right_max = arr[n-1] ;
        arr[n-1] = -1 ;
      
        for(int i= n -2 ; i>=0 ; i--){
            int curr = arr[i];
             arr[i]=right_max ;
             right_max=max(right_max , curr) ;
        }

        return arr;
    }
};