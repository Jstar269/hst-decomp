/* HSTMATCH module=hstp_trans_main.prx start=0x00068e20 end=0x00068e90 symbol=FUN_00068e20 lang=c++ */
/* Clone of src/eboot/list_erase_one_0001f6ec.cpp (hstclone.py tag c37): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Doubly-linked list erase(pos) (sibling of the range erase at 0x14f32c): advance pos, unlink and free the
   node, --size, return pos. The iterator has a user copy constructor, so the by-value pos arrives by invisible
   reference (a2) and is modified in place; that also lets the scheduler hoist its loads above the size store.
   Names provisional. */
struct Node_00068e20 { Node_00068e20 *prev; Node_00068e20 *next; };
struct It_00068e20 {
    Node_00068e20 *node;
    It_00068e20(Node_00068e20 *n) : node(n) {}
    It_00068e20(const It_00068e20 &o) : node(o.node) {}
};
struct List_00068e20 { int size; Node_00068e20 *head; };
extern "C" It_00068e20 FUN_00068e20(List_00068e20 *l, It_00068e20 pos)
{
    Node_00068e20 *n = pos.node;
    pos.node = n->next;
    n->prev->next = n->next;
    n->next->prev = n->prev;
    delete n;
    --l->size;
    return pos;
}
