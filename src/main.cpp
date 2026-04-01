#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int v = 0) : val(v), next(nullptr) {}
};

struct LinkedList {
    Node* head; // dummy head for simpler ops
    int len;

    LinkedList() : head(new Node()), len(0) {}

    void initialize() {
        int n;
        if (scanf("%d", &n) != 1) return;
        int *a = new int[n];
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
        Node* cur = head;
        for (int i = 0; i < n; i++) {
            cur->next = new Node(a[i]);
            cur = cur->next;
        }
        len = n;
        delete[] a;
    }

    // insert x after i-th element; if i==0, insert at head (before first)
    void insert(int i, int x) {
        // i in [0..len]
        Node* p = head;
        for (int k = 0; k < i && p->next; ++k) p = p->next; // move to i-th node (or last)
        // Now p points to i-th node (dummy when i==0?). We defined: after i-th element.
        // According to statement, op1: insert after i-th. So when i==0? not specified; assume valid i>=0 and not exceeding len.
        Node* q = new Node(x);
        q->next = p->next;
        p->next = q;
        ++len;
    }

    void erase(int i) {
        if (i <= 0 || i > len) return; // guard
        Node* p = head;
        for (int k = 1; k < i; ++k) p = p->next; // p points to (i-1)-th (dummy for i==1)
        Node* del = p->next;
        if (del) {
            p->next = del->next;
            delete del;
            --len;
        }
    }

    // swap odd/even positions in-place O(1) extra space
    void swap_adjacent_pairs() {
        if (len <= 1) return;
        Node* prev = head;
        Node* a = head->next; // first real
        while (a && a->next) {
            Node* b = a->next;
            Node* nxt = b->next;
            // swap a and b
            prev->next = b;
            b->next = a;
            a->next = nxt;
            // advance
            prev = a;
            a = a->next;
        }
    }

    // move first i nodes backward by x positions (guaranteed not exceed)
    // Example shows: take segment [1..i], shift it right by x within first i+x positions
    void moveback(int i, int x) {
        if (i <= 0 || x <= 0 || i > len || i + x > len) return;
        // Identify segment A = [1..i]
        Node* A_start = head->next;
        Node* tailA = head;
        for (int k = 0; k < i; ++k) tailA = tailA->next;
        Node* postA = tailA->next; // exists due to i+x<=len and x>0
        // Node at position i+x
        Node* tailB = head;
        for (int k = 0; k < i + x; ++k) tailB = tailB->next;
        Node* postB = tailB ? tailB->next : nullptr;
        // Rewire in safe order to avoid cycles:
        // 1) Move head to postA (detach A from front but A still links to postA)
        head->next = postA;
        // 2) Break A's link to postA and connect A's tail to postB
        tailA->next = postB;
        // 3) Connect tailB to A_start to insert A after tailB
        tailB->next = A_start;
    }

    int query(int i) {
        if (i <= 0 || i > len) return 0;
        Node* p = head->next;
        for (int k = 1; k < i && p; ++k) p = p->next;
        return p ? p->val : 0;
    }

    void printAll() {
        Node* p = head->next;
        bool first = true;
        while (p) {
            if (!first) printf(" ");
            first = false;
            printf("%d", p->val);
            p = p->next;
        }
        printf("\n");
    }

    void ClearMemory() {
        Node* p = head;
        while (p) {
            Node* nxt = p->next;
            delete p;
            p = nxt;
        }
        head = nullptr;
        len = 0;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    LinkedList List;
    int m, op, i, x;
    List.initialize();
    if (scanf("%d", &m) != 1) {
        List.ClearMemory();
        return 0;
    }
    while (m--) {
        scanf("%d", &op);
        if (op == 1) {
            scanf("%d%d", &i, &x);
            List.insert(i, x);
        } else if (op == 2) {
            scanf("%d", &i);
            List.erase(i);
        } else if (op == 3) {
            List.swap_adjacent_pairs();
        } else if (op == 4) {
            scanf("%d%d", &i, &x);
            List.moveback(i, x);
        } else if (op == 5) {
            scanf("%d", &i);
            printf("%d\n", List.query(i));
        } else if (op == 6) {
            List.printAll();
        }
    }
    List.ClearMemory();
    return 0;
}
