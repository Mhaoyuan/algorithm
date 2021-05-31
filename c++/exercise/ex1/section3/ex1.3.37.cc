#include"doublelist.h"

using namespace algo;

int main(){
    Doublelist<int> dl2;
    for(int i = 0; i < 20; i++){
        dl2.push_back(i);
    }
    std::cout << "test delete k" << std::endl;
    std::cout << dl2.delete_k(10) << std::endl;
    

}