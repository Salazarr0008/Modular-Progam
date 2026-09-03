#ifndef GRADES_H 

#define GRADES_H 

 

#include <array> 

#include "constants.h" 

 

double studentAverage( 

    const std::array< 

        std::array<double, ASSIGNMENT_COUNT>, 

        STUDENT_COUNT 

    >& scores, 

    int studentIndex 

); 

 

double assignmentAverage( 

    const std::array< 

        std::array<double, ASSIGNMENT_COUNT>, 

        STUDENT_COUNT 

    >& scores, 

    int assignmentIndex 

); 

 

void findExtremes( 

    const std::array< 

        std::array<double, ASSIGNMENT_COUNT>, 

        STUDENT_COUNT 

    >& scores, 

    int studentIndex, 

    double& lowest, 

    double& highest 

); 

 

int countGrade( 

    const std::array< 

        std::array<double, ASSIGNMENT_COUNT>, 

        STUDENT_COUNT 

    >& scores, 

    char target 

); 

 

double classAverage( 

    const std::array< 

        std::array<double, ASSIGNMENT_COUNT>, 

        STUDENT_COUNT 

    >& scores 

); 

 

bool hasPerfectScore( 

    const std::array< 

        std::array<double, ASSIGNMENT_COUNT>, 

        STUDENT_COUNT 

    >& scores, 

    int studentIndex 

); 

 

bool isAtRisk( 

    const std::array< 

        std::array<double, ASSIGNMENT_COUNT>, 

        STUDENT_COUNT 

    >& scores, 

    int studentIndex 

); 

 

#endif
