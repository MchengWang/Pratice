/* 单链表结构 */
struct LinkedList
{
    int val; // 节点值
    LinkedList* next; // 子节点指针

    // 构造函数
    LinkedList() : val(0), next(nullptr) {}
    LinkedList(int x) : val(x), next(nullptr) {}
    LinkedList(int x, LinkedList* next) : val(x), next(next) {}
};

class MyLinkedList {
public:

    // 初始化链表 设置默认的链表长度和头节点
    MyLinkedList() 
        :length(0), root(new LinkedList())
    {

    }

    // 获取指定位置的元素
    int get(int index) 
    {
        // 若 index 不满足条件，返回 -1
        if (index < 0 || index > (length - 1)) return -1;
        // 利用临时节点去存储根节点的下一个节点
        LinkedList* temp = root->next;
        // 循环 当到达 index 位置，返回该位置上的值即可
        while (index--) temp = temp->next;
        return temp->val;
    }

    // 在链表的表头添加头节点
    void addAtHead(int val) 
    {
        // 创建一个新节点
        LinkedList* newLinked = new LinkedList(val);
        // 将新节点的子节点指针置为根节点的子节点
        newLinked->next = root->next;
        // 把新节点放在根节点的下面
        root->next = newLinked;
        // 添加一个节点后，单链表的长度加 1
        length++;
    }

    // 在链表的结尾添加节点
    void addAtTail(int val)
    {
        // 创建要插入的新节点
        LinkedList* newLinked = new LinkedList(val);
        // 利用临时节点遍历，找到链表的最后一个节点
        LinkedList* temp = root->next;
        while (temp->next) temp = temp->next;
        // 将最后一个节点的子节点指针设置为新插入节点
        temp->next = newLinked;
        length++;
    }

    // 在索引 index 的位置上插入
    void addAtIndex(int index, int val)
    {
        // 插入index的时候，如果下标是=0,就相当于从头插入，所以要包含<=
        if (index <= 0) addAtHead(val); 
        else if (index == length) addAtTail(val);
        else if (index > length) return;
        else {
            LinkedList* newnode = new LinkedList(val);
            // 辅助指针从头指针开始
            LinkedList* cur = root;
            while (index--) cur = cur->next;//遍历到第index-1的节点，循环次数是index次 但是辅助指针是从头指针开始而不是第一个节点
            newnode->next = cur->next;//连接index
            cur->next = newnode;//连接前一个
            length++;//长度+1
        }
    }

    void deleteAtIndex(int index)
    {
        if (index < 0 || index >= length) return;
        //从头指针开始
        LinkedList* cur = root;
        //遍历到index-1的位置,循环次数是index次
        while (index--) 
            cur = cur->next;
        //相当于直接跨过了index节点
        cur->next = cur->next->next;
        length--;
    }
private:
    int length; // 用来存储链表的长度
    LinkedList* root; // 用于作为根节点
};
