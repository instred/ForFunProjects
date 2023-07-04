#ifndef FILEMANAGE_HPP
#define FILEMANAGE_HPP

#include <iostream>
#include <fstream>
#include <string>

class FileManage{

    public:
        static void fillFile();
        static std::string removeLine();
        static bool findLogin(std::string login, std::string pwd);
        static void saveLogin(std::string login, std::string pwd);

};



#endif // FILEMANAGE_HPP