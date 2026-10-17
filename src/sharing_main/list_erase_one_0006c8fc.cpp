/* HSTMATCH module=hstp_trans_main.prx start=0x0006c8fc end=0x0006c96c symbol=FUN_0006c8fc lang=c++ */
/* Clone of src/eboot/list_erase_one_0001f6ec.cpp (hstclone.py tag c37): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Doubly-linked list erase(pos) (sibling of the range erase at 0x14f32c): advance pos, unlink and free the
   node, --size, return pos. The iterator has a user copy constructor, so the by-value pos arrives by invisible
   reference (a2) and is modified in place; that also lets the scheduler hoist its loads above the size store.
   Names provisional. */
struct Node_0006c8fc { Node_0006c8fc *prev; Node_0006c8fc *next; };
struct It_0006c8fc {
    Node_0006c8fc *node;
    It_0006c8fc(Node_0006c8fc *n) : node(n) {}
    It_0006c8fc(const It_0006c8fc &o) : node(o.node) {}
};
struct List_0006c8fc { int size; Node_0006c8fc *head; };
extern "C" It_0006c8fc FUN_0006c8fc(List_0006c8fc *l, It_0006c8fc pos)
{
    Node_0006c8fc *n = pos.node;
    pos.node = n->next;
    n->prev->next = n->next;
    n->next->prev = n->prev;
    delete n;
    --l->size;
    return pos;
}
