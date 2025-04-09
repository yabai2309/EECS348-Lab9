/*
EECS 348 Lab 09
Matrix operation program

Inputs: A file with size of the matrix and 2 matrixes
Outputs: Execute whatever function the user want

Collaborators: None
Other sources: None
Author's name: Anh Hoang
Creation date: 4/8/25

*/
#include "matrix.hpp"//Include necessary library
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

template<typename T>
void theRealSwapRow(Matrix<T>& matrix, size_t row1, size_t row2){
    matrix.swap_rows(row1, row2);
}
template<typename T>
void theRealSwapCol(Matrix<T>& matrix, size_t col1, size_t col2){
    matrix.swap_cols(col1, col2);
}
template<typename T>
void theRealupdateValue(Matrix<T>& matrix, size_t row, size_t col, T value){
    matrix.set_value(row, col, value);
}
//Helper function to print out the menu for user
void printMenu(){
    cout << endl;
    cout << "Choose what do you want to do:" << endl;
    cout << "1) Add two matrix together" <<endl;
    cout << "2) Multiply two matrix together" <<endl;
    cout << "3) Calculate sum of the diagonal" <<endl;
    cout << "4) Swap row" <<endl;
    cout << "5) Swap column" <<endl;
    cout << "6) Update value at a location" <<endl;
    cout << "7) Exit" << endl;
    cout << "Enter: " ;
}

