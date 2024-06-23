#include<bits/stdc++.h>
using namespace std;


int main(){
    string s;

    cout<<"Enter string: ";
    cin>>s;

    string flag = "01111110";
    int cnt = 0;
    cout<<"here"<<endl;
    for(int i=0;i<s.length();i++){
        if(s[i]=='1')
            cnt++;
        else
            cnt = 0;

        if(cnt==5){
            s.insert(i+1, "0");
            cnt=0;
        }
    }
    s.insert(0, flag);
    s.insert(s.length(), flag);

    for(int i=0;i<s.length();i++){
        if(i==8 || i== s.length()-8)
            cout<<" ";
        cout<<s[i];
    }

}