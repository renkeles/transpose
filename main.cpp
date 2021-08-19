#include <iostream>
#include <ctime>

int** create_array2d(unsigned row, unsigned col){
    int** array = new int* [row];
    array[0] = new int[row * col];
    for(unsigned i = 1; i != row; i++){
        array[i] = array[i - 1] + col;
    }
    return array;
}

int** init_array2d(int** array, unsigned row, unsigned col){
    for(unsigned i = 0; i < row; i++){
        for(unsigned j = 0; j < col; j++){
            array[i][j] = 0;
        }
    }
    return array;
}

void print_array2d(int** array, unsigned row, unsigned col){
    for(unsigned i = 0; i < row; i++){
        for(unsigned j = 0; j < col; j++){
            std::cout.width(5);
            std::cout << array[i][j];
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void fill_array2d(int** array, unsigned row, unsigned col){
    for(unsigned i = 0; i < row; i++){
        for(unsigned j = 0; j < col; j++){
            array[i][j] = (1 + rand() % 99);
        }
    }
}

int** transpose(const int* const* m, unsigned rows, unsigned cols){
    int** transposeArr = create_array2d(cols, rows);
    transposeArr = init_array2d(transposeArr, cols, rows);
    for(unsigned i = 0; i < rows; i++){
        for(unsigned j = 0; j < cols; j++){
            transposeArr[j][i] = m[i][j];
        }
    }


    return transposeArr;
}

typedef struct{
    int min = 0;
    unsigned row = 0;
} MinRow;



void swap_min(int* m[], unsigned rows, unsigned cols){
    MinRow *minRow = new MinRow;
    minRow->min = m[0][0];
    for(unsigned i = 0; i < rows; i++){

        for(unsigned j = 0; j < cols; j++){
            if(m[i][j] < minRow->min){
                minRow->min = m[i][j];
                minRow->row = i;
            }
        }
    }
    int* tmp = m[minRow->row];
    m[minRow->row] = m[0];
    m[0] = tmp;
    delete minRow;
}

int main(){

    srand(time(0u));

    const unsigned row = 5;
    const unsigned col = 4;

    int** array2d = create_array2d(row, col);
    array2d = init_array2d(array2d, row, col);
    //print_array2d(array2d, row, col);
    fill_array2d(array2d, row, col);
    print_array2d(array2d, row, col);

    int** transpose2d = create_array2d(col, row);
    transpose2d = init_array2d(transpose2d, col, row);
    transpose2d = transpose(array2d, row, col);

    print_array2d(transpose2d, col, row);
    swap_min(transpose2d, col, row);
    print_array2d(transpose2d, col, row);

    return 0;
};
