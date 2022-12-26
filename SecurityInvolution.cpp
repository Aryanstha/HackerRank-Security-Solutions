#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    
    int n, i;
    
    cin>>n;
    
    int arr[n-1];
    
    for(i=0;i<n;i++)
        cin>>arr[i];
    for(i=0;i<n;){
        if(arr[i]>=arr[arr[i]])
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
        return 0;
    }
}