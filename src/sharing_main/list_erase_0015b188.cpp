/* HSTMATCH module=hstp_trans_main.prx start=0x0015b188 end=0x0015b228 symbol=FUN_0015b188 lang=c++ */
/* Clone of src/eboot/list_erase_0001f64c.cpp (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
/* Doubly-linked list erase(first, last): unlink [first, last), then free each node, advancing first and
   decrementing the size; the result iterator is last. Names provisional. */
struct Node_0015b188 { Node_0015b188 *prev; Node_0015b188 *next; };
struct It_0015b188 { Node_0015b188 *node; };
extern "C" void FUN_0015b188(It_0015b188 *ret, int *size, It_0015b188 *first, It_0015b188 *last)
{
    Node_0015b188 *f = first->node;
    Node_0015b188 *l = last->node;
    if (f == l) {
        ret->node = l;
        return;
    }
    Node_0015b188 *lp = l->prev;
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
