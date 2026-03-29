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
        if(!node){
            return nullptr;
        }
        unordered_map<Node*, Node*> mapp;
        queue<Node*> q;
        mapp[node] = new Node(node->val);
        q.push(node);

        while(!q.empty()){
            Node* newNode = q.front();
            q.pop();
            for(Node* currNode : newNode->neighbors){
                if(mapp.find(currNode) == mapp.end()){
                    mapp[currNode] = new Node(currNode->val);
                    q.push(currNode);
                }
                mapp[newNode]->neighbors.push_back(mapp[currNode]);
            }   
        }

        return mapp[node];
    }
};
