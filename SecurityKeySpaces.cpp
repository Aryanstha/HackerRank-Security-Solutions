#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
     int e;
    std::string input;
    std::cin >> input >> e;
    for (int i=0; i < input.length(); ++i)
       std::cout << std::to_string((input[i] - '0' + e) % 10);
    return 0;  
}
