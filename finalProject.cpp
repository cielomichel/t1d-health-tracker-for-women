#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <limits>
#include <algorithm>
using namespace std;

class HealthEntry {
private:
    string date;
    string time;
    int bloodSugar;
    int cycleDay;
    string cyclePhase;
    bool periodStarted;
    string symptoms;
    int stressLevel;
    double sleepHours;
    string exercise;
    string insulinNotes;
    string foodNotes;
    string waterIntake;
    string mood;
    string generalNotes;

public:
    HealthEntry() {
        date = "";
        time = "";
        bloodSugar = 0;
        cycleDay = 0;
        cyclePhase = "Unknown";
        periodStarted = false;
        symptoms = "None";
        stressLevel = 0;
        sleepHours = 0.0;
        exercise = "None";
        insulinNotes = "None";
        foodNotes = "None";
        waterIntake = "Unknown";
        mood = "Unknown";
        generalNotes = "None";
    }

    HealthEntry(string d, string t, int bs, int cd, string cp, bool ps,
                string sym, int stress, double sleep, string ex, string insulin,
                string food, string water, string m, string notes) {
        date = d;
        time = t;
        bloodSugar = bs;
        cycleDay = cd;
        cyclePhase = cp;
        periodStarted = ps;
        symptoms = sym;
        stressLevel = stress;
        sleepHours = sleep;
        exercise = ex;
        insulinNotes = insulin;
        foodNotes = food;
        waterIntake = water;
        mood = m;
        generalNotes = notes;
    }

    string getDate() const {
        return date;
    }

    string getTime() const {
        return time;
    }

    int getBloodSugar() const {
        return bloodSugar;
    }

    int getCycleDay() const {
        return cycleDay;
    }

    string getCyclePhase() const {
        return cyclePhase;
    }

    bool getPeriodStarted() const {
        return periodStarted;
    }

    string getSymptoms() const {
        return symptoms;
    }

    int getStressLevel() const {
        return stressLevel;
    }

    double getSleepHours() const {
        return sleepHours;
    }

    string getExercise() const {
        return exercise;
    }

    string getInsulinNotes() const {
        return insulinNotes;
    }

    string getFoodNotes() const {
        return foodNotes;
    }

    string getWaterIntake() const {
        return waterIntake;
    }

    string getMood() const {
        return mood;
    }

    string getGeneralNotes() const {
        return generalNotes;
    }

    void setDate(string d) {
        date = d;
    }

    void setTime(string t) {
        time = t;
    }

    void setBloodSugar(int bs) {
        bloodSugar = bs;
    }

    void setCycleDay(int cd) {
        cycleDay = cd;
    }

    void setCyclePhase(string cp) {
        cyclePhase = cp;
    }

    void setPeriodStarted(bool ps) {
        periodStarted = ps;
    }

    void setSymptoms(string sym) {
        symptoms = sym;
    }

    void setStressLevel(int stress) {
        stressLevel = stress;
    }

    void setSleepHours(double sleep) {
        sleepHours = sleep;
    }

    void setExercise(string ex) {
        exercise = ex;
    }

    void setInsulinNotes(string insulin) {
        insulinNotes = insulin;
    }

    void setFoodNotes(string food) {
        foodNotes = food;
    }

    void setWaterIntake(string water) {
        waterIntake = water;
    }

    void setMood(string m) {
        mood = m;
    }

    void setGeneralNotes(string notes) {
        generalNotes = notes;
    }

    string getBloodSugarCategory() const {
        if (bloodSugar < 70) {
            return "Low";
        }
        else if (bloodSugar <= 180) {
            return "In range";
        }
        else if (bloodSugar <= 250) {
            return "High";
        }
        else {
            return "Very high";
        }
    }

    void displayShort(int index) const {
        cout << left << setw(5) << index
             << setw(14) << date
             << setw(10) << time
             << setw(10) << bloodSugar
             << setw(16) << getBloodSugarCategory()
             << setw(18) << cyclePhase
             << setw(12) << stressLevel
             << setw(10) << sleepHours << "\n";
    }

