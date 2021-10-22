//longest increasing subsequence in nlogn 
#include<bits/stdc++.h>
using namespace std;
int bs(vector<int> &lis, int val){
    int l=0,h=lis.size();
    while(l<h){
        int mid = l + (h-l)/2;
        if(lis[mid]<val) l=mid+1;
        if(lis[mid]==val) return -1;
        else h=mid;
    }
    return l;

}
int main(){
    int n; cin >> n;
    vector<int> list;
    for(int i=0;i<n;i++){
        int x; cin >> x; list.push_back(x);
    }
    vector<int> lis;
    lis.push_back(list[0]);
    for(int i=1;i<n;i++){
        if(lis[lis.size()-1]<list[i]){
            lis.push_back(list[i]);
        }
        else{
            int ind = bs(lis,list[i]);
            if(ind!=-1) lis[ind]=list[i];
        }
    }
    for(int i=0;i<lis.size();i++) cout << lis[i] <<  " ";
    cout << endl;
    cout << lis.size() << endl;
    return 0;
}