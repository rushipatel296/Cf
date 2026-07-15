#include <iostream>
#include <vector>
#include <string>
using namespace std;

string solution(vector<string>& str){
    int n = str.size();
    string s = "";

    for(string ele : str){
        if(ele < s){
            s = ele + s;
        }else{
            s = s + ele;
        }
    }
    return s;

}


int main(){
    int T;
    vector<string> answers;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        vector<string> str;
        for(int i = 0; i < n; i++){
            string s;
            cin >> s;
            str.push_back(s);
        }
        string ans = solution(str);
        answers.push_back(ans);
    }

    for(auto ans : answers){
        cout << ans << endl;
    }
    return 1;
}