    void displayFull() const {
        cout << "\n----------------------------------------\n";
        cout << "Date: " << date << "\n";
        cout << "Time: " << time << "\n";
        cout << "Blood sugar: " << bloodSugar << " mg/dL\n";
        cout << "Category: " << getBloodSugarCategory() << "\n";
        cout << "Cycle day: " << cycleDay << "\n";
        cout << "Cycle phase: " << cyclePhase << "\n";
        cout << "Period started: " << (periodStarted ? "Yes" : "No") << "\n";
        cout << "Symptoms: " << symptoms << "\n";
        cout << "Stress level: " << stressLevel << "/10\n";
        cout << "Sleep hours: " << sleepHours << "\n";
        cout << "Exercise: " << exercise << "\n";
        cout << "Insulin notes: " << insulinNotes << "\n";
        cout << "Food notes: " << foodNotes << "\n";
        cout << "Water intake: " << waterIntake << "\n";
        cout << "Mood: " << mood << "\n";
        cout << "General notes: " << generalNotes << "\n";
        cout << "----------------------------------------\n";
    }

};

void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int getIntInput(string prompt, int minValue, int maxValue) {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;

        if (!cin.fail() && value >= minValue && value <= maxValue) {
            clearInput();
            return value;
        }

        cout << "Invalid input. Please enter a number between " << minValue << " and " << maxValue << ".\n";
        clearInput();
    }
}

double getDoubleInput(string prompt, double minValue, double maxValue) {
    double value;
    while (true) {
        cout << prompt;
        cin >> value;

        if (!cin.fail() && value >= minValue && value <= maxValue) {
            clearInput();
            return value;
        }

        cout << "Invalid input. Please enter a number between " << minValue << " and " << maxValue << ".\n";
        clearInput();
    }
}

string getStringInput(string prompt) {
    string value;
    cout << prompt;
    getline(cin, value);

    if (value.empty()) {
        return "None";
    }

    return value;
}

bool getYesNoInput(string prompt) {
    char answer;
    while (true) {
        cout << prompt;
        cin >> answer;
        clearInput();

        answer = tolower(answer);

        if (answer == 'y') {
            return true;
        }
        else if (answer == 'n') {
            return false;
        }
        else {
            cout << "Please enter y or n.\n";
        }
    }
}

string chooseCyclePhase() {
    cout << "\nChoose cycle phase:\n";
    cout << "1. Menstrual\n";
    cout << "2. Follicular\n";
    cout << "3. Ovulation\n";
    cout << "4. Luteal/PMS\n";
    cout << "5. Unknown\n";

    int choice = getIntInput("Enter choice: ", 1, 5);

    if (choice == 1) {
        return "Menstrual";
    }
    else if (choice == 2) {
        return "Follicular";
    }
    else if (choice == 3) {
        return "Ovulation";
    }
    else if (choice == 4) {
        return "Luteal/PMS";
    }
    else {
        return "Unknown";
    }
}

void printHeader() {
    cout << "\n========================================\n";
    cout << "        Health Tracker for Women      \n";
    cout << "========================================\n";
    cout << "A women-focused Type 1 diabetes tracker\n";
    cout << "for glucose, cycle patterns, symptoms,\n";
    cout << "sleep, stress, food, insulin, and notes.\n";
}

void printMenu() {
    cout << "\n--------------- Main Menu ---------------\n";
    cout << "1. Add daily health entry\n";
    cout << "2. View all entries\n";
    cout << "3. View full entry details\n";
    cout << "4. Search entries by date\n";
    cout << "5. Edit an entry\n";
    cout << "6. Delete an entry\n";
    cout << "7. Blood sugar summary\n";
    cout << "8. Cycle phase trend summary\n";
    cout << "9. Symptom and lifestyle summary\n";
    cout << "10. Exit\n";
    cout << "-----------------------------------------\n";
}

