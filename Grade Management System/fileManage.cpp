#include "fileManage.hpp"

std::vector<std::pair<std::string, std::string>> FileManage::loadLogin(){
    std::ifstream file("login.txt");
    std::string l, p;
    std::vector<std::pair<std::string, std::string>> credentials;
    while(file >> l >> p){
        credentials.push_back(std::make_pair(l,p));
    }
    return credentials;
}

bool FileManage::findLogin(std::string login, std::string pwd){
    std::vector<std::pair<std::string, std::string>> creds = FileManage::loadLogin();
    for (int i = 0; i<creds.size(); i++){
        if(creds[i].first == login && creds[i].second == pwd){
            return true;
        }
    }
    return false;
}

void FileManage::saveLogin(std::string login, std::string pwd){
    std::ofstream file("login.txt", std::ios::app);
    file << login << " " << pwd << '\n';
}

void FileManage::fillFile(){
    std::fstream file;
    int i = 1;
    file.open("available_ids.txt", std::ios::out);
    if(file.is_open()){
        while(i <= 30){
            file << std::to_string(i) + '\n';
            i++;
        }
        file.close();
    }
    else{
        std::cout << "Unable to open file";
    }
}

std::string FileManage::removeLine(){
    std::fstream file_read;
    std::fstream file_write;
    char c;
    int line_no = 1;
    std::string id = "";
    file_read.open("available_ids.txt", std::ios::in);
    file_write.open("tmp.txt", std::ios::out);
    while(file_read.get(c)){
        if(line_no != 1)
            file_write << c;
        if(line_no == 1)
            id += c;
        if(c == '\n')
            line_no++;
    }
    file_read.close();
    file_write.close();
    remove("available_ids.txt");
    rename("tmp.txt", "available_ids.txt");
    return id;
}
