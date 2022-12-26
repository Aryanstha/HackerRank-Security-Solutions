#include<iostream>
#include<map>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n, num; 
    cin>>n;
    map<int,int> m;
    
    for(int i=1; i<n+1; i++){
        cin>>num;
        m.insert({num,i});
    }
    
    for(int i=1;i<n+1;i++){
        cout<<m[i]<<"\n";
    }
    
    return 0;
}
