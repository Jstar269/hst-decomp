/* HSTMATCH module=EBOOT.BIN start=0x0006b274 end=0x0006b314 symbol=FUN_0006b274 lang=c++ */
/* Clone of src/eboot/list_erase_0014f188.cpp (hstclone.py tag c13): addresses substituted; exact match verified; names and types await human review. */
/* Doubly-linked list erase(first, last): unlink [first, last), then free each node, advancing first and
   decrementing the size; the result iterator is last. Names provisional. */
struct Node_0006b274 { Node_0006b274 *prev; Node_0006b274 *next; };
struct It_0006b274 { Node_0006b274 *node; };
extern "C" void FUN_0006b274(It_0006b274 *ret, int *size, It_0006b274 *first, It_0006b274 *last)
{
    Node_0006b274 *f = first->node;
    Node_0006b274 *l = last->node;
    if (f == l) {
        ret->node = l;
        return;
    }
    Node_0006b274 *lp = l->prev;
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
