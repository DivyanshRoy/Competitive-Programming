// Problem Link: https://www.codechef.com/MAY17/problems/WSITES01

#include<bits/stdc++.h>
using namespace std;

//Trie code:- GeeksforGeeks

#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])

// Alphabet size (# of symbols)
#define ALPHABET_SIZE (26)

// Converts key current character into index
// use only 'a' through 'z' and lower case
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

// trie node
struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];

    // isLeaf is true if the node represents
    // end of a word
    bool isLeaf;
};

// Returns new trie node (initialized to NULLs)
struct TrieNode *getNode(void)
{
    struct TrieNode *pNode = NULL;

    pNode = (struct TrieNode *)malloc(sizeof(struct TrieNode));

    if (pNode)
    {
        int i;

        pNode->isLeaf = false;

        for (i = 0; i < ALPHABET_SIZE; i++)
            pNode->children[i] = NULL;
    }

    return pNode;
}

// If not present, inserts key into trie
// If the key is prefix of trie node, just marks leaf node
void insert(struct TrieNode *root, const char *key)
{
    int level;
    int length = strlen(key);
    int index;

    struct TrieNode *pCrawl = root;

    for (level = 0; level < length; level++)
    {
        index = CHAR_TO_INDEX(key[level]);
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();

        pCrawl = pCrawl->children[index];
    }

    // mark last node as leaf
    pCrawl->isLeaf = true;
}

// Returns true if key presents in trie, else false
bool search(struct TrieNode *root, const char *key)
{
    int level;
    int length = strlen(key);
    int index;
    struct TrieNode *pCrawl = root;

    for (level = 0; level < length; level++)
    {
        index = CHAR_TO_INDEX(key[level]);

        if (!pCrawl->children[index])
            return true;

        pCrawl = pCrawl->children[index];
    }
    return 0;
}


int main()
{
     struct TrieNode *root = getNode();

    long int n,i,al,len;
    char c,arr[200005];
    vector< string > se;
    vector< string >::iterator iter;
    set<string> ans,store;
    set<string>::reverse_iterator riter;
    string p=" ";
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>c>>arr;
        if(c=='+')
        {
            store.insert(arr);
        }
        else
            se.push_back(arr);
    }
    for(riter=store.rbegin();riter!=store.rend();riter++)
    {
        if(search(root,(*riter).c_str()))
            insert(root,(*riter).c_str());
    }
    sort(se.begin(),se.end());
    for(iter=se.begin(),i=0;iter!=se.end();iter++,i++)
    {
        len=(*iter).length();
        al=0;
        for(al=0;al<len;al++)
        {
            if(search(root,(*iter).substr(0,al+1).c_str()))
            {
                ans.insert((*iter).substr(0,al+1));
                break;
            }
        }
        if(al==len)
        {
            cout<<-1;
            return 0;
        }
    }
    cout<<ans.size()<<endl;
    set< string>::iterator siter;
    for(siter=ans.begin();siter!=ans.end();siter++)
    {
        cout<<*siter<<endl;
    }
    return 0;
}
