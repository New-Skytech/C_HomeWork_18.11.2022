#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string str, date[1000002];
string BaseForConvertation = ("0" "1" "2" "3" "4" "5" "6" "7" "8" "9" "A" "B" "C" "D" "E" "F" "G" "H" "I" "J" "K" "L" "M" "N" "O" "P" "Q" "R" "S" "T" "U");

ifstream filein;
ofstream fileout;

int main() {
	filein.open("INPUT.txt");
	fileout.open("OUTPUT.txt");
	getline(filein, str);

	int s = 0;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '/') {
			s++;
			continue;
		}
		date[s] += str[i]; 
	}

	
	int base = stoi (date[0]) + 1;

	for (int i = 0; i < 3; i++) {
		int number = stoi(date[i]);
		int ostatok = 0;
		string ansver = "", chr = "";
		while (number > 0) {
			ostatok = number % base;
			number = number / base;
			chr = BaseForConvertation[ostatok];
			chr += ansver;
			ansver = chr;
		}
		fileout << ansver;
		if (i < 2) {
			fileout << "/";
		}
	}
	filein.close();
	fileout.close();
}

