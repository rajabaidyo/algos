// simple bellman ford algorithm
// assumption: 
#include<bits/stdc++.h>
using namespace std;
int main(){
    // int n; cin >> n; vector<int> list; while(n--){int x; cin >> x; list.push_back(x);}
    int n,m;
    cin >> n >> m;
    vector<int> list[2*m];
    for(int i=0;i<m;i++){
        int x,y,w; cin >> x >> y >> w;
        list[i].push_back(x); list[i].push_back(y); list[i].push_back(w);
        list[m+i].push_back(y); list[m+i].push_back(x); list[m+i].push_back(w);
    }
    vector<int> dist(n+1);
    for(int i=0;i<=n;i++){
        dist[i]=INT_MAX;
    }
    // assuming 0 is the source node;
    // dist[1]=0;
    cout << "Enter the source node" << endl;
    int s; cin >> s;
    dist[s]=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<2*m;j++){
            if(dist[list[j][0]]!=INT_MAX)
            dist[list[j][1]]=min(dist[list[j][1]],dist[list[j][0]]+list[j][2]);
        }
    }

    for(int i=1;i<=n;i++){
        cout << dist[i] <<  " ";
    }







    return 0;
}