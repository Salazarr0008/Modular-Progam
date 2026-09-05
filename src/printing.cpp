#include "printRos.h" 
#include "grades.h" 
#include "utilities.h" 

#include <iostream> 
#include <iomanip> 

// prints the top of the grade report
void printHeader() { 

    std::cout << padName("STUDENT", NAME_WIDTH); 

    // prints the assignment numbers
    for (auto i{0}; i < ASSIGNMENT_COUNT; i++) { 
        std::cout << std::setw(5) << "A" << i; 
    } 

    // prints average and letter grade headers
    std::cout << std::setw(8) << "AVG" 
              << std::setw(6) << "GRADE" 
              << std::endl; 

    // prints a line under the header
    for (auto i{0}; i < 60; i++) { 
        std::cout << "-"; 
    } 

    std::cout << std::endl; 
} 

// prints one students grades and average
void printStudentRow( 
    const std::array<std::string, STUDENT_COUNT>& names, 
    const std::array<std::array<double, ASSIGNMENT_COUNT>, 
    STUDENT_COUNT>& scores, 
    int studentIndex) { 

    // prints the students name
    std::cout << padName(names[studentIndex], NAME_WIDTH); 

    // prints all their assignment grades
    for (auto i{0}; i < ASSIGNMENT_COUNT; i++) { 
        std::cout << std::setw(6) 
                  << std::setprecision(1) 
                  << std::fixed 
                  << scores[studentIndex][i]; 
    } 

    // gets the students average
    double avg{studentAverage(scores, studentIndex)}; 

    // prints average and letter grade
    std::cout << std::setw(8) 
              << std::setprecision(2) 
              << std::fixed 
              << avg 
              << " \t" 
              << letterGrade(avg); 

    // marks students with a perfect score
    if (hasPerfectScore(scores, studentIndex)) { 
        std::cout << "  *"; 
    } 

    // marks students that are at risk
    if (isAtRisk(scores, studentIndex)) { 
        std::cout << "  !"; 
    } 

    std::cout << std::endl; 
} 

// prints how many students have each letter grade
void printHistogram( 
    const std::array<std::array<double, ASSIGNMENT_COUNT>, 
    STUDENT_COUNT>& scores, 
    const std::array<std::string, STUDENT_COUNT>& names) { 

    // letter grades to check
    std::array<char, 5> letters{{'A', 'B', 'C', 'D', 'F'}}; 

    std::cout << "\nGRADE DISTRIBUTION\n"; 

    // goes through each letter grade
    for (auto letter : letters) { 

        // counts how many students have that grade
        auto count{countGrade(scores, letter)}; 

        std::cout << letter << " | "; 

        // prints one # for each student
        for (auto i{0}; i < count; i++) { 
            std::cout << "#"; 
        } 

        std::cout << "\t\t(" << count << ")\n"; 
    } 
} 

// prints the average for each assignment
void printAssignmentSummary( 
    const std::array<std::array<double, ASSIGNMENT_COUNT>, 
    STUDENT_COUNT>& scores) { 

    std::cout << "\nASSIGNMENT AVERAGES\n"; 

    // goes through each assignment
    for (auto i{0}; i < ASSIGNMENT_COUNT; i++) { 

        // gets the assignment average
        auto avg{assignmentAverage(scores, i)}; 

        std::cout << "  A" << i + 1 << ": " 
                  << std::setw(6) 
                  << std::setprecision(2) 
                  << std::fixed 
                  << avg; 

        // shows if an assignment average is below 70
        if (avg < 70.0) { 
            std::cout << "\t<-- review this assignment"; 
        } 

        std::cout << std::endl; 
    } 
} 

// prints the student roster
void printRoster( 
    const std::array<std::string, STUDENT_COUNT>& names) { 

    std::cout << "\nROSTER\n"; 

    // goes through all the student names
    for (auto name : names) { 

        // prints their initials and full name
        std::cout << initialsOf(name) 
                  << "\t" 
                  << name 
                  << std::endl; 
    } 
} 
