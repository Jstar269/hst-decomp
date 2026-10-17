/* HSTMATCH module=EBOOT.BIN start=0x0014f3cc end=0x0014f43c symbol=FUN_0014f3cc lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Doubly-linked list erase(pos) (sibling of the range erase at 0x14f32c): advance pos, unlink and free the
   node, --size, return pos. The iterator has a user copy constructor, so the by-value pos arrives by invisible
   reference (a2) and is modified in place; that also lets the scheduler hoist its loads above the size store.
   Names provisional. */
struct Node_0014f3cc { Node_0014f3cc *prev; Node_0014f3cc *next; };
struct It_0014f3cc {
    Node_0014f3cc *node;
    It_0014f3cc(Node_0014f3cc *n) : node(n) {}
    It_0014f3cc(const It_0014f3cc &o) : node(o.node) {}
};
struct List_0014f3cc { int size; Node_0014f3cc *head; };
extern "C" It_0014f3cc FUN_0014f3cc(List_0014f3cc *l, It_0014f3cc pos)
{
    Node_0014f3cc *n = pos.node;
    pos.node = n->next;
    n->prev->next = n->next;
    n->next->prev = n->prev;
    delete n;
    --l->size;
    return pos;
}
