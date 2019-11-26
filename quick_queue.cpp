#include <iostream>
#include <random>
#include <ctime>
#include <stdlib.h>
#include <queue>



void print(const int * _arr_, const std::size_t &  _size_);
void generate_arr(int * _arr_, const std::size_t & _size_, const int & left, const int & right);




struct Range {
   int start;
   int end;

   Range(int newStart, int newEnd) : start(newStart), end(newEnd) {}
};


void _swap_(int * left, int * right)
{
    int temp = *left;
    *left = * right;
    *right = temp;
    return;
}

bool compare(int & lhs, int & rhs, int flag){
    
    if(flag == 1)
        return (lhs > rhs); // formally we will do smaller swap elements of array
    else 
        return (lhs < rhs);    
}

void QuickSort(int *  _arr_, int start, int end)
{
    std::queue<Range> queue; // queue, instead stack
    queue.push(Range{start, end}); // we call our constructor if range
    while(!queue.empty()) // after call function pop we delete our element from head of queue
    {
        // formally our queue emulate work of recursion alghorithm
         Range next = queue.front();
         queue.pop(); 

         int start = next.start;
         int end = next.end;
         int _index_ = start;
         
       //  int rand_ind = rand() % (end - start + 1);
        // _swap_(&_arr_[rand_ind], &_arr_[end]); 

         if(start < end) {

             for(int Index = start; Index < end; Index++) {
                 
                 if(_arr_[Index] <= _arr_[end]){
                    _swap_(&_arr_[_index_], &_arr_[Index]);
                    _index_++;
                 }
             }
             _swap_(&_arr_[end], &_arr_[_index_]  ); // basic element a end
             queue.push(Range(start, --_index_));
             queue.push(Range(_index_++, end));

         }
    } 
    return;
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

int main()
{
    srand(time(NULL));
    int N = 20;
    int left = 0;
    int right = 20;
    int * arr = new int[N];
    generate_arr(arr, N, left, right);
    print(arr, N);

    QuickSort(arr, left, N - 1);

    //print(arr, N);
    return 0;
}
