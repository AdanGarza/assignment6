// Assignment 6 - User-Defined Functions
// multi-function C++ program that demonstrates each concept from the assignment requirements
// ============================================================

#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>

// Prototypes
double calcTax(double income, double rate);
double calcShipping(double weight, double ratePerPound = 1.50, double baseFee = 5.00);
void mathSummary(double x);
void printHeader(const std::string &title);
void displayResult(const std::string &label, double value);
void convertTime(int totalSeconds, int &minutes, int &seconds);
void countCalls();
void displayBox(int width);
void displayBox(int width, int height);

// ============================================================
// Function: mathSummary
// Purpose : Demonstrate predefined math functions from <cmath>
// Params  : x - input value to summarize
// Returns : void
// ============================================================
void mathSummary(double x)
{
    std::cout << "mathSummary for " << x << " -> ";
    std::cout << "sqrt=" << std::sqrt(x) << ", ";
    std::cout << "x^3=" << std::pow(x, 3.0) << ", ";
    std::cout << "ceil=" << std::ceil(x) << ", ";
    std::cout << "floor=" << std::floor(x) << ", ";
    std::cout << "abs(x*-1)=" << std::fabs(x * -1.0) << '\n';
}

// ============================================================
// Function: calcTax
// Purpose : Calculate tax owed based on income and rate
// Params  : income - gross income
//           rate   - tax rate as decimal (e.g., 0.25)
// Returns : tax owed (double)
// ============================================================
double calcTax(double income, double rate)
{
    return income * rate;
}

// ============================================================
// Function: printHeader
// Purpose : Print a simple titled header to separate parts
// Params  : title - header text to display
// Returns : void
// ============================================================
void printHeader(const std::string &title)
{
    std::cout << "\n=== " << title << " ===\n";
}

// ============================================================
// Function: displayResult
// Purpose : Print a descriptive label and a numeric value formatted
// Params  : label - text label to show
//           value - numeric value to display
// Returns : void
// ============================================================
void displayResult(const std::string &label, double value)
{
    std::cout << std::left << std::setw(18) << label << ": " << std::fixed << std::setprecision(2) << value << '\n';
}

// ============================================================
// Function: convertTime
// Purpose : Convert total seconds into minutes and remaining seconds
// Params  : totalSeconds - input seconds (by value)
//           minutes      - output minutes (by reference)
//           seconds      - output seconds (by reference)
// Returns : void
// Note    : minutes and seconds are references so the caller
//           receives the computed results.
// ============================================================
void convertTime(int totalSeconds, int &minutes, int &seconds)
{
    minutes = totalSeconds / 60;
    seconds = totalSeconds % 60;
}

// ============================================================
// Function: countCalls
// Purpose : Track and display how many times this function was called
// Params  : none
// Returns : void
// Note    : Uses a static local variable to retain the call count
//           between invocations.
// ============================================================
void countCalls()
{
    static int calls = 0;
    ++calls;
    std::cout << "countCalls has been called " << calls << " time(s)." << '\n';
}

// ============================================================
// Function: displayBox (square)
// Purpose : Draw a square outline of '*' characters (width x width)
// Params  : width - side length in characters
// Returns : void
// ============================================================
void displayBox(int width)
{
    displayBox(width, width);
}

// ============================================================
// Function: displayBox (rectangle)
// Purpose : Draw a rectangular outline of '*' characters
// Params  : width  - number of columns
//           height - number of rows
// Returns : void
// ============================================================
void displayBox(int width, int height)
{
    if (width <= 0 || height <= 0)
    {
        std::cout << "Invalid box size." << '\n';
        return;
    }
    for (int r = 0; r < height; ++r)
    {
        for (int c = 0; c < width; ++c)
            std::cout << ((r == 0 || r == height - 1 || c == 0 || c == width - 1) ? '*' : ' ');
        std::cout << '\n';
    }
}

// ============================================================
// Function: calcShipping
// Purpose : Compute shipping cost using optional default rate/base fee
// Params  : weight        - package weight in pounds
//           ratePerPound - cost per pound
//           baseFee      - flat base fee
// Returns : total shipping cost (double)
// ============================================================
double calcShipping(double weight, double ratePerPound, double baseFee)
{
    return baseFee + weight * ratePerPound;
}

// ============================================================
// Function: main
// Purpose : Drive program demonstrating all parts (1-7)
// Params  : none
// Returns : exit code (int)
// ============================================================
int main()
{
    std::cout << std::fixed << std::setprecision(2);

    // Part 1
    printHeader("Part 1 - Math Summary");
    mathSummary(16.0);
    mathSummary(5.75);

    // Part 2 & 3
    printHeader("Part 2 - Tax Calculation");
    double income = 0.0, rate = 0.0;
    std::cout << "Enter gross income: ";
    std::cin >> income;
    std::cout << "Enter tax rate (decimal, e.g. 0.25): ";
    std::cin >> rate;
    double tax = calcTax(income, rate);
    displayResult("Gross Income", income);
    displayResult("Tax Rate", rate);
    displayResult("Tax Owed", tax);

    // Part 4
    printHeader("Part 4 - Time Conversion");
    int totalSec = 0;
    std::cout << "Enter seconds: ";
    std::cin >> totalSec;
    int mins = 0, secs = 0;
    convertTime(totalSec, mins, secs);
    displayResult("Minutes", static_cast<double>(mins));
    displayResult("Seconds", static_cast<double>(secs));

    // Part 5
    printHeader("Part 5 - Static Variable");
    countCalls();
    countCalls();
    countCalls();
    countCalls();

    // Part 6
    printHeader("Part 6 - displayBox Overloads");
    std::cout << "Square 4x4:\n";
    displayBox(4);
    std::cout << "Rectangle 6x2:\n";
    displayBox(6, 2);

    // Part 7
    printHeader("Part 7 - calcShipping Defaults");
    double w = 8.0;
    displayResult("Ship (all args)", calcShipping(w, 2.0, 6.0));
    displayResult("Ship (w+rate)", calcShipping(w, 2.0));
    displayResult("Ship (w only)", calcShipping(w));

    return 0;
}
