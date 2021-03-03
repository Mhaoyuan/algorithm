#include<iostream>
#include<sstream>
#include"../stack/stack.h"

int main(){
    algo::StackList<std::string> vals = algo::StackList<std::string>();
    algo::StackList<std::string> ops = algo::StackList<std::string>();
    std::string line, word;
    getline(std::cin, line);
    std::istringstream record(line);

    while(record >> word) {
        if (word == "+" || word == "-" || word == "*" || word == "/"){
            ops.Push(word.c_str());
        }else if (word == ")") {
            std::string v = vals.Pop();
            std::string o = ops.Pop();
            std::string exp = "(" + vals.Pop() + o + v + ")";
            vals.Push(exp);
        }else{
            vals.Push(word.c_str());
        }
    }
    vals.Show();
}