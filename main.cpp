#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void registerUser() {
    string username, password;
    
    cout << "Enter a username: ";
    cin >> username;
    cout << "Enter a password: ";
    cin >> password;

    // Store the username and password in a file
    ofstream file;
    file.open("users.txt", ios::app);  // Append mode
    file << username << " " << password << endl;
    file.close();

    cout << "Registration successful!" << endl;
}

bool loginUser() {
    string username, password, storedUser, storedPass;
    
    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter your password: ";
    cin >> password;

    ifstream file("users.txt");
    bool loginSuccess = false;

    // Check if username and password match any stored credentials
    while (file >> storedUser >> storedPass) {
        if (storedUser == username && storedPass == password) {
            loginSuccess = true;
            break;
        }
    }

    file.close();

    if (loginSuccess) {
        cout << "Login successful! Welcome, " << username << "!" << endl;
        return true;
    } else {
        cout << "Invalid username or password." << endl;
        return false;
    }
}

void recoverPassword() {
    string username, storedUser, storedPass;
    
    cout << "Enter your username to recover your password: ";
    cin >> username;

    ifstream file("users.txt");
    bool userFound = false;

    // Search for the username in the file and recover the password
    while (file >> storedUser >> storedPass) {
        if (storedUser == username) {
            userFound = true;
            cout << "Password for user " << username << " is: " << storedPass << endl;
            break;
        }
    }

    file.close();

    if (!userFound) {
        cout << "Username not found." << endl;
    }
}

int main() {
    int choice;

    while (true) {
        cout << "\n1. Register\n2. Login\n3. Recover Password\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                if (loginUser()) {
                    return 0;  // Successful login, exit the program
                }
                break;
            case 3:
                recoverPassword();
                break;
            case 4:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}

