#ifndef FILEMANAGE_HPP
#define FILEMANAGE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class FileManage{

    public:
        static void fillFile();
        static std::string removeLine();
        static bool findLogin(std::string login, std::string pwd);
        static void saveLogin(std::string login, std::string pwd);
        static std::vector<std::pair<std::string, std::string>> loadLogin();

};



#endif // FILEMANAGE_HPP