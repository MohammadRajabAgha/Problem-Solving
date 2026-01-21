#include<iostream>
#include<string>
using namespace std;

string ReadText(string Message)
{
	string Name;

	cout << Message << endl;
	getline(cin, Name);

	return Name;
}

string EncryptText(string Text, short EncryptKey)
{
	for (int i = 0; i < Text.length(); i++)
	{
		Text[i] = char((int)Text[i] + EncryptKey);
	}
	                                                                                                   
	return Text;
}

string DecryptText(string Text, short EncryptKey)
{

	for (int i = 0; i < Text.length(); i++)
	{
		Text[i] = char((int)Text[i] - EncryptKey);
	}

	return Text;
}

int main()
{
	const short EncryptKey = 2; //Define a constant encryption key to be used for both encryption and decryption.

	string TextAfterEncryption, TextAfterDecryption;

	string Text = ReadText("Pleas enter Your Text?");

	TextAfterEncryption = EncryptText(Text, EncryptKey);
	TextAfterDecryption = DecryptText(TextAfterEncryption, EncryptKey);// IMPORTANT TO SEND TEXT AFTER ENCRYPTION ,NOT TEXT

	cout << "\nText Before Encryption: " << Text;
	cout << "\nText After Encryption: " << TextAfterEncryption;
	cout << "\nText After Decryption: " << TextAfterDecryption;


	return 0;

}


//(int)Text[i]: التأكد من أن الحرف يُعامَل كرقم(لإجراء العملية الحسابية).
//
//char(...) : التأكد من تحويل الناتج الرقمي إلى حرف مجددًا.


