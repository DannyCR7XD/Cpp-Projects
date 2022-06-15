#include<iostream>
#include<iomanip>
using namespace std;

int main(){
  
   //initialize interest rate and loan rates as well as the montly earned income variables
   double loan,intRate,monPay;
   double monthlyRate,totalInterest,monthlyInterest,balance;
   int count = 0;
  
   //Prompts user to enter amount to represent the loan
   cout << "Loan: ";
   cin >> loan;
  
   //Requests user for interest rate
   cout << "Yearly Interest Rate: ";
   cin >> intRate;
  
   //Requests user for Monthly payments earned
   cout << "Monthly payment: ";
   cin >> monPay;
  
   //Calculates monthly rate
   monthlyRate = intRate / 12;
   balance = loan;
   totalInterest = 0;
  
   //shows output 
  
   cout << endl << left << setw(40) << "Initial Loan: " << fixed << setprecision(0) << loan << endl;
   cout << left << setw(40) << "Monthly Interest: " << setprecision(2) << monthlyRate << "%" << endl;
   cout << left << setw(40) << "Monthly Payment: " << setprecision(0) << monPay << endl << endl;
  
   //Diplays remaining loan and monthly interest paid for each month
   cout << left << setw(15) << " Month" << left << setw(18) << "Remaining Loan" << "Amount of interest due per month" << endl;  
   while(balance > 0){
       //Monthly interest amount
       monthlyInterest = (balance * (monthlyRate/100));
       //Accumulated monthly interest amount
       totalInterest += monthlyInterest;              
       cout << right << setw(4) << ++count << right << setw(21) <<
           setprecision(2) << balance << right << setw(26) << setprecision(4) << monthlyInterest << endl;
       //Whats remaining of loan
       balance -= (monPay - monthlyInterest);
      
   }
   //Displays total interest paid
   cout << endl << left << setw(44) << "Total amount of interest paid: " << setprecision(4) << totalInterest << endl;
  
}