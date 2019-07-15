

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) 
        	return NULL;
        if (root->left) 
        	root->left->next = root->right;
        if (root->right) 
        	root->right->next = root->next? root->next->left : NULL;
        connect(root->left);
        connect(root->right);
        return root;
    }
};


class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return NULL;
        Node *p = root->next;
        while (p) {
            if (p->left) {
                p = p->left;
                break;
            }
            if (p->right) {
                p = p->right;
                break;
            }
            p = p->next;
        }
        if (root->right) root->right->next = p; 
        if (root->left) root->left->next = root->right ? root->right : p; 
        connect(root->right);
        connect(root->left);
        return root;
    }
};

