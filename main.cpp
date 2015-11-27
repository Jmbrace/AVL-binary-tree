#include <fstream>
#include <iostream>
#include <string>
#include <locale>
#include <cstdlib>
#include "binaryTree.h"
#include <time.h>

int main(int argc, char *argv[]){
  std::fstream fs, ts; 
  binaryTree tree;
  fs.open("english.o");
  //ts.open("sortedListOfWords.txt"); 
  if(fs.is_open())
  {  std::locale loc;
  	 std::string temp = " ";
  	 fs >> temp;
  	 while(!fs.eof())
  	  {
        for(int i = 0; i < temp.size(); i++){
      	  temp[i] = std::tolower(temp[i],loc);//puts everything to lowercase 
      }
        if(!(temp.find('\'')>temp.size()))
          temp = temp.erase(temp.find('\''),1);//get rid of apostrophes in words
       //if insert word returns true, if true write it to the file
        if(tree.addWord(temp)){//add word to tree 
  	      //std::cout <<temp << std::endl;
          //ts << temp << std::endl; Here I wrote to a file so that I could sort it and
          //each line number corresponds to a rank
        }
  	    fs >> temp;
  	  }
  }
  srand (time(NULL));
  char input = 's';
  int rank = 0;
  int sizeOfTree = tree.getNumberOfWords();
  while(input!='Q' && input!='q')
  {
    std::cout << "Enter 'R' to input a rank, 'W' to print the word of the day, or press 'Q' to quit: " << std::endl;
    std::cin >> input;
    if(input == 'R' ||input == 'r' )
    {
      std::cout << "Enter an integer: "<< std::endl;
      std::cin >> rank;
      if(tree.validRank(rank))
        std::cout << "The word with rank " << rank << " is " << tree.getWordOfDay(rank)<<std::endl;
      else
      {
        std::cout << "The given rank, " << rank << " is out of bounds" <<std::endl;
        continue;
      }  
        
    }
    if(input == 'W'|| input == 'w' )
    {
      rank = std::rand()%sizeOfTree + 1;
      std::cout << "The word of the day has rank " << rank << " and is " << tree.getWordOfDay(rank)<<std::endl;
    }
  }
  return 0;
}