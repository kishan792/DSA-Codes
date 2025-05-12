//Subsequence problem.....
#include<iostream>
using namespace std;
void generateSubsequence(string str,string &ans,int i)
{
    if(i>=str.size())
    {
        cout<<ans<<endl;
        return;
    }
    ans = ans + str[i];
    generateSubsequence(str,ans,i+1);
    ans.pop_back();
    generateSubsequence(str,ans,i+1);   

}
int main()
{
    string str = "abc";
    string ans = "";

    generateSubsequence(str,ans,0);

    return 0;
}