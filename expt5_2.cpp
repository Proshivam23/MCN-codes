#include<bits/stdc++.h>
using namespace std;

int main(){
    string flag = "01111110";
    string esc = "11100000";

    string check = "";

    string s;
    cout<<"Enter string: ";
    cin>>s;

    
    for(int i=0;i<s.length();i+=8){
        check = s.substr(i,8);
        if(flag==check || esc == check){
            s.insert(i, esc);
            i+=8;
        }
    }
    s.insert(0, flag);
    s.insert(s.length()-1,flag);

    for(int i=0;i<s.length();i++){
        if(i==8 || i== s.length()-8)
            cout<<" ";
        cout<<s[i];
    }
}