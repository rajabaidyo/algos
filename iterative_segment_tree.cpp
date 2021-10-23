#include<bits/stdc++.h>
using namespace std;
void printing(vector<int> &st){
    int n=st.size()/2;
    while(true){
        cout << "1. Print_segment_st 2. Nope" << endl;
        int x; cin >> x; 
        if(x==1){
            for(int i=0;i<2*n;i++) cout << st[i] << " ";
            cout << endl;
        }
        else break;
    }
    return ;
}
void create_st(vector<int> &st){
    int n= st.size()/2;
    for(int i=n-1;i>=1;i--){
        st[i]= max(st[2*i],st[2*i+1]);
    }
    printing(st);
    return ;
}
void update(vector<int> &st){
    int n = st.size()/2;
    cout << "enter index and value respectively" << endl;
    int ind,val ; cin >> ind >> val;
    ind+=n;
    st[ind]=val;
    while(ind>1){
        ind/=2;
        int maxi=max(st[2*ind],st[2*ind+1]);
        if(st[ind]!=maxi) st[ind]=maxi;
        else break;
    }
    printing(st);
    return ;
}

void max_find(vector<int> &st){
    cout << "Enter the start index and end index..considering from is inclusive but to is exclusive" << endl;
    int n=st.size()/2; 
    int from,to; cin >> from  >> to;
    from+=n;
    to+=n;
    int maxi=INT_MIN;
    while(from<to){
        if((from&1)==1){
            maxi=max(maxi,st[from]);
            from++;
        }
        if((to && 1)==1){
            to--;
            maxi=max(maxi,st[to]);
        }
        from/=2;
        to/=2;
    }
    cout << maxi << endl;
    return ;
}

int main(){
    int n; cin >> n;
    vector<int> st(2*n,0);
    for(int i=0;i<n;i++){
        int x; cin >> x; st[i+n]=x;
    }
    create_st(st);
    while(true){
        cout << "1. update 2. exit" << endl;
        int x; cin >> x; cout << endl;
        if(x==1) update(st);
        else break;
    }

    while(true){
        cout << "1. max_find 2. exit" << endl;
        int x; cin >> x;
        if(x==1){
            max_find(st);
        }
        else break;
    } 



    return 0;
}