#include <iostream>
#include <string>
#include <cctype>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <sstream>
using namespace std;


//tests if function has punctuation at end and returns bool value                                                 
bool hasPunct(string word){
  char lastChar = word.at(word.size() - 1);                                                                                             
  if(ispunct(lastChar)){
    return true;
  }
  return false;

}



//breaks line into words which are scrambled                                                                      
string breakLine(string input){

  stringstream ss (input);
  string word;
  string lineOut;

  while(ss >> word){
    int size = word.size();
    if(hasPunct(word) == true){
      size -= 1;
      if(size <= 3){
        lineOut += word + " ";
      }
      else
        lineOut += shuffle(word, size) + " ";
    }

    if(hasPunct(word) == false){
      if(word.length() <= 3)
        lineOut += word + " ";
      else
        lineOut +=  shuffle(word, word.size()) + " ";
    }

  }

  return lineOut;
}



//shuffle algorithm                                                                     
string shuffle(string line, int size){
  int temp, swapTarget;
  for(int i = size - 2; i > 1; i--){
    swapTarget = rand() % i + 1;
    temp = line[i];
    line[i] = line[swapTarget];
    line[swapTarget] = temp;
  }
  return line;

}




int main(){
 
  srand(time(0));                                                                                    

  string input;

  while(getline(cin, input))
	cout << breakLine(input) << endl;

  return 0;
}


