#include <iostream>
#include <random>

using namespace std;

void path (int** P, int q, int r)  //Function to find shortest path (from Class Notes)
{
	if(P[q][r] != 0)
	{	
		path(P, q, P[q][r]);
		cout << "v" << P[q][r] + 1 << " ";
		path(P, P[q][r], r);
	}
	
}

int main()
{
	int** Matrix;	// Contains the original matrix					
	int** dist;		//Matrix which contains shortest paths between vertex
	int** Next;		//This matrix is used for matrix reconstruction
	int n;
	srand(time(NULL)); 

	n = rand()%(6) + 5; 
	cout << " The Value of n : " << n << "\n";
	Matrix=new int*[n];				
	dist=new int*[n];
	Next = new int*[n];
	
	for(int i=0;i<n;i++)
	{
		Matrix[i]=new int[n];		
		for(int j=0;j<n;j++)		
		{
				Matrix[i][j] = 1 + rand()%9 ;
				if (i==j)
			{
				Matrix[i][j] = 0;
			}
		}
	}

	for(int i=0;i<n;i++) // Make it symmetric
	{
		for(int j=0;j<n;j++)		
		{
				
				if (i==j)
			{
				Matrix[i][j] = 0;
			}
				else if (Matrix[i][j] != Matrix[j][i])
						Matrix[i][j] = Matrix[j][i];
		}
	}

	cout<<"The adjacency matrix is:\n";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cout<<Matrix[i][j]<<"\t";	
		cout<<"\n";						
	}

// Next matrix is for path reconstruction
	
//Intitializing dist and Next matrix

	for(int i=0;i<n;i++)
	{
		dist[i]=new int[n];		
		Next[i] = new int[n];
		for(int j=0;j<n;j++)		
		{
				dist[i][j] = Matrix[i][j];
				Next[i][j] = 0;  // Initialize all terms to zero. This matrix is used for Path reconstruction
				
		}
	}


	for(int k = 0; k<n;k++)	// O(n3) algorithm for Floyd Shortest Path
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
			{	int inter_dist = dist[i][k] + dist[k][j];
				if ( dist[i][j] > inter_dist ){
					dist[i][j] = inter_dist;
					Next[i][j] = k;
					}
			}

	
	
for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{	if(i!=j && j > i){
			cout << "Shortest Weighted Distance(Length) between " << "v"<<i+1 << " and " << "v" << j+1 << " = " << dist[i][j]; //Printing the distances
			cout << "\n";}
		}}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{

			if (i!=j && j > i){
			cout << "Shortest Path between " << "v"<<i+1 << " and " << "v" << j+1 << "    ================> "; //Printing the shortest paths b/w vertex
			cout << "v" << i+1 << " ";
			path(Next,i,j);
			cout << "v" << j+1<< "";
			cout << "\n";

				}
				}
 	}

	for(int i=0;i<n;i++)  //Clearing the memory spaces
		{
		delete[] dist;			
		delete[] Matrix;	
		delete[] Next;	}		

}


