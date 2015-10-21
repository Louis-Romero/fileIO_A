//Louis Paul Romero
//October 20, 2015
//File Read and Write Assignment 1

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cctype>

using namespace std;

int main ()
{   
    ifstream fin, finCap;
    ofstream fout, foutUpper, foutCapital;
   
    fin.open("gba.txt");
    finCap.open("gba.txt");
    fout.open("results.txt");
    foutUpper.open("uppercase.txt");
    foutCapital.open("capitalize.txt");
    
    string valA, wordNoPunct, wordCapitalized, allUpper, makeUpper, upperWord;
    double counter = 0, averageCharacters;
    int sum = 0, numberLetters, minusFromWordCount = 0, totalNumWords, oneLetterWords = 0, twoLetterWords = 0, threeLetterWords = 0, fourLetterWords = 0, fiveLetterWords = 0, sixLetterWords = 0, sevenLetterWords = 0, eightLetterWords = 0, nineLetterWords = 0, tenLetterWords = 0, elevenOrMoreLetterWords = 0, twelveLetterWords =0; 
    char individualLetter, upperFirst, individualMakeUpper;
   
    if(fin.fail())
    {
        cout << "Error opening input file!" << endl;
        exit(1);
    }
    
    if(finCap.fail())
    {
        cout << "Error opening input file!" << endl;
        exit(1);
    }
    
    if(fout.fail())
    {
        cout << "Error opening output file!" << endl;
        exit(1);
    }
    
    if(foutUpper.fail())
    {
        cout << "Error opening output file!" << endl;
        exit(1);
    }
    
    if(foutCapital.fail())
    {
        cout << "Error opening output file!" << endl;
        exit(1);
    }
    
    while(finCap >> makeUpper)
    {
        for(int ix = 0; ix < makeUpper.length(); ix++)
        {
                individualMakeUpper = toupper(makeUpper[ix]);
                upperWord = upperWord + individualMakeUpper;
        }
       foutCapital << upperWord << " ";
       upperWord = "";
    }//end of while
    
    while(fin >> valA)
    {
        upperFirst = toupper(valA[0]); 
        wordCapitalized = upperFirst + valA.substr(1, valA.length() - 1) + " ";
        foutUpper << wordCapitalized;
       
        for(int ix = 0; ix < valA.length(); ix++)
        {
            if(valA[valA.length()-1] == ',' || valA[valA.length()-1] == '.')
            {
              numberLetters = valA.length()-1;  
            } 
            else if(valA == "--")
            {
                numberLetters = 0;
            }
            else
            {
                numberLetters = valA.length();
            } 
        }//end of for loop
        
        sum = sum + numberLetters;
       
        if(numberLetters == 1)
        {
            oneLetterWords++;
        }
        if(numberLetters == 2 && valA != "--")
        {
            twoLetterWords++;
        }
        if(valA == "--")
        {
            minusFromWordCount++;
        }
        if(numberLetters == 3)
        {
            threeLetterWords++;
        }
        if(numberLetters == 4)
        {
            fourLetterWords++;
        }
        if(numberLetters == 5)
        {
            fiveLetterWords++;
        }
        if(numberLetters == 6)
        {
            sixLetterWords++;
        }
        if(numberLetters == 7)
        {
            sevenLetterWords++;
        }
        if(numberLetters == 8)
        {
            eightLetterWords++;
        }
        if(numberLetters == 9)
        {
            nineLetterWords++;
        }
        if(numberLetters == 10)
        {
            tenLetterWords++;
        }
        
        if(numberLetters > 11)
        {
            elevenOrMoreLetterWords++;
        }    
        counter++;
    }//end of while loop
    
    totalNumWords = counter - minusFromWordCount;
    averageCharacters = sum/totalNumWords;
    
    fout << "The average characters per word is " << averageCharacters << endl;
    fout << oneLetterWords << " words of length 1" << endl;
    fout << twoLetterWords << " words of length 2" << endl;
    fout << threeLetterWords << " words of length 3" << endl;
    fout << fourLetterWords << " words of length 4" << endl;
    fout << fiveLetterWords << " words of length 5" << endl;
    fout << sixLetterWords << " words of length 6" << endl;
    fout << sevenLetterWords << " words of length 7" << endl;
    fout << eightLetterWords << " words of length 8" << endl;
    fout << nineLetterWords << " words of length 9" << endl;
    fout << tenLetterWords << " words of length 10" << endl;
    fout << elevenOrMoreLetterWords << " words of length 11 or longer" << endl;
    fout << "The number of words in the file is " << totalNumWords << endl;
    
    fin.close();
    finCap.close();    
    fout.close();
    foutCapital.close();
    foutUpper.close();
    
    return 0;
}

