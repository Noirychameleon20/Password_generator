#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random password
void generatePassword(int length) {
    // Arrays to hold character types
    char numbers[] = "0123456789";
    char lowerCase[] = "abcdefghijklmnopqrstuvwxyz";
    char upperCase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char specialChar[] = "!@#$^&*?";

    // Random number generator seed
    srand((int)time(NULL));

    // Ensure a strong password by including at least one character from each type
    char password[length + 1]; // +1 for null-terminator
    password[0] = numbers[rand() % 10];
    password[1] = lowerCase[rand() % 26];
    password[2] = upperCase[rand() % 26];
    password[3] = specialChar[rand() % 8];

    // Fill the remaining slots with random characters from all types
    char allChars[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!@#$^&*?";
    for (int i = 4; i < length; i++) {
        password[i] = allChars[rand() % (sizeof(allChars) - 1)];
    }

    // Shuffle the password to randomize the order of characters
    for (int i = 0; i < length; i++) {
        int j = rand() % length;
        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }

    // Null-terminate and print the password
    password[length] = '\0';
    printf("%s\n", password);
}

int main() {
    int length;
    printf("Hi Supriya, enter the length of the password: ");
    scanf("%d", &length);

    if (length < 4) {
        printf("Password length must be at least 4 to include all character types.\n");
        return 1;
    }

    printf("Supriya, your password is: ");
    generatePassword(length);

    while (1) {
        int choice;
        printf("\nSupriya, press 1 to generate a new password or press 0 to exit: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Your new password is: ");
            generatePassword(length);
        } else {
            printf("You have exited, Supriya!\n");
            return 0;
        }
    }
}
