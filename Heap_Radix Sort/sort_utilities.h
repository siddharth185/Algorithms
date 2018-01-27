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
void heap_print_array(int arr[], int n)
{
  /**
    Accepts an array and print the elements .

    @param A integer array and size of array n.

*/
  for(int i=1; i<=n; ++i)
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

int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}
 
// A function to do counting sort of arr[] according to
// the digit represented by exp.
void countSort(int arr[], int n, int exp)
{
    int output[n]; // output array
    int i, count[10] = {0};
 
    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
        count[ (arr[i]/exp)%10 ]++;
 
    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
 
    // Build the output array
    for (i = n - 1; i >= 0; i--)
    {
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i];
        count[ (arr[i]/exp)%10 ]--;
    }
 
    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}
 
// The main function to that sorts arr[] of size n using 
// Radix Sort
void radixsort(int arr[], int n)
{
    // Find the maximum number to know number of digits
    int m = getMax(arr, n);
 
    // Do counting sort for every digit. Note that instead
    // of passing digit number, exp is passed. exp is 10^i
    // where i is current digit number
    for (int exp = 1; m/exp > 0; exp *= 10)
    	{visualize(arr,n);
        countSort(arr, n, exp);}
        visualize(arr,n);

}


void max_heapify(int *a, int i, int n)
{
    int j, temp;
    temp = a[i];
    j = 2*i;
    while (j <= n)
    {
        if (j < n && a[j+1] > a[j])
            j = j+1;
        if (temp > a[j])
            break;
        else if (temp <= a[j])
        {
            a[j/2] = a[j];
            j = 2*j;
        }
    }
    a[j/2] = temp;
    return;
}
void heap_sort(int *a, int n)
{	
    int i, temp;
    for (i = n; i >= 2; i--)
    {	visualize(a, i+1);
        temp = a[i];
        a[i] = a[1];
        a[1] = temp;
        max_heapify(a, 1, i - 1);
        
    }
    visualize(a, i+1);
    //visualize(a, i-1);
}
void build_maxheap(int *a, int n)
{
    int i;
    for(i = n/2; i >= 1; i--)
    {
        max_heapify(a, i, n);
    }
}