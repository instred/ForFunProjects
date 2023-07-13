#include <string>
#include <iostream>
#include <vector>
#include <fstream>



int silnia(int n){
    if(n == 1)
        return n;
    return n * silnia(n-1);
}

int silnia2(int n){
    int ans = 1;
    for(int i=2;i<=n;i++){
        ans *= i;
    }
    return ans;
}

int main(){
    std::cout << silnia(10) << " " << silnia2(10);
    return 0;
}