#include <iostream>
#include <random>


using namespace std;

void naive_matrix_mult(int **a, int **b, int **c, int n)
{
  for (int i = 0; i < n; i++)
          {
              for (int j = 0; j < n; j++)
              {
                  c[i][j] = 0;
                  for (int k = 0; k < n; k++)
                  {
                      c[i][j] = c[i][j] + a[i][k] * b[k][j];
                  }
              }
}
}


void matrix_sum(int **a, int **b, int **c, int n){
  for (int i = 0; i < n; i++)
  for (int j = 0; j < n; j++){
    c[i][j] = a[i][j] + b[i][j];
  }
}

void matrix_sub(int **a, int **b, int **c, int n){
  for (int i = 0; i < n; i++)
  for (int j = 0; j < n; j++){
    c[i][j] = a[i][j] - b[i][j];
  }
}
void matrix_mul(int **a, int **b, int **c, int n){
  if (n == 1){
    c[0][0] = a[0][0] * b[0][0];
  }
  else{
    int **a11 = new int*[(n / 2)];
    int **a12 = new int*[(n / 2)];
    int **a21 = new int*[(n / 2)];
    int **a22 = new int*[(n / 2)];

    int **b11 = new int*[(n / 2)];
    int **b12 = new int*[(n / 2)];
    int **b21 = new int*[(n / 2)];
    int **b22 = new int*[(n / 2)];

    int **c11 = new int*[(n / 2)];
    int **c12 = new int*[(n / 2)];
    int **c21 = new int*[(n / 2)];
    int **c22 = new int*[(n / 2)];

    int **temp1 = new int*[(n / 2)];
    int **temp2 = new int*[(n / 2)];

    int **m1 = new int*[(n / 2)];
    int **m2 = new int*[(n / 2)];
    int **m3 = new int*[(n / 2)];
    int **m4 = new int*[(n / 2)];
    int **m5 = new int*[(n / 2)];
    int **m6 = new int*[(n / 2)];
    int **m7 = new int*[(n / 2)];

    for (int i = 0; i < (n / 2); i++){
      a11[i] = new int[(n / 2)];
      a12[i] = new int[(n / 2)];
      a21[i] = new int[(n / 2)];
      a22[i] = new int[(n / 2)];

      b11[i] = new int[(n / 2)];
      b12[i] = new int[(n / 2)];
      b21[i] = new int[(n / 2)];
      b22[i] = new int[(n / 2)];

      c11[i] = new int[(n / 2)];
      c12[i] = new int[(n / 2)];
      c21[i] = new int[(n / 2)];
      c22[i] = new int[(n / 2)];

      temp1[i] = new int[(n / 2)];
      temp2[i] = new int[(n / 2)];

      m1[i] = new int[n / 2];
      m2[i] = new int[n / 2];
      m3[i] = new int[n / 2];
      m4[i] = new int[n / 2];
      m5[i] = new int[n / 2];
      m6[i] = new int[n / 2];
      m7[i] = new int[n / 2];
    }

    for (int i = 0; i < (n / 2); i++)
    for (int j = 0; j < (n / 2); j++){
      a11[i][j] = a[i][j];
      a12[i][j] = a[i][j + (n / 2)];
      a21[i][j] = a[i + (n / 2)][j];
      a22[i][j] = a[i + (n / 2)][j + (n / 2)];

      b11[i][j] = b[i][j];
      b12[i][j] = b[i][j + (n / 2)];
      b21[i][j] = b[i + (n / 2)][j];
      b22[i][j] = b[i + (n / 2)][j + (n / 2)];
    }
    

    matrix_sum(a11, a22, temp1, (n / 2)); // a11 + a22
    matrix_sum(b11, b22, temp2, (n / 2)); // b11 + b22
    matrix_mul(temp1, temp2, m1, (n / 2)); //m1 = (a11 + a22) (b11 + b22)

    matrix_sum(a21, a22, temp1, (n / 2)); // a21 + a22
    matrix_mul(temp1, b11, m2, (n / 2)); //m2 = (a21 + a22) b11

    matrix_sub(b12, b22, temp1, (n / 2)); // b12 - b22
    matrix_mul(a11, temp1, m3, (n / 2)); //m3 = a11 (b12 - b22)

    matrix_sub(b21, b11, temp1, (n / 2)); // b21 - b11
    matrix_mul(a22, temp1, m4, (n / 2)); //m4 = a22 (b21 - b11)

    matrix_sum(a11, a12, temp1, (n / 2)); // a11 + a12
    matrix_mul(temp1, b22, m5, (n / 2)); //m5 = (a11 + a12) b22

    matrix_sub(a21, a11, temp1, (n / 2)); // a21 - a11
    matrix_sum(b11, b12, temp2, (n / 2)); // b11 + b12
    matrix_mul(temp1, temp2, m6, (n / 2)); //m6 = (a21 - a11) (b11 + b12)

    matrix_sub(a12, a22, temp1, (n / 2)); // a12 - a22
    matrix_sum(b21, b22, temp2, (n / 2)); // b21 + b22
    matrix_mul(temp1, temp2, m7, (n / 2)); //m7 = (a12 - a22) (b21 + b22)

      for (int i = 0; i < (n / 2); i++){
      delete[] a11[i];
      delete[] a12[i];
      delete[] a21[i];
      delete[] a22[i];

      delete[] b11[i];
      delete[] b12[i];
      delete[] b21[i];
      delete[] b22[i];}

    matrix_sum(m1, m4, temp1, n / 2); // m1 + m4
    matrix_sum(temp1, m7,temp2, n / 2); // m1 + m4 + m7
    matrix_sub(temp2, m5, c11, n / 2);// c11 = m1 + m4 - m5 + m7

    matrix_sum(m3, m5, c12, n / 2); // c12 = m3 + m5

    matrix_sum(m2, m4, c21, n / 2); // c21 = m2 + m4
    
    matrix_sum(m1, m3, temp1, n / 2); // m1 + m3
    matrix_sum(temp1, m6, temp2, n / 2); //m1 + m3 + m6
    matrix_sub(temp2, m2, c22, n / 2); // c22 = m1 - m2 + m3 + m6

    for (int i = 0; i < n / 2; i++)
    for (int j = 0; j < n / 2; j++){
      c[i][j] = c11[i][j];
      c[i][j + (n / 2)] = c12[i][j];
      c[i + (n / 2)][j] = c21[i][j];
      c[i + (n / 2)][j + (n / 2)] = c22[i][j];
    }



    for (int i = 0; i < (n / 2); i++){
 
      delete[] c11[i];
      delete[] c12[i];
      delete[] c21[i];
      delete[] c22[i];

      delete[] temp1[i];
      delete[] temp2[i];

    }
  }
}

