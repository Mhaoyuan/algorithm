#include<iostream>
#include<sstream>
#include"../stack/stack.h"
#include"../queue/queue.h"

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
    algo::StackList<std::string> ops = algo::StackList<std::string>();
    std::string line, word;
    getline(std::cin, line);
    std::istringstream record(line);
    while(record >> word){
        if (word == "+") {
            ops.Push(word);
        }
        else if (word == "-"){
            ops.Push(word);
        }
        else if (word == "*"){
            ops.Push(word);
        }else if (word == "/"){
            ops.Push(word);
        }else if (word == "("){
            std::cout << "";
        }else if (word == ")"){
            std::cout << ops.Pop() << " ";
        }else{
            std::cout << word << " ";
        }
    }
    std::cout << std::endl;
}




/*

p = L;   这个是让p指向头指针L,然后 L = 
L = L->next;
free(p);
Del_X_3(L,x);

*/