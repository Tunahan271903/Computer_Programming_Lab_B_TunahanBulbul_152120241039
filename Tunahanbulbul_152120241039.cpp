#include <iostream>
#include <string>
#include <limits>

using namespace std;

struct Node {
    string songTitle;
    Node* next;
};

void addSong(Node*& head, string title) {
    Node* newNode = new Node();
    newNode->songTitle = title;
    newNode->next = head;
    head = newNode;
    cout << "Song added successfully to the top!\n";
}

void listSongs(Node* head) {
    if (head == nullptr) {
        cout << "\nThe playlist is currently empty.\n";
        return;
    }

    cout << "\n--- Your Playlist ---\n";
    Node* temp = head;
    int count = 1;
    while (temp != nullptr) {
        cout << count << ". " << temp->songTitle << endl;
        temp = temp->next;
        count++;
    }
}

void searchSong(Node* head, string title) {
    Node* temp = head;
    bool found = false;

    while (temp != nullptr) {
        if (temp->songTitle == title) {
            found = true;
            break;
        }
        temp = temp->next;
    }

    if (found) {
        cout << "Result: '" << title << "' was found in the playlist!\n";
    } else {
        cout << "Result: '" << title << "' was not found.\n";
    }
}

int main() {
    Node* head = nullptr; 
    int choice;
    string title;

    while (true) {
        cout << "\n--- Music Playlist Menu ---\n";
        cout << "1. Add Song (Prepend)\n";
        cout << "2. Search Song\n";
        cout << "3. List All Songs\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input! Please enter a number (1-4).\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        cin.ignore();

        if (choice == 1) {
            cout << "Enter song title: ";
            getline(cin, title);
            addSong(head, title);
        } 
        else if (choice == 2) {
            cout << "Enter song title to search: ";
            getline(cin, title);
            searchSong(head, title);
        } 
        else if (choice == 3) {
            listSongs(head);
        } 
        else if (choice == 4) {
            cout << "Exiting program...\n";
            break;
        } 
        else {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}