#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
void solved();
int main(){
    solved();
    return 0;
}
void solved(){
    string str;
    cin >> str;
    int len = str.length();
    int ans = 0;
    int start = 1;
    for (int i = 0; i < len - 1;i++){
        if(str[i]==str[i+1]){
            start++;
        }else{
            start = 1;
        }
        if(start>ans){
            ans = start;
        }
    }
    if(start>ans){
        ans = start;
    }
    printf("%d", ans);
}