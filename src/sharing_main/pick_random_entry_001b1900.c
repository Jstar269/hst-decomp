/* HSTMATCH module=hstp_trans_main.prx start=0x001b1900 end=0x001b1a18 symbol=FUN_001b1900 lang=c99 */
/* Clone of src/eboot/pick_random_entry_001a4334.c (hstclone.py tag ds1011s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Matching idioms: the volatile unsigned count member (retail reloads 904(s1) every iteration) and
   #pragma opt_strength_reduction off (retail recomputes the element address with sll+addu); the
   comparisons are written cur == v and r == j so the beq/bnel operand order is retail's. */
struct Obj_001b1900 { char pad[0x384]; int **items; volatile unsigned count; };
extern int FUN_001776f8(void *self);
extern unsigned int DAT_003ba2c8;

int FUN_001b1900(char *self)
{
    struct Obj_001b1900 *o = (struct Obj_001b1900 *)self;
    int n = 0;
    int cur = FUN_001776f8(self);
    unsigned i;
#pragma opt_strength_reduction off
    for (i = 0; i < o->count; i++) {
        int v = *o->items[i];
        if (v < 0 || cur == v)
            continue;
        n++;
    }
    if (n <= 0)
        n = 1;
    DAT_003ba2c8 = DAT_003ba2c8 * 0x343fd + 0x269ec3;
    int r = (int)((DAT_003ba2c8 >> 16) & 0x7fff) % n;
    int j = 0;
    for (i = 0; i < o->count; i++) {
        int v = *o->items[i];
        if (v < 0 || cur == v)
            continue;
        if (r == j)
            return v;
        j++;
    }
    return 0;
}
