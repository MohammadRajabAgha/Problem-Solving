#include<iostream>
#include<string>
#include<ctime>

using namespace std;

enum enQuestionLevel { EasyLev = 1, MedLev, HardLev, Mix };
enum enOpType { Add = 1, Sub, Mul, Div, MixOp };

struct stQuestion
{
    int Number1 = 0;
    int Number2 = 0;
    enQuestionLevel QuestionLevel;
    enOpType OpType;
    int CorrectAnswer = 0;
    int PlayerAnswer = 0;
    bool AnswerResult = false;
};

struct stQuiz
{
    stQuestion QuestionList[100];
    short NumberOfQuestions = 0;
    enQuestionLevel QuizLevel;
    enOpType QuizOpType;
    short NumberOfRightAnswer = 0;
    short NumberOfWrongAnswer = 0;
    bool IsPASS = false;
};

short ReadHowManyQuestion()
{
    short NumberOfQuestions = 0;
    do
    {
        cout << "How Many Question Do You Want To Answer ? ";
        cin >> NumberOfQuestions;

    } while (NumberOfQuestions < 1 || NumberOfQuestions>10);

    return NumberOfQuestions;
}

void SetScreenColor(bool Right)
{
    if (Right)
    {
        system("color 2F");
    }
    else
    {
        system("color 4F");
        cout << "\a";
    }
}

string GetOpTypeSymbol(enOpType OpType)
{
    string arrOpType[5] = { "+","-","*","/","Mix" };

    return arrOpType[OpType - 1];
}

enQuestionLevel ReadQuizLevel()
{
    int QuizLevel = 0;
    do
    {
        cout << "Enter Question Level [1]:Easy, [2]:Med, [3]:Hard, [4]:Mix ? ";
        cin >> QuizLevel;

    } while (QuizLevel < 1 || QuizLevel>4);

    return (enQuestionLevel)QuizLevel;
}

enOpType ReadQuizOpType()
{
    int QuizOpType = 0;

    do
    {
        cout << "Enter Operation Type [1]:Add, [2]:Sub, [3]:Mul, [4]:Div, [5]:Mix ? ";
        cin >> QuizOpType;

    } while (QuizOpType < 1 || QuizOpType>5);

    return (enOpType)QuizOpType;
}

int RandomNumber(int From, int To)
{
    int randNum = 0;

    randNum = From + rand() % (To - From + 1);

    return randNum;
}

int SampleCalculater(int Number1, int Number2, enOpType OpType)
{
    switch (OpType)
    {
    case Add:
        return Number1 + Number2;
        break;
    case Sub:
        return Number1 - Number2;
        break;
    case Mul:
        return Number1 * Number2;
        break;
    case Div:
        return Number1 / Number2;
        break;

    default:
        return Number1 + Number2;
        break;
    }
}

enOpType GetRandomOperationType()
{
    int Op = RandomNumber(1, 4);
    return (enOpType)Op;
}

stQuestion GenerateQuestion(enQuestionLevel QuestionLevel, enOpType OpType)
{
    stQuestion Question;

    if (QuestionLevel == enQuestionLevel::Mix)
    {
        QuestionLevel = (enQuestionLevel)RandomNumber(1, 3);
    }

    if (OpType == enOpType::MixOp)
    {
        OpType = GetRandomOperationType();
    }

    Question.OpType = OpType;

    switch (QuestionLevel)
    {
    case enQuestionLevel::EasyLev:
        Question.Number1 = RandomNumber(1, 10);
        Question.Number2 = RandomNumber(1, 10);
        Question.QuestionLevel = QuestionLevel;
        Question.CorrectAnswer = SampleCalculater(Question.Number1, Question.Number2, OpType);

        break;

    case enQuestionLevel::MedLev:
        Question.Number1 = RandomNumber(10, 50);
        Question.Number2 = RandomNumber(10, 50);
        Question.QuestionLevel = QuestionLevel;
        Question.CorrectAnswer = SampleCalculater(Question.Number1, Question.Number2, OpType);

        break;

    case enQuestionLevel::HardLev:
        Question.Number1 = RandomNumber(50, 100);
        Question.Number2 = RandomNumber(50, 100);
        Question.QuestionLevel = QuestionLevel;
        Question.CorrectAnswer = SampleCalculater(Question.Number1, Question.Number2, OpType);

        break;
    }

    return Question;

}

