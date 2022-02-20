#include<iostream>
using namespace std;

int arr[1001];
int N;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    arr[1] = 1;
    arr[2] = 2;
    cin >> N;
    for (int i = 3; i <= N; i++){
        arr[i] = (arr[i-1] + arr[i-2])%10007;
    }
    cout << arr[N];
}