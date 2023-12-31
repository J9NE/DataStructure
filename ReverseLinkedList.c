/***
  터미널을 통해 입력받은 값으로 연결리스트를 생성하고 생성한 리스트를 역순으로 변환하는 프로그램
  C Program that generate linked-list with values entered through the terminal and reverse the generated lists.
  by 2023. 07. 16 Jane
  - 스택 구조로 연결 리스트를 생성함
  - 동적 할당
***/

#include <stdio.h>
#include <stdlib.h>

typedef int Data; // 데이터 필드에 들어갈 자료형의 수정이 용이하도록 typedef로 선언함

typedef struct ListNode {
  Data val;              // data field
  struct ListNode *next; // link field
} Node;

Node *head = NULL;

int isListEmpty() { return head == NULL; }
void initList() { head = NULL; }

void push(Data e) {
  if (e >= 0) {
    /*
    e가 음수가 아닐 때만 새로운 노드를 생성한다.
    이 조건을 추가하지 않으면, 프로그램 종료를 위해 입력한 음수의 값을 지닌 노드가 생성된다.
    */
    Node *p = (Node *)malloc(sizeof(Node));
    p->val = e;

    p->next = head;
    head = p;
  }
}

void printList() {
  Node *current;

  if (isListEmpty()) {
    printf("Empty List!");
    return;
  } else {
    current = head;
    while (current != NULL) {
      printf("%2d", current->val);
      if (current->next != NULL) {
        printf(" ▷ "); // 현재 노드의 다음 노드가 존재하는 경우에만 화살표 출력
      }
      current = current->next;
    }
  }
  printf("\n");
}

void reverseList() {
  if (isListEmpty()) {
    printf("Empty List!");
    return;
  } else {
    Node *current = head, *next = NULL, *prev = NULL;

    while (current != NULL) {
      next = current->next;
      current->next = prev;
      prev = current;
      current = next;
    }
    head = prev;
    /*
    printList() 함수 사용을 위해 while문이 완료된 이후(reverse가 완료된 이후) head가 가리키는 노드를 조정한다.
    head는 포인터 변수 current에게 사용되었을 뿐 직접적으로 사용된 적은 없다. 즉 head는 처음 위치 그대로이다.
    reverse가 완료된 이후엔 연결된 순서가 바뀌었으므로, head가 가리키는 노드의 주소 필드는 NULL값이 된다.
    따라서 해당 command없이 이 프로그램을 실행할 경우, reverse된 완전한 리스트가 printList()로 출력 되지 않는다.
    */
  }
}

int main() {
  printf("리스트에 삽입하고 싶은 정수들을 순서대로 적으세요.\n");
  printf("음수를 입력하면 입력은 종료됩니다.:\n");

  int user_input = 0;
  while (scanf("%d", &user_input) == 1 && user_input >= 0) {
    push(user_input);
    // 사용자로부터 입력 받은 값을 리스트에 push한다.
  }

  printf("만들어진 리스트:\n");
  printList();
  
  reverseList();
  printf("역순으로 변환된 리스트: \n");
  printList();
  return 0;
}