void GenerateQuestions(stQuiz& Quiz)
{
    for (int QuestionNumber = 0; QuestionNumber < Quiz.NumberOfQuestions; QuestionNumber++)
    {
        Quiz.QuestionList[QuestionNumber] = GenerateQuestion(Quiz.QuizLevel, Quiz.QuizOpType);
    }
}

void PrintQuestions(int QuestionNumber, const stQuiz& Quiz)
{
    cout << "\n\nQuestion [" << QuestionNumber + 1 << "/" << Quiz.NumberOfQuestions << "]" << "\n\n";
    cout << Quiz.QuestionList[QuestionNumber].Number1 << "\n";
    cout << Quiz.QuestionList[QuestionNumber].Number2 << " ";
    cout << GetOpTypeSymbol(Quiz.QuestionList[QuestionNumber].OpType); // يعرض الرمز (+, -, *, /)
    cout << "\n__________\n";



}

int ReadPlayerAnswer()
{
    int Answer = 0;
    cin >> Answer;
    return Answer;
}

void CorrectAnswer(int QuestionNumber, stQuiz& Quiz)
{
    if (Quiz.QuestionList[QuestionNumber].PlayerAnswer != Quiz.QuestionList[QuestionNumber].CorrectAnswer)
    {
        Quiz.NumberOfWrongAnswer++;
        Quiz.QuestionList[QuestionNumber].AnswerResult = false;
        cout << "Wrong Answer :(\n";
        cout << "The Right Answer is : " << Quiz.QuestionList[QuestionNumber].CorrectAnswer;
    }
    else
    {
        Quiz.NumberOfRightAnswer++;
        Quiz.QuestionList[QuestionNumber].AnswerResult = true;
        cout << "Right Answer :)";


    }

    SetScreenColor(Quiz.QuestionList[QuestionNumber].AnswerResult);

}

void PrintandAsksndCorrectQuestion(stQuiz& Quiz)
{
    for (int QuestionNumber = 0; QuestionNumber < Quiz.NumberOfQuestions; QuestionNumber++)
    {
        PrintQuestions(QuestionNumber, Quiz);
        Quiz.QuestionList[QuestionNumber].PlayerAnswer = ReadPlayerAnswer();
        CorrectAnswer(QuestionNumber, Quiz);
    }
    Quiz.IsPASS = (Quiz.NumberOfRightAnswer >= Quiz.NumberOfWrongAnswer);
}

string GetFinalResultText(stQuiz Quiz)
{
    if (Quiz.IsPASS)
        return "PASS :-)";
    else
        return "Fail :-(";
}

string GetQuestionLevelText(enQuestionLevel QuestionLevel)
{
    string arrQuestionLevel[4] = { "Easy","Med","Hard","Mix" };

    return arrQuestionLevel[QuestionLevel - 1];
}

void PrintResult(stQuiz Quiz)
{
    cout << "\n______________________________________\n\n";
    cout << "Final Results is " << GetFinalResultText(Quiz);
    cout << "\n______________________________________\n\n";
    cout << "Number Of Questions : " << Quiz.NumberOfQuestions << "\n";
    cout << "Question Level        :" << GetQuestionLevelText(Quiz.QuizLevel) << "\n";
    cout << "OpType         :" << GetOpTypeSymbol(Quiz.QuizOpType) << "\n";
    cout << "Number Of Right Answer : " << Quiz.NumberOfRightAnswer << "\n";
    cout << "Number Of Wrong Answer : " << Quiz.NumberOfWrongAnswer << "\n";
    cout << "\n______________________________________\n\n";

    SetScreenColor(Quiz.IsPASS);
}

