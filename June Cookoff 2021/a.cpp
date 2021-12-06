class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> v;
        
        for(int i=0;i<nums.size();i++){
            if(i!=0 && nums[i]==nums[i-1])
            continue;
            int p=i+1,q=nums.size()-1;
            while(p<q) {
                if(nums[i]+nums[p]+nums[q]<0){
                    while(p!=i+1 && nums[p]==nums[p-1])
                    p++;
                }
                else if(nums[i]+nums[p]+nums[q]>0){
                    while(q!=)
                }
                else{
                    vector <int> v1={nums[i],nums[p],nums[q]};
                    v.push_back(v1);
                }
            }
        }
        return v;

    }
};