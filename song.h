#pragma once
#include <iostream>
#include <string>
using namespace std;
class Song {
private:
     string title;
     string artist;
    int duration; 
    int year;

public:
    Song(const  string& t = "Unknown", const  string& a = "Unknown",
        const int& d = 0,const int& y = 0)
        : title(t), artist(a), duration(d), year(y) {
        if (d < 0) cout<<"Duration cannot be negative\n";
        if (y < 0) cout<<"Year cannot be negative\n";
    }

    Song(const Song& other)
        : title(other.title), artist(other.artist),
        duration(other.duration), year(other.year) {
    }

    ~Song() {};

    Song& operator=(const Song& other) {
        if (this != &other) {
            title = other.title;
            artist = other.artist;
            duration = other.duration;
            year = other.year;
        }
        return *this;
    }

    bool operator==(const Song& other) const {
        return title == other.title;
    }

    bool operator!=(const Song& other) const {
        return !(*this == other);
    }

    bool operator<(const Song& other) const {
        if (title != other.title) return title < other.title;
        return artist < other.artist;
    }

    bool operator>(const Song& other) const {
        return other < *this;
    }

    bool operator<=(const Song& other) const {
        return !(other < *this);
    }

    bool operator>=(const Song& other) const {
        return !(*this < other);
    }

     string getTitle() const { return title; }
     string getArtist() const { return artist; }
    int getDuration() const { return duration; }
    int getYear() const { return year; }

    void setTitle(const  string& t) { title = t; }
    void setArtist(const  string& a) { artist = a; }
    void setDuration(const int& d) {
        if (d < 0) cout<<"Duration cannot be negative";
        duration = d;
    }
    void setYear(int y) {
        if (y < 0) cout<<"Year cannot be negative";
        year = y;
    }
    void fileInput(istream& is) {
        string title, artist;
        int duration, year;

        getline(is, title, ',');
        getline(is, artist, ',');
        is >> duration;
        is.ignore(); 
        is >> year;
        is.ignore();

        setTitle(title);
        setArtist(artist);
        setDuration(duration);
        setYear(year);
    }
    void getInput() {
        string title, artist;
        int duration, year;

        cout << "Enter title: ";
        getline(cin, title);
        cout << "Enter artist: ";
        getline(cin, artist);
        cout << "Enter duration (seconds): ";
        cin >> duration;
        cout << "Enter year: ";
        cin >> year;
        cin.ignore();

        setTitle(title);
        setArtist(artist);
        setDuration(duration);
        setYear(year);
    }
    void display() const {
        cout << "Title: " << title
            << ", Artist: " << artist
            << ", Duration: " << duration << "s"
            << ", Year: " << year << endl;
    }
    void fileOutput(ostream& os) const {
        os << title << "," << artist << "," << duration << "," << year;
    }
};

ostream& operator<<(ostream& os, const Song& song) {
    // cout ka reference sa match karega
    if (&os == &cout) {
        song.display();         
    }
    else {
        song.fileOutput(os);   
    }
    return os;
}


 istream& operator>>( istream& is, Song& song) {
     if (&is == &cin) {
         song.getInput();
     }
     else {
         song.fileInput(is);
     }
    return is;
}