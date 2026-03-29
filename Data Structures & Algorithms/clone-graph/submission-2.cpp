/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>()
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> mapp;
        return dfs(node, mapp);
    }

    Node* dfs(Node* node, unordered_map<Node*, Node*>& mapp){
        if(!node) return nullptr;

        if(mapp.find(node) != mapp.end()){
            return mapp[node];
        }

        Node* newNode = new Node(node->val);
        mapp[node] = newNode;

        for(Node* curr : node->neighbors){
            newNode->neighbors.push_back(dfs(curr, mapp));
        }

        return newNode;
    }
};
