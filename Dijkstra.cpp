// code for Dijkstra algorithm
#include<bits/stdc++.h>
using namespace std;
int lowest(vector<int> &dis,int low){
    int index;
    int val=INT_MAX;
    for(int i=1;i<dis.size();i++){
        if(dis[i]>low && dis[i]<val){
            val=dis[i];
            index=i;
        }
    }
    return index;
}
int main(){
    // int n; cin >> n; vector<int> list; while(n--){int x; cin >> x; list.push_back(x);}
    int n,m;
    cin >> n >> m;
    vector<vector<int> > list(n+1,vector<int>(n+1,0));
    for(int i=0;i<m;i++){
        int x,y,w; cin >> x >> y >> w;
        list[x][y]=w;
        list[y][x]=w;
    }
    vector<int> dis(n+1,INT_MAX);
    cout << "Enter the source" << endl;
    int s; cin >>s; dis[s]=0;
    int low=-1;
    for(int i=1;i<n+1;i++){
        int index=lowest(dis,low);
        low=dis[index];
        for(int j=1;j<n+1;j++){
            if(list[index][j]!=0)
                // if(dis[j]!=INT_MAX)
                dis[j]=min(dis[j],dis[index]+list[index][j]);
        }
    }
    for(int i=1;i<n+1;i++) cout << dis[i] << " ";










    return 0;
}