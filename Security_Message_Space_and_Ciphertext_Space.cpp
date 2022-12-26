#include<iostream>
#include<string>

int main(){
    std::string s;
    int num;
    
    std::cin>>s;

    for(int i=0; i<s.length(); i++){
        num=s[i];
        if(num=='9'){s[i]='0';}
        else{s[i]=num+1;}
    }

    std::cout<<s;

    return 0;
}
