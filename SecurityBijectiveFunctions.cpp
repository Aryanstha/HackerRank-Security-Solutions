#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int i=0, n, s=1, num;
    std::vector<int> v;
    std::vector<int>::iterator it;

    std::cin>>n;

    while(i<n && s){
        std::cin>>num;
        it=find(v.begin(), v.end(), num);

        if(it==v.end()){
            v.push_back(num);
            i++;
        }

        else{s=0;}
    }

    if(s==1){
        std::cout<<"YES";
    }

    else {std::cout<<"NO";}

    return 0;
}
