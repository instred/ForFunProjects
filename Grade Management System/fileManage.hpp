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
        static void saveLogin(std::string login, std::string pwd);

};



#endif // FILEMANAGE_HPP