void addEntry(vector<HealthEntry>& entries) {
    cout << "\nAdd New Health Entry\n";
    cout << "Use a format like 05/01/2026 for date.\n";

    string date = getStringInput("Date: ");
    string time = getStringInput("Time: ");
    int bloodSugar = getIntInput("Blood sugar mg/dL: ", 20, 600);
    int cycleDay = getIntInput("Cycle day, or 0 if unknown: ", 0, 60);
    string cyclePhase = chooseCyclePhase();
    bool periodStarted = getYesNoInput("Did your period start today? y/n: ");
    string symptoms = getStringInput("Symptoms, like cramps, bloating, cravings, fatigue: ");
    int stressLevel = getIntInput("Stress level 0-10: ", 0, 10);
    double sleepHours = getDoubleInput("Sleep hours: ", 0.0, 24.0);
    string exercise = getStringInput("Exercise notes: ");
    string insulinNotes = getStringInput("Insulin notes: ");
    string foodNotes = getStringInput("Food notes: ");
    string waterIntake = getStringInput("Water intake notes: ");
    string mood = getStringInput("Mood: ");
    string generalNotes = getStringInput("General notes: ");

    HealthEntry entry(date, time, bloodSugar, cycleDay, cyclePhase, periodStarted,
                      symptoms, stressLevel, sleepHours, exercise, insulinNotes,
                      foodNotes, waterIntake, mood, generalNotes);

    entries.push_back(entry);
    cout << "Entry added successfully.\n";
}

void viewAllEntries(const vector<HealthEntry>& entries) {
    if (entries.empty()) {
        cout << "\nNo entries found.\n";
        return;
    }

    cout << "\nAll Entries\n";
    cout << left << setw(5) << "#"
         << setw(14) << "Date"
         << setw(10) << "Time"
         << setw(10) << "Glucose"
         << setw(16) << "Category"
         << setw(18) << "Cycle Phase"
         << setw(12) << "Stress"
         << setw(10) << "Sleep" << "\n";

    cout << string(95, '-') << "\n";

    for (size_t i = 0; i < entries.size(); i++) {
        entries[i].displayShort(static_cast<int>(i + 1));
    }
}

void viewFullEntry(const vector<HealthEntry>& entries) {
    if (entries.empty()) {
        cout << "\nNo entries found.\n";
        return;
    }

    viewAllEntries(entries);
    int index = getIntInput("Enter entry number to view: ", 1, static_cast<int>(entries.size()));
    entries[index - 1].displayFull();
}

void searchByDate(const vector<HealthEntry>& entries) {
    if (entries.empty()) {
        cout << "\nNo entries found.\n";
        return;
    }

    string targetDate = getStringInput("Enter date to search: ");
    bool found = false;

    cout << "\nSearch Results\n";

    for (size_t i = 0; i < entries.size(); i++) {
        if (entries[i].getDate() == targetDate) {
            entries[i].displayFull();
            found = true;
        }
    }

    if (!found) {
        cout << "No entries found for that date.\n";
    }
}

void editEntry(vector<HealthEntry>& entries) {
    if (entries.empty()) {
        cout << "\nNo entries found.\n";
        return;
    }

    viewAllEntries(entries);
    int index = getIntInput("Enter entry number to edit: ", 1, static_cast<int>(entries.size()));
    HealthEntry& entry = entries[index - 1];

    cout << "\nEditing Entry\n";
    cout << "Leave text responses blank to store None.\n";

    entry.setDate(getStringInput("New date: "));
    entry.setTime(getStringInput("New time: "));
    entry.setBloodSugar(getIntInput("New blood sugar mg/dL: ", 20, 600));
    entry.setCycleDay(getIntInput("New cycle day, or 0 if unknown: ", 0, 60));
    entry.setCyclePhase(chooseCyclePhase());
    entry.setPeriodStarted(getYesNoInput("Did your period start today? y/n: "));
    entry.setSymptoms(getStringInput("New symptoms: "));
    entry.setStressLevel(getIntInput("New stress level 0-10: ", 0, 10));
    entry.setSleepHours(getDoubleInput("New sleep hours: ", 0.0, 24.0));
    entry.setExercise(getStringInput("New exercise notes: "));
    entry.setInsulinNotes(getStringInput("New insulin notes: "));
    entry.setFoodNotes(getStringInput("New food notes: "));
    entry.setWaterIntake(getStringInput("New water intake notes: "));
    entry.setMood(getStringInput("New mood: "));
    entry.setGeneralNotes(getStringInput("New general notes: "));

    cout << "Entry updated successfully.\n";
}

