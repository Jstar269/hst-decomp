/* HSTMATCH module=hstp_trans_main.prx start=0x00068d80 end=0x00068e20 symbol=FUN_00068d80 lang=c++ */
/* Clone of src/eboot/list_erase_0001f64c.cpp (hstclone.py tag x9): addresses substituted; exact match verified; names and types await human review. */
/* Doubly-linked list erase(first, last): unlink [first, last), then free each node, advancing first and
   decrementing the size; the result iterator is last. Names provisional. */
struct Node_00068d80 { Node_00068d80 *prev; Node_00068d80 *next; };
struct It_00068d80 { Node_00068d80 *node; };
extern "C" void FUN_00068d80(It_00068d80 *ret, int *size, It_00068d80 *first, It_00068d80 *last)
{
    Node_00068d80 *f = first->node;
    Node_00068d80 *l = last->node;
    if (f == l) {
        ret->node = l;
        return;
    }
    Node_00068d80 *lp = l->prev;
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
