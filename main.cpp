#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>

#define len(a) (sizeof(a)/sizeof(a[0]))
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;

    ListNode(int x) :
            val(x), next(NULL) {
    }

    ListNode(int x, ListNode *next) : val(x), next(next) {}
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

ListNode *FindKthToTail(ListNode *pHead, int k) {
    // write code here
    if (pHead == nullptr) {
        return nullptr;
    }
    int len = 0;
    ListNode *bakHead = pHead;
    while (pHead) {
        len++;
        pHead = pHead->next;
    }
    if (k > len) {
        return nullptr;
    }
    int step = len - k;
    while (step--) {
        bakHead = bakHead->next;
    }
    return bakHead;
}

ListNode *deleteNode(ListNode *head, int val) {
    // write code here

    ListNode *bakHead = head, *temp;
    while (head) {
        if (bakHead->val == val) {
            bakHead = bakHead->next;
            break;
        }
        if (head->val == val) {
            temp->next = head->next;
            break;
        }
        temp = head;
        head = head->next;
    }
    return bakHead;
}

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;

    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};

RandomListNode *Clone(RandomListNode *pHead) {
}

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;

    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

int TreeDepth(TreeNode *pRoot) {
    //空节点没有深度
    if (pRoot == NULL)
        return 0;
    //返回子树深度+1
    return max(TreeDepth(pRoot->left), TreeDepth(pRoot->right)) + 1;


    int depth = 1;
    int step = 1;
    if (pRoot == nullptr) {
        return 0;
    }
    TreeNode *root = pRoot, *bak = root;
    while (pRoot) {

        if (pRoot->left) {//左边能走
            bak = pRoot;
            pRoot = pRoot->left;
        } else if (pRoot->right) {//右边能走
            bak = pRoot;
            pRoot = pRoot->right;
        } else {//走到底部了，回退并删除底部节点，保存最大步数
            if (bak->left) {
                bak->left = nullptr;
            } else if (bak->right) {
                bak->right = nullptr;
            } else {//根节点无路可走，删光了
                break;
            }

            depth = step > depth ? step : depth;

            pRoot = root;//从起点重新开始
            step = 1;

            continue;
        }
        step++;

    }

    return depth;

}

vector<int> PrintFromTopToBottom(TreeNode *pRoot) {
    int step = 1;
    vector<int> result;
    if (pRoot == nullptr) {
        return result;
    }
    vector<vector<int>> vDepth;

    TreeNode *root = pRoot, *bak = root;
    while (pRoot) {
        if (vDepth.size() < step) {//创建各层级队列
            vDepth.emplace_back(vector<int>{});
        }

        if (pRoot->left) {//左边能走
            bak = pRoot;
            pRoot = pRoot->left;
        } else if (pRoot->right) {//右边能走
            bak = pRoot;
            pRoot = pRoot->right;
        } else {//走到底部了，回退并删除底部节点，保存最大步数

            //添加层级数据
            vDepth[step - 1].emplace_back(pRoot->val);


            if (bak->left) {
                bak->left = nullptr;
            } else if (bak->right) {
                bak->right = nullptr;
            } else {//根节点无路可走，删光了
                break;
            }
            delete pRoot;

            pRoot = root;//从起点重新开始
            step = 1;

            continue;
        }
        step++;

    }
    delete root;
    delete bak;
    for (int i = 0; i < vDepth.size(); i++) {
        vector<int> curDepth = vDepth[i];
        for (int j = 0; j < curDepth.size(); ++j) {
            result.emplace_back(curDepth[j]);
        }
        curDepth.clear();
        curDepth.shrink_to_fit();
    }
    vDepth.clear();
    vDepth.shrink_to_fit();
    return result;
}
//BFS 之字形打印
//vector<vector<int> > Print(TreeNode* pRoot) {
//    vector<vector<int>> result;
//    queue<TreeNode*> que;
//    que.emplace(pRoot);
//    while(!que.empty()){
//        TreeNode *cur=que.front();
//        que.pop();
//        if (cur->left){
//            que.emplace(cur->left);
//        }
//        if (cur->right){
//            que.emplace(cur->right);
//        }
//    }
//}


