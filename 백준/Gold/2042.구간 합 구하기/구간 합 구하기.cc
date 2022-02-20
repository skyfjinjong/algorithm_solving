#include<iostream>
using namespace std;

long long tree[3000002];
int N, M, K;
int a, b;
long long c;
void updateTree(int idx, long long value){
    tree[idx] = value;
    while (true){
        idx /= 2;
        tree[idx] = tree[idx*2] + tree[idx*2+1];
        if (idx == 1) break; 
    }
}
long long acc_sum(int l, int r){
    long long sum = 0;
    while(l <= r){
        if (l == r){
            sum += tree[l];
            break;
        }
        if (l > r){
            break;
        }
        if (l%2!=0){
            sum += tree[l];
            l++;
        }
        if (r%2==0){
            sum += tree[r];
            r--;
        }
        l/=2;
        r/=2;
    }
    return sum;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> K;
    int S = 1;
    while (S <= N){
        S *= 2;
    }
    for(int i = S; i < S + N; i++){
        cin >> tree[i];
    }
    for(int j = S-1; j > 0; j--){
        tree[j] = tree[j*2] + tree[j*2+1];
    }
    for(int z = 0; z < M + K; z++){
        cin >> a >> b >> c;
        if (a == 1){
            updateTree(b+S-1, c);
        }
        else if (a == 2){
            cout << acc_sum(S+b-1, S+c-1) << "\n";
        }
    }
    return 0;
}