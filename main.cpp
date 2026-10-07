// Meesum Kazmi (Sem-3 | LA | HCI) share this project with me 
#include <iostream>
#include <fstream>
#include <string>
#include"stack.h"
#include <unordered_map>
#include "song.h"
#include "songLibrary.h"
#include "playlist.h"

using namespace std;

int main() {

    // For Song Library
    SongLibrary<Song> library;
    // Using Map for Playlist, By using string->
    // PlayList Name we can access specific Playlist
    unordered_map<string, Playlist*> playlistMap; // bad dekhna hain

    //Just to active PlayList
    Playlist* currentPlaylist = nullptr;
    Song* currentSong = nullptr;

    //stack for Recently Played Song
    Stack<Song*> history;

    //Dummy data for Songs Input
    //simple add karega run krny pr
    // temporary obj pass kr ke initialize

    library.addSong(Song("Blinding Lights", "The Weeknd", 200, 2020));
    library.addSong(Song("Shape of You", "Ed Sheeran", 210, 2017));
    library.addSong(Song("Numb", "Linkin Park", 190, 2003));
    library.addSong(Song("Levitating", "Dua Lipa", 180, 2021));


    int choice;

    do {
       

        cout << "\n";
        cout << "+====================================================================+\n";
        cout << "|                              SPOTIFY                               |\n";
        cout << "+====================================================================+\n";
        cout << "|                              MENU                                  |\n";
        cout << "+====================================================================+\n";


        cout << "| LIBRARY MANAGEMENT                                                 |\n";
        cout << "|   [1] View All Songs in Library    [2] Add Song to Library         |\n";
        cout << "+--------------------------------------------------------------------+\n";

        cout << "| PLAYLIST MANAGEMENT                                                |\n";
        cout << "|   [3] Create Playlist           [4] List All Playlists             |\n";
        cout << "|   [5] Switch Playlist           [6] Delete Playlist                |\n";
        cout << "+--------------------------------------------------------------------+\n";

        cout << "| CURRENT PLAYLIST ACTIONS                                           |\n";
        cout << "|   [7] Add Song to Playlist      [8] Remove Song from Playlist      |\n";
        cout << "|   [9] View Current Playlist                                        |\n";
        cout << "+--------------------------------------------------------------------+\n";

        cout << "| PLAYBACK CONTROLS                                                  |\n";
        cout << "|   [10] Play Song                [11] Play Curent PlayList Song     |\n";
        cout << "|   [12] Play Previous Song       [13] Play Next Song                |\n";
        cout << "+--------------------------------------------------------------------+\n";

        cout << "| FILE OPERATIONS                                                    |\n";
        cout << "|   [14] Load Songs from File     [15] Save Library to File          |\n";
        cout << "|   [16] Save Playlist to File                                       |\n";
        cout << "+--------------------------------------------------------------------+\n";

        cout << "| RECENTLY PLAYED                                                    |\n";
        cout << "|   [17] Show Recently Played Songs                                  |\n";
        cout << "|                                                                    |\n";
        cout << "+--------------------------------------------------------------------+\n";

        cout << "| [0] Exit Program                                                   |\n";
        cout << "+====================================================================+\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            cout << "\n----------------------- All Songs --------------------------\n";
            library.displayAllSongs();
            cout << "\n----------------------------------------------------------------\n";
            break;

        case 2:{

            cout << "\n----------------------------------------------------------------\n";
            Song newSong;
            cin >> newSong;
            library.addSong(newSong);
            cout << "Song added to library.\n";
            cout << "\n----------------------------------------------------------------\n";

            break;
        }
        case 3: {
            cout << "\n----------------------------------------------------------------\n";
            string name;
            cout << "Enter new playlist name: ";
            getline(cin, name);

            if (playlistMap.count(name)) {
                cout << "Playlist already exists.\n";
            }
            else {
                playlistMap[name] = new Playlist(&library);
                cout << "Playlist \"" << name << "\" created.\n";
            }
            cout << "\n----------------------------------------------------------------\n";
            break;
        }
        case 4:
            cout << "\n----------------------------------------------------------------\n";
            cout << "=== Playlists ===\n";
            for (const auto& p : playlistMap)
                cout << "- " << p.first <<"\n";
            cout << "\n----------------------------------------------------------------\n";
            break;

        case 5:{
             //switch playlist
            cout << "\n----------------------------------------------------------------\n";
            string name;
            cout << "Enter playlist name to switch to: ";
            getline(cin, name);
            if (playlistMap.count(name)) {
                currentPlaylist = playlistMap[name];
                cout << "Switched to playlist \"" << name << "\".\n";
            }
            else {
                cout << "Playlist not found.\n";
            }
            cout << "\n----------------------------------------------------------------\n";
            break;
        }
        case 6: {
            string name;
            cout << "Enter the name of playlist, want to delete\n";
            getline(cin, name);
            if (playlistMap.count(name)) {
                playlistMap.erase(name);
                cout << "Playlist \"" << name << "\"has been deleted\n";
            }
            else {
                cout << "No playlist exist of this name\n";
            }
            break;
        }
        case 7:
            // add song to playlist
            cout << "\n----------------------------------------------------------------\n";
            if (!currentPlaylist) {
                cout << "No active playlist. Please switch to one.\n";
            }
            else {
                string title;
                cout << "Enter song title to add: ";
                getline(cin, title);
                currentPlaylist->addSong(Song(title, "", 0, 0));
            }
            cout << "\n----------------------------------------------------------------\n";
            break;

        case 8:
            //remove song to playlist
            cout << "\n----------------------------------------------------------------\n";
            if (!currentPlaylist) {
                cout << "No active playlist.\n";
            }
            else {
                string title;
                cout << "Enter song title to remove: ";
                getline(cin, title);
                currentPlaylist->removeSong(title);// bst deletion
            }
            cout << "\n----------------------------------------------------------------\n";

            break;

        case 9:
            //view current playlist
            cout << "\n----------------------------------------------------------------\n";
            if (!currentPlaylist) {
                cout << "No active playlist.\n";
            }
            else {
                currentPlaylist->displayPlaylist();
            }    
            cout << "\n----------------------------------------------------------------\n";
            break;

        case 10: {
            if (!library.isEmpty()) {
                string name;
                cout << "Enter the song name: ";
                getline(cin, name);
                if (library.findSong(name)) {
                    currentSong = library.findSong(name);
                    history.push(currentSong);

                    cout << "Playing " << *currentSong;
                }
                else {
                    cout << "song not found\n";
                }
            }
            break;
        }
        case 11:
            cout << "\n----------------------------------------------------------------\n";
            if (!currentPlaylist) {
                cout << "No active playlist.\n";
            }
            else {
                currentPlaylist->playCurrent();
                history.push(currentPlaylist->getCurrent());
            }
            cout << "\n----------------------------------------------------------------\n";
            break;

        case 12:
            cout << "\n----------------------------------------------------------------\n";
            if (!currentPlaylist) {
                cout << "No active playlist.\n";
            }
            else {
                currentPlaylist->playPrevious();
            }
            cout << "\n----------------------------------------------------------------\n";
            break;

        case 13:
            cout << "\n----------------------------------------------------------------\n";
            if (!currentPlaylist) {
                cout << "No active playlist.\n";
            }
            else {
                currentPlaylist->playNext();
            }
            cout << "\n----------------------------------------------------------------\n";
            break;

        case 14: {
            cout << "\n----------------------------------------------------------------\n";
            string name;
            cout << "Enter File name\n";
            cin >> name;
            ifstream fin(name);
            if (!fin) {
                cout << "Unable to open file\n";
            }
            else {
                Song temp;

                //overload hoa hai song class mai
                while (fin >> temp) {
                    library.addSong(temp);
                }
                cout << "Song has been added to library.\n";
            }
            cout << "\n----------------------------------------------------------------\n";
            break;
        }
        case 15: {
            cout << "\n----------------------------------------------------------------\n";
            string name;
            cout << "Enter File name\n";
            cin >> name;

            // bug 
            ofstream fout(name);
            if (!fout) {
                cout << "Unable to open file\n";
            }
            else {
                library.displayAllSongs(fout);
            }
            cout << "\n----------------------------------------------------------------\n";
            break;
        }
        case 16: {
            cout << "\n----------------------------------------------------------------\n";
            if (!currentPlaylist) {
                cout << "No active playlist.\n";
            }
            else {
                string fname;
                cout << "Enter file name: ";
                getline(cin, fname);
                ofstream fout(fname);

                if (fout) {
                    currentPlaylist->displayPlaylist(fout);
                }
                else {
                    cout << "Unable to open file\n";
                }
            }
            cout << "\n----------------------------------------------------------------\n";
            break;
        }
        case 17: {
            cout << "\n----------------------------------------------------------------\n";
            history.display();
            cout << "\n----------------------------------------------------------------\n";
            break;
        }
        case 0:
            cout << "Exiting program.\n"
                << "L1F23SCS0383 MUHAMMAD BILAL\n"
                << "L1F23BSCS0878 AMAD UL HAQ\n"
                << "L1F23BSCS0790  ASHIR" << endl;
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 0);

    return 0;
}
