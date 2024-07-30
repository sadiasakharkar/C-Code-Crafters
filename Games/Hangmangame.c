#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 20
#define MAX_TRIES 6

// Function prototypes
void initializeGame(char word[MAX_WORD_LENGTH], char guessedLetters[MAX_WORD_LENGTH]);
void displayHangman(int tries);
void displayWord(char word[MAX_WORD_LENGTH], char guessedLetters[MAX_WORD_LENGTH]);
bool isLetterGuessed(char letter, char guessedLetters[MAX_WORD_LENGTH]);

int main() {
    char word[MAX_WORD_LENGTH];
    char guessedLetters[MAX_WORD_LENGTH];
    int tries = 0;

    initializeGame(word, guessedLetters);

    printf("Welcome to Hangman!\n");
    printf("Try to guess the word.\n");

    while (tries < MAX_TRIES) {
        displayHangman(tries);
        displayWord(word, guessedLetters);

        char guess;
        printf("Enter a letter: ");
        scanf(" %c", &guess);

        if (!isalpha(guess)) {
            printf("Invalid input. Please enter a letter.\n");
            continue;
        }

        if (isLetterGuessed(guess, guessedLetters)) {
            printf("You've already guessed that letter.\n");
            continue;
        }

        guessedLetters[strlen(guessedLetters)] = guess;
        guessedLetters[strlen(guessedLetters)] = '\0';

        if (!strchr(word, guess)) {
            tries++;
            printf("Incorrect guess! You have %d tries left.\n", MAX_TRIES - tries);
        }

        bool allLettersGuessed = true;
        for (int i = 0; i < strlen(word); i++) {
            if (!isLetterGuessed(word[i], guessedLetters)) {
                allLettersGuessed = false;
                break;
            }
        }

        if (allLettersGuessed) {
            printf("Congratulations! You guessed the word: %s\n", word);
            break;
        }
    }

    if (tries == MAX_TRIES) {
        displayHangman(MAX_TRIES);
        printf("Sorry, you've run out of tries. The word was: %s\n", word);
    }

    return 0;
}

// Function to initialize the game
void initializeGame(char word[MAX_WORD_LENGTH], char guessedLetters[MAX_WORD_LENGTH]) {
    printf("Player 1, enter a word: ");
    scanf("%s", word);

    for (int i = 0; i < strlen(word); i++) {
        guessedLetters[i] = '_';
    }
    guessedLetters[strlen(word)] = '\0';
}

// Function to display the Hangman based on the number of tries
void displayHangman(int tries) {
    printf("\n");
    switch (tries) {
        case 0:
            printf("   +---+\n");
            printf("   |   |\n");
            printf("       |\n");
            printf("       |\n");
            printf("       |\n");
            printf("       |\n");
            printf("=========\n");
            break;
        case 1:
            printf("   +---+\n");
            printf("   |   |\n");
            printf("   O   |\n");
            printf("       |\n");
            printf("       |\n");
            printf("       |\n");
            printf("=========\n");
            break;
        case 2:
            printf("   +---+\n");
            printf("   |   |\n");
            printf("   O   |\n");
            printf("   |   |\n");
            printf("       |\n");
            printf("       |\n");
            printf("=========\n");
            break;
        case 3:
            printf("   +---+\n");
            printf("   |   |\n");
            printf("   O   |\n");
            printf("  /|   |\n");
            printf("       |\n");
            printf("       |\n");
            printf("=========\n");
            break;
        case 4:
            printf("   +---+\n");
            printf("   |   |\n");
            printf("   O   |\n");
            printf("  /|\\  |\n");
            printf("       |\n");
            printf("       |\n");
            printf("=========\n");
            break;
        case 5:
            printf("   +---+\n");
            printf("   |   |\n");
            printf("   O   |\n");
            printf("  /|\\  |\n");
            printf("  /    |\n");
            printf("       |\n");
            printf("=========\n");
            break;
        case 6:
            printf("   +---+\n");
            printf("   |   |\n");
            printf("   O   |\n");
            printf("  /|\\  |\n");
            printf("  / \\  |\n");
            printf("       |\n");
            printf("=========\n");
            break;
    }
}

// Function to display the word with guessed letters
void displayWord(char word[MAX_WORD_LENGTH], char guessedLetters[MAX_WORD_LENGTH]) {
    printf("Word: ");
    for (int i = 0; i < strlen(word); i++) {
        if (isLetterGuessed(word[i], guessedLetters))
            printf("%c ", word[i]);
        else
            printf("_ ");
    }
    printf("\n");
}

// Function to check if a letter has been guessed
bool isLetterGuessed(char letter, char guessedLetters[MAX_WORD_LENGTH]) {
    for (int i = 0; i < strlen(guessedLetters); i++) {
        if (letter == guessedLetters[i])
            return true;
    }
    return false;
}