void deleteEntry(vector<HealthEntry>& entries) {
    if (entries.empty()) {
        cout << "\nNo entries found.\n";
        return;
    }

    viewAllEntries(entries);
    int index = getIntInput("Enter entry number to delete: ", 1, static_cast<int>(entries.size()));
    bool confirm = getYesNoInput("Are you sure you want to delete this entry? y/n: ");

    if (confirm) {
        entries.erase(entries.begin() + index - 1);
        cout << "Entry deleted.\n";
    }
    else {
        cout << "Delete canceled.\n";
    }
}

void bloodSugarSummary(const vector<HealthEntry>& entries) {
    if (entries.empty()) {
        cout << "\nNo entries found.\n";
        return;
    }

    int total = 0;
    int lowest = entries[0].getBloodSugar();
    int highest = entries[0].getBloodSugar();
    int lowCount = 0;
    int rangeCount = 0;
    int highCount = 0;
    int veryHighCount = 0;

    for (size_t i = 0; i < entries.size(); i++) {
        int bg = entries[i].getBloodSugar();
        total += bg;

        if (bg < lowest) {
            lowest = bg;
        }

        if (bg > highest) {
            highest = bg;
        }

        if (bg < 70) {
            lowCount++;
        }
        else if (bg <= 180) {
            rangeCount++;
        }
        else if (bg <= 250) {
            highCount++;
        }
        else {
            veryHighCount++;
        }
    }

    double average = static_cast<double>(total) / entries.size();

    cout << fixed << setprecision(1);
    cout << "\nBlood Sugar Summary\n";
    cout << "Total entries: " << entries.size() << "\n";
    cout << "Average blood sugar: " << average << " mg/dL\n";
    cout << "Lowest blood sugar: " << lowest << " mg/dL\n";
    cout << "Highest blood sugar: " << highest << " mg/dL\n";
    cout << "Low readings: " << lowCount << "\n";
    cout << "In-range readings: " << rangeCount << "\n";
    cout << "High readings: " << highCount << "\n";
    cout << "Very high readings: " << veryHighCount << "\n";

    cout << "\nPattern notes:\n";

    if (lowCount > 0) {
        cout << "You recorded at least one low reading. Lows are important to watch closely.\n";
    }

    if (highCount + veryHighCount > rangeCount) {
        cout << "More readings were high than in range. Consider reviewing food, insulin, cycle, sleep, and stress notes.\n";
    }
    else {
        cout << "Most readings were not marked high. Keep tracking to see longer-term patterns.\n";
    }
}

void cycleTrendSummary(const vector<HealthEntry>& entries) {
    if (entries.empty()) {
        cout << "\nNo entries found.\n";
        return;
    }

    vector<string> phases;
    phases.push_back("Menstrual");
    phases.push_back("Follicular");
    phases.push_back("Ovulation");
    phases.push_back("Luteal/PMS");
    phases.push_back("Unknown");

    cout << "\nCycle Phase Trend Summary\n";

    for (size_t i = 0; i < phases.size(); i++) {
        string phase = phases[i];
        int total = 0;
        int count = 0;
        int highCount = 0;
        int lowCount = 0;

        for (size_t j = 0; j < entries.size(); j++) {
            if (entries[j].getCyclePhase() == phase) {
                int bg = entries[j].getBloodSugar();
                total += bg;
                count++;

                if (bg > 180) {
                    highCount++;
                }

                if (bg < 70) {
                    lowCount++;
                }
            }
        }

        if (count > 0) {
            double average = static_cast<double>(total) / count;
            cout << fixed << setprecision(1);
            cout << "\n" << phase << " phase:\n";
            cout << "Entries: " << count << "\n";
            cout << "Average glucose: " << average << " mg/dL\n";
            cout << "High readings: " << highCount << "\n";
            cout << "Low readings: " << lowCount << "\n";
        }
    }

    cout << "\nReminder: This program does not give medical advice. It helps organize patterns you may want to discuss with a healthcare professional.\n";
}

