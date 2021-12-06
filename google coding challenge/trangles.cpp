#include<bits/stdc++.h>


using namespace std;




int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  


    int t=1,t1=1;
    // cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int x=0;
        vector <vector <int>> matrix(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>matrix[i][j];
                if(matrix[i][j]==0)
                x=1;
            }
        }
        vector <vector <int>> leftUpper(n,vector<int>(m,0));
        vector <vector <int>> leftdown(n,vector<int>(m,0));
        vector <vector <int>> rightUpper(n,vector<int>(m,0));
        vector <vector <int>> rightDown(n,vector<int>(m,0));
        for(int i=1;i<n;i++){
            for(int j=m-2;j>=0;j--){
                if(matrix[i-1][j]==0 && matrix[i][j+1]==0 && matrix[i][j]==0){
                    rightUpper[i][j]=min(rightUpper[i-1][j],rightUpper[i][j+1])+1;
                }
            }
        }
        for(int i=n-2;i>=0;i--){
            for(int j=m-2;j>=0;j--){
                if(matrix[i+1][j]==0 && matrix[i][j+1]==0 && matrix[i][j]==0){
                    rightDown[i][j]=min(rightDown[i+1][j],rightDown[i][j+1])+1;
                }
            }
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i-1][j]==0 && matrix[i][j-1]==0 && matrix[i][j]==0){
                    leftUpper[i][j]=min(leftUpper[i-1][j],leftUpper[i][j-1])+1;
                }
            }
        }
        for(int i=n-2;i>=0;i--){
            for(int j=1;j<m;j++){
                if(matrix[i+1][j]==0 && matrix[i][j-1]==0 && matrix[i][j]==0){
                    leftdown[i][j]=min(leftdown[i+1][j],leftdown[i][j-1])+1;
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans=ans+min(leftUpper[i][j],rightUpper[i][j]);
                ans=ans+min(leftdown[i][j],rightDown[i][j]);
            }
        }
        cout<<ans<<'\n';

    }  
}

/*
Some helpful points
1.) Calm yourself
2.) check for semicolon or data type mismatch
3.) It can be solved
*/

