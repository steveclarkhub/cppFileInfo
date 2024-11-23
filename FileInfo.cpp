// FileInfo.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>

using namespace std;

int main() {
    string filename;
    cout << "Enter the filename: ";
    cin >> filename;

    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Error: Could not open the file." << endl;
        return 1;
    }

    int lineCount = 0, blankLines = 0, duplicateLines = 0;
    string line, lineEnding;
    unordered_set<string> uniqueLines;

    while (getline(file, line)) {
        lineCount++;

        // Check for blank lines
        if (line.empty()) {
            blankLines++;
        }
        else {
            // Check for duplicate lines
            if (!uniqueLines.insert(line).second) {
                duplicateLines++;
            }

            // Determine line ending type (assuming consistent endings)
            if (lineEnding.empty()) {
                lineEnding = line.substr(line.length() - 1);
            }
        }
    }

    file.close();

    cout << "Total lines: " << lineCount << endl;
    cout << "Blank lines: " << blankLines << endl;
    cout << "Duplicate lines: " << duplicateLines << endl;
    return 0;
}