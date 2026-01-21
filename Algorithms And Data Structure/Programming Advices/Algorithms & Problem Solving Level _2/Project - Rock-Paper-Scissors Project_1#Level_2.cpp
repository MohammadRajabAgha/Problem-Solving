#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

enum enGameChoice { Stone = 1, Paper = 2, Scissors = 3 };

enum enWinner { Player1 = 1, Computer = 2, Draw = 3 };

struct stRoundInfo
{
    short RoundNumber = 0;
    enGameChoice Player1Choice;
    enGameChoice ComputerChoice;
    enWinner Winner;
    string WinnerName;
};

struct stGameResults
{
    short GameRounds = 0;
    short Player1WinTimes = 0;
    short ComputerWinTimes = 0;
    short DrawTimes = 0;
    enWinner GameWinner;
    string WinnerName = "";
};

short RandomNumber(short From, short To)
{
    short RandomNumber = 0;

    RandomNumber = From + rand() % (To - From + 1);

    return RandomNumber;
}

short ReadHowManyRounds()
{
    short NumberOfRounds = 1;

    do
    {
        cout << "How Many Rounds 1 to 10\n";
        cin >> NumberOfRounds;

    } while (NumberOfRounds < 1 || NumberOfRounds > 10);

    return NumberOfRounds;
}

enGameChoice GetComputerChoice()
{
    return enGameChoice(RandomNumber(1, 3));
}

enWinner WhoWinTheRound(stRoundInfo RoundInfo)//important.
{

    if (RoundInfo.Player1Choice == RoundInfo.ComputerChoice)
        return enWinner::Draw;

    switch (RoundInfo.Player1Choice)
    {
    case enGameChoice::Stone:
        if (RoundInfo.ComputerChoice == enGameChoice::Paper)
        {
            return enWinner::Computer;
        }
        break;

    case enGameChoice::Paper:
        if (RoundInfo.ComputerChoice == enGameChoice::Scissors)
        {
            return enWinner::Computer;
        }
        break;

    case(enGameChoice::Scissors):
        if (RoundInfo.ComputerChoice == enGameChoice::Stone)
        {
            return enWinner::Computer;
        }
        break;
    }

    return enWinner::Player1;
}

string WinnerName(enWinner Winner)
{
    string ArrWinnerName[3] = { "Player1","Computer","No Winner (Draw)" };
    return ArrWinnerName[Winner - 1];
}

enWinner WhoWinTheGame(short Player1WinTimes, short ComputerWinTimes)
{
    if (Player1WinTimes > ComputerWinTimes)
        return enWinner::Player1;
    else  if (ComputerWinTimes > Player1WinTimes)
        return enWinner::Computer;
    else
        return enWinner::Draw;
}

stGameResults FillGameResults(int GameRounds, short Player1WinTimes, short ComputerWinTimes, short DrawTimes)
{
    stGameResults GameResults;

    GameResults.GameRounds = GameRounds;
    GameResults.Player1WinTimes = Player1WinTimes;
    GameResults.ComputerWinTimes = ComputerWinTimes;
    GameResults.DrawTimes = DrawTimes;
    GameResults.GameWinner = WhoWinTheGame(Player1WinTimes, ComputerWinTimes);
    GameResults.WinnerName = WinnerName(GameResults.GameWinner);

    return GameResults;
}

string ChoiceName(enGameChoice Choice)//important.
{
    string ArrGameChoice[3] = { "Stone", "Paper", "Scissors" };
    return ArrGameChoice[Choice - 1];
}

void SetWinnerScreenColor(enWinner Winner)
{
    switch (Winner)
    {
    case enWinner::Player1:
        system("color 2F");//Green.
        break;

    case enWinner::Computer:
        system("color 4F");//Red.
        cout << "\a";
        break;

    default:
        system("color 6F");//Yellow.
        break;
    }
}

