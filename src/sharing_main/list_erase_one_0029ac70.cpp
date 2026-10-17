/* HSTMATCH module=hstp_trans_main.prx start=0x0029ac70 end=0x0029ace0 symbol=FUN_0029ac70 lang=c++ */
/* Clone of src/eboot/list_erase_one_0001f6ec.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Doubly-linked list erase(pos) (sibling of the range erase at 0x14f32c): advance pos, unlink and free the
   node, --size, return pos. The iterator has a user copy constructor, so the by-value pos arrives by invisible
   reference (a2) and is modified in place; that also lets the scheduler hoist its loads above the size store.
   Names provisional. */
struct Node_0029ac70 { Node_0029ac70 *prev; Node_0029ac70 *next; };
struct It_0029ac70 {
    Node_0029ac70 *node;
    It_0029ac70(Node_0029ac70 *n) : node(n) {}
    It_0029ac70(const It_0029ac70 &o) : node(o.node) {}
};
struct List_0029ac70 { int size; Node_0029ac70 *head; };
extern "C" It_0029ac70 FUN_0029ac70(List_0029ac70 *l, It_0029ac70 pos)
{
    Node_0029ac70 *n = pos.node;
    pos.node = n->next;
    n->prev->next = n->next;
    n->next->prev = n->prev;
    delete n;
    --l->size;
    return pos;
}
