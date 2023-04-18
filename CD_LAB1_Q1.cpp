#include<bits/stdc++.h>
using namespace std;

int main(){

    int int = 20;
    long long int n, i=0;

    vector<string>s;
    string c;

    while(getline(cin,c)){
        if(c.length() == 0)
            break;
        s.push_back(c);
    }
    
    n = s.size();

    if(n==0){

        cout<<"not a comment"<<endl;

    }

    if(n == 1){

            if(s[0][0] == '/' && s[0][1] == '/')
                cout<<"Single Line Comment"<<endl;

            else if(s[0][0] == '/' && s[0][1] == '*'){
                int l = s[n-1].length();
                if(s[n-1][l-2] == '*' && s[n-1][l-1] == '/')
                    cout<<"Multi-Line Comment"<<endl; 
                else
                    cout<<"Not a Comment"<<endl;
            }

            else
                cout<<"not a comment"<<endl;
    }

    else if(s[0][0] == '/' && s[0][1] == '*'){
        
            int l = s[n-1].length();
            if(s[n-1][l-2] == '*' && s[n-1][l-1] == '/')
                cout<<"Multi-Line Comment"<<endl; 
            else
                cout<<"Not a Comment"<<endl;
    }


    else
            cout<<"Not a comment"<<endl;

    return 0;
}
