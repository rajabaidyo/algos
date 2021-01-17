// code for max heap insertion and deletion
#include<bits/stdc++.h>
using namespace std;
void heapify(int i,vector<int> &list){
    int parent =(i-1)/2;
    if(parent>=0){
        if(list[i]>list[parent]){
            // cout << "i'm here";
            swap(list[i],list[parent]);
            heapify(parent,list);
        }
    }
    return ;
}
void bala(int i,vector<int> &list){
    int child1=(2*i+1);
    int child2=(2*i+2);
    if(child1<list.size() && list[i]<list[child1]){
        swap(list[i],list[child1]);
        bala(child1,list);
    }
    else if(child2<list.size() && list[i]<list[child2]){
        swap(list[i],list[child2]);
        bala(child2,list);
    }
}
void insert(int x,vector<int> &list){
    list.push_back(x);
    heapify(list.size()-1,list);
}
int search(int n,vector<int> &list){
    for(int i=0;i<list.size();i++){
        if(list[i]==n){
            swap(list[i],list[list.size()-1]);
            list.pop_back();
            return i;
        }
    }
    return 0;
}
void deletion(int m,vector<int> &list){
    int i=search(m,list);
    cout << "i=" << i << endl;
    bala(i,list);
}
int main(){
    int n; cin >>  n;
    vector<int> list;
    for(int i=0;i<n;i++){
        int x; cin >> x;
        insert(x,list);
    }
    while(true){
        cout << "wanna del " << "1=yes" << " 2=no";
        int x; cin >> x; if(x==1){int m; cin >> m; deletion(m,list);}
        else break;
    }
    for(int i=0;i<list.size();i++){
        cout << list[i] << " ";
    }
    return 0;
}