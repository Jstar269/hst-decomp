/* HSTMATCH module=hstp_trans_main.prx start=0x001c71e4 end=0x001c7284 symbol=FUN_001c71e4 lang=c++ */
/* Clone of src/eboot/list_erase_0001f64c.cpp (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
/* Doubly-linked list erase(first, last): unlink [first, last), then free each node, advancing first and
   decrementing the size; the result iterator is last. Names provisional. */
struct Node_001c71e4 { Node_001c71e4 *prev; Node_001c71e4 *next; };
struct It_001c71e4 { Node_001c71e4 *node; };
extern "C" void FUN_001c71e4(It_001c71e4 *ret, int *size, It_001c71e4 *first, It_001c71e4 *last)
{
    Node_001c71e4 *f = first->node;
    Node_001c71e4 *l = last->node;
    if (f == l) {
        ret->node = l;
        return;
    }
    Node_001c71e4 *lp = l->prev;
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
