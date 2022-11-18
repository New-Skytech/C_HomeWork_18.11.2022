#include <iostream>
#include <fstream>

using namespace std;


int main()
{
    ifstream infile;
    ofstream outfile;
    string word;
    int leng;
    int size;


    remove("OUTPUT.txt");

    infile.open("INPUT.txt");
    outfile.open("OUTPUT.txt", ofstream::app);

    infile >> size;
    
    for (int x = 0; x < size; x++) {
        infile >> word;
        leng = word.size();
        bool flag = true;
        for (int y = 1; y < leng; y++) {
            if (word[y - 1] > word[y]) {
                flag = false;
            }
        }
        if (flag == false) {
            outfile << "NO" << endl;
            continue;
        }
        int zero_counter = 0, one_counter = 0, two_counter = 0;
        if (word[0] == 48) {
            zero_counter++;
        }
        else
        {
            outfile << "NO" << endl;
            continue;
        }
        for (int i = 1; i < leng; i++) {
            if (word[i] == 48) {
                zero_counter++;
            }
            if (word[i] == 49) {
                one_counter++;
            }
            if (word[i] == 50) {
                two_counter++;
            }
        }
        if (zero_counter == one_counter and one_counter == two_counter) {
            outfile << "YES" << endl;
        }
        else {
            outfile << "NO" << endl;
        }
    }
    infile.close();
    outfile.close();
}
