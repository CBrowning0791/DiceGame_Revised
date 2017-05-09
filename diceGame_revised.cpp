/*C++ program built to semi-replicate playing dice poker from the witcher 2*/
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <vector>
#include <string>

//checks players hand for score/hand
std::string handCheck(int array[]); 

//array to display the 'hand' to the player and asks them to select what to keep
void handKeeper(int hand[], std::vector<int> keepList);

//Various small functions to check hands//
bool fiveOfAKind(int array[]);
bool fourOfAKind(int array[]);
bool fullHouse(int array[]);
bool threeOfAKind(int array[]);
bool pair(int array[]);
bool straight(int array[]);
bool twoPair(int array[]);

//Sorting
void bubbleSort(int array[]);

int main(void)
{
    int diceHand [5];
    std::vector<int> handKeep (5,0);
    srand(time(NULL));
    diceHand[0] = rand() %6 + 1;
    diceHand[1] = rand() %6 + 1;
    diceHand[2] = rand() %6 + 1;
    diceHand[3] = rand() %6 + 1;
    diceHand[4] = rand() %6 + 1;
    bubbleSort(diceHand);
    handKeeper(diceHand,handKeep);
    //std::cout << handCheck(diceHand);
    std::cout << diceHand[0] << diceHand[1] << diceHand[2] << diceHand[3] << diceHand[4] << std::endl;


}

std::string handCheck(int array[])
{
    int sortingHand[5];
    for(int x = 0; x<5; x++)
    {
        sortingHand[x] = array[x];
    }
    
    /*sortingHand[0] = 2;
    sortingHand[1] = 3;
    sortingHand[2] = 3;
    sortingHand[3] = 4;
    sortingHand[4] = 6;*/

    /*for(int x = 0; x<5; x++)
    {
        std::cout << array[x] << " " << sortingHand[x] << std::endl;
    }*/
    
    if(fiveOfAKind(sortingHand) == true)
        return "five";
    if(fourOfAKind(sortingHand) == true)
        return "four";
    if(straight(sortingHand) == true)
        return "straight";
    if(threeOfAKind(sortingHand) == true)
        if(fullHouse(sortingHand) == true)
            return "house";
        else
            return "three";
    if(twoPair(sortingHand) == true)
        return "twoPair";
    if(pair(sortingHand) == true)
        return "pair";

  return "Nothing special";
}

void handKeeper(int hand[], std::vector<int> keepList)
{
    
    std::string enteredLine;
    enteredLine = "default";
    std::cout << "This is your hand: " << hand[0] << " , " << hand[1] << " , " << hand[2] << " , " << hand[3] << " , " << hand[4] << std::endl;
    std::cout << "You currently have a: " << handCheck(hand) << std::endl;
    keepList.clear();
    while(enteredLine.compare("x") != 0)
    {
        std::cout << "Enter the dice would you like to keep for the next round one at a time. When finished enter 'x': ";
        std::cin >> enteredLine;
        keepList.push_back(std::stoi(enteredLine));
    }
    std::cout << keepList[0] << " "<< keepList[1] << " "<< keepList[2] << " "<< keepList[3] << " "<< keepList[4] << " " << std::endl;
}

//These are the scoring functions. Fully tested given the possible hands that can be thrown and sorted.

bool fiveOfAKind(int array[])
{
    for(int x = 0; x<4; x++)
        if(array[x] != array[x+1])
        {
            return false;
        }
    return true;
}

bool fourOfAKind(int array[])
{
    bool frontFour = true;
    bool backFour = true;
    for(int x = 0; x<3; x++)
        if(array[x] != array[x+1])
            frontFour = false;
    for(int y = 4; y>1; y--)
    {
        if(array[y] != array[y-1])
            backFour = false;
    }
    if(frontFour == false && backFour == false)
        return false;
    return true;
}

bool fullHouse(int array[])
{
   // std::cout << "I made it into the fullhouse \n";
    if(array[0] == array[1] && array[1] != array[2])
        return true;
    if(array[4] == array[3] && array[3] != array[2])
        return true;
    return false;
}

bool threeOfAKind(int array[])
{
    if(array[0] == array[1] && array[1] == array[2])
        return true;
    if(array[1] == array[2] && array[2] == array[3])
        return true;
    if(array[2] == array[3] && array[3] == array[4])
        return true;
    return false;
}

bool pair(int array[])
{
    if(array[0] == array[1] || array[1] == array[2] || array[2] == array[3] || array[3] == array[4])
        return true;
    return false;
}

bool straight(int array[])
{
    if(array[0]+1 == array[1] && array[1]+1 == array[2] && array[2]+1 == array[3] && array[3]+1 == array[4])
        return true;
    else
        return false;
}

bool twoPair(int array[])
{
    if(array[0] == array[1])
        {
        if(array[2] == array[3])
            return true;
        else if(array[3] == array[4])
            return true;
        }
    else if(array[1] == array[2])
        {
        if(array[3] == array[4])
            {   
            return true;
            }
        }
    return false;
}

//Sorting

void bubbleSort(int array[])
{
    int n;
    for(int x = 0; x<5; x++)
    {
        for (int y = 0; y<4; y++)
            if (array[y] > array[y+1])
            {
            n = array[y];
            array[y] = array[y+1];
            array[y+1] = n;
            
            }

    }
}