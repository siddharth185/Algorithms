/**
    CS-575-01 Asn 2, hw1.cpp
    Purpose: Implement Various Sorting Algorithms and visualize them as well

    @author Siddharth Kulshrestha
    @version 1.0 10/02/17
*/
#include<iostream>
#include<algorithm>
#include <random>
#include "sort_utilities.h" //Contains the utility functions to sort and visualize the sorting
#include <time.h>

using namespace std;


int main()
{
	srand(time(NULL)); //Assign Random Seed to the Pseudo-Random Generator

	int randArr[1000];
	int n, algo;

	cout << "Please choose the sorting algorithm to use!! \n\n";
	cout << " Please enter 1 for EXCHANGE sort, 2 for INSERT sort, 3 for MERGE sort and 4 for Randomized QUICK Sort \n\n ";
	cin >> algo ;
	if(algo > 4)
	{
		cout << "Please Enter correct choice!!";
		exit(0);
	}
	cout << "Please enter the value of n \n\n";
	cin >> n;





	if(n>1000 || n <1)
	{
		cout << "Please enter a value of n in the correct range. \n";
		exit(1);
	}

	if(n <=20)
	{
		for (int i = 0; i<n;i++)
		{
		randArr[i] = rand()%14 + 1; //Random Numbers added to the array
		}
	}
	else
	{
		for (int i = 0; i<n;i++)
		{
		randArr[i] = rand()%10000;
		}

	}
	cout << "\n";

	cout << "The UNSORTED array is ====>> \n";
	print_array(randArr, n);

	cout << "\n \n";

	switch(algo){  //Switch case to decide which algorithm to use according to User
		case 1:
			exchange_sort(randArr, n);
			break;
		case 2:
			insertionSort(randArr, n);
			break;
		case 3:
			mergeSort(randArr, 0, n-1);
			break;
		case 4:
			QuickSort(randArr, 0, n-1);
			break;
		default:
			exit(0);
	}

  	cout << "\n";
  	cout << "The sorted array is ====>> \n";
 	print_array(randArr, n);
 	cout << "\n";

	return 0;
}
