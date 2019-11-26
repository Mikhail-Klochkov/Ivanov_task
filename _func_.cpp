#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <random>

#include "decl.h"

void _swap_(int * lhs, int * rhs)
{
	int temp = *lhs;
	*lhs = *rhs;
	*rhs = temp;
}

bool compare(int & lhs, int & rhs, int flag)
{
     if (flag == 1)
        return (lhs > rhs); // if bigger then
     else
     	return (lhs < rhs); // if smaller then

}

void print(const int * _arr_, const std::size_t &  _size_)
{
	std::cout << std::endl;
	for(std::size_t i = 0 ; i < _size_ ; i++)
		 std::cout << _arr_[i] << "  ";
}


void generate_arr(int * _arr_, const std::size_t & _size_, const int & left, const int & right)
{
	if(right <= left){
		std::cout << "'right' should be more then 'left'" << std::endl;
	}
    for(std::size_t iter = 0 ; iter < _size_ ; iter++)
    	_arr_[iter] = rand() % (right - left + 1);
}

int * bubble_sort(int* _arr_, const std::size_t &  _size_,
                        bool (*compare)(int & a, int & b, int flag), int flag, int & sum)
{
	int i = 0;
	char  swap_cnt = 0;
    sum = 0; 
    if(_size_ == 0)
    	 return (0); 
     while(i < _size_) {
         if(i + 1 != _size_ && compare(_arr_[i], _arr_[i + 1], flag)) { // flag is define which operator of comparing need us
         	_swap_(&_arr_[i], &_arr_[i + 1]);
            swap_cnt = 1;
         }
         i++;
         if(i == _size_) {
         	sum++;
         }
         if(i == _size_ && swap_cnt == 1) { 
            swap_cnt = 0;
            i = 0;
         }
    }
    return (_arr_);
}

int non_stable_quick(int *arr, int start, int end){
    
    int wall = start;

    if(start < end) {
        for(int Index = start; Index  < end; Index++){
            
            
            if(arr[Index] <= arr[end]){
                _swap_(&arr[wall], &arr[Index]);
                wall++;
            }
        }
        _swap_(&arr[wall], &arr[end]);
        non_stable_quick(arr, start, wall - 1);
        non_stable_quick(arr, wall + 1, end);
    }
    return 0;
}

void quickSortMiddle(int *a, int left, int right)
{
    if(left >= right)
          return;
    
    int leftI = left;
    int rightI = right;
    int pivot = a[left + (right - left)/2]; // set pivot to value
    while(leftI <= rightI)
    {
        while(a[leftI]  < pivot )
            leftI++;   // use pivot by value
        while(a[rightI] > pivot )
            rightI--;  // use pivot by value
        if(leftI <=rightI)
        {
            _swap_(&a[ leftI ], &a[ rightI ]);
            leftI++;
            rightI--;
        }
    }
    if(left < rightI)
          quickSortMiddle(a,left,rightI); // < not <=
    if(leftI < right)
          quickSortMiddle(a,leftI,right); // < not <=
}


int * bubble_sort_one(int* _arr_, const std::size_t &  _size_,
                        bool (*compare)(int & a, int & b, int flag), int flag) // Тоже самое, что и bubble_sort только он проходит один раз помассиву
{ 
	int i = 0;
    if(_size_ == 0)
    	 return (0); 
    
    while(i < _size_) {
         if(i + 1 != _size_ && compare(_arr_[i], _arr_[i + 1], flag)) { // flag is define which operator of comparing need us
         	_swap_(&_arr_[i], &_arr_[i + 1]);
         }
         i++;
    }
    return (_arr_);
}

void dublicate_arr(const int * copy_arr, int * dublicat, const std::size_t & _size_ )
{
    for(int i = 0; i < _size_ ; i++) 
    	dublicat[i] = copy_arr[i];
}


void create_data(arr2D & DATA, int* arr, const std::size_t & _size_, 
	             int & iteration_r, int & iteration_d) {

    std::cout << "work_create_data: " << "\n";
    print(arr, _size_);
    int flag = 1;
    bool (*comp)(int &, int &, int ) = NULL;
    comp = &compare;
    
    int * temp = new int[_size_]; 
    dublicate_arr(arr, temp, _size_);
    DATA._arr_[iteration_d] = temp;    
    for(int iter = iteration_d + 1; iter < iteration_r + iteration_d + 1; iter++){
        dublicate_arr(bubble_sort_one(DATA._arr_[iter - 1],  _size_, comp, flag), DATA._arr_[iter] , _size_); 
    }
    flag = 0;
    for(int iter = iteration_d - 1; iter >= 0; iter--){
        dublicate_arr(bubble_sort_one(DATA._arr_[iter + 1],  _size_, comp, flag), DATA._arr_[iter] , _size_); 
    }
   
  DATA.print();
  delete [] temp;

}

