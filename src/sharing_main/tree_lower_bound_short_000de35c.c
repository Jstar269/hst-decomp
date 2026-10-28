/* HSTMATCH module=hstp_trans_main.prx start=0x000de35c end=0x000de394 symbol=FUN_000de35c lang=c99 */
/* Clone of src/eboot/tree_lower_bound_short_000da39c.c (hstclone.py tag c170007): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Node { struct Node *f00; struct Node *f04; char pad[4]; short key; };

struct Node *FUN_000de35c(void *self, short *k, struct Node *cur, struct Node *best)
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
