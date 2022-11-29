#include <iostream>
#include <vector>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;
    int childCount;

    TrieNode(char givenChar)
    {
        data = givenChar;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
        childCount = 0;
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
        int index = givenWord[0] - 'a';
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
            root->childCount++;
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

        int index = givenWord[0] - 'a';
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

    string lcp(string str, string &ans)
    {
        for (int i = 0; i < str.length(); i++)
        {
            char ch = str[i];
            if (root->childCount == 1)
            {
                ans.push_back(ch);

                int index = ch - 'a';
                root = root->children[index];
            }
            else
            {
                break;
            }

            if (root->isTerminal)
                break;
        }
    }
};

int main()
{
    Trie *t = new Trie();
    vector<string> arr = {"coding", "codezen", "codingninja", "coder"};

    for (int i = 0; i < arr.size(); i++)
    {
        t->insert(arr[i]);
    }

    string ans = "";
    t->lcp(arr[0], ans);

    return 0;
}