//之字形打印
vector<vector<int>> Print(TreeNode *pRoot) {
    int step = 1;
    vector<int> result;

    vector<vector<int>> vDepth;
    if (pRoot == nullptr) {
        return vDepth;
    }
    TreeNode *root = pRoot, *bak = root;
    while (pRoot) {
        if (vDepth.size() < step) {//创建各层级队列
            vDepth.emplace_back(vector<int>{});
        }

        if (pRoot->left) {//左边能走
            bak = pRoot;
            pRoot = pRoot->left;
        } else if (pRoot->right) {//右边能走
            bak = pRoot;
            pRoot = pRoot->right;
        } else {//走到底部了，回退并删除底部节点，保存最大步数

            //添加层级数据
            vDepth[step - 1].emplace_back(pRoot->val);


            if (bak->left) {
                bak->left = nullptr;
            } else if (bak->right) {
                bak->right = nullptr;
            } else {//根节点无路可走，删光了
                break;
            }
            delete pRoot;

            pRoot = root;//从起点重新开始
            step = 1;

            continue;
        }
        step++;

    }
//    delete root;delete bak;

    for (int i = 0; i < vDepth.size(); i++) {
        vector<int> *curDepth = &vDepth[i];
        if ((i + 1) % 2 == 0) {//偶数行
            vector<int> temp;
            while (!curDepth->empty()) {
                temp.push_back(curDepth->back());
                curDepth->pop_back();
            }
            vDepth[i] = temp;
        }
//        curDepth.clear();
//        curDepth.shrink_to_fit();
    }
//    vDepth.clear();
//    vDepth.shrink_to_fit();
    return vDepth;
}

//树的子结构
bool HasSubtree(TreeNode *pRoot1, TreeNode *pRoot2) {
    if (!pRoot1 || !pRoot2) {
        return false;
    }
    queue<TreeNode *> rootQue;
    rootQue.push(pRoot1);
    vector<TreeNode *> lefts;
    while (!rootQue.empty()) {
        TreeNode *cur = rootQue.front();
        rootQue.pop();

        if (cur->val == pRoot2->val) {
            lefts.push_back(cur);
        }

        if (cur->left) {
            rootQue.push(cur->left);
        }
        if (cur->right) {
            rootQue.push(cur->right);
        }
    }
    string right;
    queue<TreeNode *> rightQue;
    rightQue.push(pRoot2);
    while (!rightQue.empty()) {
        TreeNode *temp = rightQue.front();
        rightQue.pop();
        right += (std::to_string(temp->val) + " ");
        if (temp->left) {
            rightQue.push(temp->left);
        }
        if (temp->right) {
            rightQue.push(temp->right);
        }
    }
    bool has = false;
    while (!lefts.empty()) {
        TreeNode *cur = lefts.back();
        lefts.pop_back();
        string left;
        queue<TreeNode *> leftQue;
        leftQue.push(cur);
        while (!leftQue.empty()) {
            TreeNode *temp = leftQue.front();
            leftQue.pop();
            left += (std::to_string(temp->val) + " ");
            if (temp->left) {
                leftQue.push(temp->left);
            }
            if (temp->right) {
                leftQue.push(temp->right);
            }
        }
        has = left.find(right) != string::npos;
        if (has) {
            return true;
        }
    }

    return false;
}

bool hasPath(vector<vector<char> > &matrix, string word) {
    // write code here
    int rowSize = matrix.size();
    int colSize = matrix[0].size();

    for (int i = 0; i < rowSize; ++i) {
        vector<char> row = matrix[i];
        for (int j = 0; j < colSize; ++j) {
            char curLetter = row[j];

            if (curLetter == word[0]) {

            }

        }
    }
}

//合并两个有序列表，废弃
ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    ListNode *head = new ListNode(-1), *bak = head;
    while (list1 != nullptr || list2 != nullptr) {
        //左链表小于右链表
        if (list1 != nullptr && list1->val <= list2->val) {
            head->next = new ListNode(list1->val);
            list1 = list1->next;
        }
            //右链表小于左链表
        else if (list2 != nullptr) {
            head->next = new ListNode(list2->val);
            list2 = list2->next;
        }
        head = head->next;
    }
    return bak->next;
}


//合并有序链表
ListNode *merge(ListNode *head1, ListNode *head2) {
    ListNode *dummyHead = new ListNode(0);
    ListNode *temp = dummyHead, *temp1 = head1, *temp2 = head2;
    while (temp1 != nullptr && temp2 != nullptr) {
        if (temp1->val <= temp2->val) {
            temp->next = temp1;
            temp1 = temp1->next;
        } else {
            temp->next = temp2;
            temp2 = temp2->next;
        }
        temp = temp->next;
    }
    if (temp1 != nullptr) {
        temp->next = temp1;
    } else if (temp2 != nullptr) {
        temp->next = temp2;
    }
    return dummyHead->next;
}

//leetcode 148 归并排序 ->自底向上合并
/*
 * 思路为
 * 1.先获取链表总长度
 * 2.获取分治后每段块数：初始为1（自底向上），逐步*2，逐步合并有序链表
 */
