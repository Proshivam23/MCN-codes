#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;

    int n = s.length();
    for(int i=0;i<n;i++){
        if(s[i]=='1')
            cout<<" High 1 ";
        else
            cout<<" Low 0  ";
    }
    cout<<endl;
    for(int i=0;i<n;i++)
        cout<<"       |";
        
    cout<<endl;
    for(int i=0;i<n;i++){
        if(s[i]=='0')
            cout<<"_______|";
        else
            std::cout<<"¯¯¯¯¯¯¯|";
    }
    cout<<endl;
    for(int i=0;i<n;i++)
        cout<<"       |";
    return 0;
}
