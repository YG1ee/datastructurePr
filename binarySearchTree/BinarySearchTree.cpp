#include <iostream>
using namespace std;

template<typename T>
class BST {
    private:
        T data;
        BST *left, *right;

    public:
        BST *node = NULL;

        BST() {
            left = NULL;
            right = NULL;
        }

        void insertNode(T datum);
        void deleteNode(T datum);
};

void BST::insertNode(T datum) {
    BST *newNode = new BST();
    this.data = datum;

    while (this.node != NULL) {
        if (datum < this.node->data) // 추가하는 자료값이 현재 노드보다 작은 경우
            this.node = this.node->left;
        else if (datum > this.node->data) // 추가하는 자료값이 현재 노드보다 큰 경우
            this.node = this.node->right;
        else // 추가하는 자료값이 현재 노드와 같은 경우
            cout << "해당 키는 이미 이진 탐색 트리에 있습니다!\n";
    }
    this.node = newNode;
}

void BST::deleteNode(T datum) {
    BST *parent = NULL, *child;
    
    while ((this.node != NULL) && (this.node->data != datum)) { // 삭제할 노드 위치 탐색
        parent = node;
        if (datum < this.node->data)
            this.node = this.node->left;
        else // datum > this.node->data
            this.node = this.node->right;
    }

    if (!node) {
        cout << "\n 지우려는 키가 이진 탐색 트리에 없습니다!\n";
        exit(0);
    }
    
    // 삭제할 노드가 단말 노드인 경우
    if ((this.node->left == NULL) && (this.node->right == NULL))
        if (parent != NULL)
            if (parent->

}
