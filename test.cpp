#include <string>
#include <iostream>
#include <vector>
#include <fstream>



void foo(){
    std::ifstream file("test.txt");
    std::string l,p,nums;
    while (file >> l >> p >> nums){
        for (int i = 0; i < nums.length(); i+=2){
            std::cout << nums[i] - '0' << '\n';
        }
    }
}

int main(){
    foo();

    return 0;
}