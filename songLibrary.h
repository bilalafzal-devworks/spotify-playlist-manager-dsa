#pragma once
#include"tree.h"
#include"song.h"
#include<iostream>
using namespace std;

template <typename T>
class SongLibrary : public BinarySearchTree<T> {
private:
    void findByArtist(TreeNode<T>* node, const string& artist) const {
        if (!node) return;
        findByArtist(node->left, artist);
        if (node->data.getArtist() == artist) {
            cout << node->data << endl;
        }
        findByArtist(node->right, artist);
    }

public:
    SongLibrary() : BinarySearchTree<T>() {}

    void addSong(T song=T()) {
        if (song == T()) {
            cin >> song;
        }
        this->insert(song);
    }

    void deleteSong(const string& title) {
        T temp(title, "",0, 0);// author zero
        this->remove(temp);
    }

    T* findSong(const string& title) const {
        T temp(title, "",0, 0);
        TreeNode<T>* node = this->search(this->getRoot(), temp);
        if (!node) {
            return nullptr;
        }
        else {
            return &(node->data);
        }
    }

    void displayAllSongs(ostream& out = cout) const {
        if (this->isEmpty()) {
            cout << "Library is empty" << endl;
            return;
        }
        if (&out == &cout) {
            cout << "Songs in library (sorted by title):" << endl;
            this->inorderTraversal();
        }
        else {
            out << "Songs in library (sorted by title):" << endl;
            this->inorderTraversal(out);
        }
        
    }

    void findSongsByArtist(const string& artist) const {
        if (this->isEmpty()) {
            cout << "Library is empty" << endl;
            return;
        }
        cout << "Songs by " << artist << ":" << endl;
        findByArtist(this->root, artist);
    }
};
