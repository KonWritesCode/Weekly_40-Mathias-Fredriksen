#include <iostream>
#include <vector>
#include <conio.h>
#include <string>
#include <stdio.h>
#include <time.h>  


constexpr int vertical{10};
constexpr int horizontal{10};


char table[vertical][horizontal];

int backslashPosY{ 2 };
int backslashPosX{ 7 };

int forwardslashPosY{ 8 };
int forwardslashPosX{ 3 };

int asteriskPositonY;
int asteriskPositonX;

struct People
{
    std::string name;
    long long phoneNumber;
} person[10];

/*struct human 
{
    double height;
};

struct father
{
    long money;
    std::string car;
};

struct child : public father, human
{
    std::string name;
};

//You get 0.1 dollars for each ad shown to the user
float cashPerAdsShown = 0.1f;
//you get 1.5 dollars extra for each ad that was clicked by the user
float cashPerAdsClicked = 1.5f;

struct adverticing 
{
    int adsShown = 24;
    int adsClicked = 3;
    float percentageClicked = (float)adsClicked / (float)adsShown;
    float revenueFromAdsAverage = ((adsClicked * cashPerAdsClicked) + (adsShown * cashPerAdsShown))/adsShown;
    //How many ads was shown to readers
    //What percentage of ads were clicked
    //How much you've earned on average from each ad that was clicked
} youtube;

void advecticingCaclutate() 
{
    std::cout << "Ads Shown to the users today: " << youtube.adsShown << std::endl;
    std::cout << "Percentage of the ads clicked today: " << youtube.percentageClicked * 100 << "%\n";
    std::cout << "Average revenue form ads shown today: " << "$" << youtube.revenueFromAdsAverage << std::endl;
    std::cout << "Total revenue earned today: " << "$" << (youtube.adsClicked * cashPerAdsClicked) + (youtube.adsShown * cashPerAdsShown) << std::endl;
}*/

void Task3()
{
    int amountOfPeople;
    std::cout << "Enter the number of people in a group (1-10): ";
    std::cin >> amountOfPeople;
    
    while (amountOfPeople > 10 || amountOfPeople <= 0 || std::cin.fail())
    {
        std::cout << "That's not a valid number\n";
        std::cin >> amountOfPeople;
    }
    std::cin.clear();
    std::cin.ignore(32767, '\n');

    std::cout << "\nPlease type the name and phone number of each person respectively. \n";
    for(int i = 1; i < amountOfPeople+1; i++)
    {
        std::string inputName;
        long float phoneNumber;

        std::cout << "Person " << i << "'s name: ";
        std::getline(std::cin, inputName);
        std::cin.clear();
        //std::cin.ignore(32767, '\n');

        std::cout << "Person " << i << "'s phone number: ";
        std::cin >> phoneNumber;
        //std::cin.clear();
        std::cin.ignore(32767, '\n');

        person[i].name = inputName;
        person[i].phoneNumber = phoneNumber;
        
        std::cout << std::endl;
    }

    int displayPerson;
    bool exitLoop{false};

    system("cls");
    while (!exitLoop)
    {
        std::cout << "(Type 0 to exit)\n";
        std::cout << "Choose which persons information you'd like to display (1-" << amountOfPeople << "): ";
        std::cin >> displayPerson;

        while (displayPerson > amountOfPeople || displayPerson < 0 || std::cin.fail())
        {
            std::cout << "That's not a valid number\n";
            std::cin >> displayPerson;
        }
        
        system("cls");

        if(displayPerson != 0)
        {
            std::cout << person[displayPerson].name << std::endl;
            std::cout << person[displayPerson].phoneNumber << std::endl;
        }
        else { exitLoop = true; }

        std::cout << std::endl;
    }
}

void DrawBoard() 
{
    int k;

    for (int k = 0; k < vertical; k++)
    {
        for (int i = 0; i < horizontal; i++)
        {
            if (i == asteriskPositonX && k == asteriskPositonY)
            {
                table[k][i] = '*';
            }
            else if(i == backslashPosX && k == backslashPosY)
            {
                table[k][i] = '\\';
            }
            else if (i == forwardslashPosX && k == forwardslashPosY)
            {
                table[k][i] = '/';
            }
            else 
            {
                table[k][i] = '-';
            }

            std::cout << " " << table[k][i];
        }
        std::cout << "\n";
    }
}