enGameChoice ReadPlayer1Choice()
{
    short Choice = 0;
    do
    {
        cout << "Your Choice:[1]:Stone, [2]:Paper, [3]:Scissors ? ";
        cin >> Choice;

    } while (Choice < 1 || Choice>3);

    return enGameChoice(Choice);
}

void PrintRoundResult(stRoundInfo RoundInfo)
{
    cout << "\n____________ Round [" << RoundInfo.RoundNumber << "] ____________\n\n";
    cout << "Player1  Choice : " << ChoiceName(RoundInfo.Player1Choice) << endl;
    cout << "Computer Choice : " << ChoiceName(RoundInfo.ComputerChoice) << endl;
    cout << "Round Winner    :[" << RoundInfo.WinnerName << "]\n";
    cout << "_________________________________________\n" << endl;

    SetWinnerScreenColor(RoundInfo.Winner);
}

stGameResults PlayAllRounds(short HowManyRounds)
{
    stRoundInfo RoundInfo;
    short Player1WinTimes = 0, ComputerWinTimes = 0, DrawTimes = 0;

    for (short GameRound = 1; GameRound <= HowManyRounds; GameRound++)
    {
        cout << "\nRound [" << GameRound << "] begins:\n\n";
        RoundInfo.RoundNumber = GameRound;
        RoundInfo.Player1Choice = ReadPlayer1Choice();
        RoundInfo.ComputerChoice = GetComputerChoice();
        RoundInfo.Winner = WhoWinTheRound(RoundInfo);
        RoundInfo.WinnerName = WinnerName(RoundInfo.Winner);


        //Increases Win/Draw Counters.
        if (RoundInfo.Winner == enWinner::Player1)
            Player1WinTimes++;
        else if (RoundInfo.Winner == enWinner::Computer)
            ComputerWinTimes++;
        else
            DrawTimes++;


        PrintRoundResult(RoundInfo);
    }

    return FillGameResults(HowManyRounds, Player1WinTimes, ComputerWinTimes, DrawTimes);
}

string Tabs(short NumberOfTabs)
{
    string t = "";

    for (int i = 1; i <= NumberOfTabs; i++)
    {
        t = t + "\t";
    }
    return t;
}

void ShowGameOverScreen()
{
    cout << Tabs(2) << "____________________________________________________________\n\n";
    cout << Tabs(2) << "                    +++Game Over+++                    \n";
    cout << Tabs(2) << "____________________________________________________________\n\n";

}

void ShowFinalGameResult(stGameResults GameResults)
{
    cout << Tabs(2) << "_______________________ [Game Round] _______________________\n\n";
    cout << Tabs(2) << "Game Rounds        :" << GameResults.GameRounds << endl;
    cout << Tabs(2) << "Player1 Won Times  :" << GameResults.Player1WinTimes << endl;
    cout << Tabs(2) << "Computer Won Times :" << GameResults.ComputerWinTimes << endl;
    cout << Tabs(2) << "Draw Times         :" << GameResults.DrawTimes << endl;
    cout << Tabs(2) << "Final Times        :" << GameResults.WinnerName << endl;
    cout << Tabs(2) << "____________________________________________________________\n\n";

    SetWinnerScreenColor(GameResults.GameWinner);
}

void ResetScreen()
{
    system("cls");
    system("color 0F");
}

void StartGame()
{
    char PlayAgin = 'Y';

    do
    {
        ResetScreen();
        stGameResults GameResults = PlayAllRounds(ReadHowManyRounds());
        ShowGameOverScreen();
        ShowFinalGameResult(GameResults);
        cout << Tabs(2) << "Do You Want To Play Again? Y/N ? ";
        cin >> PlayAgin;

    } while (PlayAgin == 'Y' || PlayAgin == 'y');

}

int main()
{
    srand((unsigned)time(NULL));

    StartGame();

    return 0;
}


//My First Method.

