/* HSTMATCH module=hstp_trans_main.prx start=0x00291364 end=0x0029140c symbol=FUN_00291364 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* One step of a table-driven offset (set up by FUN_0029134c, reset by FUN_0029140c): the byte table
   DAT_002db038 (21 entries 0,6,11,15,19,17,...,1, a decaying hop) is scaled by `scale`, negated when `invert`
   is set, and added to the saved base; the target's f4 takes the new value and its f8 moves by the same
   delta. The sign flip is `d *= -1` (`d = -d` re-extends d before the negu). Names provisional. */
typedef struct BounceTarget {
    char pad0[4];
    short f4;
    char pad6[2];
    short f8;
} BounceTarget;

typedef struct Bounce {
    BounceTarget *target;
    short base;
    unsigned int frame;
    unsigned char invert;
} Bounce;

extern unsigned char DAT_002db038[];

void FUN_00291364(Bounce *self, float scale)
{
    unsigned int amp = DAT_002db038[self->frame % 21];
    short d = (short)(amp * scale);
    if (self->invert) {
        d *= -1;
    }
    short n = self->base + d;
    BounceTarget *t = self->target;
    short old = t->f4;
    t->f4 = n;
    t->f8 += n - old;
    self->frame++;
}