void PlayMathGame()
{
    stQuiz Quiz;

    Quiz.NumberOfQuestions = ReadHowManyQuestion();
    Quiz.QuizLevel = ReadQuizLevel();
    Quiz.QuizOpType = ReadQuizOpType();

    GenerateQuestions(Quiz);
    PrintandAsksndCorrectQuestion(Quiz);
    PrintResult(Quiz);

}

void ResetScreen()
{
    system("cls");
    system("color 0F");
}

void startGame()
{
    char PlayAgain = 'Y';

    do
    {
        ResetScreen();
        PlayMathGame();

        cout << "Do you want to play again? (Y/N): ";
        cin >> PlayAgain;

    } while (PlayAgain == 'Y' || PlayAgain == 'y');


}

int main()
{
    srand((unsigned)time(NULL));

    startGame();



    return 0;
}



//Project 2.My Solution With Librarys......

//#include<iostream>
//#include "C:\Users\ASUS\MyLibrary\MyLibraries.h"
//#include<string>
//#include<ctime>
//
//using namespace std;
//
//enum enQuestionLevel { EasyLev = 1, MedLev, HardLev, Mix };
////important.....
//using MathLib::enOpType;
//
//struct stQuestion
//{
//    int Number1 = 0;
//    int Number2 = 0;
//    enQuestionLevel QuestionLevel;
//    enOpType OpType;
//    int CorrectAnswer = 0;
//    int PlayerAnswer = 0;
//    bool AnswerResult = false;
//};
//
//struct stQuiz
//{
//    stQuestion QuestionList[100];
//    short NumberOfQuestions = 0;
//    enQuestionLevel QuizLevel;
//    enOpType QuizOpType;
//    short NumberOfRightAnswer = 0;
//    short NumberOfWrongAnswer = 0;
//    bool IsPASS = false;
//};
//
//
//enQuestionLevel ReadQuizLevel()
//{
//    int QuizLevel = 0;
//    do
//    {
//        cout << "Enter Question Level [1]:Easy, [2]:Med, [3]:Hard, [4]:Mix ? ";
//        cin >> QuizLevel;
//
//    } while (QuizLevel < 1 || QuizLevel>4);
//
//    return (enQuestionLevel)QuizLevel;
//}
//
//enOpType ReadQuizOpType()
//{
//    int QuizOpType = 0;
//
//    do
//    {
//        cout << "Enter Operation Type [1]:Add, [2]:Sub, [3]:Mul, [4]:Div, [5]:Mix ? ";
//        cin >> QuizOpType;
//
//    } while (QuizOpType < 1 || QuizOpType>5);
//
//    return (enOpType)QuizOpType;
//}
//
//enOpType GetRandomOperationType()
//{
//    int Op = LogicalLib::RandomNumber(1, 4);
//    return (enOpType)Op;
//}
//
//stQuestion GenerateQuestion(enQuestionLevel QuestionLevel, enOpType OpType)
//{
//    stQuestion Question;
//
//    if (QuestionLevel == enQuestionLevel::Mix)
//    {
//        QuestionLevel = (enQuestionLevel)LogicalLib::RandomNumber(1, 3);
//    }
//
//    if (OpType == enOpType::MixOp)
//    {
//        OpType = GetRandomOperationType();
//    }
//
//    Question.OpType = OpType;
//
//    switch (QuestionLevel)
//    {
//    case enQuestionLevel::EasyLev:
//        Question.Number1 = LogicalLib::RandomNumber(1, 10);
//        Question.Number2 = LogicalLib::RandomNumber(1, 10);
//        Question.QuestionLevel = QuestionLevel;
//        Question.CorrectAnswer = MathLib::SampleCalculater(Question.Number1, Question.Number2, OpType);
//
//        break;
//
//    case enQuestionLevel::MedLev:
//        Question.Number1 = LogicalLib::RandomNumber(10, 50);
//        Question.Number2 = LogicalLib::RandomNumber(10, 50);
//        Question.QuestionLevel = QuestionLevel;
//        Question.CorrectAnswer = MathLib::SampleCalculater(Question.Number1, Question.Number2, OpType);
//
//        break;
//
//    case enQuestionLevel::HardLev:
//        Question.Number1 = LogicalLib::RandomNumber(50, 100);
//        Question.Number2 = LogicalLib::RandomNumber(50, 100);
//        Question.QuestionLevel = QuestionLevel;
//        Question.CorrectAnswer = MathLib::SampleCalculater(Question.Number1, Question.Number2, OpType);
//
//        break;
//    }
//
//    return Question;
//
//}
//
//void GenerateQuestions(stQuiz& Quiz)
//{
//    for (int QuestionNumber = 0; QuestionNumber < Quiz.NumberOfQuestions; QuestionNumber++)
//    {
//        Quiz.QuestionList[QuestionNumber] = GenerateQuestion(Quiz.QuizLevel, Quiz.QuizOpType);
//    }
//}
//
//void PrintQuestions(int QuestionNumber, const stQuiz& Quiz)
//{
//    cout << "\n\nQuestion [" << QuestionNumber + 1 << "/" << Quiz.NumberOfQuestions << "]" << "\n\n";
//    cout << Quiz.QuestionList[QuestionNumber].Number1 << "\n";
//    cout << Quiz.QuestionList[QuestionNumber].Number2 << " ";
//    cout << LogicalLib::GetOpTypeSymbol(Quiz.QuestionList[QuestionNumber].OpType); // يعرض الرمز (+, -, *, /)
//    cout << "\n__________\n";
//
//}
//
//int ReadPlayerAnswer()
//{
//    int Answer = 0;
//    cin >> Answer;
//    return Answer;
//}
//
//void CorrectAnswer(int QuestionNumber, stQuiz& Quiz)
//{
//    if (Quiz.QuestionList[QuestionNumber].PlayerAnswer != Quiz.QuestionList[QuestionNumber].CorrectAnswer)
//    {
//        Quiz.NumberOfWrongAnswer++;
//        Quiz.QuestionList[QuestionNumber].AnswerResult = false;
//        cout << "Wrong Answer :(\n";
//        cout << "The Right Answer is : " << Quiz.QuestionList[QuestionNumber].CorrectAnswer;
//    }
//    else
//    {
//        Quiz.NumberOfRightAnswer++;
//        Quiz.QuestionList[QuestionNumber].AnswerResult = true;
//        cout << "Right Answer :)";
//
//
//    }
//
//    LogicalLib::SetScreenColor(Quiz.QuestionList[QuestionNumber].AnswerResult);
//
//}
//
//void PrintandAsksndCorrectQuestion(stQuiz& Quiz)
//{
//    for (int QuestionNumber = 0; QuestionNumber < Quiz.NumberOfQuestions; QuestionNumber++)
//    {
//        PrintQuestions(QuestionNumber, Quiz);
//        Quiz.QuestionList[QuestionNumber].PlayerAnswer = ReadPlayerAnswer();
//        CorrectAnswer(QuestionNumber, Quiz);
//    }
//    Quiz.IsPASS = (Quiz.NumberOfRightAnswer >= Quiz.NumberOfWrongAnswer);
//}
//
//string GetFinalResultText(stQuiz Quiz)
//{
//    if (Quiz.IsPASS)
//        return "PASS :-)";
//    else
//        return "Fail :-(";
//}
//
//string GetQuestionLevelText(enQuestionLevel QuestionLevel)
//{
//    string arrQuestionLevel[4] = { "Easy","Med","Hard","Mix" };
//
//    return arrQuestionLevel[QuestionLevel - 1];
//}
//
//void PrintResult(stQuiz Quiz)
//{
//    cout << "\n______________________________________\n\n";
//    cout << "Final Results is " << GetFinalResultText(Quiz);
//    cout << "\n______________________________________\n\n";
//    cout << "Number Of Questions : " << Quiz.NumberOfQuestions << "\n";
//    cout << "Question Level        :" << GetQuestionLevelText(Quiz.QuizLevel) << "\n";
//    cout << "OpType         :" << LogicalLib::GetOpTypeSymbol(Quiz.QuizOpType) << "\n";
//    cout << "Number Of Right Answer : " << Quiz.NumberOfRightAnswer << "\n";
//    cout << "Number Of Wrong Answer : " << Quiz.NumberOfWrongAnswer << "\n";
//    cout << "\n______________________________________\n\n";
//
//    LogicalLib::SetScreenColor(Quiz.IsPASS);
//}
//
//void PlayMathGame()
//{
//    stQuiz Quiz;
//
//    Quiz.NumberOfQuestions = ReadInputs::ReadPositiveNumber("How Many Question Do You Want To Answer ? ");
//    Quiz.QuizLevel = ReadQuizLevel();
//    Quiz.QuizOpType = ReadQuizOpType();
//
//    GenerateQuestions(Quiz);
//    PrintandAsksndCorrectQuestion(Quiz);
//    PrintResult(Quiz);
//
//}
//
//void ResetScreen()
//{
//    system("cls");
//    system("color 0F");
//}
//
//void startGame()
//{
//    char PlayAgain = 'Y';
//
//    do
//    {
//        ResetScreen();
//        PlayMathGame();
//
//        PlayAgain = ReadInputs::ReadChar("Do you want to play again? (Y/N): ");
//
//    } while (PlayAgain == 'Y' || PlayAgain == 'y');
//
//}
//
//int main()
//{
//    srand((unsigned)time(NULL));
//
//    startGame();
//
//    return 0;
//}



