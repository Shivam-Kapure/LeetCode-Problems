/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
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
    Node* dfsHelper(Node* curr, unordered_map<Node*, Node*>& umap) {
        vector<Node*> clone_neighbors;
        Node* clone = new Node(curr->val);
        umap[curr] = clone;

        for(auto it : curr->neighbors) {
            if(umap.find(it) != umap.end())
                clone_neighbors.push_back(umap[it]);
            else
                clone_neighbors.push_back(dfsHelper(it, umap));
        }
        clone->neighbors = clone_neighbors;
        return clone;
    }
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> umap;

        if(node == NULL)
            return node;
        if(node->neighbors.size() == 0) {
            Node* clone = new Node(node->val);
            return clone;
        }
        return dfsHelper(node, umap);
    }
};