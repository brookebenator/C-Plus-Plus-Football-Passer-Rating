/******************************************************************************
Name: Brooke Benator
Date: 2/26/2024
Assignment: Homework 4
Due Date: 2/26/2024
Section: 6
About this project: This homework practices how to use loops, as well as if statements, counters, and
focuses on functions
Assumptions: User inputs positive values/0 into the program, as well as accurate numbers that are probable

All work below was performed by Brooke Benator 

*******************************************************************************/
#include <iostream>
#include <iomanip>
using namespace std;

//declares welcome message function
void welcomeMessage(); 
//declares passer rating function
double getPasserRating(double, double, double, double, double);


int main()
{
    char choice = 'Y'; 'y'; 'n'; 'N';   //choices the user may input
    double counter = 1;                 //counts how many pairs of players the user compares 
    double difference;                  //difference between ratings
    double perfectrating = 158.3;       //amount of a perfect rating
    
    //amounts user will input for each players stats
    double passingattemptsA, completionsA, yardsA, tdpassesA, interceptionsA;
    double passingattemptsB, completionsB, yardsB, tdpassesB, interceptionsB;
    
    welcomeMessage();                   //calls welcome message
    
    do                                  //loop starts to compare two players
    {
    cout << "Enter single game information for Player A:" << endl;
    
    //user inputs information for player A
    
    cout << "Attempts: ";
    cin >> passingattemptsA;
    cout << "Completions: ";
    cin >> completionsA;
    cout << "Passing Yards: ";
    cin >> yardsA;
    cout << "Touchdowns: ";
    cin >> tdpassesA;
    cout << "Interceptions: ";
    cin >> interceptionsA;
    cout << endl;
    
 
    //user inputs information for player B
    
    cout << "Enter single game information for Player B:" << endl;
    cout << "Attempts: ";
    cin >> passingattemptsB;
    cout << "Completions: ";
    cin >> completionsB;
    cout << "Passing Yards: ";
    cin >> yardsB;
    cout << "Touchdowns: ";
    cin >> tdpassesB;
    cout << "Interceptions: ";
    cin >> interceptionsB;
    
    cout << fixed << showpoint << setprecision(1);   //sets decimals to 1 place 
    cout << endl;
    cout << "Player A's single game passer rating: ";
    
    //calls passer rating for player A and avoids division by 0
    if (getPasserRating(passingattemptsA, completionsA, yardsA, tdpassesA, interceptionsA) > 0)
        cout << getPasserRating(passingattemptsA, completionsA, yardsA, tdpassesA, interceptionsA);
    else 
        cout << "0.0";
    cout << endl;
    
    cout << "Player B's single game passer rating: ";
    
    //calls passer rating for player B and avoids division by 0
    if (getPasserRating(passingattemptsB, completionsB, yardsB, tdpassesB, interceptionsB) > 0)
        cout << getPasserRating(passingattemptsB, completionsB, yardsB, tdpassesB, interceptionsB);
    else 
    cout << "0.0";
    
    //computes difference between the two scores
    difference = getPasserRating(passingattemptsA, completionsA, yardsA, tdpassesA, interceptionsA) 
    - getPasserRating(passingattemptsB, completionsB, yardsB, tdpassesB, interceptionsB);
    
    //if statement displays which player scored higher and their rating difference
    if(getPasserRating(passingattemptsA, completionsA, yardsA, tdpassesA, interceptionsA) 
    > getPasserRating(passingattemptsB, completionsB, yardsB, tdpassesB, interceptionsB))
    {
        cout << endl;
        cout << "Player A was better than Player B by a difference of ";
        cout << difference;                     //does not allow negative numbers
            if(difference < 0)
                difference = difference * -1;
        cout << endl;
        cout << endl;
    }
    else if (getPasserRating(passingattemptsA, completionsA, yardsA, tdpassesA, interceptionsA) 
    < getPasserRating(passingattemptsB, completionsB, yardsB, tdpassesB, interceptionsB))
    {
        cout << endl;
        cout << "Player B was better than Player A by a difference of ";
        if(difference < 0)                      //does not allow negative numbers
                difference = difference * -1;
        cout << difference;
        cout << endl;
    }
    
    //if player A and B have the same rating the difference is not calculated
    else 
    {
        cout << endl;
        cout << "Player A and B have the same rating!";
        cout << endl;
    }
    
    //displays only if player A has a perfect passer rating
    if(getPasserRating(passingattemptsA, completionsA, yardsA, tdpassesA, interceptionsA) >= perfectrating
    && (getPasserRating(passingattemptsB, completionsB, yardsB, tdpassesB, interceptionsB) < perfectrating))
    {
        cout << "Player A had a PERFECT passer rating.";
        cout << endl;
    }
    
    //displays only if player B has a perfect passer rating
    if(getPasserRating(passingattemptsB, completionsB, yardsB, tdpassesB, interceptionsB) >= perfectrating
    && (getPasserRating(passingattemptsA, completionsA, yardsA, tdpassesA, interceptionsA) < perfectrating))
    {
        cout << endl;
        cout << "Player B had a PERFECT passer rating.";
        cout << endl;
    }
    
    //displays if both player A and B have a perfect passer rating
    if((getPasserRating(passingattemptsA, completionsA, yardsA, tdpassesA, interceptionsA) >= perfectrating
    && (getPasserRating(passingattemptsB, completionsB, yardsB, tdpassesB, interceptionsB) >= perfectrating)))
    {
        cout << endl;
        cout << "Player A had a PERFECT passer rating.";
        cout << endl;
        cout << "Player B had a PERFECT passer rating.";
        cout << endl;
    }
    
    cout << endl;
    cout << "Would you like to compare another pair of players? (Y or N): ";
    cin >> choice;      //user inputs yes or no if they want to compare another player
        if(choice == 'Y' || choice == 'y')
        {
            cout << endl;
            counter++;  //if user compares another set, the counter of pairs increases by 1
        }
    
    
    }while(choice == 'y' || choice == 'Y');       //loop repeats while user wants to compare
    
    //invalid message appears if user enters anything other than Y/N
    if(choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N')
        cout << "Invalid entry. Exiting program...";
    
    //when user does not want to compare again, number of compares will display    
    if(choice == 'N' || choice == 'n')
    {
        cout << "You compared ";
        if (counter > 1)
            cout << static_cast<int>(counter) << " pairs of players."; //for more than 1 pair compared
        else if (counter == 1)
            cout << "1 pair of players.";                              //for only 1 pair compared
    }    

    return 0;
}

void welcomeMessage() //this function displays the welcome message and requirements for a perfect rating
{
    cout << "Welcome to the NFL Quarterback Passer Rating Calculator!" << endl;
    cout << "A perfect passer rating (158.3) requires at least:" << endl;
    cout << "77.5% completion percentage" << endl;
    cout << "12.5 yards per attempt" << endl;
    cout << "11.875% touchdown % per attempt" << endl;
    cout << "No interceptions" << endl;
    cout << endl;
}

//in this section the numbers the user
//inputs are passed into the function where the player rating is calcualted

double getPasserRating(double passingattempts, double completions, double yards, 
double tdpasses, double interceptions)
{
    double a, b, c, d;
    double astat, bstat, cstat, dstat, passerrating;
    
    //equations for each part of final formula
    a = ((completions/passingattempts) - .3) * 5;
    b = ((yards/passingattempts) - 3) * .25;
    c = (tdpasses/passingattempts) * 20;
    d = (2.375 - ((interceptions/passingattempts) * 25));
    
    
    //gives each letter their corresponding value based on a, b, c, and d
    if (a > 2.375)
        astat = 2.375;
    else if (a < 0)
        astat = 0;
    else astat = a;
    if (b > 2.375)
        bstat = 2.375;
    else if (b < 0)
        bstat = 0;
    else
        bstat = b;
    if (c > 2.375)
        cstat = 2.375;
    else if (c < 0)
        cstat = 0;
    else
        cstat = c;
    if (d > 2.375)
        dstat = 2.375;
    else if (d < 0)
        dstat = 0;
    else
        dstat = d;

    //final formula for passer rating    
    passerrating = ((astat + bstat + cstat + dstat) / 6) * 100;
    //returns the passer rating to the called function
    return passerrating;
    
}
















