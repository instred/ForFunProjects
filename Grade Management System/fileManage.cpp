#include "fileManage.hpp"

void fill_file(){
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

std::string remove_line(){
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
