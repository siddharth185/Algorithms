  /**
    CS-575-01 Asn 5
    Purpose: Implement Dynamic Prog Algorithms

    @author Siddharth Kulshrestha
    @version 1.0 12/05/17
*/
  #include<iostream>
  #include<algorithm>
  #include<random>
  
  using namespace std;

    int n;
    int keep = 0; 
    int max_profit_value = 0;


  class item{
    public : 
    int profit;
    int wght;
    int mark;
    int upperBound;
  };

  class node
  { public:
    float val;
    int curr_index;
  };



  void sorter(node a[], int k)
  {
      int x,y;
      for(x = 0; x < k-1; x++) {
        for(y = x + 1;y < k;y++) {
          if(a[y].val > a[x].val) 
            std:swap(a[x], a[y]);}}}
                 
        

  float KWF2(int i, int wght, int profit, node user[], int W, item it[]) // Implement KWF2 from class notes
  {
          int j;

          float x[9];
          float bound;

          bound  = (float)profit;
          for(j = 0; j < n;j++)
          {
            x[j] = 0 ; 

          while  (wght < W &&  i < n)                
          {
              if (wght  + it[user[i].curr_index].wght  <=  W )
            {
                x[i]=1;                                  
                wght = wght + it[user[i].curr_index].wght; 
                bound = bound + it[user[i].curr_index].profit;
            }                               
           else
           {
                x[i]=(float)(W - wght)/(float)it[user[i].curr_index].wght;    
                wght  = W; 
                bound  =  bound + (float)it[user[i].curr_index].profit * x[i];
           }
            i++;                                                        
          }
         return bound;
  }}

  int promising_checker(int i,int W,node user[],int profit, int wght,item it[]) //Check if node is promising
  {
        if (wght < W)
          return 1;
        float Bound;
        Bound= KWF2(i+1, wght, profit,user,W,it);

        cout << "Visited Node: " << keep << " Profit: " << profit << " Weight: " << wght << " Bound: " << Bound << "\n";
        keep = keep + 1;

        float maxer = (float)max_profit_value;

         if (Bound > maxer) return 1;
         return 1;
  }

  void knapsack(int i, int profit, int wght,int W,node user[], int include1[],int pri_set[],item it[])
  {
      if  ( wght  <=  W &&  profit  > max_profit_value )
      {
          max_profit_value = profit ;
          for(int j=0;j< n;j++)
            pri_set[j]= include1[j]; 
      }

      if  (promising_checker(i,W, user,profit,wght,it))
      {

          include1[i+1] = 1;
          knapsack(i+1, profit + it[user[i+1].curr_index].profit, wght + it[user[i+1].curr_index].wght,W,user,include1,pri_set,it);
          include1[i+1]  = 0;
          knapsack(i+1, profit, wght, W, user, include1, pri_set, it);
      }
          
  }

  

  void brute_force(int n,item it[],int W) //Implement Brute Force Method
  {
  	int j, i,user, sum, int_W, P_new, P, sum_w;

  	P=0;

    sum = pow(2,n);

  	int mark[9];

  	

  	for(i = 1;i < sum;i++)
  	{
           int_W=0;
           P_new=0;
          for(j=n-1;j>=0;j--)
          {
          	it[j].mark = 0;
          }
          for(j=n-1;j>=0;j--)
          {
         		user = (i>>j)&1;
         		if(user == 1)
         		{
         			int_W += it[j].wght;
         			P_new += it[j].profit;
         			it[j].mark = 1;
             	}
          } 

          if(int_W <= W && P_new > P)
             {
             		for(j=0;j<n;j++)
             		{
             			mark[j]=0;
             		}
             		P = P_new;
             		sum_w = int_W;
             		for(j=0;j<n;j++)
             		{
             			if(it[j].mark==1)
             				mark[j]=1;
             		}
             }
      }
      cout << "\n((USING BRUTE FORCE)) ========>\n\n";
      cout << "MAX TOTAL PROFIT:  " << P << " MAX TOTAL WEIGHT: " << sum_w << "\n\n";
      for(i=0; i < n;i++)
      {
      	if(mark[i] == 1)
        cout << "Item: " << i << " Profit: " << it[i].profit << " Weight: " << it[i].wght << "\n";
      }
  }

  void printArray(int* theArray, int numberOfRows, int numberOfColumns){ //Print an array
    for(int x = 0; x < numberOfRows; x++){
        for(int y = 0; y < numberOfColumns; y++){
            cout << theArray[x * numberOfColumns + y] << " ";
        }
        cout << "\n" << endl;
    }
}

  void refinement_algo(int n, item it[], int W) //Refinement DP Algo
  {
    int *B;

    int i, k, w, optimal;

    optimal = 0;

    B = new int[(n+1)* (W+1)];

    for(i = 0;i < W+1;i++)
        B[0 * (W+1)+i] = 0;

    for(k = 1;k<n+1;k++)
    {
      B[k *  (W+1)+0] = 0;
      for(w = 1;w < W+1;w++)
      {
        if (!(it[k-1].wght <= w && (B[(k-1)*(W+1) +(w-it[k-1].wght)] + it[k-1].profit > B[(k-1)*(W+1) + w])))
            B[k*(W+1)+w]=B[(k-1) * (W+1) + w];
        else
          B[k * (W+1)+w]=B[(k-1) * (W+1) + (w-it[k-1].wght)] + it[k-1].profit;
          
      }
    }

        int user, sum_w_1;

        user=W;  

        sum_w_1 = 0;

        for(i=0;i<n;i++)
        {
            it[i].mark=0;
        }
        for(i=n;i>=1;i--)  
        {  
          if(B[i*(W+1)+user] > B[(i-1)*(W+1)+user] )  
              {  
                  it[i-1].mark = 1; 

                  sum_w_1 += it[i-1].wght;

                  user=user-it[i-1].wght;

              }  
        }

      cout << "\n ((USING REFINED DYNAMIC PROGRAMMING)) ========> \n";
      cout << "The B Matrix is : " << endl;
      printArray(B, n+1, W+1);

      cout << "MAX TOTAL PROFIT: " << B[n*(W+1) + W] << " MAX TOTAL WEIGHT: " << sum_w_1 << "\n\n"  ;
      cout << "Items Included in optimal solution : \n";
      for(i=0;i<n;i++)
      {
        if(it[i].mark == 1)
          cout << "Item : " << i << " Profit: " << it[i].profit << " Weight: " << it[i].wght << "\n";
      }
      free(B);

  }

  int main()
  {

  	srand(time(NULL));

  	int i, W;

  	W = 0; 

    n = (rand()%5) + 4;

  	item it[9];

    cout << "Total Included Items(n) : " << n << " \n";

    cout << "Items Information : \n";

  	for(i=0;i<n;i++)
  	{
  		it[i].profit = (rand()%21) + 10;

  		it[i].wght = (rand()%16) + 5;

  		it[i].mark = 0;

      cout << "Item: " << i << " Profit: " << it[i].profit << " Weight: " << it[i].wght << "\n";

  		W = W + it[i].wght;
  	}

  	W =(int)floor(W * 0.6);

  	cout << "W = " << W;

  	brute_force(n, it, W);

    refinement_algo(n, it, W);

    int include1[9] = {0};

    int pri_set[9] = {0};

    node user[9];

    for(i = 0;i < n;i++)
    {
      user[i].val = (float)it[i].profit / (float)it[i].wght;
      user[i].curr_index = i;
    }
    sorter(user,n);

    cout << " \nUSING BACKTRACKING ALGORITHM =====>>\n\n";

    knapsack(-1,0,0, W, user, include1, pri_set, it);

    int sum_w_2;

    sum_w_2=0;

       for (i = 0 ;  i < n;  i++)
     {
        if(pri_set[i]==1)
        sum_w_2 += it[user[i].curr_index].wght;
     }
     cout << "\n";
     cout << "MAX TOTAL PROFIT: " << max_profit_value << " MAX TOTAL WEIGHT: " << sum_w_2 << "\n" ;

      cout << "Items Included in optimal solution : \n";

     for (i = 0 ; i < n;  i++)
     {
        if(pri_set[i] == 1)
          cout << "Item: " << user[i].curr_index << " Profit: " << it[user[i].curr_index].profit << " Weight: " << it[user[i].curr_index].wght << "\n";
     }

  	return 0;
  }
