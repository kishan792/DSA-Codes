#include<bits/stdc++.h>
using namespace std;
//arr[] = {1,2,3}

void calcXor(int arr[],int &ans,vector<int> &mainAns,int i,int size)
{   
    if(i>=size)
    {
        return;
    }

    ans = ans^arr[i];
    calcXor(arr,ans,mainAns,i+1,size);

    mainAns.push_back(ans);
    ans = ans^arr[i];

    calcXor(arr,ans,mainAns,i+1,size);

}
int main()
{
 int arr[] = {5,1,6};
 vector<int> mainAns;
 int ans = 0;
 calcXor(arr,ans,mainAns,0,3);
 ans = 0;
for(int i = 0;i<mainAns.size();i++)
{
    cout<<mainAns[i]<<"   ";
}
//cout<<ans<<endl;
}