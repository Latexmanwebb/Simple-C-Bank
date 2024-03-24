#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

// Defining Functions
int signup(void);
int startscreen(string street, string name, string number, string age, string username);
int checking(string username);
float cash = 0;
int moneyadd(float add, string username);
int mainscreen(string username);
int accountsetting(string username);
string emailaddress = ""; // Initialize with an empty string

int main(void)
{
    string answer;
    do {
        // Security Challenge
        answer = get_string("Pass the Following Security Challenge. \nType the following word 'apple' ");
    } while (strcmp(answer, "apple") != 0);
    printf("Good Job!\n");
    signup();
    return 0;
}

int signup(void)
{
    // Defining Variables
    string age, street, name, number, username;
    char confirm;

    do {
        // Getting more info
        system("clear");
        printf("You're doing great! Let's get a bit more info on you to finish setting up your account!\n");
        age = get_string("How old are you?: ");
        street = get_string("Where do you live?: ");
        name = get_string("Whats your full name?: ");
        number = get_string("Whats your phone number?: ");
        username = get_string("Whats your desired Username?: ");

        system("clear");
        printf("So far we have this info for your account: \n Street: %s\n Name: %s \n Phone Number: %s \n Age: %s  \n User: %s \n", street, name, number, age, username);

        // Do command that that asks if correct
        do {
            confirm = get_char("\nIs this info correct? Y/N : ");
            // If Invalid input ask again (Problem with looping the variable fix)
            if (confirm != 'N' && confirm != 'n' && confirm != 'y' && confirm != 'Y') {
                system("clear");
                printf("Invalid please Try Again\n \n");
                printf("So far we have this info for your account: \n Street: %s\n Name: %s \n Phone Number: %s \n Age: %s  \n User: %s \n", street, name, number, age, username);
            }
        } while (confirm != 'N' && confirm != 'n' && confirm != 'y' && confirm != 'Y');
    } while (confirm == 'N' || confirm == 'n');

    startscreen(street, name, number, age, username);
    return 0;
}

// Account setup function
int startscreen(string street, string name, string number, string age, string username) {
    string password;
    string confirmpass;

    system("clear");
    // Fake Account Set Up
    int i = 0;
    do {
        printf("Initializing .... %d", i);
        sleep(1);
        i += 10;
        system("clear");
    } while (i <= 100);
    system("clear");
    printf("Initializing 👍\n");

    int f = 0;
    do {
        printf("Verifying information .... %d", f);
        sleep(1);
        f += 10;
        system("clear");
    } while (f <= 100);
    system("clear");
    printf("Initializing 👍\n");
    printf("Verification👍\n");
    sleep(3);
    printf("Account Creation Successful 👍\n");
    sleep(2);

    // Password Creation
    do {
        password = get_string("One last thing! What's your desired password? Make Sure it's Secure! : ");
        system("clear");
        confirmpass = get_string("Retype Your Password : ");
        if (strcmp(confirmpass, password) != 0) {
            system("clear");
            printf("Invalid Try Again\n");
        }
    } while (strcmp(confirmpass, password) != 0);

    system("clear");
    mainscreen(username);
    return 0;
}

// Main Screen
int mainscreen(string username)
{
    printf("Welcome %s!\n", username);
    printf("Select An Option! \n\t[1] Checkings Account\n\t[2] Setting\n");
    int option = get_int("Option : ");
    if (option == 1) {
        system("clear");
        checking(username);
    }
    else if (option == 2) {
        system("clear");
        accountsetting(username);
    }
    return 0;
}

// Checking
int checking(string username)
{
    float add = 0;
    char question;

    do {
        system("clear");
        printf("Current Cash %.2f$\n", cash);
        question = get_char("Would you like to add cash? Y/N: ");
    } while (question != 'N' && question != 'n' && question != 'y' && question != 'Y');

    if (question == 'y' || question == 'Y') {
        system("clear");
        moneyadd(add, username);
    }

    else if (question == 'n' || question == 'N') {
        system("clear");
        mainscreen(username);
    }
    return 0;
}

// Money addition
int moneyadd(float add, string username)
{
    float cashadding = get_float("How much cash to add?: ");
    cash += cashadding;
    add = cash;
    system("clear");

    mainscreen(username);
    return add;
}

// Account Setting
int accountsetting(string username){
    printf("Choose From The Choices Below!\n\tChange Email Adress: %s  [1]\n\tExit\t\t      [2]\n", emailaddress);
    int choice = get_int("Option : ");
    if (choice == 1) { // Compare with integer value 1
        system("clear");
        emailaddress = get_string("New Email Address: ");
        system("clear");
        accountsetting(username);
    }
    else if (choice == 2) { // Compare with integer value 2
        system("clear");
        mainscreen(username);
    }
    return 0;
}

