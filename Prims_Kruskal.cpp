#include<iostream>
#include<algorithm>

using namespace std;

class edge{ //Class to represent Edge
public:
    int x, y;
    int w;
};

int algo;

int array[11];
int array1[11];

void sort_edges(edge array[] , int n) //Sort the edges
{
    int node1, node2;

    for(node1 = 0; node1 < n-1; node1++) {
        for(node2 = node1+1; node2 < n; node2++) {
            if(array[node1].w > array[node2].w) {
                std:swap(array[node1], array[node2]);
            }}}}
    



void union3(int repx, int repy, int height[]) //Implemented Union3 according to Class Notes
{
    
    if (height[repx] > height [repy])
        array1[repy] = repx;
    else if (height[repx] == height[repy])
    {
        height[repx]++;

        array1[repy] = repx;
    }
    else
        array1[repx] = repy; 
}


int find3(int y)  //Implemented find3 according to Class Notes
{
    int parent, node, root;

    root = y;

    while(root != array1[root])
        root=array1[root];

    node = y;
    while(1)
    {
        if (node != root)
    {
        parent = array1[node];
        array1[node] = root;
        node = parent;
    }
    else 
        break;
    }

}
void Prim(int *Matrix, int n) // Prims Algorithm
{
    int i, less, less1, count;

    int cost[n];

    count=0;

    int parent[n];

    less=999;

    for(i=0;i<n;i++)
    {
        cost[i]=999;

        array[i]=0;
    }

    parent[0] = -999;

    cost[0] = 0;

    

 while(count < n-1)
 {
        for(i=0;i<n;i++)
        {
            if(cost[i] < less && array[i] == 0)
            {
                    less = cost[i];

                    less1 = i;
            }          
         }

        array[less1] = 1;

        for(i = 0; i < n; i++)
        {
            if( array[i] == 0 && cost[i] > Matrix[less1 * n+i] && Matrix[less1 * n+i] > 0 )
            {
                    cost[i] = Matrix[less1 * n + i];
                    parent[i] = less1;
            }


        }

        less = 999;
        count++;
 }

cout << "Prims MST is - \n";

for (i = 1; i < n; i++)
        cout << parent[i] << " - " << i << "\n";
}

void Kruskal(int *Matrix, int n) // Kruskals Algorithm
{
    int i, j, position = 0, ucomp, vcomp;

    edge E[n * n], T[n * n];

    int height[n];



    for(i = 0;i < n;i++)
    {
        for(j=0;j<n;j++)
        {
            E[position].w = Matrix[i * n + j];

            E[position].x = i;

            E[position].y = j;

            position = position + 1;
        }
    }

    sort_edges(E, n * n);
    

    int l = 0;

    while(l < n)
    {
        array1[l] = l;
        height[l] = 0;
        l++;
    };

    position = 0;

    for(i = 0;i < n * n;i++)
    {
        if(E[i].w != 0)
        {
            ucomp=find3(E[i].x);

            vcomp=find3(E[i].y);

            if(vcomp!= ucomp)
            {
                T[position] = E[i];

                union3(ucomp, vcomp,height);

                position = position + 1;

                if(position == n-1)
                    break;
            }
        }
    }
    cout << "Kruskal MST  is - \n";

    for(i = 0;i < n - 1; i++)
    {
        cout << T[i].x << " - " << T[i].y << "\n"; 
    }
}

int main()
{
    srand(time(NULL));

    int *Matrix;

    int i, j, n;

    n = (rand() % 6) + 5;

    cout << "The value of n is : " << n << "\n";
    
    Matrix = new int[n * n]; // Adjacancy Matrix

    for(i = 0;i < n;i++)

        for(j = 0;j <= i;j++)  
        {
            if(!(i==j)) 
            {
               Matrix[i*  n + j] = rand()%10+1;

                Matrix[j * n + i] = Matrix[i*n+j];
            }
            else
            {
                

                 Matrix[i * n + j] = 0;
            }
        }


    cout << "\nThe Adjacancy Matrix is \n";

    for(i = 0;i < n;i++)
    {
        for(j = 0;j < n;j++)
        {
            cout << Matrix[i * n + j] << " ";
        }
        cout << "\n";
    }

    cout << "  \n \n Please Enter 1 for Prims and enter 2 for Kruskal \n \n";

    cin >> algo;
    
    cout << "\n";
    if (algo == 1)
        Prim(Matrix, n);
   
    else if (algo == 2)
        Kruskal(Matrix, n);
    else
        cout << "ERROR : Please enter 1 or 2. Quitting the Program \n";
}
