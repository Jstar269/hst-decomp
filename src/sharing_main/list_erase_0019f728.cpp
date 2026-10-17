/* HSTMATCH module=hstp_trans_main.prx start=0x0019f728 end=0x0019f7c8 symbol=FUN_0019f728 lang=c++ */
/* Clone of src/eboot/list_erase_0001f64c.cpp (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
/* Doubly-linked list erase(first, last): unlink [first, last), then free each node, advancing first and
   decrementing the size; the result iterator is last. Names provisional. */
struct Node_0019f728 { Node_0019f728 *prev; Node_0019f728 *next; };
struct It_0019f728 { Node_0019f728 *node; };
extern "C" void FUN_0019f728(It_0019f728 *ret, int *size, It_0019f728 *first, It_0019f728 *last)
{
    Node_0019f728 *f = first->node;
    Node_0019f728 *l = last->node;
    if (f == l) {
        ret->node = l;
        return;
    }
    Node_0019f728 *lp = l->prev;
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
