/* HSTMATCH module=EBOOT.BIN start=0x0001f6ec end=0x0001f75c symbol=FUN_0001f6ec lang=c++ */
/* Clone of src/eboot/list_erase_one_0014f3cc.cpp (hstclone.py tag c36): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Doubly-linked list erase(pos) (sibling of the range erase at 0x14f32c): advance pos, unlink and free the
   node, --size, return pos. The iterator has a user copy constructor, so the by-value pos arrives by invisible
   reference (a2) and is modified in place; that also lets the scheduler hoist its loads above the size store.
   Names provisional. */
struct Node_0001f6ec { Node_0001f6ec *prev; Node_0001f6ec *next; };
struct It_0001f6ec {
    Node_0001f6ec *node;
    It_0001f6ec(Node_0001f6ec *n) : node(n) {}
    It_0001f6ec(const It_0001f6ec &o) : node(o.node) {}
};
struct List_0001f6ec { int size; Node_0001f6ec *head; };
extern "C" It_0001f6ec FUN_0001f6ec(List_0001f6ec *l, It_0001f6ec pos)
{
    Node_0001f6ec *n = pos.node;
    pos.node = n->next;
    n->prev->next = n->next;
    n->next->prev = n->prev;
    delete n;
    --l->size;
    return pos;
}
