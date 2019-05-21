// 문자열을 키값으로 하는 이진 탐색 트리 코드
#include <iostream>
#define MAX_ARG 100
using namespace std;

class Node {
public:
    char *string;
    Node *left, *right;
    Node(char *strung) {
        string = strung;
        left = NULL;
        right = NULL;
    }
};

class BST {
private:
    Node *parent, *child;
    Node *succ_parent, *succ;
    
public:
    Node *root, *ptr;
    Node *search_ptr, *search_parent;
    
    BST() {
        root = ptr = NULL;
    }
    
    void insertNode(char *strung) {
        ptr = root;
        Node *newNode = new Node(strung);
        int compare;
        
        if (!root) // 노드가 하나도 없는 경우
            root = newNode;
        else {
            while (ptr) {
                compare = strcmp(strung, ptr->string);
                if (compare < 0) {
                    parent = ptr;
                    ptr = ptr->left;
                }
                else if (compare > 0) {
                    parent = ptr;
                    ptr = ptr->right;
                }
                else {
                    cout << "해당 키는 이미 이진 탐색 트리에 존재합니다." << endl;
                    delete newNode;
                    return;
                }
            }
            if (strcmp(strung, parent->string) < 0)
                parent->left = newNode;
            else
                parent->right = newNode;
        }
    }
    /* 노드 삭제 미구현
    void deleteNode(char *strung) {
        succ = NULL;
        parent = NULL;
        
        Node *targetNode = searchBST(strung); // 삭제할 노드 위치 탐색
        
        if (!targetNode) {
            cout << endl << "지우려는 키가 이진 탐색 트리에 없습니다!" << endl;
            return;
        }
        
        // 삭제할 노드가 단말 노드인 경우
        if ((targetNode->left == NULL) && (targetNode->right == NULL)) {
            if (search_parent != NULL) {
                if (search_parent->left == targetNode)
                    search_parent->left = NULL;
                else // search_parent->right == targetNode
                    search_parent->right = NULL;
            }
        }
        // 삭제할 노드의 차수가 1인 경우
        else if ((targetNode->left == NULL) || (targetNode->right == NULL)) {
            if (targetNode->left != NULL)
                child = targetNode->left;
            else // targetNode->right != NULL
                child = targetNode->right;
            
            if (search_parent != NULL)
                if (targetNode == search_parent->left)
                    search_parent->left = child;
                else // targetNode == parent->right
                    search_parent->right = child;
                else // search_parent == NULL, 즉 targetNode가 root 노드인 상황
                    targetNode = child;
        }
        // 삭제할 노드의 차수가 2인 경우
        else { // 삭제되는 노드는 parent, 삭제된 노드 자리에 들어갈 후계자는 succ
            succ_parent = parent = targetNode;
            succ = targetNode->left;
            while (succ->right) {
                succ_parent = succ;
                succ = succ->right;
            }
            if (parent->left == succ) {
                parent->left = succ->left;
                parent->string = succ->string;
            }
            else {
                succ_parent->right = succ->left;
                parent->string = succ->string;
            }
        }
        delete succ;
        cout << strung << "키를 성공적으로 삭제했습니다!" << endl;
    }
    */
    
    Node* searchBST(char *strung) {
        search_ptr = root;
        int compare;
        
        while (search_ptr) {
            compare = strcmp(strung, search_ptr->string);
            if (!compare)
                return search_ptr;
            else if (compare == -1) {
                search_parent = search_ptr;
                search_ptr = search_ptr->left;
            }
            else {
                search_parent = search_ptr;
                search_ptr = search_ptr->right;
            }
        }
        return NULL; // 노드 검색에 실패한 경우 널값 반환
    }
    
    void displayInorder(Node *node) {
        if (node) {
            displayInorder(node->left);
            cout << node->string << " / ";
            displayInorder(node->right);
        }
    }
};

int main() {
    BST *bst1 = new BST();
    int argc = 0;
    char *argv[MAX_ARG];
    char delim[] = " \t\n";
    char input[] = "data structure is one of the most important courses in computer science";
    
    argv[argc++] = strtok(input, delim);
    while ((argv[argc++] = strtok(NULL,delim)));
    
    for (int i = 0; i < argc-1; i += 1)
        bst1->insertNode(argv[i]);
    
    bst1->displayInorder(bst1->root);
    cout << endl;
    
    return 0;
}
