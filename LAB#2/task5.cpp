#include <iostream>
using namespace std;

void allocate(int**& matrix, int rows, int cols) 
{
    matrix = new int*[rows];
    for (int i = 0; i < rows; i++) matrix[i] = new int[cols];
}

void input(int** matrix, int rows, int cols) 
{
    for (int i = 0; i < rows; i++) 
        for (int j = 0; j < cols; j++) 
            cin >> matrix[i][j];
}

void display(int** matrix, int rows, int cols) 
{
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) 
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}

void add(int** A, int** B, int**& result, int rows, int cols) 
{
    allocate(result, rows, cols);
    for (int i = 0; i < rows; i++) 
        for (int j = 0; j < cols; j++) 
            result[i][j] = A[i][j] + B[i][j];
}

void subtract(int** A, int** B, int**& result, int rows, int cols) 
{
    allocate(result, rows, cols);
    for (int i = 0; i < rows; i++) 
        for (int j = 0; j < cols; j++) 
            result[i][j] = A[i][j] - B[i][j];
}

void multi(int** A, int** B, int**& result, int row1, int column1, int column2) {
    allocate(result, row1, column2);
    for (int i = 0; i < row1; i++) 
        for (int j = 0; j < column2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < column1; k++) 
                result[i][j] += A[i][k] * B[k][j];
        }
}

void deallocate(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) delete[] matrix[i];
    delete[] matrix;
}

int main() {
    int row1, column1, row2, column2;
    
    cout << "enter rows and cols for 1 matrix: ";
    cin >> row1 >> column1;
    cout << "Enter rows and cols for 2 matrix: ";
    cin >> row2 >> column2;

    int** A_matrix;
    int** B_matrix;
    allocate(A_matrix, row1, column1);
    allocate(B_matrix, row2, column2);

    cout << "Enter elements for first matrix:\n";
    input(A_matrix, row1, column1);
    cout << "Enter elements for second matrix:\n";
    input(B_matrix, row2, column2);

    if (row1 == row2 && column1 == column2) 
    {
        int** addition_answer;
        int** subtraction_answer;
        add(A_matrix, B_matrix, addition_answer, row1, column1);
        subtract(A_matrix, B_matrix, subtraction_answer, row1, column1);
        cout << "addition:\n";
        display(addition_answer, row1, column1);
        cout << "subtraction:\n";
        display(subtraction_answer, row1, column1);
        deallocate(addition_answer, row1);
        deallocate(subtraction_answer, row1);
    }

    if (column1 == row2) 
    {
        int** product_answer;
        multi(A_matrix, B_matrix, product_answer, row1, column1, column2);
        cout << "multiplication:" << endl;

        display(product_answer, row1, column2);
        deallocate(product_answer, row1);
    } 
    else cout << "not possible.\n";

    deallocate(A_matrix, row1);
    deallocate(B_matrix, row2);

    return 0;
}

