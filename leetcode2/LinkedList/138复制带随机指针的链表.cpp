#include <map>
#include <vector>

using namespace std;

/*
给你一个长度为 n 的链表，每个节点包含一个额外增加的随机指针 random ，该指针可以指向链表中的任何节点或空节点。
构造这个链表的 深拷贝。 深拷贝应该正好由 n 个 全新 节点组成，其中每个新节点的值都设为其对应的原节点的值。
新节点的 next 指针和 random 指针也都应指向复制链表中的新节点，并使原链表和复制链表中的这些指针能够表示相同的链表状态。
复制链表中的指针都不应指向原链表中的节点 。
例如，如果原链表中有 X 和 Y 两个节点，其中 X.random --> Y 。那么在复制链表中对应的两个节点 x 和 y ，同样有 x.random --> y 。
返回复制链表的头节点。
用一个由 n 个节点组成的链表来表示输入/输出中的链表。每个节点用一个 [val, random_index] 表示：
val：一个表示 Node.val 的整数。
random_index：随机指针指向的节点索引（范围从 0 到 n-1）；如果不指向任何节点，则为  null 。
你的代码 只 接受原链表的头节点 head 作为传入参数。
*/

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


/*
Node* copyRandomList(Node* head) {
    // 复制带随机指针的链表
    // 方法1：O(n)时间，额外O(n)空间
    if (head == NULL) {
        return head;
    }

    // 记录原链表中节点地址与索引的字典
    map<Node*, int> RLmap;
    // 记录复制链表每个节点地址的容器
    vector<Node*> copy_map;

    // 遍历原链表并同步创建复制链表的每个节点
    // 第一个节点
    int index(0);
    auto op(head);
    RLmap[op] = index;
    Node* copy_head = new Node(op->val);
    auto copy_p(copy_head);
    copy_map.push_back(copy_p);
    
    op = op->next;
    ++ index;
    // 其他节点
    while (op != NULL) {
        // 创建地址-索引哈希表
        RLmap[op] = index;
        ++ index;

        // 同步创建复制链表中的每个节点并保存每个节点的地址
        copy_p->next = new Node(op->val);

        op = op->next;
        copy_p = copy_p->next;
        copy_map.push_back(copy_p);
    }

    // 遍历原链表，根据random的值从RLmap中确定指向的节点索引
    copy_p = copy_head;
    while (head != NULL) {
        if (head->random != NULL) {
            copy_p->random = copy_map[RLmap[head->random]];
        }

        head = head->next;
        copy_p = copy_p->next;
    }

    return copy_head;
}
*/


Node* copyRandomList(Node* head) {
    // 复制带随机指针的链表
    // 方法2：O(n^2)时间，额外O(1)空间
    if (head == NULL) {
        return head;
    }

    // 第一次遍历，创建所有节点
    auto p(head);
    Node* copy_head = new Node(p->val);
    auto copy_p(copy_head);

    p = p->next;
    while (p != NULL) {
        copy_p->next = new Node(p->val);
        p = p->next;
        copy_p = copy_p->next;
    }

    // 第二次遍历，寻找random指向的节点地址
    p = head;
    copy_p = copy_head;
    auto pnode(head), copy_node(copy_head);
    while (p != NULL) {
        if (p->random == NULL) {
            copy_p->random = NULL;
        }
        else {
            pnode = head;
            copy_node = copy_head;
            while (pnode != NULL) {
                // 找到p节点random所指向的节点地址
                if (p->random == pnode) {
                    copy_p->random = copy_node;
                    break;
                }
                pnode = pnode->next;
                copy_node = copy_node->next;
            }
        }

        p = p->next;
        copy_p = copy_p->next;
    }

    return copy_head;
}
