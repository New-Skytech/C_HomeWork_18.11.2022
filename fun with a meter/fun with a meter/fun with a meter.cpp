#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream infile;
    ofstream outfile;
    string trash;
    int size;
    int counter = 0;
    char ch;
    double distance;
    int difference_x;
    int difference_y;
    double previous_distances[1300], uniqe_distances[1300];
    int answer_counter = 0;

    remove("OUTPUT.txt");

    infile.open("INPUT.txt");
    outfile.open("OUTPUT.txt", ofstream::app);

    infile >> size;
    size = size * 2;
    int* coordinates = new int[size];

    while (!infile.eof()) {
        infile >> coordinates[counter];
        counter++;
    }
    
    counter = 0;

    for (int minuend = 0; minuend < size - 2; minuend += 2) {
        for (int subtrahend = minuend + 2; subtrahend < size - 1; subtrahend += 2) {
            difference_x = pow(coordinates[minuend] - coordinates[subtrahend], 2);
            difference_y = pow(coordinates[minuend + 1] - coordinates[subtrahend + 1], 2);
            distance = sqrt(difference_x + difference_y);
            counter++;
            bool flag = true;
            for (int i = 0; i < 7; i++) {
                if (distance == previous_distances[i]) {
                    flag = false;
                }
            }
            previous_distances[counter] = distance;
            if (flag) {
                uniqe_distances[answer_counter] = distance;
                answer_counter++;
            }
        }
    }
    outfile << answer_counter << endl;
    for (int i = 0; answer_counter > i; i++) {
        outfile << uniqe_distances[i] << endl;
    }
    infile.close();
    outfile.close();
}
