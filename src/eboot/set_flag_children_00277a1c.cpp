/* HSTMATCH module=EBOOT.BIN start=0x00277a1c end=0x00277b24 symbol=FUN_00277a1c lang=c++ */
/* Clone of src/eboot/set_flag_children_00277914.cpp (hstclone.py tag c33): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Turn a flag on for eleven owned objects through virtual slot 1 (vtable +0xc), in the order 1, 2, 0, 3..10,
   then for the object at +0x8b8 via 0xffb3c (sets bit 0 of its halfword at +0xe). Names provisional. */
class W_00277a1c {
public:
    virtual void v00();
    virtual void v01(int on);
};
struct S_00277a1c {
    char pad0[0x48c];
    W_00277a1c *w[11];
    char pad1[0x8b8 - 0x4b8];
    void *x;
};
extern "C" void FUN_000ffb3c(void *p, int on);
extern "C" void FUN_00277a1c(S_00277a1c *s)
{
    s->w[1]->v01(1);
    s->w[2]->v01(1);
    s->w[0]->v01(1);
    s->w[3]->v01(1);
    s->w[4]->v01(1);
    s->w[5]->v01(1);
    s->w[6]->v01(1);
    s->w[7]->v01(1);
    s->w[8]->v01(1);
    s->w[9]->v01(1);
    s->w[10]->v01(1);
    FUN_000ffb3c(s->x, 1);
}
