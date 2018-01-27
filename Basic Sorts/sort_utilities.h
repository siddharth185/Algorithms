void swap(int *xp, int *yp)
/**
    Swaps two integer numbers.

    @param Two integer values.
    @return The volume of the sphere.
*/
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void print_array(int arr[], int n)
{
  /**
    Accepts an array and print the elements .

    @param A integer array and size of array n.

*/
  for(int i=0; i<n; ++i)
      std::cout << arr[i] << ' ';

}

void visualize(int arr[], int n){
  /**
    Visualizes sorting arrays using * .

    @param A integer array and size of array n.
    @return Visualizations in form of **** .
*/
  if (n <= 20){
    {
      for(int i = 0; i < n;i++){
        for (int j = 0; j < arr[i]; j++)
          std::cout << "*";
      std::cout << "\n";
    }
      std::cout << "\n";

    }
  }

}

void exchange_sort(int arr[], int n)
{
  /**
    Implements exchange Sort Algorithm .

    @param A integer array and size of array n.

*/

  visualize(arr, n);
	for (int i = 0; i < n- 1; i++){
   		for (int j = 0; j < n-i-1; j++)
      		if (arr[j] > arr[j+1])
          		swap(&arr[j], &arr[j+1]);

      if(n <= 20)
        visualize(arr, n);
    }
}

void insertionSort(int arr[], int n)
{
  /**
    Implements Insertion Sort Algorithm .

    @param A integer array and size of array n.

*/
   int i, key, j;
   visualize(arr, n) ;
   for (i = 1; i < n; i++)
   {
       key = arr[i];
       j = i-1;


       while (j >= 0 && arr[j] > key)  //Move elements of array that are greater than key
                                      //to one position ahead
       {
           arr[j+1] = arr[j];
           j = j-1;

       }

       arr[j+1] = key;
       visualize(arr, n) ;


   }


}

void merge(int arr[], int l, int m, int r)
{  /**
    Implements Merge Function.


*/

    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];


    i = 0;
    j = 0;
    k = l;

    visualize(arr, r+2);
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }


    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }


    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

int Partition(int a[], int low, int high)
{  /**
    Partitions an array for quick sort.

    @param A integer array and low and high bounds.

*/
  int pivot, index, i;
  index = low;
  pivot = high;

  for(i=low; i < high; i++)
  {
    if(a[i] < a[pivot])
    {
      swap(&a[i], &a[index]);
      index++;
    }
  }
  swap(&a[pivot], &a[index]);

  return index; // Return index of the pivot
}

int RandPivotPartition(int a[], int low, int high)
{
  /**
      Randomly partitions array using a randomly generated pivot.

      @param A integer array and low and high bounds.

  */
  int pvt, n, temp;
  n = rand();

  pvt = low + n%(high-low+1);  //Randomly generating and choosing a pivot from the range
  visualize(a, high+2);

  swap(&a[high], &a[pvt]);


  return Partition(a, low, high);  // Partition array using pivot
}

int QuickSort(int a[], int low, int high)
{
  int pindex;
  if(low < high)
  {

    pindex = RandPivotPartition(a, low, high);
    visualize(a, high+2);

    QuickSort(a, low, pindex-1);  //Recursively apply on left sub array
    QuickSort(a, pindex+1, high); //Recursively apply on right sub array

  }
  return 0;
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {

        int m = l+(r-l)/2;

        mergeSort(arr, l, m); //Recursively apply mergesort on left sub array
        mergeSort(arr, m+1, r); //Recursively apply mergesort on left sub array
        merge(arr, l, m, r); // Merge the arrays
        visualize(arr, r+2);

    }
}
