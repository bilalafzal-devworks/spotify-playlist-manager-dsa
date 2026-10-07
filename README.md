# 🎵 Spotify-Style Music Library & Playlist Manager

A console-based music library and playlist manager written in **C++**, built from scratch using custom data structures (no STL containers for the core logic).

> **Course:** Data Structures and Algorithms (DSA)
> **University:** University of Central Punjab (UCP), Lahore
> **Program:** BS Computer Science, Faculty of Information Technology

---

## 📖 Table of Contents

1. [Overview](#-overview)
2. [Features](#-features)
3. [Data Structures Used](#-data-structures-used)
4. [Project Structure](#-project-structure)
5. [Getting Started](#-getting-started)
6. [How to Use](#-how-to-use)
7. [Song File Format](#-song-file-format)
8. [Sample Session](#-sample-session)
9. [Design Notes](#-design-notes)
10. [Time Complexity](#-time-complexity)
11. [Known Limitations](#-known-limitations)
12. [Future Improvements](#-future-improvements)
13. [Authors](#-authors)

---

## 🔎 Overview

This project simulates the core of a music streaming app such as Spotify. You can keep a sorted **song library**, create multiple **playlists**, move between songs with **next / previous** controls, see your **recently played** songs, and **load / save** data from text files.

The main goal of the project is to show how classic data structures solve real problems:

| Real-world need | Data structure |
|---|---|
| Keep all songs sorted and searchable | Binary Search Tree |
| Playlist with next / previous navigation | Doubly Linked List |
| Recently played history | Stack (built on the Doubly Linked List) |
| Find a playlist by its name | `unordered_map` (hash table) |

---

## ✨ Features

- **Song library** stored in a BST, kept sorted by title
- **Add songs** manually or **load them from a file**
- **Multiple playlists**, each with its own current song
- **Playlist controls:** add, remove, view, play current, next, previous
- **Recently played** list using a stack
- **File I/O:** load songs from a `.txt` file, save the library or a playlist to a file
- **Operator overloading** (`<<`, `>>`) so the same `cout << song` prints nicely to the console and writes CSV to a file
- Fully **template-based** containers (`BinarySearchTree<T>`, `DoublyLinkedList<T>`, `Stack<T>`)

---

## 🧱 Data Structures Used

| Structure | File | Used for |
|---|---|---|
| `BinarySearchTree<T>` | `tree.h` | Base class of the song library (insert, search, remove, in-order traversal) |
| `SongLibrary<T>` | `songLibrary.h` | Inherits from the BST; adds `addSong`, `findSong`, `deleteSong`, `findSongsByArtist` |
| `DoublyLinkedList<T>` | `LinkedList.h` | Playlist storage, supports moving forward and backward |
| `Stack<T>` | `stack.h` | Inherits from the doubly linked list; push / pop for recently played |
| `Node<T>` | `Node.h` | Basic singly linked node |
| `Song` | `song.h` | Song data with comparison operators and file / console I/O |
| `Playlist` | `playList.h` | Holds `Song*` pointers into the library plus a "current song" pointer |
| `unordered_map` | `main.cpp` | Maps a playlist name to its `Playlist` object |

---

## 📁 Project Structure

```
.
├── main.cpp          # Menu-driven program (entry point)
├── song.h            # Song class + operator overloads
├── songLibrary.h     # Song library (BST-based)
├── tree.h            # Generic Binary Search Tree
├── LinkedList.h      # Generic Doubly Linked List (Node2 + DoublyLinkedList)
├── stack.h           # Stack built on the Doubly Linked List
├── Node.h            # Generic singly linked node
├── playList.h        # Playlist class
├── song.txt          # Sample song data
└── README.md
```

---

## 🚀 Getting Started

### Prerequisites

- A C++ compiler with **C++11 or newer** support (tested with `g++` using `-std=c++17`)
  - Windows: [Visual Studio](https://visualstudio.microsoft.com/) or MinGW-w64
  - Linux: `sudo apt install g++`
  - macOS: `xcode-select --install`
- [Git](https://git-scm.com/)

### 1. Clone the repository

```bash
git clone https://github.com/bilalafzal-devworks/spotify-playlist-manager-dsa.git
cd spotify-playlist-manager-dsa
```

### 2. Build and run

**Option A: Command line (g++)**

```bash
g++ -std=c++17 main.cpp -o spotify
./spotify          # Linux / macOS
spotify.exe        # Windows
```

**Option B: Visual Studio**

1. Create a new **Empty Project** (C++).
2. Copy all `.h` files and `main.cpp` into the project folder, then add them via *Add → Existing Item*.
3. Press **Ctrl + F5** to build and run.

> ⚠️ **Linux / macOS note:** file names are case-sensitive. The header file is named `playList.h`, so `main.cpp` must contain `#include "playList.h"` (capital **L**).

### 3. Make sure `song.txt` is in the same folder you run from

Option `[14]` opens the file by name, so run the program from the folder that contains `song.txt`.

> ⚠️ **Line endings:** if you clone on Linux / macOS and loaded songs show a blank `Title:` line, the file has Windows (CRLF) line endings. Convert it once with:
> ```bash
> sed -i 's/\r$//' song.txt
> ```

---

## 🎮 How to Use

Run the program and type the number of the option you want.

| # | Option | What it does |
|---|---|---|
| **Library** | | |
| 1 | View All Songs in Library | Prints all songs, sorted by title |
| 2 | Add Song to Library | Asks for title, artist, duration (seconds), year |
| **Playlists** | | |
| 3 | Create Playlist | Creates an empty playlist with the name you enter |
| 4 | List All Playlists | Shows all playlist names |
| 5 | Switch Playlist | Makes a playlist the active one |
| 6 | Delete Playlist | Removes a playlist by name |
| **Current playlist** | | |
| 7 | Add Song to Playlist | Adds a song from the library by title |
| 8 | Remove Song from Playlist | Removes a song by title |
| 9 | View Current Playlist | Shows all songs in the active playlist |
| **Playback** | | |
| 10 | Play Song | Plays any library song by title and adds it to history |
| 11 | Play Current Playlist Song | Plays the playlist's current song and adds it to history |
| 12 | Play Previous Song | Moves to the previous song in the playlist |
| 13 | Play Next Song | Moves to the next song in the playlist |
| **Files** | | |
| 14 | Load Songs from File | Reads songs from a text file into the library |
| 15 | Save Library to File | Writes the library to a file |
| 16 | Save Playlist to File | Writes the active playlist to a file |
| **History** | | |
| 17 | Show Recently Played Songs | Prints the history stack |
| 0 | Exit Program | Quits |

**Typical workflow:** `14` (load songs) → `3` (create playlist) → `5` (switch to it) → `7` (add songs) → `11` / `13` / `12` (play, next, previous) → `17` (history).

---

## 📄 Song File Format

One song per line, comma-separated, with no spaces around the commas:

```
title,artist,duration_in_seconds,year
```

Example (`song.txt`):

```
Blinding Lights,The Weeknd,200,2020
Shape of You,Ed Sheeran,210,2017
Numb,Linkin Park,190,2003
Levitating,Dua Lipa,180,2021
Someone Like You,Adele,230,2011
Perfect,Ed Sheeran,263,2017
Bohemian Rhapsody,Queen,354,1975
Believer,Imagine Dragons,204,2017
Peaches,Justin Bieber,198,2021
Sunflower,Post Malone,158,2018
```

The program also starts with four songs already in the library (Blinding Lights, Shape of You, Numb, Levitating).

---

## 💻 Sample Session

```
Enter your choice: 14
Enter File name
song.txt
Song has been added to library.

Enter your choice: 3
Enter new playlist name: MyList
Playlist "MyList" created.

Enter your choice: 5
Enter playlist name to switch to: MyList
Switched to playlist "MyList".

Enter your choice: 7
Enter song title to add: Numb
Added to playlist: Title: Numb, Artist: Linkin Park, Duration: 190s, Year: 2003
```

---

## 🧠 Design Notes

- **Song ordering:** `Song::operator<` compares by title first, then artist. `operator==` compares titles only, so songs are looked up by title.
- **Library never copies songs into playlists.** A playlist stores `Song*` pointers to the nodes inside the library BST, so there is one copy of each song.
- **New playlist songs are added at the front** of the doubly linked list, so the newest song is first.
- **One `<<` operator, two outputs:** `operator<<(ostream&, const Song&)` checks whether the stream is `cout`. If so, it prints a readable line. Otherwise it writes CSV. `operator>>` does the same for reading from `cin` or a file.
- **History** records songs played through options `10` and `11`.
- **Inheritance for reuse:** `SongLibrary` extends `BinarySearchTree`, and `Stack` extends `DoublyLinkedList`.

---

## ⏱️ Time Complexity

| Operation | Complexity |
|---|---|
| Add / find / delete song in library (BST) | O(log n) average, O(n) worst case (unbalanced tree) |
| Display library (in-order traversal) | O(n) |
| Add song to playlist (find in library + insert at front) | O(log n) average |
| Next / previous song | O(1) |
| Remove song from playlist | O(n) |
| Push to history (stack) | O(1) |
| Find playlist by name (`unordered_map`) | O(1) average |

---

## ⚠️ Known Limitations

- **Option 11 on an empty playlist crashes** because the code reads the current song before checking that one exists.
- **Option 15 (save library)** writes a header line and trailing spaces into the file, so reloading that file with option 14 is not reliable yet. Use the plain CSV format shown above for loading.
- **Deleting a playlist (option 6)** does not free its memory, and deleting the active playlist leaves the program pointing at it. Switch to another playlist right after deleting.
- The BST is **not self-balancing**, so loading songs already sorted by title makes it behave like a linked list.
- Menu input is not validated. Typing letters where a number is expected will break the menu loop.
- Songs cannot be removed from the library from the menu.

---

## 🔮 Future Improvements

- Replace the BST with an AVL or Red-Black tree for guaranteed O(log n)
- Add shuffle and repeat modes for playlists
- Validate all user input
- Add a "remove song from library" menu option
- Fix the issues listed above and add unit tests
- Search by artist from the menu (`findSongsByArtist` already exists in `songLibrary.h`)

---

## 👥 Authors

| Name | Registration No. |
| Muhammad Bilal | L1F23BSCS0383 |

**Course:** Data Structures and Algorithms (DSA)

---

## 📜 License

This project was created for educational purposes as part of a university course.****
