#pragma once
#include <iostream>
#include <string>
#include "LinkedList.h"
#include "song.h"
#include "tree.h"
#include "songLibrary.h"

using namespace std;

class Playlist {
private:
    SongLibrary<Song>* songlist;
    DoublyLinkedList<Song*> songs;
    Node2<Song*>* current;
    static int count;
public:
    Playlist(SongLibrary<Song>* list) : songlist(list), current(nullptr) 
    { count++; }

    void addSong(const Song& song) {
        Song* temp = songlist->findSong(song.getTitle());
        if (temp) {
            songs.insertFront(temp);
            if (current == nullptr && !songs.isEmpty()) {
                current = songs.getHead();  
            }
            cout << "Added to playlist: " << *temp << endl;
        }
        else {
            cout << "Song \"" << song.getTitle() << "\" not found in the library.\n";
        }
    }

    void removeSong(const string& title) {
        if (songs.isEmpty()) {
            cout << "Playlist is empty" << endl;
            return;
        }

        Node2<Song*>* node = songs.getHead();  
        while (node) {
            if (node->data->getTitle() == title) {
                if (node == current) {
                    if (current->next) {
                        current = current->next;
                    }
                    else {
                        current = current->prev;
                    }
                }

                if (node == songs.getHead()) {
                    songs.deleteFront();
                }
                else {
                    if (node->prev) node->prev->next = node->next;
                    if (node->next) node->next->prev = node->prev;
                    else songs.setTail(node->prev);
                    delete node;
                    songs.decrementSize();
                }

                cout << "Removed song with title: " << title << endl;
                return;
            }
            node = node->next;
        }

        cout << "Song with title '" << title << "' not found" << endl;
    }

    void displayPlaylist(ostream&out=cout) const {
        if (&out == &cout) {
            if (songs.isEmpty()) {
                cout << "Playlist is empty" << endl;
                return;
            }
            cout << "Playlist:\n";
            songs.display();
        }
        else {
            if (songs.isEmpty()) {
                out << "Playlist is empty" << endl;
                return;
            }
            out << "Playlist:\n";
            songs.display(out);
        }
       
    }

    void playNext() {
        if (songs.isEmpty()) {
            cout << "Playlist is empty" << endl;
            return;
        }
        if (current && current->next) {
            current = current->next;
            cout << "Playing: " << *current->data << endl;
        }
        else {
            cout << "No next song available" << endl;
        }
    }

    void playPrevious() {
        if (songs.isEmpty()) {
            cout << "Playlist is empty" << endl;
            return;
        }
        if (current && current->prev) {
            current = current->prev;
            cout << "Playing: " << *current->data << endl;
        }
        else {
            cout << "No previous song available" << endl;
        }
    }

    void playCurrent() const {
        if (songs.isEmpty()) {
            cout << "Playlist is empty" << endl;
            return;
        }
        if (current) {
            cout << "Playing: " << *current->data << endl;
        }
        else {
            cout << "No song selected" << endl;
        }
    }

    void clearPlaylist() {
        while (!songs.isEmpty()) {
            songs.deleteFront();
        }
        current = nullptr;
        cout << "Playlist cleared" << endl;
    }

    bool isEmpty() const {
        return songs.isEmpty();
    }

    int getSize() const {
        return songs.getSize();
    }

    Song* getCurrent()const {
        return current->data;
    }
};
int Playlist::count = 0;