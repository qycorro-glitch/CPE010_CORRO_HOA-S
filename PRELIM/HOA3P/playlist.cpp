#include "playlist.h"

void Playlist::insertSong(std::string song) {

    Node* newNode = new Node(song);

    if(head == nullptr){
        head = newNode;
        head->next = head;
        head->prev = head;
        return;
    }

    Node* temp = head->prev;

    temp->next = newNode;
    newNode->prev = temp;
    newNode->next = head;
    head->prev = newNode;
}

void Playlist::deleteSong(std::string song){

    if(head == nullptr){
        std::cout << "Playlist is empty.\n";
        return;
    }

    Node* current = head;

    do{

        if(current->song == song){

            if(current->next == current){
                delete current;
                head = nullptr;
                return;
            }

            current->prev->next = current->next;
            current->next->prev = current->prev;

            if(current == head)
                head = current->next;

            delete current;

            std::cout << song << " removed.\n";
            return;
        }

        current = current->next;

    }while(current != head);

    std::cout << "Song not found.\n";
}

void Playlist::playAll(){

    if(head == nullptr){
        std::cout << "Playlist is empty.\n";
        return;
    }

    Node* temp = head;

    std::cout << "\nPlaylist:\n";

    do{
        std::cout << temp->song << std::endl;
        temp = temp->next;
    }while(temp != head);
}

void Playlist::nextSong(std::string current){

    if(head == nullptr)
        return;

    Node* temp = head;

    do{

        if(temp->song == current){
            std::cout << "Next Song: " << temp->next->song << std::endl;
            return;
        }

        temp = temp->next;

    }while(temp != head);

    std::cout << "Song not found.\n";
}

void Playlist::previousSong(std::string current){

    if(head == nullptr)
        return;

    Node* temp = head;

    do{

        if(temp->song == current){
            std::cout << "Previous Song: " << temp->prev->song << std::endl;
            return;
        }

        temp = temp->next;

    }while(temp != head);

    std::cout << "Song not found.\n";
}