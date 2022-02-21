#include<iostream>
#include<sstream>
#include<string>

using namespace std;


int main(void){
    string str;
    getline(cin, str);
    stringstream ss(str);
    
    string res;
    int count = 0;
    while(ss >> str){
        count++;
    }
    cout << count;
}
