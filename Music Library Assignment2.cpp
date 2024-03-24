/* A Music Library System is a software application used to manage the storage and retrieval of music
tracks and albums. System need to maintain information such as track title, artist, album, genre, duration,
release year, and any other relevant attributes. System should able to add new music track, remove the
track, update the information of the track, search the specific track also it should display the information
of all the track which are present in the database. Use the Concept of Circular Linked list to implement the
above system*/


#include <iostream>
#include <string>
using namespace std;

struct Music {
    string title, artist, album, genre;
    int duration, r_year;
    Music* next;
};

Music* get_Music() {
    Music* temp = new Music;
    temp->next = nullptr;
    return temp;
}

Music* Creation() {
    string title, artist, album, choice, genre;
    int duration, r_year;
    Music *temp, *New, *head;
    head = nullptr;
    do {
        cout << "Enter Music Track Title :";
        cin >> title;
        cout << "Enter Artist :";
        cin >> artist;
        cout << "Enter Album :";
        cin >> album;
        cout << "Enter Duration :";
        cin >> duration;
        cout << "Enter Genre:";
        cin >> genre;
        cout << "Enter release Year :";
        cin >> r_year;

        New = get_Music();

        if (New == nullptr) {
            cout << "Memory is not allocated for Music Library System";
        } else {
            New->title = title;
            New->artist = artist;
            New->album = album;
            New->duration = duration;
            New->genre = genre;
            New->r_year = r_year;
        }

        if (head == nullptr) {
            head = New;
            New->next = head;
        } else {
            temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = New;
            New->next = head;
        }

        cout << "Do you want to add more tracks? (Y/N) ";
        cin >> choice;
    } while (choice == "y" || choice == "Y");

    return head;
}

void Display(Music* head) {
    Music* temp;
    temp = head;
    if (temp == nullptr) {
        cout << "Music Library System not created ";
        return;
    }

    cout << "Title\tArtist\tAlbum\tDuration\tGenre\tRelease Year" << endl;
    do {
        cout << temp->title << "\t\t"
             << temp->artist << "\t\t"
             << temp->album << "\t\t"
             << temp->duration << "\t\t\t\t"
             << temp->genre << "\t\t\t"
             << temp->r_year << endl;
        temp = temp->next;
    } while (temp != head);
}

Music* insert_AtBegining(Music *head) {
    Music *temp, *New;

    New = get_Music();
    cout << "Enter Music Track Title :";
    cin >> New->title;
    cout << "Enter Artist :";
    cin >> New->artist;
    cout << "Enter Album :";
    cin >> New->album;
    cout << "Enter Duration :";
    cin >> New->duration;
    cout << "Enter Genre:";
    cin >> New->genre;
    cout << "Enter release Year :";
    cin >> New->r_year;

    if (head == nullptr) {
        head = New;
        New->next = head;
    } else {
        temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = New;
        New->next = head;
        head = New;
    }
    return head;
}

Music* insert_AtEnd(Music *head) {
    Music *temp, *New;

    New = get_Music();
    cout << "Enter Music Track Title :";
    cin >> New->title;
    cout << "Enter Artist :";
    cin >> New->artist;
    cout << "Enter Album :";
    cin >> New->album;
    cout << "Enter Duration :";
    cin >> New->duration;
    cout << "Enter Genre:";
    cin >> New->genre;
    cout << "Enter release Year :";
    cin >> New->r_year;

    if (head == nullptr) {
        head = New;
        New->next = head;
    } else {
        temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = New;
        New->next = head;
    }
    return head;
}

Music* insert_AtAfter(Music *head) {
    Music *temp, *New;
    string key;

    New = get_Music();
    cout << "Enter Music Track Title :";
    cin >> New->title;
    cout << "Enter Artist :";
    cin >> New->artist;
    cout << "Enter Album :";
    cin >> New->album;
    cout << "Enter Duration :";
    cin >> New->duration;
    cout << "Enter Genre:";
    cin >> New->genre;
    cout << "Enter release Year :";
    cin >> New->r_year;

    if (head == nullptr) {
        head = New;
        New->next = head;
    } else {
        temp = head;
        cout << "Enter After which Music to Insert ";
        cin >> key;
        do {
            if (temp->title == key) {
                New->next = temp->next;
                temp->next = New;
                cout << "New Music Record Inserted";
                return head;
            }
            temp = temp->next;
        } while (temp != head);
    }
}

Music* Search_Music(Music* head) {
    Music* temp = head;
    string title;
    cout << "Enter Music title to be Searched: ";
    cin >> title;

    if (temp == nullptr) {
        cout << "Music Library is empty" << endl;
        return nullptr;
    } else {
        do {
            if (temp->title == title) {
                cout << "Title\tArtist\tAlbum\tDuration\tGenre\tRelease Year" << endl;
                cout << temp->title << "\t\t"
                     << temp->artist << "\t\t"
                     << temp->album << "\t\t"
                     << temp->duration << "\t\t\t\t"
                     << temp->genre << "\t\t\t"
                     << temp->r_year << endl;
                return temp;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Music with title '" << title << "' not found" << endl;
        return nullptr;
    }
}

Music* delete_Music(Music* head) {
    string title;
    cout << "Enter title of the Music to be deleted";
    cin >> title;
    if (head == nullptr) {
        cout << "Music Library is empty" << endl;
        return nullptr;
    }

    Music* current = head;
    Music* previous = nullptr;

    // Search for the music track with the given title
    do {
        if (current->title == title) {
            // If the track is found
            if (previous == nullptr) {
                // If the track is the first node in the list
                Music* last = head;
                while (last->next != head) {
                    last = last->next;
                }
                if (head == head->next) {
                    // If there's only one node in the list
                    delete head;
                    head = nullptr;
                } else {
                    last->next = head->next;
                    delete head;
                    head = last->next;
                }
            } else {
                // If the track is not the first node in the list
                previous->next = current->next;
                if (current == head) {
                    head = head->next;
                }
                delete current;
            }
            cout << "Music track '" << title << "' deleted successfully" << endl;
            return head;
        }
        previous = current;
        current = current->next;
    } while (current != head);

    cout << "Music track with title '" << title << "' not found" << endl;
    return head;
}

int main() {
    Music* head = nullptr; // Initialize head pointer to nullptr

    int choice;
    do {
        cout << "\nMenu:" << endl;
        cout << "1. Create Music Library" << endl;
        cout << "2. Display Music Library" << endl;
        cout << "3. Insert Music Track at Beginning" << endl;
        cout << "4. Insert Music Track at End" << endl;
        cout << "5. Insert Music Track After a Specific Track" << endl;
        cout << "6. Search for a Music Track" << endl;
        cout << "7. Delete for a Music Track " << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                head = Creation();
                break;
            case 2:
                Display(head);
                break;
            case 3:
                head = insert_AtBegining(head);
                break;
            case 4:
                head = insert_AtEnd(head);
                break;
            case 5:
                head = insert_AtAfter(head);
                break;
            case 6:
                Search_Music(head);
                break;
            case 7:
                head = delete_Music(head);
                break;
            case 8:
                cout << "Exiting program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice! " << endl;
        }
    } while (choice != 8);

    return 0;
}