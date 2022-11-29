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

    void printSuggestions(TrieNode *curr, vector<string> &temp, string prefix)
    {
        // base case
        if (curr->isTerminal)
        {
            temp.push_back(prefix);
        }

        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            TrieNode *next = curr->children[ch - 'a'];

            if (next != NULL)
            {
                prefix.push_back(ch);
                printSuggestions(next, temp, prefix);
                prefix.pop_back();
            }
        }
    }

    vector<vector<string>> getSuggestions(string str)
    {
        TrieNode *prev = root;
        vector<vector<string>> output;
        string prefix = "";

        for (int i = 0; i < str.length(); i++)
        {
            char lastch = str[i];
            prefix.push_back(lastch);

            // check for lastch

            TrieNode *curr = prev->children[lastch - 'a'];

            // if not found
            if (curr == NULL)
            {
                break;
            }

            // if found
            vector<string> temp;
            printSuggestions(curr, temp, prefix);

            output.push_back(temp);
            temp.clear();

            prev = curr;
        }
        return output;
    }
};
int main()
{
    cout << endl
         << endl
         << endl;

    vector<string> contactList = {"cod", "code", "coding", "codding", "coly"};
    string queryStr = "coding";

    // creation of Trie
    Trie *t = new Trie();

    // step 1 : Add all words to trie

    for (int i = 0; i < contactList.size(); i++)
    {
        string str = contactList[i];
        t->insert(str);
    }

    vector<vector<string>> ans = t->getSuggestions(queryStr);

    cout << "All Suggestions are : " << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl
         << endl
         << endl;
    return 0;
}