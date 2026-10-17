/* HSTMATCH module=EBOOT.BIN start=0x0006b314 end=0x0006b384 symbol=FUN_0006b314 lang=c++ */
/* Clone of src/eboot/list_erase_one_0014f3cc.cpp (hstclone.py tag c36): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Doubly-linked list erase(pos) (sibling of the range erase at 0x14f32c): advance pos, unlink and free the
   node, --size, return pos. The iterator has a user copy constructor, so the by-value pos arrives by invisible
   reference (a2) and is modified in place; that also lets the scheduler hoist its loads above the size store.
   Names provisional. */
struct Node_0006b314 { Node_0006b314 *prev; Node_0006b314 *next; };
struct It_0006b314 {
    Node_0006b314 *node;
    It_0006b314(Node_0006b314 *n) : node(n) {}
    It_0006b314(const It_0006b314 &o) : node(o.node) {}
};
struct List_0006b314 { int size; Node_0006b314 *head; };
extern "C" It_0006b314 FUN_0006b314(List_0006b314 *l, It_0006b314 pos)
{
    Node_0006b314 *n = pos.node;
    pos.node = n->next;
    n->prev->next = n->next;
    n->next->prev = n->prev;
    delete n;
    --l->size;
    return pos;
}
