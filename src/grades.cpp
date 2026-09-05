#include "grades.h" 
#include "utilities.h" 
#include "constants.h" 

#include <iostream> 
#include <limits> 

// finds the average grade for one student
double studentAverage( 
    const std::array<std::array<double, ASSIGNMENT_COUNT>, 
    STUDENT_COUNT>& scores, 
    int studentIndex) { 

    // makes sure the student number is valid
    if (studentIndex < 0 || studentIndex >= STUDENT_COUNT) { 
        std::cout << "Invalid index provided\n"; 
        return -1.0; 
    } 

    double total{}; 

    // adds all of the students grades together
    for (auto i{0}; i < ASSIGNMENT_COUNT; i++) { 
        total += scores[studentIndex][i]; 
    } 

    // returns the students average
    return total / ASSIGNMENT_COUNT; 
} 

// finds the average for one assignment
double assignmentAverage( 
    const std::array<std::array<double, ASSIGNMENT_COUNT>, 
    STUDENT_COUNT>& scores, 
    int assignmentIndex) { 

    double total{}; 

    // adds each students grade for the assignment
    for (auto i{0}; i < STUDENT_COUNT; i++) { 
        total += scores[i][assignmentIndex]; 
    } 

    // returns the assignment average
    return total / STUDENT_COUNT; 
} 

// finds the lowest and highest grade for a student
void findExtremes( 
    const std::array<std::array<double, ASSIGNMENT_COUNT>, 
    STUDENT_COUNT>& scores, 
    int studentIndex, 
    double& lowest, 
    double& highest) { 

    // starting values for lowest and highest
    lowest = std::numeric_limits<double>::max(); 
    highest = std::numeric_limits<double>::min(); 

    // goes through all the students grades
    for (auto i{0}; i < ASSIGNMENT_COUNT; i++) { 

        // checks for a new lowest grade
        if (scores[studentIndex][i] < lowest) { 
            lowest = scores[studentIndex][i]; 
        } 

        // checks for a new highest grade
        if (scores[studentIndex][i] > highest) { 
            highest = scores[studentIndex][i]; 
        } 
    } 
} 

// counts how many students have a certain letter grade
int countGrade( 
    const std::array<std::array<double, ASSIGNMENT_COUNT>, 
    STUDENT_COUNT>& scores, 
    char target) { 

    int count{}; 

    // goes through each student
    for (auto i{0}; i < STUDENT_COUNT; i++) { 

        // checks if their letter grade matches
        if (letterGrade(studentAverage(scores, i)) == target) { 
            count++; 
        } 
    } 

    return count; 
} 

// finds the average for the whole class
double classAverage( 
    const std::array<std::array<double, ASSIGNMENT_COUNT>, 
    STUDENT_COUNT>& scores) { 

    auto total{0.0}; 

    // goes through every student and assignment
    for (auto i{0}; i < STUDENT_COUNT; i++) { 
        for (auto j{0}; j < ASSIGNMENT_COUNT; j++) { 
            total += scores[i][j]; 
        } 
    } 

    // returns the class average
    return total / (STUDENT_COUNT * ASSIGNMENT_COUNT); 
} 

// checks if a student has a perfect score
bool hasPerfectScore( 
    const std::array<std::array<double, ASSIGNMENT_COUNT>, 
    STUDENT_COUNT>& scores, 
    int studentIndex) { 

    // checks all of the students grades
    for (auto i{0}; i < ASSIGNMENT_COUNT; i++) { 
        if (scores[studentIndex][i] >= 100.0) { 
            return true; 
        } 
    } 

    return false; 
} 

// checks if a student is at risk
bool isAtRisk( 
    const std::array<std::array<double, ASSIGNMENT_COUNT>, 
    STUDENT_COUNT>& scores, 
    int studentIndex) { 

    // checks if their average is below 70
    if (studentAverage(scores, studentIndex) < 70.0) { 
        return true; 
    } 

    // checks if any grade is below 50
    for (auto i{0}; i < ASSIGNMENT_COUNT; i++) { 
        if (scores[studentIndex][i] < 50.0) { 
            return true; 
        } 
    } 

    return false; 
} 
