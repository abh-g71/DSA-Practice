class Solution {
public:

void merge(vector<int>& nums,int s,int mid,int e){
    vector<int>temp;

    int i = s;
    int j = mid +1;

    while(i <= mid && j <= e){
        if(nums[i] < nums[j]){
            temp.push_back(nums[i]);
            i++;
        }else{
            temp.push_back(nums[j]);
            j++;
        }
    }

    while( i <= mid){
        temp.push_back(nums[i]);
        i++;
    }
    while( j <= e){
        temp.push_back(nums[j]);
            j++;
    }

    for(int k =s ; k <= e ; k++){
        nums[k] = temp[k-s];
    }
}
    void solve(vector<int>& nums,int s,int e){
        if(s>=e){
            return;
        }
        int mid = s + (e-s)/2;

        solve(nums,s,mid);

        solve(nums,mid+1,e);

        merge(nums,s,mid,e);
        

    }
    vector<int> sortArray(vector<int>& nums) {
        vector<int>ans;
        int n = nums.size();
        int s = 0 ;
        int e = n-1;
        int mid = s+(e-s)/2;
        solve(nums,s,e);
        return nums;
    }
};