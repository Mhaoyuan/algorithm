#include<iostream>
#include<sstream>
#include"../stack/stack.h"

/*  % java InfixToPostfix
 *  ( 2 + ( ( 3 + 4 ) * ( 5 * 6 ) ) )
 *  [Ctrl-d]
 *  2 3 4 + 5 6 * * + 
 *
 *  % java InfixToPostfix
 *  ( ( ( 5 + ( 7 * ( 1 + 1 ) ) ) * 3 ) + ( 2 * ( 1 + 1 ) ) )
 *  5 7 1 1 + * + 3 * 2 1 1 + * + 
 *
 *  % java InfixToPostfix | java EvaluatePostfix
 *  ( 2 + ( ( 3 + 4 ) * ( 5 * 6 ) ) )
 *  [Ctrl-d]
 *  212
 */

int main(){
    algo::StackList<int> vals = algo::StackList<int>();
    std::string line, word;
    getline(std::cin, line);
    std::istringstream record(line);
    while(record >> word){
        if(word == "+" ){
            int v = vals.Pop();
            int res = vals.Pop() + v ;
            vals.Push(res);
        }else if (word == "-"){
            int v = vals.Pop();
            int res = vals.Pop() - v ;
            vals.Push(res);
        }else if (word == "*"){
            int v = vals.Pop();
            int res = vals.Pop() * v ;
            vals.Push(res);
        }else if (word == "/"){
            int v = vals.Pop();
            int res = vals.Pop() / v ;
            vals.Push(res);
        }
        else {
            vals.Push(std::stoi(word));
        }
    }
    std::cout << "res = " << vals.Peek() << std::endl;
}