// ProceduralProgrammingProjects.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

const int MAX_STUDENTS = 100;
const int MAX_TEST_SCORES = 100;

string studentNames[MAX_STUDENTS];
double testScores[MAX_STUDENTS][MAX_TEST_SCORES];
double averages[MAX_STUDENTS];

int numStudents = 0;
int numTestScores = 0;

void readData(ifstream& inputFile);
void calculateAverages();
char calculateLetterGrade(double average);
void reportCard();

int main() {
    ifstream inputFile("StudentGrades.txt");
    if (!inputFile) {
        cout << "Error opening file! Check path and file name." << endl;
        return 1;
    }

    readData(inputFile);
    inputFile.close();

    calculateAverages();
    reportCard();

    return 0;
}

void readData(ifstream& inputFile) {
    numStudents = 0;
    string name;
    double score;

    while (inputFile >> name) {
        studentNames[numStudents] = name;
        int i = 0;

        // Read test scores until end of line or maximum test scores
        while (i < MAX_TEST_SCORES && inputFile >> score) {
            testScores[numStudents][i] = score;
            i++;
            if (inputFile.peek() == '\n' || inputFile.peek() == EOF) {
                break;
            }
        }

        // Base number of scores on the first student's scores
        if (numTestScores == 0) {
            numTestScores = i;
        }

        numStudents++;
    }
}
// Iterate through the array of students and the array of test scores, calculating averages per student.
void calculateAverages() {
    for (int i = 0; i < numStudents; i++) {
        double total = 0;
        for (int j = 0; j < numTestScores; j++) {
            total += testScores[i][j];
        }
        if (numTestScores != 0) {
            averages[i] = total / numTestScores;
        }
        else {
            averages[i] = 0; // In case of division by zero
        }
    }
}

char calculateLetterGrade(double average) {
    if (average >= 90) return 'A';
    else if (average >= 80) return 'B';
    else if (average >= 70) return 'C';
    else if (average >= 60) return 'D';
    else return 'F';
}


// Report formatting
void reportCard() {
    cout << left << setw(20) << "Student Name"
        << setw(10) << "Average"
        << setw(10) << "Grade" << endl;
    cout << "**************************************" << endl;
    // Loop through the studentNames array based on the numStudents value to output names, averages, and letter grade.
    for (int i = 0; i < numStudents; i++) {
        cout << left << setw(20) << studentNames[i]
            << setw(10) << fixed << setprecision(2) << averages[i]
            << setw(10) << calculateLetterGrade(averages[i]) << endl;
    }
}
