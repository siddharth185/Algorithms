#include<iostream>
#include<algorithm>
#include <random>
#include "sort_utilities.h" //Contains the utility functions to sort and visualize the sorting

using namespace std;


int main()
{
	srand(time(NULL)); 
	int randArr[1000];
	int n, algo;

	cout << "Please choose the sorting algorithm to use!! \n\n";
	cout << " Please enter 1 for RADIX sort, 2 for HEAP sort \n\n ";
	cin >> algo ;
	if(algo > 2)
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
	if(algo == 2)
	{	
		if(n <=20)
	{
		for (int i = 1; i<=n;i++)
			randArr[i] = rand()%14 + 1; //Random Numbers added to the array
	}
	else
	{
		for (int i = 1; i<=n;i++)
			randArr[i] = rand()%998 + 1;
}
}
	else
	{
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
		randArr[i] = rand()%998 + 1;
		}
	}}

cout << "\n";
	cout << "The UNSORTED array is ====>> \n";
	if(algo == 2)
  		heap_print_array(randArr, n);
  	else
 		print_array(randArr, n);
	cout << "\n \n";

	switch(algo){  //Switch case to decide which algorithm to use according to User
		case 1:
			radixsort(randArr, n);
			break;
		case 2:
			{
				build_maxheap(randArr,n);
				heap_sort(randArr, n);
			}
			break;
		default:
			exit(0);
		}


	cout << "\n";
  	cout << "The sorted array is ====>> \n";
  	if(algo == 2)
  		heap_print_array(randArr, n);
  	else
 		print_array(randArr, n);
 	cout << "\n";
}

