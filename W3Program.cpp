// Weekly Performance Evaluator — Week 3 

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    // Constants
    const double PRO_TRAIN_HRS = 6.0;   // hours per week for Pro level
    const double INT_TRAIN_HRS = 3.0;   // hours per week for Intermediate level
    const double SLEEP_MIN_OK = 7.0;   // below this is not enough sleep
    const double SLEEP_GOOD_MIN = 7.5;  // minimum of good sleep range
    const double SLEEP_GOOD_MAX = 9.0;  // maximum of good sleep range
    const double W_TRAIN = 10.0;        // training adds 10 points/hour
    const double W_SLEEP = 5.0;         // sleep adds 5 points/hour above 7

    // Welcome message
    cout << "==============================\n";
    cout << " Weekly Performance Evaluator\n";
    cout << "==============================\n\n";

    // User inputs
    string player;
    int age;
    double trainingHours;
    double sleepHours;

    cout << "Enter player's full name: ";
    getline(cin, player);

    cout << "Enter player's age: ";
    cin >> age;
    if (!cin || age <= 0) { cout << "Invalid age.\n"; return 0; }

    cout << "Training hours this week: ";
    cin >> trainingHours;
    if (!cin || trainingHours < 0.0) { cout << "Invalid training hours.\n"; return 0; }

    cout << "Avg sleep hours/night: ";
    cin >> sleepHours;
    if (!cin || sleepHours <= 0.0) { cout << "Invalid sleep hours.\n"; return 0; }

    // Calculate readiness score
    double readinessScore = (trainingHours * W_TRAIN)
        + ((sleepHours - SLEEP_MIN_OK) * W_SLEEP);

    // Determine performance level
    string level;
    if (trainingHours >= PRO_TRAIN_HRS
        && (sleepHours >= SLEEP_GOOD_MIN && sleepHours <= SLEEP_GOOD_MAX)) {
        level = "Pro";
    }
    else if (trainingHours >= INT_TRAIN_HRS && sleepHours >= SLEEP_MIN_OK) {
        level = "Intermediate";
    }
    else {
        level = "Beginner";
    }

    // Suggest advice
    string advice;
    if (sleepHours < SLEEP_MIN_OK || trainingHours < INT_TRAIN_HRS) {
        advice = "Build base: 3 focused sessions + target 8h sleep.";
    }
    else if (trainingHours >= PRO_TRAIN_HRS
        && !(sleepHours >= SLEEP_GOOD_MIN && sleepHours <= SLEEP_GOOD_MAX)) {
        advice = "Great workload; improve sleep routine for next gains.";
    }
    else {
        advice = "Solid balance; maintain consistency and recovery.";
    }

    // Menu setup
    string sectionTitle = "";
    string planFocus;
    double techMins;
    double condMins;
    string fatigueRisk;
    int restDays;
    string recoveryTip;

    // Show menu options
    cout << "\nMenu:\n";
    cout << "  1) Evaluate Level\n";
    cout << "  2) Build Training Plan\n";
    cout << "  3) Readiness & Recovery\n";
    cout << "Enter choice (1-3): ";
    int choice;
    cin >> choice;
    if (!cin) { cout << "Invalid menu choice.\n"; return 0; }
    cout << fixed << showpoint << setprecision(2);

    // Handle menu selection
    switch (choice)
    {
    case 1: { // Option 1: show player level
        sectionTitle = "LEVEL";
        cout << "\n----- LEVEL -----\n";
        cout << "Player: " << player << "\n";
        cout << "Age   : " << age << "\n";
        cout << "Level : " << level << "\n";
        cout << "Readiness Score: " << readinessScore << "\n";
        break;
    }

    case 2: { // Option 2: build a training plan
        sectionTitle = "TRAINING PLAN";
        cout << "\n------- TRAINING PLAN -------\n";

        // Plan focus depends on level
        if (level == "Pro")       planFocus = "Advanced Finishing & High-Tempo Play";
        else if (level == "Intermediate") planFocus = "Passing & Finishing Basics";
        else                      planFocus = "Ball Mastery & Light Conditioning";

        // Training time distribution
        if (level == "Pro") { techMins = 50.0; condMins = 30.0; }
        else if (level == "Intermediate") { techMins = 45.0; condMins = 25.0; }
        else { techMins = 35.0; condMins = 20.0; }

        // If sleep is low, shift more time to technique
        if (sleepHours < SLEEP_MIN_OK) {
            techMins += 10.0;
            condMins -= 10.0;
            if (condMins < 0.0) condMins = 0.0;
        }

        cout << left << setw(20) << "Player:" << right << setw(20) << player << "\n";
        cout << left << setw(20) << "Age:" << right << setw(20) << age << "\n";
        cout << left << setw(20) << "Level:" << right << setw(20) << level << "\n";
        cout << left << setw(20) << "Plan Focus:" << right << setw(20) << planFocus << "\n";
        cout << left << setw(20) << "Tech (min):" << right << setw(20) << techMins << "\n";
        cout << left << setw(20) << "Cond (min):" << right << setw(20) << condMins << "\n";
        cout << "------------------------------\n";
        break;
    }

    case 3: { // Option 3: recovery advice
        sectionTitle = "READINESS & RECOVERY";
        cout << "\n---- READINESS & RECOVERY ----\n";

        // Determine fatigue level
        if (sleepHours < SLEEP_MIN_OK) fatigueRisk = "High";
        else if ((trainingHours >= PRO_TRAIN_HRS && !(sleepHours >= SLEEP_GOOD_MIN && sleepHours <= SLEEP_GOOD_MAX))
            || trainingHours < INT_TRAIN_HRS) fatigueRisk = "Moderate";
        else fatigueRisk = "Low";

        // Rest days suggestion
        if (fatigueRisk == "High") restDays = 2;
        else if (fatigueRisk == "Moderate") restDays = 1;
        else restDays = 0;

        // Give recovery tip
        if (sleepHours < SLEEP_MIN_OK) recoveryTip = "Aim for 8h sleep; reduce screens.";
        else if (trainingHours >= PRO_TRAIN_HRS) recoveryTip = "Foam roll + light technical work.";
        else recoveryTip = "Stretch, hydrate, short ball session.";

        cout << left << setw(20) << "Player:" << right << setw(20) << player << "\n";
        cout << left << setw(20) << "Age:" << right << setw(20) << age << "\n";
        cout << left << setw(20) << "Fatigue Risk:" << right << setw(20) << fatigueRisk << "\n";
        cout << left << setw(20) << "Rest Days:" << right << setw(20) << restDays << "\n";
        cout << left << setw(20) << "Tip:" << right << setw(20) << recoveryTip << "\n";
        cout << "-------------------------------\n";
        break;
    }

    default:
        cout << "Invalid menu choice.\n";
        return 0;
    }

    // Save results to file
    ofstream out("report.txt");
    if (out) {
        out << fixed << showpoint << setprecision(2);
        out << "WEEKLY PERFORMANCE REPORT (Week 3)\n";
        out << "----------------------------------\n";
        out << left << setw(18) << "Player:" << right << setw(20) << player << "\n";
        out << left << setw(18) << "Age:" << right << setw(20) << age << "\n";
        out << left << setw(18) << "Train hrs:" << right << setw(20) << trainingHours << "\n";
        out << left << setw(18) << "Sleep (h):" << right << setw(20) << sleepHours << "\n";
        out << left << setw(18) << "Level:" << right << setw(20) << level << "\n";
        out << left << setw(18) << "Readiness:" << right << setw(20) << readinessScore << "\n";
        out << left << setw(18) << "Advice:" << right << setw(20) << advice << "\n";
        out << "----------------------------------\n";
        out.close();
        cout << "\nReport saved to report.txt\n";
    }
    else {
        cout << "\nError: could not open report.txt\n";
    }

    return 0;
}
