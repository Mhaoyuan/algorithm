#include<vector>
#include<iostream>
#include<algorithm>

namespace sorting{

template<typename T>
void insertionSort(std::vector<T> &vec){
    typedef typename std::vector<T>::size_type size_type;
    typedef typename std::vector<T>::value_type value_type;
    size_type size = vec.size();
    for(int i = 0; i < size; i++){
        int min = i;
        for(int j = i; j < size; j++){
            if(vec[j] < vec[min]){
                min = j;
            }
        }
        auto temp = vec[i];
        vec[i] = vec[min];
        vec[min] = temp;
    }
}

template<typename T>
void show(T value){
    std::cout << " " << value;
}
}



int main(){
    std::vector<int> nums{1,16,6,3,7,2,3,503,43,563,43,2,643};
    sorting::insertionSort(nums);
    for_each(nums.begin(), nums.end(), sorting::show<int>);
}