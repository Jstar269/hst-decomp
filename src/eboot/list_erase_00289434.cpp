/* HSTMATCH module=EBOOT.BIN start=0x00289434 end=0x002894d4 symbol=FUN_00289434 lang=c++ */
/* Clone of src/eboot/list_erase_0014f188.cpp (hstclone.py tag c13): addresses substituted; exact match verified; names and types await human review. */
/* Doubly-linked list erase(first, last): unlink [first, last), then free each node, advancing first and
   decrementing the size; the result iterator is last. Names provisional. */
struct Node_00289434 { Node_00289434 *prev; Node_00289434 *next; };
struct It_00289434 { Node_00289434 *node; };
extern "C" void FUN_00289434(It_00289434 *ret, int *size, It_00289434 *first, It_00289434 *last)
{
    Node_00289434 *f = first->node;
    Node_00289434 *l = last->node;
    if (f == l) {
        ret->node = l;
        return;
    }
    Node_00289434 *lp = l->prev;
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
