/* HSTMATCH module=EBOOT.BIN start=0x001a4334 end=0x001a444c symbol=FUN_001a4334 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Matching idioms: the volatile unsigned count member (retail reloads 904(s1) every iteration) and
   #pragma opt_strength_reduction off (retail recomputes the element address with sll+addu); the
   comparisons are written cur == v and r == j so the beq/bnel operand order is retail's. */
struct Obj_001a4334 { char pad[0x384]; int **items; volatile unsigned count; };
extern int FUN_0016b534(void *self);
extern unsigned int DAT_00310fc8;

int FUN_001a4334(char *self)
{
    struct Obj_001a4334 *o = (struct Obj_001a4334 *)self;
    int n = 0;
    int cur = FUN_0016b534(self);
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
    DAT_00310fc8 = DAT_00310fc8 * 0x343fd + 0x269ec3;
    int r = (int)((DAT_00310fc8 >> 16) & 0x7fff) % n;
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
