class Node{
    public:
        Node *child[26];
        bool endWord;
    
        Node(){
            for(int i=0;i<26;i++)
                child[i]=nullptr;
            endWord=false;
        }
};


class Trie {
public: 
    
    Node *root;
    
    Trie() {
        root=new Node();
    }
    
    void insert(string s) {
        Node *p = root;
        for(int i = 0; i < s.size(); ++ i)
        {
            if(p -> child[s[i] - 'a'] == NULL)
                p -> child[s[i] - 'a'] = new Node();
            p = p -> child[s[i] - 'a'];
        }
        p -> endWord = true;
    }
    
    bool search(string word) {
         Node *p = root;
        for(int i = 0; i < word.size() && p != NULL; ++ i)
            p = p -> child[word[i] - 'a'];
        return p==nullptr?false:p->endWord;
    }
    
    bool startsWith(string key) {
        Node *p = root;
        for(int i = 0; i < key.size() && p != NULL; ++ i)
            p = p -> child[key[i] - 'a'];
        return p!=nullptr;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */