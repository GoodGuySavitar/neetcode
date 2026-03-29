class Node{
public: 
    Node* links[27];
    bool flag = false;

    bool containsKey(char ch){
        return links[ch - 'a'] != NULL;
    }

    void put(char ch, Node* node){
        links[ch - 'a'] = node;
    }

    Node* get(char ch){
        return links[ch - 'a'];
    }

    void setEnd(){
        flag = true;
    }

    bool isEnd(){
        return flag;
    }
};
class WordDictionary {
private: 
    Node* root;
public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* node = root; 
        for(int i = 0; i < word.size(); i++){
            if(!node->containsKey(word[i])){
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }

    bool dfs(string word, int j, Node* root){
        Node* node = root;
        for(int i = j; i < word.size(); i++){
            char c = word[i];
            if(c == '.'){
                for(Node* ch : node->links){
                    if(ch != nullptr && dfs(word, i+1, ch)){
                        return true;
                    }
                }
                return false;
            }
            else {
                if(!node->containsKey(c)){
                    return false;
                }
                node = node->get(c);
            }
        }
        return node->isEnd();
    }
};