//Main function
int main() {
    //Handle file I/O
    string filename;//Create a place holder for file name
    cout << "Specify the file you want to read: ";//Prompt user for file name
    std::cin >> filename;//Write to the place holder created
    ifstream file(filename);//Open file 
    if (!file) {//If we cannot open the file
        cerr << "File is not found" << endl;//Print out message to user
        return 1;//Return value 1 indicating error
    }
    
    //Read the first line as the size of the matrix
    int size, typeFlag;//Create a placeholder as integer for the size
    file >> size >> typeFlag;
    file.ignore();
   
    try{
        if(typeFlag == 0){//Integer matrices
            Matrix<int> matrix1(size), matrix2(size);
            file >> matrix1 >> matrix2;
            cout << "First matrix:"  << endl;//Print out the first matrix
            matrix1.print_matrix();
            cout << "Second matrix:"  << endl;//Print out the second matrix
            matrix2.print_matrix();
             //Handle user choices from the command line menu
            int choice = 0;//Create a placeholder for user choice
            printMenu();//Print out the menu to the user
            std::cin >> choice;//Listen to user input
            while(choice != 7){//Create a loop to keep asking user until user want to quit
                switch(choice){//Switch-case to navigate the choices
                    case 1: {//Handle the add function
                        Matrix<int> matrix3 = matrix1+matrix2;//Add 2 matrix together
                        matrix3.print_matrix();//Print out that result matrix to user
                        break;//Jump out of the switch-case block
                    }
                    case 2: {//Handle multiply function
                        Matrix<int> matrix3 = matrix1*matrix2;//Multiply 2 matrix together
                        matrix3.print_matrix();//Print out that result matrix to user
                        break;//Jump out of the switch-case block
                    }
                    case 3: {//Handle diagonal sum function
                        int matrix_choice;//Create a placeholder for user to choose the matrix they want
                        int sumBoth;//Create a placeholder for the return value
                        cout << "Choose between matrix_1 (1) or matrix(2). Type in the number 1 or 2: ";
                        cin >> matrix_choice;//Prompt user and get the matrix choice
                        if (matrix_choice == 1){//If they choose matrix 1 
                            sumBoth = matrix1.sum_diagonal_major() + matrix1.sum_diagonal_minor();//Calculate the diagonal sum
                            if (size % 2 == 1) {//For the case it's odd number
                            int center = matrix1.get_value(size / 2, size / 2);//Get the middle value
                            sumBoth -= center;//Final value would minus that middle value because it's being calculated twice
                            }
                        } else if (matrix_choice == 2){//If they choose matrix 2
                            sumBoth = matrix2.sum_diagonal_major() + matrix1.sum_diagonal_minor();//Calculate the diagonal sum
                            if (size % 2 == 1) {//For the case it's odd number
                            int center = matrix2.get_value(size / 2, size / 2);//Get the middle value
                            sumBoth -= center;//Final value would minus that middle value because it's being calculated twice
                            }
                        } else {
                            throw std::out_of_range("Not a correct value for matrix choice. Please restart and try again");
                        }
                        cout << "Diagonal sum is: " << sumBoth << endl;//Print out the sum to the user
                        break;//Jump out of the switch-case block
                    }
                    case 4: {//Handle swap row funciton
                        int matrix_choice;//Create a placeholder for user to choose the matrix they want
                        int row_from, row_to;//Create a variable to save the 2 row from user
                        cout << "Choose between matrix_1 (1) or matrix(2). Type in the number 1 or 2: " ;
                        cin >> matrix_choice;//Prompt user and get the matrix choice
                        cout << "Enter the first row you want to swap (0-indexed): " ;
                        cin >> row_from;//Prompt user for row 1 choice 
                        cout << "Enter the second row you want to swap (0-indexed): " ;
                        cin >> row_to;//Prompt user for row 2 choice 
                        if (matrix_choice == 1){//If they choose matrix 1 
                            theRealSwapRow(matrix1, row_from, row_to);//Swap the row
                            cout << "Swapped! Here is your output:" << endl;
                            matrix1.print_matrix();//Print out that result matrix to user
                        } else if (matrix_choice== 2){//If they choose matrix 2
                            theRealSwapRow(matrix2, row_from, row_to);//Swap the row
                            cout << "Swapped! Here is your output:" << endl;
                            matrix2.print_matrix();//Print out that result matrix to user
                        }else {
                            throw std::out_of_range("Not a correct value for matrix choice. Please restart and try again");
                        }
                        break;//Jump out of the switch-case block
                    }
                    case 5: {//Handle swap column function
                        int matrix_choice;//Create a placeholder for user to choose the matrix they want
                        int col_from, col_to;//Create a variable to save the 2 col from user
                        cout << "Choose between matrix_1 (1) or matrix(2). Type in the number 1 or 2: " ;
                        cin >> matrix_choice;//Prompt user and get the matrix choice
                        cout << "Enter the first row you want to swap (0-indexed): " ;
                        cin >> col_from;//Prompt user for column 1 choice 
                        cout << "Enter the second row you want to swap (0-indexed): ";
                        cin >> col_to;//Prompt user for column 2 choice 
                        if (matrix_choice == 1){//If they choose matrix 1
                            theRealSwapCol(matrix1, col_from, col_to);//Swap the column
                            cout << "Swapped! Here is your output:" << endl;
                            matrix1.print_matrix();//Print out that result matrix to user
                        } else if(matrix_choice == 2) {//If they choose matrix 2
                            theRealSwapCol(matrix2, col_from, col_to);//Swap the column
                            cout << "Swapped! Here is your output:" << endl;
                            matrix2.print_matrix();//Print out that result matrix to user
                        }else {
                            throw std::out_of_range("Not a correct value for matrix choice. Please restart and try again");
                        }
                        break;//Jump out of the switch-case block
                    }
                    case 6: {//Handle update position function
                        int matrix_choice;//Create a placeholder for user to choose the matrix they want
                        int num, col, row;//Create a variable to save value of column, row and the target value after change
                        cout << "Choose between matrix_1 (1) or matrix(2). Type in the number 1 or 2: " ;
                        cin >> matrix_choice;//Prompt user and get the matrix choice
                        cout << "Enter the row you want to update: " ;
                        cin >> row;//Prompt user for the row
                        cout << "Enter the column you want to update: ";
                        cin >> col;//Prompt user for the column
                        cout << "Enter the value you want to update at that position: " ;
                        cin >> num;//Prompt user for target value to change to
                        if (matrix_choice == 1){//If they choose matrix 1
                            theRealupdateValue(matrix1,row, col, num);//Change the value at that location
                            cout << "Updated! Here is your output:" << endl;
                            matrix1.print_matrix();//Print out that result matrix to user
                        } else if (matrix_choice == 2) {//If they choose matrix 2
                            theRealupdateValue(matrix2,row, col, num);//Change the value at that location
                            cout << "Updated! Here is your output:" << endl;
                            matrix2.print_matrix();//Print out that result matrix to user
                        } else {
                            throw std::out_of_range("Not a correct value for matrix choice. Please restart and try again");
                        }
                        break;//Jump out of the switch-case block
                    }
                }
            printMenu();//Print menu again for user to continue choosing
            std::cin >> choice;//Overwrite the choice variable
            }
        } else if (typeFlag == 1){//Double matrices
            Matrix<double> matrix1(size), matrix2(size);//Create the matrix
            file >> matrix1 >> matrix2;//Read in the matrix

             //Handle user choices from the command line menu
            int choice = 0;//Create a placeholder for user choice
            printMenu();//Print out the menu to the user
            std::cin >> choice;//Listen to user input

            while(choice != 7){//Create a loop to keep asking user until user want to quit
                switch(choice){//Switch-case to navigate the choices
                    case 1: {//Handle the add function
                        Matrix<double> matrix3 = matrix1+matrix2;//Add 2 matrix together
                        matrix3.print_matrix();//Print out that result matrix to user
                        break;//Jump out of the switch-case block
                    }
                    case 2: {//Handle multiply function
                        Matrix<double> matrix3 = matrix1*matrix2;//Multiply 2 matrix together
                        matrix3.print_matrix();//Print out that result matrix to user
                        break;//Jump out of the switch-case block
                    }
                    case 3: {//Handle diagonal sum function
                        int matrix_choice;//Create a placeholder for user to choose the matrix they want
                        double sumBoth;//Create a placeholder for the return value
                        cout << "Choose between matrix_1 (1) or matrix(2). Type in the number 1 or 2: ";
                        cin >> matrix_choice;//Prompt user and get the matrix choice
                        if (matrix_choice == 1){//If they choose matrix 1 
                            sumBoth = matrix1.sum_diagonal_major() + matrix1.sum_diagonal_minor();//Calculate the diagonal sum
                            if (size % 2 == 1) {//For the case it's odd number
                            int center = matrix1.get_value(size / 2, size / 2);//Get the middle value
                            sumBoth -= center;//Final value would minus that middle value because it's being calculated twice
                            }
                        } else if (matrix_choice == 2) {//If they choose matrix 2
                            sumBoth = matrix2.sum_diagonal_major() + matrix1.sum_diagonal_minor();//Calculate the diagonal sum
                            if (size % 2 == 1) {//For the case it's odd number
                            double center = matrix2.get_value(size / 2, size / 2);//Get the middle value
                            sumBoth -= center;//Final value would minus that middle value because it's being calculated twice
                            }
                        } else {
                            throw std::out_of_range("Not a correct value for matrix choice. Please restart and try again");
                        }
                        cout << "Diagonal sum is: " << sumBoth << endl;//Print out the sum to the user
                        break;//Jump out of the switch-case block
                    }
                    case 4: {//Handle swap row funciton
                        int matrix_choice;//Create a placeholder for user to choose the matrix they want
                        int row_from, row_to;//Create a variable to save the 2 row from user
                        cout << "Choose between matrix_1 (1) or matrix(2). Type in the number 1 or 2: " ;
                        cin >> matrix_choice;//Prompt user and get the matrix choice
                        cout << "Enter the first row you want to swap (0-indexed): " ;
                        cin >> row_from;//Prompt user for row 1 choice 
                        cout << "Enter the second row you want to swap (0-indexed): " ;
                        cin >> row_to;//Prompt user for row 2 choice 
                        if (matrix_choice == 1){//If they choose matrix 1 
                            theRealSwapRow(matrix1, row_from, row_to);//Swap the row
                            cout << "Swapped! Here is your output:" << endl;
                            matrix1.print_matrix();//Print out that result matrix to user
                        } else if (matrix_choice == 2) {//If they choose matrix 2
                            theRealSwapRow(matrix1, row_from, row_to);//Swap the row
                            cout << "Swapped! Here is your output:" << endl;
                            matrix2.print_matrix();//Print out that result matrix to user
                        }else {
                            throw std::out_of_range("Not a correct value for matrix choice. Please restart and try again");
                        }
                        break;//Jump out of the switch-case block
                    }
                    case 5: {//Handle swap column function
                        int matrix_choice;//Create a placeholder for user to choose the matrix they want
                        int col_from, col_to;//Create a variable to save the 2 col from user
                        cout << "Choose between matrix_1 (1) or matrix(2). Type in the number 1 or 2: " ;
                        cin >> matrix_choice;//Prompt user and get the matrix choice
                        cout << "Enter the first row you want to swap (0-indexed): " ;
                        cin >> col_from;//Prompt user for column 1 choice 
                        cout << "Enter the second row you want to swap (0-indexed): ";
                        cin >> col_to;//Prompt user for column 2 choice 
                        if (matrix_choice == 1){//If they choose matrix 1
                            theRealSwapCol(matrix1, col_from, col_to);//Swap the column
                            cout << "Swapped! Here is your output:" << endl;
                            matrix1.print_matrix();//Print out that result matrix to user
                        } else if (matrix_choice == 2) {//If they choose matrix 2
                            theRealSwapCol(matrix2, col_from, col_to);//Swap the column
                            cout << "Swapped! Here is your output:" << endl;
                            matrix2.print_matrix();//Print out that result matrix to user
                        }else {
                            throw std::out_of_range("Not a correct value for matrix choice. Please restart and try again");//
                        }
                        break;//Jump out of the switch-case block
                    }
                    case 6: {//Handle update position function
                        int matrix_choice;//Create a placeholder for user to choose the matrix they want
                        int col, row;//Create a variable to save value of column, row and the target value after change
                        double num;
                        cout << "Choose between matrix_1 (1) or matrix(2). Type in the number 1 or 2: " ;
                        cin >> matrix_choice;//Prompt user and get the matrix choice
                        cout << "Enter the row you want to update: " ;
                        cin >> row;//Prompt user for the row
                        cout << "Enter the column you want to update: ";
                        cin >> col;//Prompt user for the column
                        cout << "Enter the value you want to update at that position: " ;
                        cin >> num;//Prompt user for target value to change to
                        if (matrix_choice == 1){//If they choose matrix 1
                            theRealupdateValue(matrix1,row, col, num);//Change the value at that location
                            cout << "Updated! Here is your output:" << endl;
                            matrix1.print_matrix();//Print out that result matrix to user
                        } else if (matrix_choice == 2) {//If they choose matrix 2
                            theRealupdateValue(matrix2,row, col, num);//Change the value at that location
                            cout << "Updated! Here is your output:" << endl;
                            matrix2.print_matrix();//Print out that result matrix to user
                        } else {
                            throw std::out_of_range("Not a correct value for matrix choice. Please restart and try again");
                        }
                        break;//Jump out of the switch-case block
                    }
                }
            printMenu();//Print menu again for user to continue choosing
            std::cin >> choice;//Overwrite the choice variable
        }
    }} catch (const std::exception& ex) {//If there is exception
        std::cerr << "Exception: " << ex.what() << std::endl;//Print it out to user
        return 1;//End the program with error code
    }

    return 0;//End the program
}