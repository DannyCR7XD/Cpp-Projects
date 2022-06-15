//Danny Castaneda 246398 Assignment #4 Object Oriented Programming
//
// Determine whether a square is magic or not.
//A C++ class that represents a square matrix, this class should contain the following
//declarations:
//• A constructor that sets the size of the square,
//• A function to read values into the square,
//• A function to print the square,
//• A function to find the sum of a given row,
//• A function to find the sum of a given column,
//• A function to find the sum of the main (or other) diagonal,
//• A function to determine whether the square is magic or not.




#include<iostream>
using namespace std;

const int MAX_SIZE = 10; 

class Square {
      
    
    int Size;
    int square[MAX_SIZE][MAX_SIZE];
    
    public:
    
    Square(int size){
        
        
        Size = size;
    }
    
    
    int sumRow(int row){
        
        int sum = 0;
        
        
        for(int j=0; j<Size; j++)
        {
            sum += square[row][j];
        }
        
        return sum;
    }
    
    
    int sumCol(int col){
        
        int sum = 0;
        
        
        for(int i=0; i<Size; i++)
        {
            sum += square[i][col];
        }
        
        return sum;
    }
    
    
    int sumMain(){
        
        int sum = 0;
        
        
        for(int i=0, j=0; i < Size && j < Size; i++,j++)
        {
            sum+= square[i][j];
        }
        
        return sum;
    }
    
    
    int sumOther(){
        
        int sum = 0;
        
        
        for(int i=0, j=Size-1; i < Size && j >= 0; i++,j--)
        {
            sum+= square[i][j];
        }
        
        return sum;
        
    }
    
   
    bool magic(){
     
        int sumOfRow = sumRow(0);
        
       
        for(int i=0; i<Size; i++)
        {
            if(sumOfRow != sumRow(i) || sumOfRow != sumCol(i))
            {
                return false;
            }
        }
        
       
        if(sumOfRow != sumMain() || sumOfRow != sumOther())
        {
            return false;
        }
        
        return true;
    }
    
    
    void readSquare(){

	cout << "Next input integers to represent in the square matrix: \n";
        
        for(int i=0; i<Size; i++)
        {
            for(int j=0; j<Size; j++)
            {
                cin >> square[i][j];
            }
        }
        
    }
    
    
    void printSquare(){

        
	for(int i=0; i<Size; i++)
        {
            for(int j=0; j<Size; j++)
            {
                cout << square[i][j] << " ";
            }
            cout << "\n";
        }
        
    }
};

int main()
{
    int size;
    
    cout << "Input Size: ";
    
    cin >> size;
    
    Square* square = new Square(size);
    
   
    square->readSquare();
    
    cout << "\n";

    square->printSquare();
    
    
    if(square->magic())
    {
        cout << "TRUE\n";
    }
    else
    {
        cout << "ELSE\n";
    }
}
