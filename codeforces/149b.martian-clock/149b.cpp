#include <iostream>
#include <string>
using namespace std;
int mabna(string a,int m){
        int ans=0;
        int d=1;
        for(int i=a.size()-1;i>-1;i--){
                if(a.at(i)<58){
                        ans+=(a.at(i)-48)*d;
                }
                else{
                        ans+=(a.at(i)-55)*d;
                }
                if(ans>=60){
                        return 61;
                }
                d*=m;
        }
        return ans;
}
int main(){
        string s;
        cin>>s;
        string a,b;
        for(int i=0;i<s.size();i++){
                if(s.at(i)==':'){
                        a=s.substr(0,i);
                        b=s.substr(i+1,s.size()-i);
                }
        }
        bool isans=false;
        int start=1;
        for(int i=0;i<s.size();i++){
                if(s.at(i)!=':'){
                        if(s.at(i)<58 and s.at(i)-48>start)
                                start=s.at(i)-48;
                        else if(s.at(i)-55>start)
                                start=s.at(i)-55;
                }
        }
        if(mabna(a,60)<=24 and mabna(b,60)<=60)
                cout<<-1;
        else{
                for(int i=start+1;i<=60;i++){
                        if(mabna(a,i)<24 and mabna(b,i)<60){
                                cout<<i<<" ";
                                isans=true;
                        }
                        else{
                                break;
                        }

                }
                if(!isans)
                        cout<<0;
        }
        cout<<endl;
        return 0;
}
