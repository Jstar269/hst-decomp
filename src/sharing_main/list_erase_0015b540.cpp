/* HSTMATCH module=hstp_trans_main.prx start=0x0015b540 end=0x0015b5e0 symbol=FUN_0015b540 lang=c++ */
/* Clone of src/eboot/list_erase_0001f64c.cpp (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
/* Doubly-linked list erase(first, last): unlink [first, last), then free each node, advancing first and
   decrementing the size; the result iterator is last. Names provisional. */
struct Node_0015b540 { Node_0015b540 *prev; Node_0015b540 *next; };
struct It_0015b540 { Node_0015b540 *node; };
extern "C" void FUN_0015b540(It_0015b540 *ret, int *size, It_0015b540 *first, It_0015b540 *last)
{
    Node_0015b540 *f = first->node;
    Node_0015b540 *l = last->node;
    if (f == l) {
        ret->node = l;
        return;
    }
    Node_0015b540 *lp = l->prev;
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
