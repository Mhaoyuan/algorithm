#include<iostream>
#include<sstream>
//#include<string>
#include"../stack/stack.h"

int main(){
    algo::StackList<std::string> sl = algo::StackList<std::string>();

    std::string line, word;
    getline(std::cin, line);
    std::istringstream record(line);
    while (record >> word){
        std::string item = word.c_str();
        if (item == "]"){
            if (sl.IsEmpty()) {
                std::cout << "error" << std::endl;
                return 0;
            }
            std::string peek = sl.Pop();
            if (peek != "["){
                std::cout << "error" << std::endl;
                return 0;
            }
        }
        else if (item == "}"){
            if (sl.IsEmpty()) {
                std::cout << "error" << std::endl;
                return 0;
            }
            std::string peek = sl.Pop();
            if (peek != "{"){
                std::cout << "error" << std::endl;
                return 0;
            }
        }
        else if (item == ")"){
            if (sl.IsEmpty()) {
                std::cout << "error" << std::endl;
                return 0;
            }
            std::string peek = sl.Pop();
            if (peek != "("){
                std::cout << "error" << std::endl;
                return 0;
            }
        }else{
            sl.Push(item);
        }
    }
    if (sl.Size() != 0) {
        std::cout << "error" << std::endl;
    }else{
        std::cout << "success" <<std::endl;
    }
    return 0;
}