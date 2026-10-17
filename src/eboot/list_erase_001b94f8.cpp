/* HSTMATCH module=EBOOT.BIN start=0x001b94f8 end=0x001b9598 symbol=FUN_001b94f8 lang=c++ */
/* Clone of src/eboot/list_erase_0014f188.cpp (hstclone.py tag c13): addresses substituted; exact match verified; names and types await human review. */
/* Doubly-linked list erase(first, last): unlink [first, last), then free each node, advancing first and
   decrementing the size; the result iterator is last. Names provisional. */
struct Node_001b94f8 { Node_001b94f8 *prev; Node_001b94f8 *next; };
struct It_001b94f8 { Node_001b94f8 *node; };
extern "C" void FUN_001b94f8(It_001b94f8 *ret, int *size, It_001b94f8 *first, It_001b94f8 *last)
{
    Node_001b94f8 *f = first->node;
    Node_001b94f8 *l = last->node;
    if (f == l) {
        ret->node = l;
        return;
    }
    Node_001b94f8 *lp = l->prev;
    f->prev->next = lp->next;
    lp->next->prev = f->prev;
    while (f != l) {
        first->node = f->next;
        delete f;
        l = last->node;
        f = first->node;
        --*size;
    }
    ret->node = l;
}