int main()
{
  srand(time(NULL));
  int n;
    cout << "Enter n such that n = 2^k \n";
  std::cin >> n;
  // while(!(n > 0 && 0 == (1 << 30) % n))
  // {
  //     cout << "Enter n such that n = 2^k"

  int **board,**board3,**board2,**board4;

board = new int*[n]; 

for (int i = 0; i < n; ++i) 
  board[i] = new int[n];

board2 = new int*[n]; 

for (int i = 0; i < n; ++i) {
  board2[i] = new int[n];
}
board3 = new int*[n]; 

for (int i = 0; i < n; ++i) {
  board3[i] = new int[n];
}

board4 = new int*[n]; 

for (int i = 0; i < n; ++i) {
  board4[i] = new int[n];
}


for (int i = 0; i < n; ++i) {   // for each row
  for (int j = 0; j < n; ++j) { // for each column
    board[i][j] = rand()%((int)(sqrt(32767/n)));
  }
}

for (int i = 0; i < n; ++i) {   // for each row
  for (int j = 0; j < n; ++j) { // for each column
    board2[i][j] = rand()%((int)(sqrt(32767/n))) ;
  }
}



cout << "Mat 1 \n";

for (int i = 0; i < n; ++i) {   // for each row
  for (int j = 0; j < n; ++j) { // for each column
    cout << board[i][j] << " ";
  }
  cout << "\n";
}

cout << "Mat 2 \n";


for (int i = 0; i < n; ++i) {   // for each row
  for (int j = 0; j < n; ++j) { // for each column
    cout << board2[i][j] << " ";
  }
  cout << "\n";
}

cout << "Multiplying using Strassen  \n";
matrix_mul(board, board2,board3, n);
cout << "Done  \n";

cout << "Multiplying using Naive O(n^3) algorithm  \n";

naive_matrix_mult(board, board2, board4,n);

cout << "Done  \n";



for(int i = 0; i < n; ++i) {
        delete[] board[i];
        delete[] board2[i];  
    }
    //Free the array of pointers
    delete[] board;
    delete[] board2;

cout << "comparing the two outputs \n";

for (int i = 0; i < n; ++i) {   
  for (int j = 0; j < n; ++j) { 
    cout << board3[i][j] << " ";
  }
  cout << "\n";
}

cout << "\n";

for (int i = 0; i < n; ++i) {   
  for (int j = 0; j < n; ++j) { 
    cout << board4[i][j] << " ";
  }
  cout << "\n";
}



int first_elem = 0;
int last_elem = n-1;


if(board4[last_elem][last_elem] == board3[last_elem][last_elem] && board4[first_elem][first_elem] == board3[first_elem][first_elem])
{
  cout << "Both matrices are equal!!";
}
else
  cout << "unequal";

for(int i = 0; i < n; ++i) {
        delete[] board3[i];
        delete[] board4[i];  
    }
    //Free the array of pointers
    delete[] board3;
    delete[] board4;
}