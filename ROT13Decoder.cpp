#include <iostream>

#include <fstream>

#include <string>

using namespace std;

int main()
{
	ifstream dataFile;

	ofstream outFile;
	outFile.open("decodedMessage.txt");
	char temp;

	dataFile.open("secretMessage.txt");
	if (!dataFile)
	{
		cout<<"The file did not open";
		return 0;
	}

	dataFile.get(temp);
		while(!dataFile.eof())
		{
			if (temp>= 'a' && temp<= 'm') temp += 13;
			else if(temp>= 'n' && temp<= 'z') temp -= 13;
			else if(temp>= 'A' && temp<= 'M') temp += 13;
			else if(temp>= 'N' && temp<= 'Z') temp -= 13;
			outFile<<temp;
			dataFile.get(temp);			
		}

	outFile<< temp;
	
	return 0;
}