//Project 2.My Solution

//#include<iostream>
//#include<ctime>
//using namespace std;
//
//enum enLevel { Easy = 1, Med, Hard, MIX };
//enum enOperationType { Add = 1, Sub, Mul, Div, Mix };
//enum enResult { PASS = 1, FAIL };
//
//struct stQuestionInfo
//{
//
//	short NumberOfQuestions = 0;
//	short QuestionNumber = 0;
//	int Number1;
//	int Number2;
//	enLevel Level;
//	enOperationType ReadOperationType;
//	char OperationType;
//	int QuestionAnswer = 0;
//	int UserAnswer = 0;
//	bool IsAnswerTrue;
//
//};
//
//struct stQuizResult
//{
//	short NumberOfQuestions = 0;
//	enLevel Level;
//	enOperationType enOpType;
//	char OpType;
//	short NumberOfRightAnswer = 0;
//	short NumberOfWrongAnswer = 0;
//	enResult Result;
//
//};
//
//enLevel ReadLevel()
//{
//	int LevelNumber = 0;
//	do
//	{
//		cout << "\nEnter Question Level  [1]:Easy,[2]:Med,[3]:Hard,[4]:Mix ? ";
//		cin >> LevelNumber;
//
//	} while (LevelNumber < 0 || LevelNumber > 4);
//
//	return (enLevel)LevelNumber;
//}
//
//void SetScreenColor(const stQuestionInfo& QuestionInfo)
//{
//	if (QuestionInfo.IsAnswerTrue)
//	{
//		system("color 2F");//Green.
//	}
//	else
//	{
//		system("color 4F");//Red.
//		cout << "\a";
//	}
//}
//
//enOperationType ReadOperationType()
//{
//	int OperationType = 0;
//	do
//	{
//		cout << "\nEnter Operation Type [1]:Add,[2]:Sub,[3]:Mul,[4]:Div,[5]:Mix ? ";
//		cin >> OperationType;
//
//	} while (OperationType < 1 || OperationType > 5);
//
//	return (enOperationType)OperationType;
//}
//
//short ReadHowManyQuestion()
//{
//	short NumberOfQuestion = 0;
//	do
//	{
//		cout << "How Many Question do you want to Answer ? ";
//		cin >> NumberOfQuestion;
//
//	} while (NumberOfQuestion < 0);
//	return NumberOfQuestion;
//}
//
//void ResetScreen()
//{
//	system("cls");
//	system("color 0F");
//}
//
//bool IsAnswerTrue(stQuestionInfo QuestionInfo)
//{
//	if (QuestionInfo.UserAnswer == QuestionInfo.QuestionAnswer)
//		return true;
//	else
//		return false;
//}
//
//int RandomNumber(int From, int To)
//{
//	int randNumber = 0;
//
//	randNumber = From + rand() % (To - From + 1);
//
//	return randNumber;
//}
//
//int GenerateNumber(stQuestionInfo QuestionInfo)
//{
//	switch (QuestionInfo.Level)
//	{
//	case enLevel::Easy:
//		return RandomNumber(1, 10);
//		break;
//
//	case enLevel::Med:
//		return RandomNumber(11, 49);
//		break;
//
//	case enLevel::Hard:
//		return RandomNumber(50, 99);
//		break;
//
//	case enLevel::MIX:
//		return RandomNumber(1, 99);
//		break;
//	}
//}
//
//char ChoiceOperationType(stQuestionInfo QuestionInfo)
//{
//
//	if (QuestionInfo.ReadOperationType == enOperationType::Mix)
//	{
//		QuestionInfo.ReadOperationType = (enOperationType)RandomNumber(1, 4);
//	}
//
//	switch (QuestionInfo.ReadOperationType)
//	{
//
//	case enOperationType::Add:
//		return '+';
//		break;
//
//	case enOperationType::Sub:
//		return '-';
//		break;
//
//	case enOperationType::Mul:
//		return '*';
//		break;
//
//	case enOperationType::Div:
//		return '/';
//		break;
//
//	default: return '+'; // ← قيمة افتراضية
//	}
//}
//
//string ChoiceLevel(enLevel Level)
//{
//	switch (Level)
//	{
//	case enLevel::Easy:
//		return "Easy";
//
//	case enLevel::Med:
//		return "Med";
//
//	case enLevel::Hard:
//		return "Hard";
//
//	case enLevel::MIX:
//		return "MIX";
//
//	}
//}
//
//string ChoiceOPerationType(enOperationType OperationType)
//{
//	switch (OperationType)
//	{
//	case enOperationType::Add:
//		return "Add";
//
//	case enOperationType::Sub:
//		return "Sub";
//
//	case enOperationType::Mul:
//		return "Mul";
//
//	case enOperationType::Div:
//		return "Div";
//
//	case enOperationType::Mix:
//		return "MIX";
//	}
//}
//
//int CalculateQuestionResult(stQuestionInfo QuestionInfo)
//{
//	switch (QuestionInfo.OperationType)
//	{
//	case '+':
//		return (QuestionInfo.Number1 + QuestionInfo.Number2);
//		break;
//
//	case '-':
//		return (QuestionInfo.Number1 - QuestionInfo.Number2);
//		break;
//
//	case '*':
//		return (QuestionInfo.Number1 * QuestionInfo.Number2);
//		break;
//
//	case '/':
//		return (QuestionInfo.Number1 / QuestionInfo.Number2);
//		break;
//
//	default: return 0; // ← قيمة افتراضية
//	}
//}
//
//void PrintQuestion(stQuestionInfo& QuestionInfo)
//{
//	cout << "\n\nQuestion [" << QuestionInfo.QuestionNumber << "/" << QuestionInfo.NumberOfQuestions << "] \n\n";
//	cout << QuestionInfo.Number1 << "\n";
//	cout << QuestionInfo.Number2 << " " << QuestionInfo.OperationType;
//	cout << "\n\n________________\n";
//	cin >> QuestionInfo.UserAnswer;
//
//	QuestionInfo.IsAnswerTrue = IsAnswerTrue(QuestionInfo);
//
//	if (QuestionInfo.IsAnswerTrue)
//	{
//		cout << "Right Answer:)\n";
//	}
//	else
//	{
//		cout << "Wrong Answer.\n";
//		cout << "The Right Answer is : " << QuestionInfo.QuestionAnswer << "\n";
//	}
//	SetScreenColor(QuestionInfo);
//}
//
//enResult IsSucceeded(stQuizResult QuizResult)
//{
//	if (QuizResult.NumberOfRightAnswer >= QuizResult.NumberOfWrongAnswer)
//		return enResult::PASS;
//	else
//		return enResult::FAIL;
//}
//
//stQuizResult FillQuizInformation(stQuestionInfo& QuestionInfo, short NumberOfRightAnswer, short NumberOfWrongAnswer)
//{
//	stQuizResult QuizResult;
//
//	QuizResult.NumberOfQuestions = QuestionInfo.NumberOfQuestions;
//	QuizResult.Level = QuestionInfo.Level;
//	QuizResult.enOpType = QuestionInfo.ReadOperationType;
//	QuizResult.OpType = QuestionInfo.OperationType;
//	QuizResult.NumberOfRightAnswer = NumberOfRightAnswer;
//	QuizResult.NumberOfWrongAnswer = NumberOfWrongAnswer;
//	QuizResult.Result = IsSucceeded(QuizResult);
//
//	return QuizResult;
//}
//
//stQuizResult PlayAllQuestion(short NumberOfQuestions)
//{
//	stQuestionInfo QuestionInfo;
//	short NumberOfRightAnswer = 0, NumberOfWrongAnswer = 0;
//
//	QuestionInfo.Level = ReadLevel();
//	QuestionInfo.ReadOperationType = ReadOperationType();
//
//	for (short QuestionNumber = 1; QuestionNumber <= NumberOfQuestions; QuestionNumber++)
//	{
//		QuestionInfo.NumberOfQuestions = NumberOfQuestions;
//		QuestionInfo.QuestionNumber = QuestionNumber;
//
//		QuestionInfo.OperationType = ChoiceOperationType(QuestionInfo);
//
//		QuestionInfo.Number1 = GenerateNumber(QuestionInfo);
//		QuestionInfo.Number2 = GenerateNumber(QuestionInfo);
//		QuestionInfo.QuestionAnswer = CalculateQuestionResult(QuestionInfo);
//
//		PrintQuestion(QuestionInfo);
//
//		if (QuestionInfo.IsAnswerTrue)
//			NumberOfRightAnswer++;
//		else
//			NumberOfWrongAnswer++;
//
//	}
//	return FillQuizInformation(QuestionInfo, NumberOfRightAnswer, NumberOfWrongAnswer);
//}
//
//void PrintScreenFinalResult(stQuizResult QuizResult)
//{
//	cout << "\n_________________________________________________\n";
//	if (QuizResult.Result == enResult::PASS)
//	{
//		cout << "Final Result is PASS:)\n";
//		system("color 2F");//Green.
//	}
//	else
//	{
//		cout << "Final Result is FAIL:(\n";
//		system("color 4F");//Red.
//	}
//	cout << "\n_________________________________________________\n";
//
//}
//
//void PrintQuizResult(stQuizResult QuizResult)
//{
//	cout << "\nNumber Of Question     : " << QuizResult.NumberOfQuestions;
//	cout << "\nQuestion Level         : " << ChoiceLevel(QuizResult.Level);
//	cout << "\nOpType                 : " << ChoiceOPerationType(QuizResult.enOpType);
//	cout << "\nNumber Of Right Answer : " << QuizResult.NumberOfRightAnswer;
//	cout << "\nNumber Of Wrong Answer : " << QuizResult.NumberOfWrongAnswer;
//	cout << "\n_________________________________________________\n";
//}
//
//void StartQuiz()
//{
//	char PlayAgain = 'Y';
//
//	stQuizResult QuizResult;
//
//	do
//	{
//
//		ResetScreen();
//		QuizResult = PlayAllQuestion(ReadHowManyQuestion());
//		PrintScreenFinalResult(QuizResult);
//		PrintQuizResult(QuizResult);
//
//		cout << "\nDo You Want To Play Again? Y/N ?";
//		cin >> PlayAgain;
//
//	} while (PlayAgain == 'Y' || PlayAgain == 'y');
//}
//
//int main()
//{
//	srand((unsigned)time(NULL));
//
//	StartQuiz();
//
//
//	return 0;
//
//}f