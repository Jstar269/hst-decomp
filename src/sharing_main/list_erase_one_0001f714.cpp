/* HSTMATCH module=hstp_trans_main.prx start=0x0001f714 end=0x0001f784 symbol=FUN_0001f714 lang=c++ */
/* Clone of src/eboot/list_erase_one_0001f6ec.cpp (hstclone.py tag c37): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Doubly-linked list erase(pos) (sibling of the range erase at 0x14f32c): advance pos, unlink and free the
   node, --size, return pos. The iterator has a user copy constructor, so the by-value pos arrives by invisible
   reference (a2) and is modified in place; that also lets the scheduler hoist its loads above the size store.
   Names provisional. */
struct Node_0001f714 { Node_0001f714 *prev; Node_0001f714 *next; };
struct It_0001f714 {
    Node_0001f714 *node;
    It_0001f714(Node_0001f714 *n) : node(n) {}
    It_0001f714(const It_0001f714 &o) : node(o.node) {}
};
struct List_0001f714 { int size; Node_0001f714 *head; };
extern "C" It_0001f714 FUN_0001f714(List_0001f714 *l, It_0001f714 pos)
{
    Node_0001f714 *n = pos.node;
    pos.node = n->next;
    n->prev->next = n->next;
    n->next->prev = n->prev;
    delete n;
    --l->size;
    return pos;
}