void MoveTheAsterisk()
{
    char playerInput;

    while (true)
    {
        system("cls");
        DrawBoard();

        switch (playerInput = _getch())
        {
        case 'w':
            if (table[asteriskPositonY-1][asteriskPositonX] == '\\' && asteriskPositonY > 0 && asteriskPositonX > 0)
            {
                asteriskPositonY--;
                asteriskPositonX--;
            }
            else if (table[asteriskPositonY -1][asteriskPositonX] == '/' && asteriskPositonY > 0 && asteriskPositonX < horizontal-1)
            {
                asteriskPositonY--;
                asteriskPositonX++;
            } 
            else if (asteriskPositonY > 0 && table[asteriskPositonY - 1][asteriskPositonX] != '\\' && table[asteriskPositonY - 1][asteriskPositonX] != '/')
            {
                asteriskPositonY--;
            }
            break;

        case 's':
            if (table[asteriskPositonY + 1][asteriskPositonX] == '\\' && asteriskPositonY < vertical-1 && asteriskPositonX < horizontal-1)
            {
                asteriskPositonY++;
                asteriskPositonX++;
            }
            else if (table[asteriskPositonY + 1][asteriskPositonX] == '/' && asteriskPositonY < vertical - 1 && asteriskPositonX > 0)
            {
                asteriskPositonY++;
                asteriskPositonX--;
            }
            else if (asteriskPositonY < vertical - 1 && table[asteriskPositonY + 1][asteriskPositonX] != '\\' && table[asteriskPositonY + 1][asteriskPositonX] != '/')
            {
                asteriskPositonY++;
            }
            break;

        case 'd':
            if(table[asteriskPositonY][asteriskPositonX + 1] == '\\' && asteriskPositonY < vertical - 1 && asteriskPositonX < horizontal - 1)
            {
                asteriskPositonY++;
                asteriskPositonX++;
            }
            else if (table[asteriskPositonY][asteriskPositonX + 1] == '/' && asteriskPositonY > 0 && asteriskPositonX < horizontal - 1)
            {
                asteriskPositonY--;
                asteriskPositonX++;
            }
            else if (asteriskPositonX < horizontal - 1 && table[asteriskPositonY][asteriskPositonX + 1] != '\\' && table[asteriskPositonY][asteriskPositonX + 1] != '/')
            {
                asteriskPositonX++;
            }
            break;

        case 'a':
            if (table[asteriskPositonY][asteriskPositonX - 1] == '\\' && asteriskPositonY > 0 && asteriskPositonX > 0)
            {
                asteriskPositonY--;
                asteriskPositonX--;
            }
            else if (table[asteriskPositonY][asteriskPositonX - 1] == '/' && asteriskPositonY < vertical - 1 && asteriskPositonX > 0)
            {
                asteriskPositonY++;
                asteriskPositonX--;
            }
            else if (asteriskPositonX > 0 && table[asteriskPositonY][asteriskPositonX - 1] != '\\' && table[asteriskPositonY][asteriskPositonX - 1] != '/')
            {
                asteriskPositonX--;
            }
            break;

        case 'g':
            exit(0);

        default:
            break;
        }
    }
}


