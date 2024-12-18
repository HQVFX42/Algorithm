// P5
//#include <bits/stdc++.h>
//using namespace std;
//
//bool KMP(const string& S, const string& P)
//{
//    vector<int> F(P.size());
//
//    int j = 0;
//    for (int i = 0; i < S.size(); i++)
//    {
//        while (j > 0 and S[i] != P[j])
//        {
//            j = F[j - 1];
//        }
//        if (S[i] == P[j])
//        {
//            j++;
//        }
//        if (j == P.size())
//        {
//            return true;
//        }
//    }
//    return false;
//}
//
//int main()
//{
//    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
//    int N;
//    cin >> N;
//
//    vector<string> Words;
//    for (int i = 0; i < N; i++)
//    {
//        string S;
//        cin >> S;
//
//        bool bInclude = false;
//        for (string& Prev : Words)
//        {
//            if (KMP(S, Prev))
//            {
//                cout << S << '\n';
//                bInclude = true;
//                break;
//            }
//        }
//
//        if (!bInclude)
//        {
//            Words.push_back(S);
//        }
//    }
//
//    return 0;
//}

//#include <bits/stdc++.h>
//using namespace std;
//
//class TrieNode
//{
//public:
//    unordered_map<char, TrieNode*> children;
//    bool isEndOfWord;
//
//    TrieNode() : isEndOfWord(false) {}
//};
//
//class Trie
//{
//private:
//    TrieNode* root;
//
//public:
//    Trie()
//    {
//        root = new TrieNode();
//    }
//
//    void Insert(const string& word)
//    {
//        TrieNode* node = root;
//        for (char c : word)
//        {
//            if (node->children.find(c) == node->children.end())
//            {
//                node->children[c] = new TrieNode();
//            }
//            node = node->children[c];
//        }
//        node->isEndOfWord = true;
//    }
//
//    bool IsSubstringOfAny(const string& text)
//    {
//        int n = text.length();
//        for (int i = 0; i < n; ++i)
//        {
//            TrieNode* node = root;
//            for (int j = i; j < n; ++j)
//            {
//                if (node->children.find(text[j]) == node->children.end())
//                {
//                    break;
//                }
//                node = node->children[text[j]];
//                if (node->isEndOfWord)
//                {
//                    return true;
//                }
//            }
//        }
//        return false;
//    }
//
//
//
//
//};
//
//int main()
//{
//    int N;
//    cin >> N;
//    cin.ignore();
//
//    Trie trie;
//    vector<string> Results;
//
//    for (int i = 0; i < N; ++i)
//    {
//        string Word;
//        getline(cin, Word);
//
//        bool ContainsPrevious = trie.IsSubstringOfAny(Word);
//
//        if (ContainsPrevious)
//        {
//            Results.push_back(Word);
//        }
//
//        trie.Insert(Word);
//    }
//
//    for (const string& Result : Results)
//    {
//        cout << Result << endl;
//    }
//
//    return 0;
//}

#include <bits/stdc++.h>
using namespace std;

const int ROOT = 1;
const int ALPHABET_SIZE = 26;
const int MX = 10000 * 400 + 5;

int Next[MX][ALPHABET_SIZE];
bool Check[MX];
int Unused = 2;

int Ctoi(char c)
{
    return c - 'a';
}

void Insert(const string& S)
{
    int Cur = ROOT;
    for (char C : S)
    {
        int Idx = Ctoi(C);
        if (Next[Cur][Idx] == -1)
        {
            Next[Cur][Idx] = Unused++;
        }
        Cur = Next[Cur][Idx];
    }
    Check[Cur] = true;
}

bool IsSubstring(const string& S)
{
    int N = S.size();
    for (int i = 0; i < N; ++i)
    {
        int Cur = ROOT;
        for (int j = i; j < N; ++j)
        {
            int Idx = Ctoi(S[j]);
            if (Next[Cur][Idx] == -1)
            {
                break;
            }
            Cur = Next[Cur][Idx];
            if (Check[Cur])
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    fill(&Next[0][0], &Next[0][0] + sizeof(Next) / sizeof(int), -1);

    int N;
    cin >> N;

    vector<string> Answers;

    for (int i = 0; i < N; ++i)
    {
        string Word;
        getline(cin, Word);

        if (IsSubstring(Word))
        {
            Answers.push_back(Word);
        }

        Insert(Word);
    }

    for (const string& Answer : Answers)
    {
        cout << Answer << '\n';
    }

    return 0;
}
