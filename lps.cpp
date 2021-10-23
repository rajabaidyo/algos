//longest prefix-suffix array
#include<bits/stdc++.h>
using namespace std;
int main(){
    string s; cin >> s;
    vector<int> pi(s.size(),0);
    int j=0,i=1;
    while(i<s.size()){
        if(s[i]!=s[j]){
            while(j>0 && s[j]!=s[i]) j=pi[j-1];
            pi[i]=j;
        }
        else{
            pi[i]=j+1;
            j++;
        }
        i++;
    }
    for(int i=0;i<pi.size();i++){
        cout << pi[i] << " ";
    }
    return 0;

}