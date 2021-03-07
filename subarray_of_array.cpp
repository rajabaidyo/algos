//code for all the subarrays for an array
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
int main(){
    vector<int> list;
    for(int i=1;i<7;i++) list.push_back(i);
    vector<vector<int> > ans;
    int len;
    vector<int> temp;
    for(int i=1;i<7;i++){
        for(int j=0;j<list.size()-i;j++){
            int t=j;
            len=i;
            while(len--){
                temp.push_back(list[t]);
                t++;
            }
            ans.push_back(temp);
            temp.clear();
        }
    }
    vector<vector<int> >::iterator mist;
    for(mist=ans.begin();mist!=ans.end();mist++){
        temp=*mist;
        for(int i=0;i<temp.size();i++) cout << temp[i] << " ";
        cout << endl;
    }









    return 0;
}