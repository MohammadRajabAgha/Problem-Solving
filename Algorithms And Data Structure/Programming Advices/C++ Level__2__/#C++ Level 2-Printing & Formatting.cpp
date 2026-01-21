#include<iostream>
#include<cstdio>

using namespace std;

int main()
{

    //Lesson 23 
    //Integer Format (PrintF)...

    cout << "\n******************************************************************\n";
    cout << "\n******************************************************************\n";
    cout << "Integer Format (PrintF)...";
    cout << "\n******************************************************************\n\n";

    int Page = 1, TotalPages = 10;

    // print string and int variable   
    printf("The page number = %d \n", Page); 
    printf("You are in Page %d of %d \n", Page, TotalPages);
   

    //Width specification   
    printf("The page number =  %0*d \n", 2, Page);
    printf("The page number =  %0*d \n", 3, Page);
    printf("The page number =  %*d \n", 3, Page);
    printf("The page number =  %0*d \n", 4, Page); 
    printf("The page number =  %0*d \n", 5, Page); 


    int Number1 = 10, Number2 = 30;
    printf("The Result of %d + %d = %d \n", Number1, Number2, Number1 + Number2);

    
  


    //Lesson 24
    //float Format (Printf)...

    cout << "\n******************************************************************\n";
    cout << "\n******************************************************************\n";
    cout << "float Format (Printf)...";
    cout << "\n******************************************************************\n\n";

    float PI = 3.14159265;

    //Precision specification  
    printf("Precision specification of %.*f\n", 1, PI);
    printf("Precision specification of %.*f\n", 2, PI);
    printf("Precision specification of %.*f\n", 3, PI);
    printf("Precision specification of %.*f\n", 4, PI);
    printf("Precision specification of %f\n", PI);


    float x = 7, y = 9;

    printf("\nThe float division is : %.3f / %.3f = %.3f \n\n", x, y, x / y);

    double d = 12.45;

    printf("The double value is : %.*f \n", 3, d);
    printf("The double value is : %.*f \n", 4, d);


    cout << "\n**************************\n";

    float a = 10.97134, b = 9, c = 5.311135;

    printf("namber : %.*f \n", 3, a);
    printf("result of %.*f / %.*f = %.*f \n", 3, a, 3, b, 2, a / b);

    cout << "\n**************************\n";

    int i = 10;

    printf("AN-94 %.*f  mm\n", 5, 5.45);
    printf("M4 %.*f mm\n", 5, 5.6);
    printf("M7  %.5f mm\n\n", 7.62);

    /* to print zeros before float or double number
    te number after %0 is number of entire float or double digits
    including zeros after and before   */

    printf("AWM %08.6f mm\n", 12.7);
    printf("AWM %08.3f mm\n", 12.7);


    cout << "\n**************************\n";


    printf("Precision specification of %*.*f this is very good \n", 10, 2, PI);



  

    //Lesson 25
    //String and Char Format (Printf)...

    cout << "\n\n******************************************************************\n";
    cout << "\n******************************************************************\n";
    cout << "String and Char Format (Printf)...";
    cout << "\n******************************************************************\n\n";

    char Name[] = { "Mohammad Rajab agha" };
    string Name2 = "Mohammad Agha";
    char Character = 'M';

    printf("Dear %s, How are you ? \n", Name);
    printf("Dear %*s, How are you\n", 30, Name);
    printf("Dear %*s, How are you ? \n\n", -30, Name);


    printf("Dear %s, How are you ? \n", Name2.c_str());
    printf("Dear %*s, How are you ? \n",30, Name2.c_str());
    printf("Dear %*s, How are you ? \n\n", -30, Name2.c_str());



    cout << "\n**************************\n";
    printf("Dear %.11s, How are you ? \n", Name);
    cout << "\n**************************\n";


    printf("Character : %c \n", Character);
    printf("Character : %0*c \n", 1, Character);
    printf("Character : %0*c \n", 2, Character);
    printf("Character : %0*c \n", 3, Character);
    printf("Character : %0*c \n\n", 4, Character);




    printf("Character : %c \n", Character);
    printf("Character : %*c \n",1, Character);
    printf("Character : %*c \n", 2, Character);
    printf("Character : %*c \n", 3, Character);
    printf("Character : %*c \n\n", 4, Character);


    cout << "\n******************************************************************\n";
    cout << "\n******************************************************************\n\n";


   

    return 0;

}