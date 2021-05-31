#include"../buffer/bounded_buffer.h"
#include<iostream>
int main(){
    
    std::cout << "bounded_buffer" << std::endl;
    bounded_buffer<int> bb_int(QUEUE_SIZE);
    std::cout << "bounded_buffer" << std::endl;;
    fifo_test(&bb_int);

    std::cout << "bounded_buffer_deque" << std::endl;
    bounded_buffer_deque<int> bb_deque_int(QUEUE_SIZE);
    std::cout << "bounded_buffer_deque" << std::endl;;
    fifo_test(&bb_deque_int);

    std::cout << "bounded_buffer_list" << std::endl;
    bounded_buffer_list<int> bb_list_int(QUEUE_SIZE);
    std::cout << "bounded_buffer_list" << std::endl;;
    fifo_test(&bb_list_int);


}
