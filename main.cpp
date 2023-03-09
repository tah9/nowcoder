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


ListNode *Merge(ListNode *pHead1, ListNode *pHead2) {

    ListNode *head = new ListNode(-1001), *last = head;
    while (pHead1 && pHead2) {
        if (pHead1->val <= pHead2->val) {//1<2,1右移
            last->next = pHead1;
            pHead1 = pHead1->next;
        } else {
            last->next = pHead2;
            pHead2 = pHead2->next;
        }
        last = last->next;
    }
    while (pHead1) {
        last->next = pHead1;
        pHead1 = pHead1->next;
        last = last->next;

    }
    while (pHead2) {
        last->next = pHead2;
        pHead2 = pHead2->next;
        last = last->next;

    }
    return head->next;
}

class Solution {
public:
    int arr[300];
    int topIndex = 0;
    int minIndex = 0;

    void push(int value) {
        arr[topIndex++] = value;
    }

    void pop() {
        topIndex--;
    }

    int top() {
        return arr[topIndex - 1];
    }

    int min() {
        int minNum = arr[0];
        for (int i = 0; i < topIndex; ++i) {
            if (arr[i] <= minNum) {
                minNum = arr[i];
                minIndex = i;
            }
        }
        return minNum;
    }
};

string ReverseSentence(string str) {
    vector<string> vStr;
    int startIndex = 0;
    int len = 0;
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] == ' ') {
//            if(len==0){
//                len=1;
//            }
            vStr.push_back(str.substr(startIndex, len));
            startIndex = i + 1;
            len = 0;
        } else {
            len++;
        }
    }
    vStr.push_back(str.substr(startIndex, str.length() + 1 - startIndex));

    string resultStr;
    while (!vStr.empty()) {
        resultStr += (vStr.back() + " ");
        vStr.pop_back();
    }
    return resultStr.substr(0, resultStr.length()-1);
}

int main(void) {
    string originStr = "nowcoder. a am I dsfsd";
    string str = ReverseSentence(originStr);
    printf("%s", str.c_str());
//    printf("%s", originStr.substr(10,1).c_str());
//    vector<int> v1{1,2,3,4,5};
//    vector<int> v2{4,5,3,2,1};
//    for(auto item:v1){
//        if (item==2){
//            v1.pop_back();
//        }
//    }
//    for(auto item:v1){
//        printf("%d\n", item);
//    }



//    int arr1[] = {1, 3, 5};
//    int arr2[] = {2, 4, 6};
////    int arr[] = {1, 1};
//    ListNode *head = createListNode(arr1, len(arr1));
//    ListNode *head2 = createListNode(arr2, len(arr2));
//
//    ListNode *m = Merge(head, head2);
//
//
//    printListNode(m);
//    ListNode *h = deleteDuplication(head);
//    printListNode(h);

    return 0;
}
