#include<iostream>
#include<limits>
#include<string>
#include<algorithm>
#include<vector>

bool comparar(std::string a, std::string b){return a<b;}

int main(){
    int n;
    std::string ans, key, ctext;
    std::string s_abc="ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    std::cin>>n;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    while(n--){
        std::cin>>key;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, ctext);

        //remove dup letters in key
        for(int i=0; i<key.size(); i++){
            for(int j=i+1; j<key.size(); j++){
                if(key[i]==key[j]){
                    key.erase(j, 1);
                }
            }
        }

        std::string s_abc2=s_abc;

        for(int i=0; i<key.size(); i++){
            for(int j=0; j<s_abc2.size(); j++){
                if(key[i]==s_abc2[j]){
                    s_abc2.erase(j, 1);
                }
            }
        }

        s_abc2=key+s_abc2;

        std::vector<std::string> v_key(key.size());

        int len=0;
        while(len<s_abc2.size()){
            v_key[len%key.size()]+=s_abc2[len];
            len++;
        }

        std::sort(v_key.begin(), v_key.end(), comparar);

        s_abc2="";
        for(int i=0; i<v_key.size(); i++){
            s_abc2+=v_key[i];
        }

        //now the original alphabet string matches (sorted) non-dup key + non-key alphabet string via index, so get index of letter from cipher in the 2nd alphabet string and use that to find true value in 1st (normal) alphabet string
        ans="";
        len=0;
        int i;
        while(len<ctext.size()){
            if(ctext[len]!=' '){
                i=s_abc2.find(ctext[len]);
                ans+=s_abc[i];
            }
            else{
                ans+=" ";
            }
            len++;
        }
        std::cout<<ans<<"\n";

    }

    return 0;
}