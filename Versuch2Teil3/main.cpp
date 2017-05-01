

#include <iostream>
#include <algorithm>
#include <string>

#define NUM_OF_CHARS 5

/*char table[2][26] = { { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' },
					  { 'w', 'n', 'j', 'y', 'a', 'l', 'h', 'v', 'e', 'p', 's', 'f', 'z', 'b', 'x', 'q', 'g', 'd', 'u', 'r', 'i', 't', 'm', 'k', 'c', 'o' }
};*/

char table[2][26] = { { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' },
					  { 'M', 'H', 'J', 'Y', 'A', 'N', 'W', 'V', 'E', 'P', 'S', 'F', 'O', 'L', 'X', 'Q', 'G', 'D', 'U', 'R', 'I', 'T', 'B', 'K', 'Z', 'C' }
};

char decodingTable[2][26] = { { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' },
							  { 'E', 'W', 'Z', 'R', 'I', 'L', 'Q', 'B', 'U', 'C', 'X', 'N', 'A', 'F', 'M', 'J', 'P', 'T', 'K', 'V', 'S', 'H', 'G', 'O', 'D', 'Y' }
};

char enigmaTable[2][26] = { { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' },
							{ 'M', 'T', 'J', 'Y', 'U', 'N', 'W', 'V', 'Q', 'C', 'S', 'P', 'A', 'F', 'X', 'L', 'I', 'Z', 'K', 'B', 'E', 'H', 'G', 'O', 'D', 'R' }
};							//Diese Tabelle ist besonders, da jeder Buchstabe eindeutig einem anderen zugeordnet ist
							//zB.: A=>M; M=>A (A<=>M)
using namespace std;

char encode(char c);
char decode(char c);
char enigma(char c);
string encode(string s);
string decode(string s);
string enigma(string s);
void printArray();

int main()
{
	char buf[80];
	string input, encodedInput, decodedInput, output;

	cout << "Geben Sie ein Wort aus 5 Grossbuchstaben ein:" << endl;						//Encode
	cin.getline(buf, 80);
	input = string(buf, buf + NUM_OF_CHARS);
	encodedInput = encode(input);
	cout << input << endl << encodedInput << endl;

	cout << "Geben Sie ein verschluesseltes Wort aus 5 Grossbuchstaben ein:" << endl;		//Decode
	cin.getline(buf, 80);
	input = string(buf, buf + NUM_OF_CHARS);
	decodedInput = decode(input);
	cout << decodedInput << endl;

	for (int i = 0; i < 2; i++)
	{
		cout << "Geben Sie ein Wort aus Grossbuchstaben ein:" << endl;		//Enigma, run twice
		cin.getline(buf, 80);
		input = buf;
		output = enigma(input);
		cout << output << endl;
	}

	getchar();
	return 0;
}

string enigma(string s)
{
	for (unsigned int i = 0; i < s.length(); i++)
	{
		s[i] = enigma(s[i]);
	}
	return s;
}

string encode(string s)
{
	for (unsigned int i = 0; i < s.length(); i++)
	{
		s[i] = encode(s[i]);
	}
	return s;
}

string decode(string s)
{
	for (unsigned int i = 0; i < s.length(); i++)
	{
		s[i] = decode(s[i]);
	}
	return s;
}

char encode(char c)
{
	return table[1][static_cast<int>(c) - 65];
}

char enigma(char c)
{
	return enigmaTable[1][static_cast<int>(c) - 65];
}

char decode(char c)
{
	return decodingTable[1][static_cast<int>(c) - 65];
}

void printArray()
{

	random_shuffle(&table[0][0], &table[0][25]);		//used to generate list of chars
	char c;
	for (int i = 0; i < 26; i++)
	{
		//c = static_cast<char>(65 + i);				//65 upper case, 97 lower case		//list in order
		c = table[0][i];																	//list shuffled
		cout << "\'" << c << "\', ";
	}
}