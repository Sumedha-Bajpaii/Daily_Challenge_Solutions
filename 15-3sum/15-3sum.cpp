class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        
        for(int k=n-1; k>=0; k--){
            int target = -nums[k];
            // cout<<k<<" ";
            int i=0, j=k-1;
            while(i<j){
                // cout<<nums[i]<<" "<<nums[j]<<endl;
                if(nums[i] + nums[j] == target){
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    while(i<j && nums[i]==temp[0])
                        i++;
                    while(i<j && nums[j]==temp[1])
                        j--;
                    while(k>=0 && nums[k]==temp[2])
                        k--;
                    k++;
                    ans.push_back(temp);
                }
                else if(nums[i] + nums[j] < target)
                    i++;
                else
                    j--;
            }
        }
        
        return ans;
    }
};