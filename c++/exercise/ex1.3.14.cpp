#include<iostream>
#include<sstream>
#include"../queue/queue.h"

int main(){
    algo::QueueList<std::string> val;
    std::string line, word;
    int k;
    getline(std::cin, line);
    std::istringstream record(line);
    while(record >> word){
        val.Enqueue(word);
    }
    std::cin >> k;
    for(int i = 0; i < val.Size() - k; i++){
        auto temp = val.Dequeue();
    }
    std::cout << val.Dequeue();
    

}