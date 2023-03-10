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
    return resultStr.substr(0, resultStr.length() - 1);
}

bool IsPopOrder(vector<int> stack, vector<int> sequence) {
    vector<int> temp;
    int stackIndex = 0, sequenceIndex = 0;
    for (; stackIndex < stack.size(); stackIndex++) {
        temp.push_back(stack[stackIndex]);
        while (!temp.empty() && temp.back() == sequence[sequenceIndex]) {
            temp.pop_back();
            sequenceIndex++;
        }
    }
    return temp.empty();
}

vector<int> maxInWindows(const vector<int> &num, unsigned int size) {
    vector<int> result;
    if (size > num.size() || size == 0)
        return result;
    int maxIndex = -1;
    for (int i = 0; i < num.size() - size + 1; ++i) {
        if (maxIndex >= i
            && result.back() >= num[i + size - 1]) {
            result.push_back(result.back());
            continue;
        }
        int max = -10001;
        for (int j = i; j < i + size; ++j) {
            if (num[j] > max) {
                max = num[j] > max ? num[j] : max;
                maxIndex = j;
            }
        }
        result.push_back(max);
    }

    return result;
}


/*
 * 两条链表拼接在一起，路径相同，若有共同节点，会会合。
 */
ListNode *FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2) {
    ListNode *p1 = pHead1, *p2 = pHead2;//保存两个链表头节点
    while (pHead1 && pHead2) {
        if (pHead1->val == pHead2->val) {
            return pHead1;
        }
        pHead1 = pHead1->next;
        pHead2 = pHead2->next;
        if (pHead1 == nullptr) {//自己链表走完走另一条链，两个链表路程相等。
            pHead1 = p2;
            p2 = nullptr;
        }
        if (pHead2 == nullptr) {
            pHead2 = p1;
            p1 = nullptr;
        }

    }
    return nullptr;
}

ListNode *ReverseList(ListNode *pHead) {
    if (pHead == nullptr) {
        return nullptr;
    }
    ListNode *preNode = nullptr, *rearNode = nullptr;
    while (pHead) {
        rearNode = pHead->next;
        pHead->next = preNode;
        preNode = pHead;
        pHead = rearNode;
    }
    delete rearNode;
    delete pHead;
    return preNode;
}

ListNode *EntryNodeOfLoop(ListNode *pHead) {
    int arr[13], index = 0;
    while (index < 13) {
        arr[index++] = pHead->val;
        pHead = pHead->next;
        if (pHead == nullptr) {
            return nullptr;
        }
        for (int i = 0; i < index; ++i) {
            if (pHead->val == arr[i]) {
                return pHead;
            }
        }
    }
    return nullptr;
}

int main(void) {
    int a1[13] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
//    int a2[1] = {5};
    ListNode *p1 = createListNode(a1, 13);;
    auto temp = p1->next->next->next->next->next->next->next;
    auto back = p1;
    while (p1->next) {
        p1 = p1->next;
    }
    p1->next = temp;

    EntryNodeOfLoop(back);
//    printListNode(back);
//    printListNode(p);

//    printListNode(ReverseList(p1));
//    ListNode *p2 = createListNode(a2, 1);
//    printf("%d", FindFirstCommonNode(p1, p2) == nullptr);
//    printf("%d", 3 > -100);
//    maxInWindows(vector<int>{2, 3, 4, 2, 6, 2, 5, 1}, 3);
//    string originStr = "nowcoder. a am I dsfsd";
//    string str = ReverseSentence(originStr);
//    printf("%s", str.c_str());
//    printf("%s", originStr.substr(10,1).c_str());
//    vector<int> v1{1, 2, 3, 4, 5};
//    vector<int> v2{2, 1, 3, 5, 4};
//    printf("%d", IsPopOrder(v1, v2));



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
