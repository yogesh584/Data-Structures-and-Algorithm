/*
    TRIE :
        Trie is also known as digital tree or prefix tree.

        WHAT :
            Trie is a type of k-ary search tree. Tries is a tree that stores strings

            K-ARY TREE :
                k-ary tree is a rooted tree in which each node has no more than k children.

        WHY :
            Search complexities can be brought to optimal limit (key length).
            For More Info Refer The Article : https://www.geeksforgeeks.org/advantages-trie-data-structure/

        WHEN :
            used for storing and searching a specific key from a set.

        DISADVANTAGE :
            The main disadvantage of tries is that they need a lot of memory for storing the strings. For each node we have too many node pointers(equal to number of characters of the alphabet).if space is concerned, then Ternary Search Tree can be preferred for dictionary implementations.

            TERNERY SEARCH TREE :
                A ternary search tree is a special trie data structure where the child nodes of a standard trie are ordered as a binary search tree.

        CONCLUSION : The final conclusion is regarding tries data structure is that they are faster but require huge memory for storing the strings.

        HASHTABLE VS TRIE :
            OPERATIONS          T.C OF TRIE             T.C OF HASHTABLE IN WORST CASE      T.C OF HASTABLE IN AVG CASE
            ADD WORD               O(l)                         O(l)                            O(1)
            REMOVE WORD            O(l)                         O(l)                            O(1)
            SEARCH WORD            O(l)                         O(l)                            O(1)

            l is length of word.

            In Case of Trie space utilization is more efficient then hashmap.
            Although the hash table has a relatively faster lookup speed, it only supports the exact match of the whole string. The trie solution is more flexible to support more applications, such as auto-complete. Also, we can easily print all the words in the dictionary in alphabetic order with a trie.

        BINARY SEARCH TREE VS TRIE :
            OPERATIONS          T.C OF TRIE             T.C OF BINARY TREE
            SEARCH WORD             O(l)                    O(l*logN)

            l is length of word.
            N is total nodes in BST.

            Trie is Faster then BST to serching words and Trie also comes with some extra functionality.
*/

#include <iostream>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char givenChar)
    {
        data = givenChar;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie
{
private:
    void insertUtil(TrieNode *root, string givenWord)
    {
        /*      BASE CASE       */
        if (givenWord.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        // Assumption : Word will be in capital letters.
        int index = givenWord[0] - 'A';
        TrieNode *child;

        // Char is Present.
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        // Char is Absent
        else
        {
            child = new TrieNode(givenWord[0]);
            root->children[index] = child;
        }

        // Recursive Call.
        insertUtil(child, givenWord.substr(1));
    }

    bool serachUtil(TrieNode *root, string givenWord)
    {
        if (givenWord.length() == 0)
        {
            return root->isTerminal;
        }

        int index = givenWord[0] - 'A';
        TrieNode *child;

        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            return false;
        }

        // Recursion
        return serachUtil(child, givenWord.substr(1));
    }

    void removeUtil(TrieNode *&root, string givenWord)
    {
        if (givenWord.length() == 0)
        {
            root->isTerminal = false;
        }

        int index = givenWord[0] - 'A';
        TrieNode *child;

        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            return;
        }

        // Recursion
        serachUtil(child, givenWord.substr(1));
    }

public:
    TrieNode *root;

    Trie()
    {
        root = new TrieNode('\0');
    }

    /*
        T.C : O(l)
    */
    void insert(string givenWord)
    {
        insertUtil(root, givenWord);
    }

    /*
        T.C : O(l)
    */
    bool search(string givenWord)
    {
        return serachUtil(root, givenWord);
    }

    void remove(string givenWord)
    {
        removeUtil(root, givenWord);
    }
};

int main()
{
    cout << endl
         << endl
         << endl;

    /*      CREATING TRIE       */
    Trie *t = new Trie();

    /*      INSERTING ELEMENTS IN TRIE      */
    t->insert("YOGESH");
    t->insert("JANGID");

    /*      SEARCHING ELEMENTS IN TRIE      */
    cout << "Seaching in Trie : " << endl;
    cout << "Is given Word is Present in Trie : " << t->search("JANGID") << endl;

    t->remove("JANGID");
    cout << t->search("JANGID") << endl;

    cout
        << endl
        << endl
        << endl;
    return 0;
}
