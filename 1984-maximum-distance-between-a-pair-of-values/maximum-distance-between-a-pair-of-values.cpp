class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int ans = 0;
        int i = 0 ; 
        int j = 0 ;

        while(i < n1 && j < n2){
            if(nums1[i] <= nums2[j]){
                ans = max(j-i,ans);
                j++;
            }else{
                i++;
            }

        }
        return ans;
    }
};