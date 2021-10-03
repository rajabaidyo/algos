#include<bits/stdc++.h>
using namespace std;
struct Trie{
    char data;
    int we=0;
    Trie* child[26]={NULL};
};
//adding a word to the trie
void add(Trie* root, string s){
    Trie* parent=root;
    for(int i=0;i<s.size();i++){
        if(parent->child[s[i]-'a']==NULL){
            Trie * temp=new Trie();
            temp->data=s[i];
            temp->we=0;
            parent->child[s[i]-'a']=temp;
        }
        parent=parent->child[s[i]-'a'];
        if(i==s.size()-1) parent->we+=1;
    }
    cout << "added" << endl;
    return ;
}
//searching a word in the trie
bool search(Trie* root, string s){
    for(int i=0;i<s.size();i++){
        if(root->child[s[i]-'a']==NULL) return false;
        else{
            root=root->child[s[i]-'a'];
            if(i==s.size()-1 && root->we==0) return false;
        }
    }
    return true;
}
void delet(Trie * root, string s, int m){
    for(int i=0;i<s.size();i++){
        if(root->child[s[i]-'a']==NULL){
            cout << "word doesn't exit" << endl;
            return ;
        }
        else{
            root=root->child[s[i]-'a'];
            if(i==s.size()-1){
                if(m==1) root->we--;
                else root->we=0;
            }
        }
    }
    cout << "deleted" << endl;
    return ;
}
int main(){
    cout << "creating root" << endl;
    Trie* root = new Trie();
    root->data='/';
    cout << root->data << " " << root->we << endl;
    while(true){
        cout << "enter the choice : " << endl;
        cout << "1. add" << endl << "2. search" << endl << "3. delete" << endl << "4. exit" << endl;
        int x; cin >> x;
        if(x==1){
            cout << "enter the string to add : " << endl;
            string s; cin >> s;
            add(root,s);
        }
        else if(x==2){
            cout << "enter the string to search : " << endl;
            string s; cin >> s;
            if(search(root, s)) cout << "exist" << endl;
            else cout << "doesn't exist" <<endl;
        }
        else if(x==3){
            cout << "select one of the following option : "<< endl << "1. delete one instance" << endl << "2. delete all the instances" << endl;
            int m; cin >> m;
            cout << "enter the string to delete : " << endl;
            string s; cin >> s;
            delet(root,s,m);
        }
        else{
            return 0;
        }
    }
    return 0;
}