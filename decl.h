#ifndef DECL_H
#define DECL_H

struct arr2D
{
	int ** _arr_;
	int one_d_size;
	int two_d_size;
	// allocate mwmory 2 dimension matrix
	arr2D(int size_1, int size_2) 	{
     
     one_d_size = size_1;
     two_d_size = size_2;
      
     _arr_ = new int*[one_d_size]; 
      
     for(std::size_t i = 0 ; i < one_d_size ; i ++)
     	_arr_[i] = new int[two_d_size];
	} 
    ~arr2D() {
    	// we should call destruction in reverse order
    	for (std::size_t i = 0 ; i < one_d_size; i++)
    		delete [] _arr_[i];
      
          	delete _arr_;
    		
    }
    void print() {
    	std::cout << "\n";
    	for (int i = 0; i < one_d_size; ++i) {
    	    for (int j = 0; j < two_d_size; ++j)
    	       std::cout << _arr_[i][j] << "   ";
    	std::cout << "\n";
    	}
    }
    void _zero_(){
        for (int i = 0; i < one_d_size; ++i)
             for(int j = 0 ; j < two_d_size; j++)
             	_arr_[i][j] = 0;
    }
    void generate_2D(int range_l, int range_r) {
    	
    	for (int i = 0; i < one_d_size; ++i)
    	  for (int j = 0; j < two_d_size; ++j)
    	       _arr_[i][j] = rand() % (range_r - range_l + 1);

    }
};

void _swap_(int * lhs, int * rhs);
bool compare(int & lhs, int & rhs, int flag);
void print(const int * _arr_, const std::size_t &  _size_);
void generate_arr(int * _arr_, const std::size_t & _size_, const int & left, const int & right);
int * bubble_sort(int* _arr_, const std::size_t &  _size_,
                        bool (*compare)(int & a, int & b, int flag),
                         int flag, int & sum);

void create_data(arr2D & DATA, int* arr, const std::size_t & _size_, int & iteration_r, int & iteration_d);
void dublicate_arr(const int * copy_arr, int * dublicat, const std::size_t & _size_ );
void quick_sort(int * _arr_, int left, int right); // range is mutable
int _partition_0(int * _arr_, int left, int right);
void quickSortMiddle(int *a, int left, int right);
int non_stable_quick(int *arr, int start, int end);
void sort_insert(int * arr, const std::size_t _size_);

#endif // DECL_H



