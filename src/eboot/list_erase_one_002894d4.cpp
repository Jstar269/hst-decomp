/* HSTMATCH module=EBOOT.BIN start=0x002894d4 end=0x00289544 symbol=FUN_002894d4 lang=c++ */
/* Clone of src/eboot/list_erase_one_0014f3cc.cpp (hstclone.py tag c36): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Doubly-linked list erase(pos) (sibling of the range erase at 0x14f32c): advance pos, unlink and free the
   node, --size, return pos. The iterator has a user copy constructor, so the by-value pos arrives by invisible
   reference (a2) and is modified in place; that also lets the scheduler hoist its loads above the size store.
   Names provisional. */
struct Node_002894d4 { Node_002894d4 *prev; Node_002894d4 *next; };
struct It_002894d4 {
    Node_002894d4 *node;
    It_002894d4(Node_002894d4 *n) : node(n) {}
    It_002894d4(const It_002894d4 &o) : node(o.node) {}
};
struct List_002894d4 { int size; Node_002894d4 *head; };
extern "C" It_002894d4 FUN_002894d4(List_002894d4 *l, It_002894d4 pos)
{
    Node_002894d4 *n = pos.node;
    pos.node = n->next;
    n->prev->next = n->next;
    n->next->prev = n->prev;
    delete n;
    --l->size;
    return pos;
}
