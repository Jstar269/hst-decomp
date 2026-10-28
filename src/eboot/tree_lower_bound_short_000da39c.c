/* HSTMATCH module=EBOOT.BIN start=0x000da39c end=0x000da3d4 symbol=FUN_000da39c lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Node { struct Node *f00; struct Node *f04; char pad[4]; short key; };

struct Node *FUN_000da39c(void *self, short *k, struct Node *cur, struct Node *best)
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
