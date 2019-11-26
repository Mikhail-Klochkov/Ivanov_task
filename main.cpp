#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <random>
#include <chrono>
#include <stddef.h>
#include <fstream>


#include "decl.h"

int main(int argc, char const *argv[])
{
	
    std::chrono::time_point<std::chrono::steady_clock> start, end;
    int elapsed_seconds = 0;
    std::ofstream file;
    file.open("data_output.txt", std::ios::app);

	srand(time(NULL));
    bool (*comp)(int & , int & , int ) = NULL;
    comp = &compare;

    int N = 300;
    int left = 0;
    int right = N; // range equal of number of values

    int * arr = new int[N];
    int * temp_1 = new int[N];
    int * temp_2 = new int[N];

    generate_arr(arr, N, left, right);
    //print(arr, N);

    dublicate_arr(arr, temp_1, N);
    dublicate_arr(arr, temp_2, N);

    int flag = 1;
    int iterations_rise = 0;
    int iterations_down = 0;

    temp_1 = bubble_sort(temp_1, N, comp, flag, iterations_rise);
    std::cout << "\n iterations_rise: " << iterations_rise;
    flag = 0;
    temp_2 = bubble_sort(temp_2, N, comp, flag, iterations_down);
    std::cout << "\n iterations_down: " << iterations_down;
    
    arr2D Data = arr2D{iterations_rise + iterations_down + 1, N};
    Data._zero_();

    create_data(Data, arr, N, iterations_rise, iterations_down);
    // we here create our _data_
    start = std::chrono::steady_clock::now();
    for(int i = 0 ; i < iterations_down + iterations_rise + 1; i++)
    	non_stable_quick(Data._arr_[i], 0, N - 1);
    // quickSortMiddle // non_stable_quick
    end = std::chrono::steady_clock::now();
    elapsed_seconds = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    file << "new "  <<" sort_insert_algoritm: " << elapsed_seconds << "   micro_sec  " << "\n";
  //  Data.print(); 
    
    file.close();
    delete [] arr;
    delete [] temp_2;
    delete [] temp_1;
    
	return 0;
}

