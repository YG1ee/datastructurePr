#include <iostream>
#include <cmath>
using namespace std;

class node {
    private:
        float coeff; // 계수
        int exp; // 지수
        node *link; // 링크
        
    public:
        node *head, *ptr; // 헤드 노드, 현재 노드
        
        node() {
            link = NULL;
            ptr = NULL;
            head = NULL;
        }
        
        void insertNum(float _coeff, int _exp) { // 항 추가
            node *newNode = new node(); // 새로운 항의 틀 생성
            newNode->coeff = _coeff; // 새로운 항에 계수 대입
            newNode->exp = _exp; // 새로운 항에 지수 대입
            newNode->link = NULL; // 새로운 항의 링크도 NULL 가리키기
            
            ptr = head; // 현재 포인터가 헤드 노드를 가리키기
            
            if(ptr != NULL) { // 항이 하나라도 있는 경우
                while(ptr->link != NULL) { // 현재 포인터가 마지막 항인지 검사
                    ptr = ptr->link; // 링크 진행 (차수 낮추기)
                }
                ptr->link = newNode; // 현재 포인터가 마지막 항인 경우
            }
            else { // 항이 하나도 없는 경우 (제일 처음 추가)
                head = newNode; // 새로운 항을 헤드 노드로 설정
            }
        }
        
        void printP() { // 다항식 출력
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
        
        node addPoly(node NodeB) {
            int expA, expB;
            node NodeC;
            ptr = head;
            NodeB.ptr = NodeB.head;
            
            while( (ptr!=NULL) | (NodeB.ptr!=NULL) ) {
                if(ptr!=NULL) // ptr 포인터가 가리키는 항이 존재하는 경우
                    expA = ptr->exp;
                else // ptr 포인터가 가리키는 항이 존재하지 않는 경우 (다항식이 끝난 경우)
                    expA = -1;
                if(NodeB.ptr!=NULL)
                    expB = NodeB.ptr->exp;
                else
                    expB = -1;
                
                if(expA == expB) { // 두 항의 지수가 같은 경우
                    if(ptr->coeff + NodeB.ptr->coeff)
                        NodeC.insertNum(ptr->coeff + NodeB.ptr->coeff, NodeB.ptr->exp);
                    ptr = ptr->link;
                    NodeB.ptr = NodeB.ptr->link;
                }
                else if(expA > expB) { // 첫 번째 다항식의 항의 지수가 더 높은 경우
                    NodeC.insertNum(ptr->coeff, ptr->exp);
                    ptr = ptr->link;
                }
                else if(expA < expB) { // 두 번째 다항식의 항의 지수가 더 높은 경우
                    NodeC.insertNum(NodeB.ptr->coeff, NodeB.ptr->exp);
                    NodeB.ptr = NodeB.ptr->link;
                }
            }
            
            return NodeC;
        }
};

int main() {
    
    node polyA; // 첫 번째 다항식 틀 생성
    polyA.insertNum(7, 7);
    polyA.insertNum(-3, 5);
    polyA.insertNum(-2, 3);
    polyA.insertNum(1, 1);
    polyA.insertNum(6, 0);
    cout << "첫 번째 다항식: ";
    polyA.printP();
    
    node polyB; // 두 번째 다항식 틀 생성
    polyB.insertNum(2, 6);
    polyB.insertNum(3, 5);
    polyB.insertNum(5, 2);
    polyB.insertNum(10, 1);
    polyB.insertNum(-6, 0);
    cout << "두 번째 다항식: ";
    polyB.printP();
    
    node polyC;
    polyC = polyA.addPoly(polyB); // 첫 번째와 두 번째 다항식을 더해 세 번째 다항식 틀에 대입
    cout << "결과 다항식: ";
    polyC.printP();
    
    return 0;
}
