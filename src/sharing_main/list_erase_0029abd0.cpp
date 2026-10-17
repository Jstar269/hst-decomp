/* HSTMATCH module=hstp_trans_main.prx start=0x0029abd0 end=0x0029ac70 symbol=FUN_0029abd0 lang=c++ */
/* Clone of src/eboot/list_erase_0001f64c.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Doubly-linked list erase(first, last): unlink [first, last), then free each node, advancing first and
   decrementing the size; the result iterator is last. Names provisional. */
struct Node_0029abd0 { Node_0029abd0 *prev; Node_0029abd0 *next; };
struct It_0029abd0 { Node_0029abd0 *node; };
extern "C" void FUN_0029abd0(It_0029abd0 *ret, int *size, It_0029abd0 *first, It_0029abd0 *last)
{
    Node_0029abd0 *f = first->node;
    Node_0029abd0 *l = last->node;
    if (f == l) {
        ret->node = l;
        return;
    }
    Node_0029abd0 *lp = l->prev;
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
