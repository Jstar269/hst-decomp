/* HSTMATCH module=hstp_trans_main.prx start=0x0015b3cc end=0x0015b43c symbol=FUN_0015b3cc lang=c++ */
/* Clone of src/eboot/list_erase_one_0001f6ec.cpp (hstclone.py tag c37): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Doubly-linked list erase(pos) (sibling of the range erase at 0x14f32c): advance pos, unlink and free the
   node, --size, return pos. The iterator has a user copy constructor, so the by-value pos arrives by invisible
   reference (a2) and is modified in place; that also lets the scheduler hoist its loads above the size store.
   Names provisional. */
struct Node_0015b3cc { Node_0015b3cc *prev; Node_0015b3cc *next; };
struct It_0015b3cc {
    Node_0015b3cc *node;
    It_0015b3cc(Node_0015b3cc *n) : node(n) {}
    It_0015b3cc(const It_0015b3cc &o) : node(o.node) {}
};
struct List_0015b3cc { int size; Node_0015b3cc *head; };
extern "C" It_0015b3cc FUN_0015b3cc(List_0015b3cc *l, It_0015b3cc pos)
{
    Node_0015b3cc *n = pos.node;
    pos.node = n->next;
    n->prev->next = n->next;
    n->next->prev = n->prev;
    delete n;
    --l->size;
    return pos;
}
