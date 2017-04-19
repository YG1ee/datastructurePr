#include <iostream>
#include <cmath>
using namespace std;

class node {
    private:
        float coeff;
        int exp;
        node *link;

    public:
        node *head, *ptr;

        node() {
            link = NULL;
            ptr = NULL;
            head = NULL;
        }

        void insertNum(float _coeff, int _exp) {
            node *newNode = new node();
            newNode->coeff = _coeff;
            newNode->exp = _exp;

            ptr = head;
                        
            if(ptr != NULL) {
                while(ptr->link != NULL) {
                    ptr = ptr->link;
                }
                ptr->link = newNode;
            }
            else {
                head = newNode;
            }
        }

        void printP() {
            ptr = head;
            if(ptr != NULL) {
                if(ptr->coeff < 0)
                    cout << "-";
                while(1) {
                    cout << abs(ptr->coeff) << "x^" << ptr->exp;
                    ptr = ptr->link;
                    if(ptr == NULL)
                        break;
                    if(ptr->coeff < 0)
                        cout << " - ";
                    else
                        cout << " + ";
                }
                cout << endl;
            }
            else
                cout << "This node is empty." << endl;
        }


};

int main() {

    node a;
    a.insertNum(-3, 5);
    a.insertNum(-2, 4);
    a.insertNum(1, 2);
    a.printP();

    node b;
    b.insertNum(2, 6);
    b.insertNum(1, 5);
    b.insertNum(5, 2);
    b.printP();

    node c;
    c.printP();

    return 0;
}
