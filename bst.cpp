// Simple Binary search tree implementation
// Raja's Code
#include<bits/stdc++.h>
using namespace std;
struct node{
    int val;
    node * parent=NULL;
    node * left=NULL;
    node * right =NULL;
};
struct node* insertion(int x,struct node* &head,struct node* parent){
    if(head==NULL){
        head=new node();
        head->parent=parent;
        head->val=x;
    }
    else{
        if(x<head->val) insertion(x,head->left,head);
        else insertion(x,head->right,head);
    }
    return head;
}
struct node* find(int x,struct node* head){
    if(head->val==x) return head;
    else if(head->val>x) return find(x,head->left);
    else return find(x,head->right);
}
struct node* rightfind(struct node* bla){
    while(bla->left!=NULL) bla=bla->left;
    return bla;
}
struct node* leftfind(struct node* bla){
    while(bla->right!=NULL) bla=bla->right;
    return bla;
}
int deletion(int x,struct node* head){
    cout << "inside deletion " << endl;
    node* change=find(x,head);
    node* check=NULL;
    if(head->right!=NULL) check=rightfind(head->right);
    else check=leftfind(head->left);
    cout << "change here==" << change->val << " " << check->val << endl;
    change->val=check->val;
    if(head->right!=NULL) check->parent->left=NULL;
    else check->parent->right=NULL;


    return 0;
}

int inorder(struct node* &head){
    if(head==NULL){
        return 0;
    }
    else{
        inorder(head->left);
        cout << head->val << " ";
        inorder(head->right);
    }
    return 0;
}
int preorder(struct node* &head){
    if(head==NULL) return 0;
    else{
        cout << head->val << " ";
        preorder(head->left);
        preorder(head->right);
    }
    return 0;
}
int postorder(struct node* &head){
    if(head==NULL) return 0;
    else{
        postorder(head->left);
        postorder(head->right);
        cout << head->val << " ";
    }   
    return 0;
}
int main(){
    struct node * head=NULL;
    while(true){
        cout << "1) Enter value" << endl << "2)Deletion" << endl << "3) Exit" << endl;
        int n; cin >> n;
        if(n==3) break;
        else if(n==1){
            int x; cin>> x;

            head = insertion(x,head,head);
        }
        else{
            int x; cin >> x;
            deletion(x,head);
        }
    }
    // cout << head->val << " " << head->left->val << " " << head->right->val << " " << head->left->parent->val << endl;
    while(true){
        cout << "enter the order for the answer \n 1)INORDER \n 2)PREORDER \n 3)POSTORDER \n 4)EXIT" << endl;
        int t; cin >> t;
        if(t==1) inorder(head);
        else if(t==2) preorder(head);
        else if(t==3) postorder(head);
        else break;
        cout << endl;
    }
    

    



    return 0;
}