//#include<iostream>
//#include<string>
//#include<cstdlib>
//#include<ctime>
//using namespace std;
//
//enum enMyChoice { Stone = 1, Paper = 2, Scissors = 3 };
//
//short ReadPositiveNumber(string Message)
//{
//    short Number = 0;
//    do
//    {
//        cout << Message << endl;
//        cin >> Number;
//    } while (Number < 0);
//
//    return Number;
//}
//
//short RandomNumber(short From, short To)
//{
//    short RandomNumber = 0;
//
//    RandomNumber = From + rand() % 3;
//
//    return RandomNumber;
//}
//
//enMyChoice ReadUserChoice()
//{
//    short Choice = 0;
//
//    cout << "\nYour Choice: [1]:Stone, [2]:Paper, [3]:Scissors ?";
//    cin >> Choice;
//
//    return enMyChoice(Choice);
//}
//
//enMyChoice ComputerRandomChoice()
//{
//    return enMyChoice(RandomNumber(1, 3));
//}
//
//void PrintChoice(enMyChoice Choice)
//{
//    switch (Choice)
//    {
//    case(enMyChoice::Paper):
//        cout << "Paper";
//        break;
//
//    case(enMyChoice::Scissors):
//        cout << "Scissors";
//        break;
//
//    case(enMyChoice::Stone):
//        cout << "Stone";
//        break;
//
//    default:
//        break;
//    }
//}
//
//string PrintRoundResult(enMyChoice UserChoice, enMyChoice ComputerChoice, short& UserCount, short& ComputerCount,short &DrawCount)
//{
//    if (UserChoice > ComputerChoice)
//    {
//        UserCount++;
//        system("color 2F");
//        return "Player1";
//    }
//    else if (UserChoice < ComputerChoice)
//    {
//        ComputerCount++;
//        cout << "\a";
//        system("color 4F");
//        return "Computer";
//    }
//    else 
//    {
//        DrawCount++;
//        system("color 6F");
//        return "No Winner";
//    }
//}
//
//void ReadRound(enMyChoice UserChoice, enMyChoice ComputerChoice, short &UserCount, short &ComputerCount, short &DrawCount)
//{
//    cout << "\nPlayer1  Choice: "; PrintChoice(UserChoice);
//    cout << "\nComputer Choice: "; PrintChoice(ComputerChoice);
//    cout << "\nRound Winner   : [" << PrintRoundResult(UserChoice, ComputerChoice, UserCount, ComputerCount, DrawCount); cout << "]\n\n";
//}
//
//void PrintFinalResult(short Number1, short Number2)
//{
//    if (Number1 > Number2)
//    {
//        system("color 2F");
//        cout << "[User Winner]";
//    }
//    else if (Number1 < Number2)
//    {
//        system("color 4F");
//        cout << "[Computer Winner]";
//    }
//    else
//    {
//        system("color 6F");
//        cout << "[No Winner]";
//    }
//}
//
//void PrintGameResult(short NumberOfRound,short UserCount, short ComputerCount,short DrawCount)
//{
//    cout << "________________________________________________________________\n\n";
//    cout << "\t\t\t+++ Game Over +++\t\t\t\n\n";
//    cout << "\t\t\t________________________________________________________________\n\n";
//    cout << "\t\t\t__________________ [Game Result] __________________\n\n";
//    cout << "\t\t\tGame Rounds        :" << NumberOfRound << "\n";
//    cout << "\t\t\tPlayer1 Won times  :" << UserCount << "\n";
//    cout << "\t\t\tComputer Won times :" << ComputerCount << "\n";
//    cout << "\t\t\tDraw times         :" << DrawCount << "\n";
//    cout << "\t\t\tFinal Winner       :"; PrintFinalResult(UserCount, ComputerCount);
//
//}
//
//void StratPlay()
//{
//    char flage;
//    do
//    {
//        short NumberOfRound = ReadPositiveNumber("How Many Rounds 1 to 10 ?");
//        short UserCount = 0, ComputerCount = 0, DrawCount = 0;
//
//        for (int i = 1; i <= NumberOfRound; i++)
//        {
//
//            cout << "\nRound [" << i << "] begins:\n";
//            enMyChoice UserChoice = ReadUserChoice();
//            enMyChoice ComputerChoice = ComputerRandomChoice();
//
//            cout << "\n____________________Round [" << i << "] ____________________\n";
//
//            ReadRound(UserChoice, ComputerChoice, UserCount, ComputerCount, DrawCount);
//
//            cout << "___________________________________________________\n\n";
//        }
//
//        PrintGameResult(NumberOfRound, UserCount, ComputerCount, DrawCount);
//        cout << "\n\n";
//
//        cout << "\t\t\tDo You Want to Play again ? Y/N?";
//        cin >> flage;
//
//        if(flage == 'Y')
//            system("cls");
//
//    } while (flage == 'Y');
//    
//}
//
//int main()
//{ 
//    srand((unsigned)time(NULL));
//    
//    StratPlay();
//
//    return 0;
//}

