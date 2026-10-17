/* HSTMATCH module=EBOOT.BIN start=0x001b9598 end=0x001b9608 symbol=FUN_001b9598 lang=c++ */
/* Clone of src/eboot/list_erase_one_0014f3cc.cpp (hstclone.py tag c36): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Doubly-linked list erase(pos) (sibling of the range erase at 0x14f32c): advance pos, unlink and free the
   node, --size, return pos. The iterator has a user copy constructor, so the by-value pos arrives by invisible
   reference (a2) and is modified in place; that also lets the scheduler hoist its loads above the size store.
   Names provisional. */
struct Node_001b9598 { Node_001b9598 *prev; Node_001b9598 *next; };
struct It_001b9598 {
    Node_001b9598 *node;
    It_001b9598(Node_001b9598 *n) : node(n) {}
    It_001b9598(const It_001b9598 &o) : node(o.node) {}
};
struct List_001b9598 { int size; Node_001b9598 *head; };
extern "C" It_001b9598 FUN_001b9598(List_001b9598 *l, It_001b9598 pos)
{
    Node_001b9598 *n = pos.node;
    pos.node = n->next;
    n->prev->next = n->next;
    n->next->prev = n->prev;
    delete n;
    --l->size;
    return pos;
}
