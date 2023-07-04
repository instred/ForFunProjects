#include "login.hpp"


bool Login::loginAccess(){
    bool access = false;
    int tryCount = 0;
    std::string login, pwd;
    login:
        if (tryCount > 2){
            std::cout << "You entered wrong credentials 3 times, program will now exit";
            return access;
        }
        std::cout << "Enter login: ";
        std::cin >> login;
        std::cout << "Enter password: ";
        std::cin >> pwd;
    if (!(FileManage::findLogin(login, pwd))){
        std::cout << "Wrong credentials!\n";
        tryCount++;
        goto login;
        
    }
    else
        access = true;
    return access;
}