//My Second Method.

//#include<iostream>
//#include<cstdlib>
//#include<ctime>
//using namespace std;
//
//enum enChoice { Stone = 1, Paper, Scissors };
//enum enWinner { Player = 1, Computer, NoWinner };
//
//struct stTimeWinnerCount
//{
//    short Player1WonTimes = 0;
//    short ComputerWonTimes = 0;
//    short DrawTimes = 0;
//};
//
//int ReadPositiveNumber(string Message)
//{
//    int Number = 0;
//    do
//    {
//        cout << Message;
//        cin >> Number;
//
//    } while (Number < 0);
//    return Number;
//}
//
//int RandomNumber(int From, int To)
//{
//    int randNum = 0;
//
//    randNum = From + rand() % (To - From + 1);
//
//    return randNum;
//}
//
//enChoice PlayerChoice()
//{
//    int Number = ReadPositiveNumber("Your Choice: [1]:Stone, [2]:Paper, [3]:Scissors ? ");
//
//    return (enChoice)Number;
//}
//
//string PrintChoice(enChoice Choice)
//{
//    switch (Choice)
//    {
//    case(Stone):
//        return "Stone";
//
//    case (Paper):
//        return "Paper";
//
//    case (Scissors):
//        return "Scissors";
//    }
//}
//
//enChoice ComputerChoice()
//{
//    int Number = RandomNumber(1, 3);
//    return (enChoice)Number;
//}
//
//string WinnerName(enWinner Winner)
//{
//    switch (Winner)
//    {
//    case Player:
//        system("color 2F");
//        return "Player";
//
//    case Computer:
//        cout << "\a";
//        system("color 4F");
//        return "Computer";
//
//    case NoWinner:
//        system("color 6F");
//        return "[NO Winner}";
//    }
//}
//
//enWinner RoundWinner(enChoice PlayerChoice, enChoice ComputerChoice)
//{
//    if (PlayerChoice == ComputerChoice)
//        return enWinner::NoWinner;
//
//
//    switch (PlayerChoice)
//    {
//    case(enChoice::Stone):
//        if (ComputerChoice == enChoice::Scissors)
//            return enWinner::Player;
//
//    case(enChoice::Scissors):
//        if (ComputerChoice == enChoice::Paper)
//            return enWinner::Player;
//
//    case(enChoice::Paper):
//        if (ComputerChoice == enChoice::Stone)
//            return enWinner::Player;
//    }
//    return enWinner::Computer;
//}
//
//void ShowRound(enChoice Player1Choice, enChoice ComputerChoice, enWinner Winner)
//{
//    cout << "\nPlayer1  Choice : " << PrintChoice(Player1Choice);
//    cout << "\nComputer Choice : " << PrintChoice(ComputerChoice);
//    cout << "\nRound Winner    : " << WinnerName(Winner);
//}
//
//stTimeWinnerCount TimeWinnerCount(enWinner Winner)
//{
//    stTimeWinnerCount TimeWinner;
//
//    if (Winner == enWinner::Player)
//        TimeWinner.Player1WonTimes++;
//    else if (Winner == enWinner::Computer)
//        TimeWinner.ComputerWonTimes++;
//    else
//        TimeWinner.DrawTimes++;
//
//
//    return TimeWinner;
//}
//
//void ShowRounds(int NumberOfRound, stTimeWinnerCount& TimeWinner)
//{
//
//
//    for (int i = 1; i <= NumberOfRound; i++)
//    {
//        cout << "\nRound [" << i << "] begins :";
//        cout << "\n\n_____________ Round [" << i << "] " << " _____________\n\n";
//
//        enChoice Player1Choice = PlayerChoice();
//        enChoice computerChoice = ComputerChoice();
//        enWinner Winner = RoundWinner(Player1Choice, computerChoice);
//
//        ShowRound(Player1Choice, computerChoice, Winner);
//        cout << "\n___________________________________\n";
//
//        if (Winner == Player) TimeWinner.Player1WonTimes++;
//        else if (Winner == Computer) TimeWinner.ComputerWonTimes++;
//        else TimeWinner.DrawTimes++;
//
//
//    }
//}
//
//void Tabs(short Number)
//{
//    for (int i = 1; i < Number; i++)
//    {
//        cout << "\t";
//    }
//}
//
//void PrintGameOver()
//{
//    Tabs(3); cout << "__________________________________________________\n\n";
//    Tabs(3); cout << "                 +++Game Over +++                 \n";
//    Tabs(3); cout << "__________________________________________________\n\n";
//}
//
//enWinner FinalWinner(stTimeWinnerCount TimeWinner)
//{
//    if (TimeWinner.Player1WonTimes > TimeWinner.ComputerWonTimes)
//        return enWinner::Player;
//    else if (TimeWinner.ComputerWonTimes > TimeWinner.Player1WonTimes)
//        return enWinner::Computer;
//    else
//        return enWinner::NoWinner;
//}
//
//void PrintGameResult(int NumberOfRound, stTimeWinnerCount TimeWinner)
//{
//
//    Tabs(3); cout << "_________________ [Game Results] _________________\n\n";
//    Tabs(3); cout << "Game Rounds        : " << NumberOfRound << "\n\n";
//    Tabs(3); cout << "Player1 Won Times  : " << TimeWinner.Player1WonTimes << "\n\n";
//    Tabs(3); cout << "Computer Won Times : " << TimeWinner.ComputerWonTimes << "\n\n";
//    Tabs(3); cout << "Draw Times         : " << TimeWinner.DrawTimes << "\n\n";
//    Tabs(3); cout << "Final Winner       : " << WinnerName(FinalWinner(TimeWinner)) << "\n\n";
//    Tabs(3); cout << "___________________________________________________\n\n";
//}
//
//void ResetScreen()
//{
//    system("cls");
//}
//
//void StartGame()
//{
//    srand((unsigned)time(NULL));
//
//    char PlayAgain = 'Y';
//
//    do
//    {
//        ResetScreen();
//
//        stTimeWinnerCount TimeWinner;
//
//        int NumberOfRound = ReadPositiveNumber("How Many Rounds 1 to 10 ?");
//
//
//        ShowRounds(NumberOfRound, TimeWinner);
//
//        PrintGameOver();
//
//        PrintGameResult(NumberOfRound, TimeWinner);
//
//
//        cout << "Do You Want To Play Again? Y/N ?";
//        cin >> PlayAgain;
//
//    } while (PlayAgain == 'Y' || PlayAgain == 'y');
//
//}
//
//int main()
//{
//    StartGame();
//
//    return 0;
//}