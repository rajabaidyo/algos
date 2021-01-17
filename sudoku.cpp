// SUDOKU SOLVER
#include<bits/stdc++.h>
using namespace std;
int check(vector<string> &list,int index,int i,int count){
    for(int j=0;j<9;j++) if(list[index][j]==char(48+count)) return 0;
    for(int j=0;j<9;j++) if(list[j][i]==char(48+count)) return 0;
    // square check
    if(index<=2 && i<=2){
        for(int m=0;m<=2;m++){
            for(int n=0;n<=2;n++) if(list[m][n]==char(48+count)) return 0;
        }
    }
    else if((index<=2)&&(i>=3 && i<=5)){
        for(int m=0;m<=2;m++){
            for(int n=3;n<=5;n++) if(list[m][n]==char(48+count)) return 0;
        }
    }
    else if((index<=2)&&(i>=6 && i<=8)){
        for(int m=0;m<=2;m++){
            for(int n=6;n<=8;n++) if(list[m][n]==char(48+count)) return 0;
        }
    }
    else if((index>=3 && index<=5)&&(i>=0 && i<=2)){
        for(int m=3;m<=5;m++){
            for(int n=0;n<=2;n++) if(list[m][n]==char(48+count)) return 0;
        }
    }
    else if((index>=3 && index<=5)&&(i>=2 && i<=5)){
        for(int m=3;m<=5;m++){
            for(int n=3;n<=5;n++) if(list[m][n]==char(48+count)) return 0;
        }
    }
    else if((index>=3 && index<=5)&&(i>=6 && i<=8)){
        for(int m=3;m<=5;m++){
            for(int n=6;n<=8;n++) if(list[m][n]==char(48+count)) return 0;
        }
    }
    else if((index>=6 && index<=8)&&(i>=0 && i<=2)){
        for(int m=6;m<=8;m++){
            for(int n=0;n<=2;n++) if(list[m][n]==char(48+count)) return 0;
        }
    }
    else if((index>=6 && index<=8)&&(i>=3 && i<=5)){
        for(int m=6;m<=8;m++){
            for(int n=3;n<=5;n++) if(list[m][n]==char(48+count)) return 0;
        }
    }
    else if((index>=6 && index<=8)&&(i>=6 && i<=8)){
        for(int m=6;m<=8;m++){
            for(int n=6;n<=8;n++) if(list[m][n]==char(48+count)) return 0;
        }
    }

    return 1;
}
int sol(vector<string> &ans,vector<string> &list,int row,int col,bool &stop){
    if(row==9) {ans=list; stop=true; return 0;}
    
    int i=row,j=col;
    while(i<9 && list[i][j]!='.'){
        j++;
        i=i+(j/9);
        j=j%9;
    }
    // if(i==4) {ans=list; stop=true; return 0;}
    if(i==9) {ans=list; stop=true; return 0;}
    // if(i>=8 && j>=8) {ans=list; stop=true; return 0;}
    for(int count=1;count<=9;count++){
        if(check(list,i,j,count)){
            list[i][j]=char(48+count);
            sol(ans,list,i,j,stop);
            if(stop==true) return 0;
            list[i][j]='.';
        }
    }
    return 0;


}
int main(){
    // int n; cin >> n; vector<int> list; while(n--){int x; cin >> x; list.push_back(x);}
    // int n; cin >> n;
    vector<string> list,ans;
    string s="";
    for(int i=0;i<9;i++){
        cin >> s;
        list.push_back(s);
        s="";
    }
    bool stop=false;
    int row=0,col=0;
    sol(ans,list,row,col,stop);
    cout << endl <<  "SOLUTION::" << endl << endl;
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++) cout << ans[i][j] << " ";
        cout << endl;
    }

    







    return 0;
}
/* test case:
53..7....
6..195...
.98....6.
8...6...3
4..8.3..1
7...2...6
.6....28.
...419..5
....8..79
*/