void DiceTask()
{
    srand(time(NULL));

    int amountOfSix{ 0 };
    int amountOfDice{ 1 };
    int timesRolled{ 0 };
    std::vector<int> diceNumbers;
    std::vector<bool> diceHeld;

    std::cout << "Choose the amout of dice you'd like to roll: ";
    std::cin >> amountOfDice;
    std::cout << std::endl;

    for(int i = 0; i < amountOfDice; i++)
    {
        diceNumbers.push_back(0);
        diceHeld.push_back(false);
    }

  while (true) 
  {

    //Roll the dice x amount of times
    std::cout << "Dice rolled: ";
    for (int i = 0; i < amountOfDice; i++) 
    {
        //Reroll non held dice
        if (diceHeld.at(i) == false) 
        {
            
            int k = rand() % 6 + 1;
            diceNumbers.at(i) = k;

            if (i != amountOfDice - 1)
            {
                std::cout << diceNumbers.at(i) << ", ";
            }
            else { std::cout << diceNumbers.at(i) << std::endl; }
        }
        else 
        {

            if (i != amountOfDice - 1)
            {
                std::cout << "\033[91m" + std::to_string(diceNumbers.at(i)) + "\033[0m" << ", ";
            }
            else { std::cout << "\033[91m" + std::to_string(diceNumbers.at(i)) + "\033[0m" << std::endl; }
        }
    }
    timesRolled++;

    int totalScore{0};
    //Find total score
    for(int i = 0; i < amountOfDice; i++)
    {
        totalScore += diceNumbers.at(i);

        if(diceNumbers.at(i) == 6)
        {
            amountOfSix++;
        }
    }

    int pairs{ 0 };
    //Find amount of pairs
    std::vector<bool> alreadyFoundPair;
    for(int i = 0; i < amountOfDice; i++)
    {
        alreadyFoundPair.push_back(false);
    }

    for(int i = 0; i < amountOfDice; i++)
    {
        for(int k = i+1; k < amountOfDice; k++)
        {
            if(i != k)
            {
                if (diceNumbers.at(i) == diceNumbers.at(k) && !alreadyFoundPair.at(i) && !alreadyFoundPair.at(k))
                {
                    pairs++;
                    alreadyFoundPair.at(i) = true;
                    alreadyFoundPair.at(k) = true;
                    break;
                }
            }
        }
    }


    std::cout << "\nTotal score: " << totalScore << std::endl;
    std::cout << "Six eyed dice: " << amountOfSix << std::endl;
    std::cout << "Amount of pairs: " << pairs << std::endl;
    std::cout << "Times rolled: " << timesRolled << std::endl;
    
    //diceNumbers.clear();

    //Choose which dice to hold
    int replayInput{1};
    while (replayInput != 0)
    {
        std::cout << "\n(Type '0' to reroll or 'h' to exit)\n";
        std::cout << "Choose which of dice you'd like to hold: ";
        std::cin >> replayInput;

        
        while (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(32767, '\n');

            char exitInput;
            std::cout << "\nAre you sure you'd like to exit?\n";
            std::cout << "(Type 'h' to exit): ";
            std::cin >> exitInput;
            
            if(exitInput == 'h' || exitInput == 'H')
            {
                exit(0);
            }
            else 
            {
                std::cout << "Choose which of dice you'd like to hold: ";
                std::cin >> replayInput;
            }

        }
        while(replayInput > amountOfDice || replayInput < 0)
        {
            std::cout << "Your number is eighter too high or too low\n";
            std::cout << "Choose which of dice you'd like to hold: ";
            std::cin >> replayInput;
        }

        if(replayInput != 0)
        {
            if(diceHeld.at(replayInput -1 ) == false)
            {
                diceHeld.at(replayInput - 1) = true;
            } 
            else 
            {
                diceHeld.at(replayInput - 1) = false;
            }
        }
        else 
        {
            break;
        }

        system("cls");

        //Used to display the dice held
        std::cout << "Dice rolled: ";
        for (int j = 0; j < amountOfDice; j++)
        {
            if (j != amountOfDice - 1)
            {
                if (diceHeld.at(j) == true)
                {
                    //red text to display which dice are held
                    std::cout << "\033[91m" + std::to_string(diceNumbers.at(j)) + "\033[0m" << ", ";
                }
                else
                {
                    std::cout << diceNumbers.at(j) << ", ";

                }
            }
            else 
            {
                if (diceHeld.at(j) == true)
                {
                    //red text to display which dice are held
                    std::cout << "\033[91m" + std::to_string(diceNumbers.at(j)) + "\033[0m" << std::endl;
                }
                else
                {
                   std::cout << diceNumbers.at(j) << std::endl;
    
                }
            }
        }
        std::cout << std::endl;

    }
    amountOfSix = 0;
    totalScore = 0;
    pairs = 0;
    alreadyFoundPair.clear();
    system("cls");

  }
}

void CapitalLetters()
{
    std::vector<char> charSentence;
    std::string textSentence;

    std::cout << "Type in a sentence: ";
    std::getline(std::cin, textSentence);

    std::cout << "Converted sentence: ";
    for (int i = 0; i < textSentence.length(); i++)
    {
        charSentence.push_back(toupper(textSentence[i]));

        std::cout << charSentence[i];
    }
    std::cout << std::endl;
}

/*
void swap(int* a, int* b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void pointers()
{

    int a = 10;
    int b = 20;
    
    

    std::cout << "a: " << a << ". b: " << b <</* ". c: " << c << ".\n";
}*/

int main(int)
{
    int chosenTask;
    do
    {
        system("cls");

        std::cout << "TASKS\n1. Capital Letters\n2. Move the astersk\n3. People and Structs\n4. Dice roller\n\nChoose a task: ";
        std::cin >> chosenTask;
        switch (chosenTask)
        {
        case 1:
            CapitalLetters();
            break;
    
        case 2:
            MoveTheAsterisk();
            break;

        case 3:
            Task3();
            break;

        case 4:
            DiceTask();
            break;

        default:
            break;
        }
    } while (true);
}