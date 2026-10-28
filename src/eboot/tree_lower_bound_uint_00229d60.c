/* HSTMATCH module=EBOOT.BIN start=0x00229d60 end=0x00229d98 symbol=FUN_00229d60 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Node { struct Node *f00; struct Node *f04; char pad[4]; unsigned int key; };

struct Node *FUN_00229d60(void *self, unsigned int *k, struct Node *cur, struct Node *best)
{
    while (cur != 0) {
        if (cur->key >= *k) {
            best = cur;
            cur = cur->f00;
        } else
            cur = cur->f04;
    }
    return best;
}
