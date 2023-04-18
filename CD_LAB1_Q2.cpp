#include<iostream>
using namespace std;
int main(){
    string str;
    cout<<"enter string \n";
    cin>>str;
    int len=str.length();
    int state=0; int l=0;
    for(int i=0;i< len;i++){
        if(state==0 && str[i]=='a')
        state=0;
        else if(state==0 || state==1 && str[i]=='b')
        state=1;
        else if( state==1 && str[i]=='a'){
        state=2;
        break;
        }
        else if( str[i] !='a' || str[i] != 'b'){
            state=2;
            break;

        }
    }
    if(state==1)
    cout<<"Yes it comes under a*b+";
    else
    cout<<"No it does not come under a*b+";

}