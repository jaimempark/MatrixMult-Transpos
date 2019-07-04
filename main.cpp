/*
    Matrix Multiplication and Transposition
    Matrix are represented as a 2D vectors holding integers.
*/
#include <iostream>
#include <vector>
using namespace std;

//Matrix multiplication - multiply the first matrix by the second and return the result
vector<vector<int>> mMultiply(vector<vector<int>> matrixA, vector<vector<int>> matrixB) {
    if(matrixA[0].size() != matrixB.size()) {
        cout << "Cannot multiply: the first matrix columns must equal the second matrix rows.";
        exit;
    } 
    vector<vector<int>> temp(matrixB.size(), vector<int>(matrixB.size(),0));
    for(int i = 0; i < matrixB.size(); i++) {
        for(int j = 0; j < matrixB.size(); j++) {
            double sum = 0;
            for(int k = 0; k < matrixB.size(); k++) {
                sum += matrixA[i][k] * matrixB[k][j];
            }
            temp[i][j] = sum;
        }
    }
    return temp;
}

//Matrix transposition - flips the N and M of the given matrix
void mTranspose(vector<vector<int>> &matrixA) {
    if(matrixA.size() == 0) {
        return;
    }
    vector<vector<int>> temp(matrixA.size(), vector<int>()); 
    for(int i = 0; i < matrixA.size(); i++) {
        for(int j = 0; j < matrixA[i].size(); j++) {
            temp[j].push_back(matrixA[i][j]);
        }
    }
    matrixA = temp;
}

//Print matrix - print out given matrix with formatting
void printM(vector<vector<int>> n) {
    for(auto vec : n) {
        for(auto i : vec) {
            if(i < 1000) {
                cout << " ";
            } if(i < 100) {
                cout << " ";
            } if(i < 10) {
            cout << " ";
            }
        cout << i << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    // Initialize a vector of vectors containing integers. This example is a 6 x 6 matrix of 0s.
    vector<vector<int>> vec2D(6, vector<int>(6,0)); 
    int count = 1;     // Assign values for vec2D
    for(int i = 0; i < vec2D.size(); i++) {
        for(int j = 0; j < vec2D[i].size(); j++) {
        vec2D[i][j] = count++;
        }
    }
    cout << "First matrix : " << endl;
    printM(vec2D);

    //matrix transpose example
    cout << "Transpose of first matrix: " << endl;;
    mTranspose(vec2D);
    printM(vec2D);
    cout << "Transpose of transposed matrix: " << endl;
    mTranspose(vec2D); //transposing again should result in the original matrix  (M^T)^T = M
    printM(vec2D);

    //matrix multiplication example
    vector<vector<int>> vec2Db(6, vector<int>(6,0)); //setting up second matrix to multiply with
    count = 1;
    for(int i = 0; i < vec2Db.size(); i++) {
        for(int j = 0; j < vec2Db[i].size(); j++) {
        vec2Db[i][j] = count++;
        }
    }
    vector<vector<int>> solution(6, vector<int>(6,0));
    cout << "Multiplication of first and a second, identical matrix: " << endl;
    solution = mMultiply(vec2D, vec2Db); 
    printM(solution);
    return 0;
}