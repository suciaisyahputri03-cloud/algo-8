#include <iostream>
#include <string>
using namespace std;

class node
{
public:
    int noMhs;
    node *next;
};

class LinkedList
{
    node *START;

public:
    LinkedList()
    {
        START = NULL;
    }

    void addNode()
    {
        int nim;
        cout << "\nmasukkan nomor mahasiswa : ";
        cin>> nim;

        node *nodeBaru = new node;
        nodeBaru->noMhs =nim;

        if (START == NULL || nim <= START->noMhs)
        {
            if (START != NULL && nim == START-> noMhs)
            {
                cout << "\nDuplikasi noMhs tidak diijinkan\n";
                return;
            }

            nodeBaru-> next = START;
            START = nodeBaru;
            return;
        }

        node *previous = START;
        node *current = START;

        while (current != NULL && nim > current->noMhs)
        {
            if (nim == current->noMhs)
            {
                cout << "\nDuplikasi noMhs tidak diijinkan\n";
                return;
            }
            previous = current;
            current = current->next;
        }

        nodeBaru->next = current;
        previous->next = nodeBaru;
    }
bool listEmpty()
    {
        return (START == NULL);
    }

    bool search(int nim, node *&previous, node *&current)
    {
        previous = START;
        current - START;

        while (current != NULL && nim != current->noMhs)
        {
            previous = current;
            current = current->next;
        }

        return (current != NULL);
    }

    bool delnode(int nim)
    {
        node *current, *previous;

        if (!search(nim, previous, current))
            return false;
        if (current == START)
            START = START->next;
        else 
            previous->next = current->next;
        delete current;
        return true;
    }

    void traverse()
    {
        if (listEmpty())
        { 
            cout << "\List kosong\n";
        }
        else
        {
            cout << "\nData di dalam List adalah:\n";
            node *currentNode = START;

            while (currentNode != NULL)
            {
                cout << currentNode-> noMhs << endl;
                currentNode = currentNode->next;
            }
            cout << endl;
        }
    }
};

int main()
{
    LinkedList mhs;
    int nim;
    char ch;

    do 
    {
        cout << "\nMenu" << endl;
        cout << "1. menambah data ke dalam list" << endl;
        cout << "2. mnghapus data dari dalam list" << endl;
        cout << "3. menmspilkan semua data di dalam list" << endl;
        cout << "4. mencari data dalam list" << endl;
        cout << "5. keluar" << endl;

        cout << "\nMasukkan pilihan (1-5): ";
        cin >> ch;

        switch (ch)
        {
            case '1':
                mhs.addNode();
                break;
                
            case '2':
                if (mhs.listEmpty())
                {
                    cout << "nList kosong" << endl;
                    break;
                }

                cout << "\nMasukkan no mahasiswa yang dihapus :";
                cin >> nim;

                if (mhs.delnode(nim) == false)
                    cout << "\nData tidsk ditemukan" << endl;
                else
                    cout << "\nData dengan nomor mahasiswa" << nim << "berhasil dihapus";
                break;
            
               