/* HSTMATCH module=EBOOT.BIN start=0x000679cc end=0x00067a3c symbol=FUN_000679cc lang=c++ */
/* Clone of src/eboot/list_erase_one_0014f3cc.cpp (hstclone.py tag c36): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Doubly-linked list erase(pos) (sibling of the range erase at 0x14f32c): advance pos, unlink and free the
   node, --size, return pos. The iterator has a user copy constructor, so the by-value pos arrives by invisible
   reference (a2) and is modified in place; that also lets the scheduler hoist its loads above the size store.
   Names provisional. */
struct Node_000679cc { Node_000679cc *prev; Node_000679cc *next; };
struct It_000679cc {
    Node_000679cc *node;
    It_000679cc(Node_000679cc *n) : node(n) {}
    It_000679cc(const It_000679cc &o) : node(o.node) {}
};
struct List_000679cc { int size; Node_000679cc *head; };
extern "C" It_000679cc FUN_000679cc(List_000679cc *l, It_000679cc pos)
{
    Node_000679cc *n = pos.node;
    pos.node = n->next;
    n->prev->next = n->next;
    n->next->prev = n->prev;
    delete n;
    --l->size;
    return pos;
}
