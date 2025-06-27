#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <ctime>
#include <algorithm> // For transform function
#include <map>
using namespace std;

// Function to wish the user according to time
void wishme() {
    time_t now = time(0);
    tm *time = localtime(&now);

    if (time->tm_hour < 12) {
        cout << "Good Morning Zain!" << endl;
        system("espeak \"Good Morning Zain\"");
    } else if (time->tm_hour >= 12 && time->tm_hour <= 16) {
        cout << "Good Afternoon Zain!" << endl;
        system("espeak \"Good Afternoon Zain\"");
    } else {
        cout << "Good Evening Zain!" << endl;
        system("espeak \"Good Evening Zain\"");
    }
}

// Function to show the date and time
void datetime() {
    time_t now = time(0);
    char *dt = ctime(&now);
    cout << "The current date and time is: " << dt << endl;
}

// Function to convert input to lowercase
string toLower(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

// Function to handle similar and typo-based commands
string matchCommand(string input) {
    map<string, string> commands = {
        {"motivate", "motivate"}, {"motivate me", "motivate"}, {"give me motivation", "motivate"},
        {"gaming tips", "gaming"}, {"game help", "gaming"}, {"gaming advice", "gaming"},
        {"fitness routine", "fitness"}, {"workout plan", "fitness"}, {"fitness advice", "fitness"},
        {"study tips", "studies"}, {"learning tricks", "studies"}, {"study help", "studies"},
        {"coding help", "coding"}, {"programming tips", "coding"}, {"debug help", "coding"}
    };

    if (commands.find(input) != commands.end()) {
        return commands[input];
    }
    return input; // If no match found, return original
}

int main() {
    system("cls");
    cout << "\t\t<==================== WELCOME TO YOUR VIRTUAL ASSISTANT ====================>" << endl;
    cout << "\t\t<========================= NAME: ZAIN'S ASSISTANT ==========================>" << endl;
    cout << "\t\t<============================ I'M HERE TO HELP ============================>" << endl;

    char password[20];
    char ch[200]; // For user commands
    string name = "Zain";

    do {
        cout << "\nEnter your password: ";
        gets(password);

        if (strcmp(password, "zain") == 0) {
            cout << "\nWelcome back, " << name << "!" << endl;
            wishme();

            while (true) {
                cout << "\nHow can I assist you? (Type 'exit' to quit): ";
                gets(ch);
                string command = toLower(string(ch));
                command = matchCommand(command); // Handle similar commands

                if (command == "hi" || command == "hello" || command == "hey") {
                    cout << "Hello Zain! How can I assist you today?" << endl;
                } else if (command == "bye" || command == "exit") {
                    cout << "Goodbye, Zain! Have a great day!" << endl;
                    system("espeak \"Goodbye Zain! Have a great day!\"");
                    break;
                } else if (command == "who are you") {
                    cout << "I'm your virtual assistant, here to make your life easier!" << endl;
                } else if (command == "time" || command == "date") {
                    datetime();
                } else if (command == "motivate") {
                    cout << "Here's some motivation: *The harder you work for something, the greater you'll feel when you achieve it!*" << endl;
                } else if (command == "gaming") {
                    cout << "Need gaming tips? Stay hydrated, learn the maps, and focus on teamwork!" << endl;
                } else if (command == "fitness") {
                    cout << "Fitness tip: Start small with daily walks and gradually add strength training to your routine." << endl;
                } else if (command == "studies") {
                    cout << "Study tip: Use the Pomodoro technique—25 minutes of focused work, then a 5-minute break!" << endl;
                } else if (command == "coding") {
                    cout << "Coding tip: Break problems into smaller tasks and tackle them one at a time!" << endl;
                } else if (command == "open google") {
                    system("start https://www.google.com");
                    cout << "Opening Google..." << endl;
                } else if (command == "open youtube") {
                    system("start https://www.youtube.com");
                    cout << "Opening YouTube..." << endl;
                } else if (command == "open instagram") {
                    system("start https://www.instagram.com");
                    cout << "Opening Instagram..." << endl;
                } else if (command == "open notepad") {
                    system("start notepad");
                    cout << "Opening Notepad..." << endl;
                } else if (command == "open command prompt") {
                    system("start cmd");
                    cout << "Opening Command Prompt..." << endl;
                } else if (command == "play music") {
                    system("start wmplayer");
                    cout << "Playing your music..." << endl;
                } else if (command == "good morning") {
                    cout << "Good morning, Zain! Ready to start your day?" << endl;
                } else if (command == "good night") {
                    cout << "Good night, Zain! Sleep well and dream big!" << endl;
                } else if (command == "help") {
                    cout << "I can help you with gaming, fitness, coding, studying, opening apps, playing music, and much more!" << endl;
                } else if (command == "joke") {
                    cout << "Why don't skeletons fight each other? They don't have the guts!" << endl;
                } else {
                    cout << "Sorry, I didn't understand that. Could you try again?" << endl;
                }
            }
        } else {
            cout << "Incorrect password. Try again." << endl;
        }
    } while (true);

    return 0;
}
