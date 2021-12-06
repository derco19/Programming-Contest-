#include<bits/stdc++.h>


using namespace std;
class Solution {
public:
    int dp[100005];
    int helper(vector<vector<int>>& arr,int val)
    {
        int ans=arr.size(),st=0,ed=arr.size()-1;
        while(st<=ed)
        {
            int mid=st+(ed-st)/2;
            if(arr[mid][0]>=val)
            {
                ans=mid;
                ed=mid-1;
            }
            else
            {
                st=mid+1;
            }
        }
        return ans;
    }
    int fun(int i,vector<vector<int>>&arr)
    {
        if(i>=arr.size())
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        int op1=fun(i+1,arr);
        int idx=helper(arr,arr[i][1]);
        int op2=arr[i][2]+fun(idx,arr);
        return dp[i]=max(op1,op2);
    }
    int phoneCalls(vector<int>& st, vector<int>& ed, vector<int>& profit) {
        vector<vector<int>> arr;
        int i,j,k,n=st.size();
        for(i=0;i<n;i++)
        {
            arr.push_back({st[i],ed[i],profit[i]});
        }
        sort(arr.begin(),arr.end());
        memset(dp,-1,sizeof(dp));
        return fun(0,arr);
    }
};
int main(){
    Solution A;
    int n;
    cin>>n;
    vector <int> a(n),b(n),c(n);
    for(auto &u:a)
    cin>>u;
    for(auto &u:b)
    cin>>u;
    for(auto &u:b)
    cin>>u;

    A.phoneCalls();
}