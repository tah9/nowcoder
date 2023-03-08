#include <iostream>
#include <vector>

#define len(a) (sizeof(a)/sizeof(a[0]))
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;

    ListNode(int x) :
            val(x), next(NULL) {
    }
};

vector<int> printListFromTailToHead(ListNode *head) {
    vector<int> result;
    while (head != nullptr) {
        result.insert(result.cbegin(), head->val);
        head = head->next;
    }
    return result;
}

ListNode *deleteDuplication(ListNode *pHead) {
    ListNode *cur = pHead, *rear = nullptr, *head = nullptr, *last = nullptr;

    while (cur) {
        rear = cur->next;

        if (rear && cur->val == rear->val) {//当前和后方相等，遍历到不等，不对返回链表操作
            while ((rear = rear->next) && cur->val == rear->val) {}
        } else {
            if (!head) {//返回链表未初始化，将节点设为头节点
                head = cur;
                head->next = nullptr;
                last = head;
            } else {//链尾链接节点
                last->next = cur;
                last = cur;
                last->next = nullptr;
            }
        }
        cur = rear;
    }
    return head;

}

void printListNode(ListNode *head) {
    printf("\n");
    while (head) {
        printf("%d ", head->val);
        head = head->next;
    }
}

ListNode *createListNode(int arr[], int len) {
    ListNode *head = new ListNode(arr[0]), *h = head;

    for (int i = 1; i < len; ++i) {
        head->next = new ListNode(arr[i]);
        head = head->next;
    }
    return h;
}

int main(void) {
    int arr[] = {1, 2, 3, 3, 4, 4, 5};
//    int arr[] = {1, 1};
    ListNode *head = createListNode(arr, len(arr));
    printListNode(head);
    ListNode *h = deleteDuplication(head);
    printListNode(h);

    return 0;
}
