//code for generating all the subsets of an array
#include<bits/stdc++.h>
#include<unordered_map>
#define ll long long int
#define hell 1000000007
using namespace std;
void vpush(vector<int> &list,int n){
    for(int i=0;i<n;i++){
        int x; cin >> x; list.push_back(x);
    }
}
void generator(vector<vector<int> > &ans, vector<int> temp,int itr,vector<int> &list){
    ans.push_back(temp);
    for(int i=itr+1;i<list.size();i++){
        temp.push_back(list[i]);
        generator(ans,temp,i,list);
        temp.pop_back();
    }
    return ;
}
int main(){
    vector<int> list;
    for(int i=1;i<5;i++) list.push_back(i);
    vector<vector<int> > ans;
    for(int i=0;i<list.size();i++){
        vector<int> temp;
        temp.push_back(list[i]);
        generator(ans,temp,i,list);
    }
    vector<vector<int> >::iterator itr;
    vector<int> temp;
    cout << "total size==>" << ans.size() << endl;
    for(itr=ans.begin();itr!=ans.end();itr++){
        temp=*itr;
        for(int i=0;i<temp.size();i++) cout << temp[i] << " ";
        cout << endl;
    }








    return 0;
}