#include<bits/stdc++.h>
using namespace std;
int main(){
    
    //char a[n][m];
    vector<int>a(3,2);
    vector<int> vec{1,2,3,4,5};
    a = vec;
    vec[3] = 10;
    cout << a[4] << endl;
    cout << (vec[3]=500)<< endl;
    
    return 0;
}