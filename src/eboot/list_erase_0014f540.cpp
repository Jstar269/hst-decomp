/* HSTMATCH module=EBOOT.BIN start=0x0014f540 end=0x0014f5e0 symbol=FUN_0014f540 lang=c++ */
/* Clone of src/eboot/list_erase_0014f188.cpp (hstclone.py tag c13): addresses substituted; exact match verified; names and types await human review. */
/* Doubly-linked list erase(first, last): unlink [first, last), then free each node, advancing first and
   decrementing the size; the result iterator is last. Names provisional. */
struct Node_0014f540 { Node_0014f540 *prev; Node_0014f540 *next; };
struct It_0014f540 { Node_0014f540 *node; };
extern "C" void FUN_0014f540(It_0014f540 *ret, int *size, It_0014f540 *first, It_0014f540 *last)
{
    Node_0014f540 *f = first->node;
    Node_0014f540 *l = last->node;
    if (f == l) {
        ret->node = l;
        return;
    }
    Node_0014f540 *lp = l->prev;
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
