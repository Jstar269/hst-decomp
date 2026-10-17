/* HSTMATCH module=hstp_trans_main.prx start=0x0028b5d8 end=0x0028b678 symbol=FUN_0028b5d8 lang=c++ */
/* Clone of src/eboot/list_erase_0001f64c.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Doubly-linked list erase(first, last): unlink [first, last), then free each node, advancing first and
   decrementing the size; the result iterator is last. Names provisional. */
struct Node_0028b5d8 { Node_0028b5d8 *prev; Node_0028b5d8 *next; };
struct It_0028b5d8 { Node_0028b5d8 *node; };
extern "C" void FUN_0028b5d8(It_0028b5d8 *ret, int *size, It_0028b5d8 *first, It_0028b5d8 *last)
{
    Node_0028b5d8 *f = first->node;
    Node_0028b5d8 *l = last->node;
    if (f == l) {
        ret->node = l;
        return;
    }
    Node_0028b5d8 *lp = l->prev;
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
