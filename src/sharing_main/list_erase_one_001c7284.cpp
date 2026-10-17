/* HSTMATCH module=hstp_trans_main.prx start=0x001c7284 end=0x001c72f4 symbol=FUN_001c7284 lang=c++ */
/* Clone of src/eboot/list_erase_one_0001f6ec.cpp (hstclone.py tag c37): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Doubly-linked list erase(pos) (sibling of the range erase at 0x14f32c): advance pos, unlink and free the
   node, --size, return pos. The iterator has a user copy constructor, so the by-value pos arrives by invisible
   reference (a2) and is modified in place; that also lets the scheduler hoist its loads above the size store.
   Names provisional. */
struct Node_001c7284 { Node_001c7284 *prev; Node_001c7284 *next; };
struct It_001c7284 {
    Node_001c7284 *node;
    It_001c7284(Node_001c7284 *n) : node(n) {}
    It_001c7284(const It_001c7284 &o) : node(o.node) {}
};
struct List_001c7284 { int size; Node_001c7284 *head; };
extern "C" It_001c7284 FUN_001c7284(List_001c7284 *l, It_001c7284 pos)
{
    Node_001c7284 *n = pos.node;
    pos.node = n->next;
    n->prev->next = n->next;
    n->next->prev = n->prev;
    delete n;
    --l->size;
    return pos;
}
