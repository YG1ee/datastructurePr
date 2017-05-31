#include <iostream>
using namespace std;

template <typename Item>
class Node {
public:
    Item data;
    Node *left, *right;
    Node() {
        left = NULL;
        right = NULL;
    }
    Node(Item datum) {
        data = datum;
        left = NULL;
        right = NULL;
    }
};

template <typename Item>
class BST {
private:
    Node<Item> *parent, *child;
    Node<Item> *succ_parent, *succ;
    
public:
    Node<Item> *root, *ptr;
    Node<Item> *search_ptr, *search_parent;
    
    BST() {
        root = ptr = NULL;
    }
    
    void insertNode(Item datum) {
        ptr = root;
        Node<Item> *newNode = new Node<Item>(datum);
        
        if (!root) // 노드가 하나도 없는 경우
            root = newNode;
        else {
            if (!searchBST(datum)) {
                while (ptr) {
                    if (datum < ptr->data) {
                        parent = ptr;
                        ptr = ptr->left;
                    }
                    else {
                        parent = ptr;
                        ptr = ptr->right;
                    }
                }
                if (datum < parent->data)
                    parent->left = newNode;
                else
                    parent->right = newNode;
            }
            else {
                cout << "해당 키는 이미 이진 탐색 트리에 존재합니다!" << endl;
                delete newNode;
            }
        }
    }
    
    void deleteNode(Item datum) {
        succ = NULL;
        parent = NULL;
        
        Node<Item> *targetNode = searchBST(datum); // 삭제할 노드 위치 탐색
        
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
        else { // 삭제되는 노드는 succ_parent, 삭제된 노드 자리에 들어갈 후계자는 succ
            succ_parent = targetNode;
            succ = targetNode->left;
            while (succ->right) {
                succ_parent = succ;
                succ = succ->right;
            }
            if (succ_parent->left == succ) {
                succ_parent->left = succ->left;
                succ_parent->data = succ->data;
            }
            else {
                succ_parent->right = succ->left;
                succ_parent->data = succ->data;
            }
        }
        delete succ;
        cout << datum << "키를 성공적으로 삭제했습니다!" << endl;
    }
    
    Node<Item>* searchBST(Item datum) {
        search_ptr = root;
        
        while (search_ptr) {
            if (datum == search_ptr->data)
                return search_ptr;
            else if (datum < search_ptr->data) {
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
    
    void displayInorder(Node<Item> *node) {
        if (node) {
            displayInorder(node->left);
            cout << node->data << "_";
            displayInorder(node->right);
        }
    }
    
    void menu() {
        cout << "*------------------------*" << endl;
        cout << "\t1: 트리 출력" << endl;
        cout << "\t2: 문자 삽입" << endl;
        cout << "\t3: 문자 삭제" << endl;
        cout << "\t4: 문자 검색" << endl;
        cout << "\t5: 종료" << endl;
        cout << "*------------------------*" << endl;
        cout << "메뉴 입력 >> ";
    }
};

int main() {
    BST<int> *bst1 = new BST<int>();

    int input1 = 5;
    int input2 = 3;
    int input3 = 9;
    int input4 = 1;
    int input5 = 4;
    bst1->insertNode(input1);
    bst1->insertNode(input2);
    bst1->insertNode(input3);
    bst1->insertNode(input4);
    bst1->insertNode(input5);
    bst1->insertNode(20);
    bst1->insertNode(15);
    bst1->insertNode(12);
    bst1->insertNode(16);
    bst1->insertNode(17);
    bst1->insertNode(5);
    bst1->insertNode(12);
    bst1->deleteNode(15);
    cout << bst1->root->data << " ";
    bst1->displayInorder(bst1->root);
    cout << endl;
    
    return 0;
}
