class Solution {
private:
    void merge(int l,int r,int m,vector<int> & nums){
        int left = l,mid = m+1;
        int right = r-l+1;

        vector<int> temp;
        for(int i=0; i<right; i++)
        {
            if(left > m){
                temp.push_back(nums[mid++]);
            }else if(mid > r){
                temp.push_back(nums[left++]);
            }
            
            else if(nums[left] < nums[mid]){
                temp.push_back(nums[left++]);
            }else{
                temp.push_back(nums[mid++]);
            }
        }
        for(int i=l,j=0; i<=r; i++,j++)
            nums[i] = temp[j];
    }

    void mergeSort(int l,int r,vector<int> & nums){
        if(l>=r) return ;
        int mid = (l+r)/2;
        mergeSort(l,mid,nums);
        mergeSort(mid+1,r,nums);
        merge(l,r,mid,nums);   
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        mergeSort(0,n-1,nums);
        return nums;
    }
};