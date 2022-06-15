//Danny Castaneda 246398. SP21 Object Oriented Program. Assignement #2

#include<iostream>
#include<string>
using namespace std;


int wordCounter(string str) //takes in a string as a parameter and returns the
			    //number of words in the string
{
    int word_count{0};
    
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
            word_count++;    
    }
    return word_count+1;  
}


int vowelCounter(string str) //takes in a string as a parameter and returns the total
			     //number of vowels in the string.
 
{ 
    int vowel_count{0};
    
    
    for(int i=0; i < str.length(); i++)  
    {
        if(str[i]=='a'|| str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u'||str[i]=='A'||str[i]=='E'||str[i]=='I'||str[i]=='O' ||str[i]=='U')
        {
          vowel_count++;
        }
    }
   return vowel_count;
}


int puncCount(string str) //takes in a string as a parameter and returns the number
			  //of punctuation characters in the string
{
    int punc_count{0};
    
     
    for (int i=0; i < str.length(); i++) {
        if (ispunct(str[i])) {  
            punc_count++; 
      }
    }
    return punc_count;
}


bool findSubString(string str) //takes in a string as a parameter and returns 1 if the
			      //string ”you” exists in the string and 0 if it is not

{
    if (str.length() >= 3) {
        
        for (int i=0; i <= str.length()-3; i++) {
            if (str[i] == 'y' && str[i+1] == 'o' && str[i+2] == 'u') {
                return 1;
            }
        }
        return 0;
    }
    else {
        return 0;
    }
}

int main ()  //inputs the string from the user. Then, prints all the four statistics based on this
	     //input string

{ 
    string str{};
    
    
    cout << "Enter the input string: ";
    getline(cin, str);  
    
    cout << "Number of words: " << wordCounter(str) << endl;
    
    cout << "Number of vowels: " << vowelCounter(str) << endl;
    
    cout << "Number of punctuations: " << puncCount(str) << endl;
    
    if (findSubString(str)) 
	{
           cout << "'you' is a part of this string." << endl;
	}
    else {
           cout <<  "'you' is not a part of this string." << endl;
   	 }
    
    
    return 0;
}