void symptomLifestyleSummary(const vector<HealthEntry>& entries) {
    if (entries.empty()) {
        cout << "\nNo entries found.\n";
        return;
    }

    int highStressHighBg = 0;
    int poorSleepHighBg = 0;
    int periodStartCount = 0;
    int periodStartHighBg = 0;
    double totalSleep = 0;
    int totalStress = 0;

    for (size_t i = 0; i < entries.size(); i++) {
        int bg = entries[i].getBloodSugar();
        int stress = entries[i].getStressLevel();
        double sleep = entries[i].getSleepHours();

        totalSleep += sleep;
        totalStress += stress;

        if (stress >= 7 && bg > 180) {
            highStressHighBg++;
        }

        if (sleep < 6 && bg > 180) {
            poorSleepHighBg++;
        }

        if (entries[i].getPeriodStarted()) {
            periodStartCount++;

            if (bg > 180) {
                periodStartHighBg++;
            }
        }
    }

    double avgSleep = totalSleep / entries.size();
    double avgStress = static_cast<double>(totalStress) / entries.size();

    cout << fixed << setprecision(1);
    cout << "\nSymptom and Lifestyle Summary\n";
    cout << "Average sleep: " << avgSleep << " hours\n";
    cout << "Average stress level: " << avgStress << "/10\n";
    cout << "High glucose readings during high stress days: " << highStressHighBg << "\n";
    cout << "High glucose readings after less than 6 hours of sleep: " << poorSleepHighBg << "\n";
    cout << "Days marked as period start: " << periodStartCount << "\n";
    cout << "High readings on period start days: " << periodStartHighBg << "\n";

    cout << "\nPossible pattern observations:\n";

    if (highStressHighBg > 0) {
        cout << "Stress may be worth tracking closely with blood sugar changes.\n";
    }

    if (poorSleepHighBg > 0) {
        cout << "Lower sleep days appeared near some high readings.\n";
    }

    if (periodStartHighBg > 0) {
        cout << "Some high readings happened on days marked as period start.\n";
    }

    if (highStressHighBg == 0 && poorSleepHighBg == 0 && periodStartHighBg == 0) {
        cout << "No strong lifestyle pattern was detected yet. More entries may reveal more.\n";
    }
}

void runProgram() {
    vector<HealthEntry> entries;
    int choice;
    bool running = true;

    printHeader();

    while (running) {
        printMenu();
        choice = getIntInput("Choose an option: ", 1, 10);

        if (choice == 1) {
            addEntry(entries);
        }
        else if (choice == 2) {
            viewAllEntries(entries);
        }
        else if (choice == 3) {
            viewFullEntry(entries);
        }
        else if (choice == 4) {
            searchByDate(entries);
        }
        else if (choice == 5) {
            editEntry(entries);
        }
        else if (choice == 6) {
            deleteEntry(entries);
        }
        else if (choice == 7) {
            bloodSugarSummary(entries);
        }
        else if (choice == 8) {
            cycleTrendSummary(entries);
        }
        else if (choice == 9) {
            symptomLifestyleSummary(entries);
        }
        else if (choice == 10) {
            running = false;
            cout << "Goodbye. Keep tracking your patterns.\n";
        }
    }
}

int main() {
    runProgram();
    return 0;
}
