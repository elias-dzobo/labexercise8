#include <iostream>
#include <iomanip>
#include <iterator>

using namespace std;

void display2D(int** arr, int N) {
    
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {

            cout << arr[i][j] << " ";
            
        }

        cout << endl;
    } 
}

void display2dIndex(int** arr, int N) {
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {

            cout << "Value: " << arr[i][j] << setw(15) << "Index: " << i << "," << j << endl;
             

        }

        cout << endl;
    } 
}

void display1D(int* arr) {
    
    for(int i = 0; i < 20; i++){
        cout<<" "<< arr[i] << " ";
    }
}

int** generateArray(int N) {
    
    int** myarr = new int*[N];
    

    int start = 0;
    int i, j;

    for (int i = 0; i < N; i ++ ){
        myarr[i] = new int[N];
    }

    for (i = 0; i < N; i++) {

        for (j = 0; j < N; j++) {
            if (i >= j) {
                myarr[i][j] = ++start;
            } else {
                myarr[i][j] = 0;
            }
            

        } 
    }

    

    return myarr;

}


int* LinearIndx(int i, int j, int** arr, int N){

    int* linearArr = new int[N*N]; 
    int idx = 0;

    int k;
    int retIdx;


    for (int a = 0; a < N; a++) {
        for (int b = 0; b < N; b ++) {


            if ( arr[a][b] == 0) {
                continue; 
            } else {
                idx = ((a+1)*a)/2 + b;
                linearArr[idx] = arr[a][b];
            }

        }
    }


    return  linearArr;


}

int** InverseIdx(int* arr, int N) {

    int** inverseArr = new int*[N];
    int idx = 0;

    for (int i=0; i < N; i++) {
        inverseArr[i] = new int[N];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i >= j) {
                inverseArr[i][j] = arr[idx];
                
            } else {
                inverseArr[i][j] = 0;
            }

            idx = idx + 1;
        }
    }

    return inverseArr;
}

int main (int argc, char *argv[]) {

  
    int** A1 = generateArray(8);
    int** A2 = generateArray(32);
    int** A3 = generateArray(128);

    int* B1 = LinearIndx(3, 2, A1, 8);
    int* B2 = LinearIndx(3, 2, A2, 32);
    int* B3 = LinearIndx(3, 2, A3, 128);

    display1D(B1);
    cout << endl;
    display1D(B2);
    cout<< endl;
    display1D(B3);
    cout<< endl;

    
    display2D(A1, 8);

    cout << "Array of size 32 x 32" << endl;
    display2D(A2, 32);

    cout<<" Array of size 128 x 128" << endl;
    display2D(A3, 128);



    cout<< " Display next" << endl;

    

    cout << endl; 
    
    int** inversedA1 = InverseIdx(B1, 8);
    cout << "Inversed array" << endl;
    display2dIndex(inversedA1, 8);

    cout << endl;
    display2D(inversedA1, 8);
 
    
}
