#include <string>
#include <iostream>
#include <vector>



void foo(std::vector<std::string>& f){
    std::string a = "du";
    f[0] = a;
}

int main(){
    std::vector<std::string> dupy;
    std::string dupa = "dupa";
    dupy.push_back(dupa);
    std::cout << dupy[0] << '\n';
    foo(dupy);
    std::cout << dupy[0] << '\n';

    return 0;
}