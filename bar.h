// -----------------------------------------------------------------------

// Project 3 - Animated Bar Chart, bar.h
//
//  bar.h is used to aggregate info related of
//  countries (name ,value, category) for use in
//  barchart.h
//
// Author: Zaid Awaidah
// Date: 2 / 10 / 2022
// Class: CS 251, Spring 2022, UIC

// -----------------------------------------------------------------------

#include <iostream>
#include <string>
#include "myrandom.h"
using namespace std;

// -----------------------------------------------------------------------

/*
 * Bar
*/
class Bar {
private:
    int value;  // population
    string name;  // country name
    string category;  // continent

public:
    // default constructor:
    Bar() {
        value = 0;
        name = "";
        category = "";
    }

    // ----------------------------------

    // parameterized constructor
    Bar(string name, int value, string category) {
        this->name = name;
        this->category = category;
        this->value = value;
    }

    // ----------------------------------

    // destructor - no memory allocated in class
    virtual ~Bar() { ; }

    // ----------------------------------

    // getName:
    string getName() const { return name; }

    // ----------------------------------

    // getValue:
    int getValue() const { return value; }

    // ----------------------------------

    // getCategory:
    string getCategory() const { return category; }

    // ----------------------------------

    /* operators
     * These allow you to compare two Bar objects.
     * Comparison is based on the Bar's value.
    */
    // ----------------------------------

    // operator: <
    bool operator<(const Bar& other) const {
        bool decisionVal = false;
        if (this->value < other.getValue()) {
            decisionVal = true;
        }
        else {
            decisionVal = false;
        }
        return decisionVal;
    }

    // ----------------------------------

    // operator: <=
    bool operator<=(const Bar& other) const {
        bool decisionVal = false;
        if (this->value <= other.getValue()) {
            decisionVal = true;
        }
        else {
            decisionVal = false;
        }
        return decisionVal;
    }

    // ----------------------------------

    // // operator: >
    bool operator>(const Bar& other) const {
        bool decisionVal = false;
        if (this->value > other.getValue()) {
            decisionVal = true;
        }
        else {
            decisionVal = false;
        }
        return decisionVal;
    }

    // ----------------------------------

    // operator: >=
    bool operator>=(const Bar& other) const {
        bool decisionVal = false;
        if (this->value >= other.getValue()) {
            decisionVal = true;
        }
        else {
            decisionVal = false;
        }
        return decisionVal;
    }
};

// -----------------------------------------------------------------------