//ListNode *sortList(ListNode *head) {
//    int length = 0;
//
//    ListNode *bak = head;
//    //获取链表总长
//    while (head) {
//        head = head->next;
//        length++;
//    }
//    //有序段长度
//    int segLength = 1;
//
//    //多少个有序段
//    int segSum = length;
//
//
//    while (segLength < length) {
//
//        //定位两个链表头，合并两个列表
//        for (int i = 0; i < segSum; ++i) {
//            ListNode *h1, *h2;
//            //定位第一个表头
//            if (i == 0) {
//                h1 = bak;
//            } else {
//                //开始定位第二个表头，以段长为准
//                h2 = h1;
//                if (i != segSum - 1) {
//                    for (int j = 0; j < segLength; ++j) {
//                        h2 = h2->next;
//                    }
//                } else {
//                    //最后一个表头
//                }
//
//            }
//
//            merge(i,)
//        }
//    }
//
//    return nullptr;
//}


ListNode *sortList(ListNode *head) {
    if (head == nullptr) {
        return head;
    }

    int length = 0;
    ListNode *node = head;
    while (node != nullptr) {
        length++;
        node = node->next;
    }
    ListNode *dummyHead = new ListNode(0, head);

    //分链长翻倍 1 2 4 8 16
    for (int subLength = 1; subLength < length; subLength <<= 1) {
        //链表指针，从头到尾 分治 合并
        ListNode *prev = dummyHead, *curr = dummyHead->next;
        while (curr != nullptr) {
            ListNode *head1 = curr;
            /*
             * 为什么要以curr->next!=nullptr作为判断标准呢
             */

            //链表指针往后移动段长距离，curr->next != nullptr用来规避最后一段小于段长的情况
            for (int i = 1; i < subLength && curr->next != nullptr; i++) {
                curr = curr->next;
            }

            //第二个链表头
            ListNode *head2 = curr->next;
            //打断链表1，便于合并
            curr->next = nullptr;
            curr = head2;


            //链表指针往后移动段长距离，curr!=nullptr用来规避curr->next为空的情况
            for (int i = 1; i < subLength && curr != nullptr && curr->next != nullptr; i++) {
                curr = curr->next;
            }

            //打断链表2
            ListNode *next = nullptr;
            if (curr != nullptr) {
                next = curr->next;
                curr->next = nullptr;
            }
            curr = next;


            ListNode *merged = merge(head1, head2);
            prev->next = merged;
            while (prev->next != nullptr) {
                prev = prev->next;
            }
        }
    }
    return dummyHead->next;
}

//148归并排序 我的
ListNode *myMergeSort(ListNode *head) {
    if (head == nullptr) {
        return head;
    }



    ListNode *lengthNode = head;
    int length = 0;
    while (lengthNode) {
        lengthNode = lengthNode->next;
        length++;
    }


    ListNode *resultPre = new ListNode(0, head);

    for (int segLength = 1; segLength < length; segLength <<= 1) {

        ListNode *pre = resultPre, *curr = resultPre->next;

        //从头至尾 分治 合并
        while (curr) {
            ListNode *head1 = curr;

            for (int i = 1; i < segLength && curr->next; ++i) {
                curr = curr->next;
            }

            //打断链1 并声明head2
            ListNode *head2 = curr->next;
            curr->next = nullptr;
            curr = head2;

            for (int i = 1; i < segLength && curr && curr->next; ++i) {
                curr = curr->next;
            }



            if (head2) {
                //打断链2
                ListNode *cutTempNode2 = curr->next;
                curr->next = nullptr;
                curr = cutTempNode2;
            }



            pre->next = merge(head1, head2);
            while (pre->next) {
                pre = pre->next;
            }


        }


    }
    return resultPre->next;

}
 

int main(void) {


//    return 0;
//    TreeNode *root = new TreeNode(1);
//    TreeNode *r2 = new TreeNode(2);
//    TreeNode *r3 = new TreeNode(3);
//    TreeNode *r4 = new TreeNode(4);
//    TreeNode *r5 = new TreeNode(5);
//    TreeNode *r6 = new TreeNode(6);
//    TreeNode *r7 = new TreeNode(7);
//    TreeNode *ree = new TreeNode(9);
//    root->left = r2;
//    root->right = r3;
//    r2->left = r4;
//    r2->right = r5;
//    r5->left = r7;
//    r3->right = r6;
//    printf("%d", HasSubtree(root, ree));

//    printf("%d", max(nullptr, nullptr));
    int a1[4] = {4,2,1,3};
//    int a2[3] = {1,3,4};
    ListNode *p1 = createListNode(a1, 4);
    ListNode *result = myMergeSort(p1);
    printListNode(result);
//    ListNode *p2 = createListNode(a2, 3);
//    ListNode *result = mergeTwoLists(p1, p2);
//    printListNode(result);
//    auto temp = p1->next->next->next->next->next->next->next;
//    auto back = p1;
//    while (p1->next) {
//        p1 = p1->next;
//    }
//    p1->next = temp;

//    deleteNode(p1, 5);
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
