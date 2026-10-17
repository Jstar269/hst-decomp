/* HSTMATCH module=EBOOT.BIN start=0x0014f188 end=0x0014f228 symbol=FUN_0014f188 lang=c++ */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
/* Doubly-linked list erase(first, last): unlink [first, last), then free each node, advancing first and
   decrementing the size; the result iterator is last. Names provisional. */
struct Node_0014f188 { Node_0014f188 *prev; Node_0014f188 *next; };
struct It_0014f188 { Node_0014f188 *node; };
extern "C" void FUN_0014f188(It_0014f188 *ret, int *size, It_0014f188 *first, It_0014f188 *last)
{
    Node_0014f188 *f = first->node;
    Node_0014f188 *l = last->node;
    if (f == l) {
        ret->node = l;
        return;
    }
    Node_0014f188 *lp = l->prev;
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
