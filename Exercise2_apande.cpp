
/**
 * @file Exercise2_apande.cpp
 * @author Aayush Pande
 * @date 2026-11-22
 * @brief Translates English text to Morse Code and Morse Code
 *        back to English using two classes and a menu.
 */

#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <limits>

using namespace std;

class MorseTranslator {
private:
    vector<string> morseCodes;

public:
    /**
     * @brief Initializes the Morse Code alphabet.
     */
    MorseTranslator() {
        morseCodes = {
            ".-", "-...", "-.-.", "-..", ".", "..-.",
            "--.", "....", "..", ".---", "-.-", ".-..",
            "--", "-.", "---", ".--.", "--.-", ".-.",
            "...", "-", "..-", "...-", ".--", "-..-",
            "-.--", "--.."
        };
    }

    /**
     * @brief Converts English text into Morse Code.
     * @param text The English sentence to translate.
     * @return The translated Morse Code string.
     */
    string toMorse(string text) {
        string result = "";

        for (int i = 0; i < text.length(); i++) {
            char letter = tolower(text[i]);

            if (letter >= 'a' && letter <= 'z') {
                int index = letter - 'a';

                if (!result.empty()) {
                    result += " ";
                }

                result += morseCodes[index];
            }
        }

        return result;
    }

    /**
     * @brief Converts a Morse Code symbol into a letter.
     * @param code The Morse Code symbol.
     * @return The matching letter or '?' if invalid.
     */
    char findLetter(string code) {
        for (int i = 0; i < morseCodes.size(); i++) {
            if (morseCodes[i] == code) {
                return 'A' + i;
            }
        }

        return '?';
    }

    /**
     * @brief Converts Morse Code into English text.
     * @param morse The Morse Code sentence.
     * @return The translated English sentence.
     */
    string toEnglish(string morse) {
        string result = "";
        string currentCode = "";

        for (int i = 0; i <= morse.length(); i++) {
            if (i == morse.length() || morse[i] == ' ') {
                if (!currentCode.empty()) {
                    result += findLetter(currentCode);
                    currentCode = "";
                }
            } else {
                currentCode += morse[i];
            }
        }

        return result;
    }
};

class TranslationApp {
private:
    MorseTranslator translator;

    /**
     * @brief Displays the translation menu.
     * @return Nothing.
     */
    void showMenu() {
        cout << "\n===== MORSE CODE TRANSLATOR =====\n";
        cout << "1. English to Morse Code\n";
        cout << "2. Morse Code to English\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
    }

    /**
     * @brief Reads a sentence with a maximum of 50 characters.
     * @return The validated input sentence.
     */
    string getSentence() {
        string sentence;

        while (true) {
            cout << "Enter a sentence (max 50 characters): ";
            getline(cin, sentence);

            if (sentence.length() <= 50) {
                return sentence;
            }

            cout << "Input is too long. Please try again.\n";
        }
    }

    /**
     * @brief Handles English to Morse translation.
     * @return Nothing.
     */
    void translateToMorse() {
        string sentence = getSentence();

        string result = translator.toMorse(sentence);

        cout << "Morse Code: " << result << endl;
    }

    /**
     * @brief Handles Morse to English translation.
     * @return Nothing.
     */
    void translateToEnglish() {
        string sentence;

        cout << "Enter Morse Code (separate letters with spaces): ";
        getline(cin, sentence);

        string result = translator.toEnglish(sentence);

        cout << "English: " << result << endl;
    }

public:
    /**
     * @brief Runs the application menu until the user exits.
     * @return Nothing.
     */
    void run() {
        int choice = 0;

        while (choice != 3) {
            showMenu();

            if (!(cin >> choice)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter 1, 2, or 3.\n";
                continue;
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if (choice == 1) {
                translateToMorse();
            } else if (choice == 2) {
                translateToEnglish();
            } else if (choice == 3) {
                cout << "Goodbye!\n";
            } else {
                cout << "Invalid choice. Try again.\n";
            }
        }
    }
};

/**
 * @brief Entry point for the Morse Code Translator.
 * @return 0 when the program finishes successfully.
 */
int main() {
    TranslationApp app;
    app.run();

    return 0;
}
