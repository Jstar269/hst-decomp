/* HSTMATCH module=hstp_trans_main.prx start=0x001bac6c end=0x001baf04 symbol=FUN_001bac6c lang=c++ */
/* Clone of src/eboot/update_slot_widgets_001ad604.cpp (hstclone.py tag s10170158a2r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Two rows of three cells: for each (row, col) the slot object at +0x86c + 12*(3*row+col+1) and the holder at +0x24 + 20*(3*row+col+82) are handled.
   When the nested vector at +0x390 of the 0x19d474 block has an element for the cell: virtual slot 1 with 0, 0xffb3c with 0, the slot object's
   fields +0xf8/+0x138 are set and 0x10d4a8 called, then 0xffc70 with the holder's widget and either 0x216e00(g5+0x18) or the holder's +0x10 field
   (chosen by the parallel vector at +0x330); otherwise virtual slot 1 with 1 and 0xffb3c with 1. Afterwards the object at +0x914 is called when
   the flag byte is set and 0xffb3c is applied to the holders 80/81 with 0 (flag) or 1.
   Matching idioms: `#pragma opt_strength_reduction off`; the running indices ra/rb are separate variables initialised in the for header
   (`row = 0, ra = 1, rb = 82`, in that order); VecVec::At() is a char-pointer sum (base-first addu); the holder addresses p/q are locals taken
   before the flag branch (as in set_two_widgets_flag_001e611c.cpp). Names provisional. */
#pragma opt_strength_reduction off
struct Widget {
    virtual void s0();
    virtual void s1(int);
};
struct Obj {
    virtual void s0();
    virtual void s1(int);
    char pad[0xf8 - 4];
    int f_f8;
    char pad2[0x138 - 0xfc];
    int f_138;
};
struct Holder {
    void *w;
    int pad[3];
    int f10;
    void Set(int v);
};
extern "C" {
void FUN_00105470(void *, int);
void FUN_001055a4(void *, int);
int FUN_0020d484(int);
void FUN_00113a50(void *);
int FUN_00225e04(void *);
void FUN_00111aa4(void *, int, int);
}
inline void Holder::Set(int v) { FUN_00105470(w, v); }
struct IntVec { int *data; unsigned size; unsigned cap; };
struct VecVec {
    IntVec *data;
    unsigned size;
    unsigned cap;
    IntVec *At(int i) { return (IntVec *)((char *)data + i * sizeof(IntVec)); }
};
struct Block {
    char pad[0x328];
    int f328;
    int f32c;
    VecVec f330;
    char pad2[0x390 - 0x33c];
    VecVec f390;
};
struct Rec12 { int a; Obj *w; int c; };
struct Self {
    char pad[0x24];
    Holder items[88];
    char pad2[0x86c - 0x704];
    Rec12 recs[7];
    char pad3[0x914 - 0x8c0];
    Widget *w914;
};
extern "C" Block *FUN_001aa91c();
extern "C" char *FUN_001aa938();

extern "C" void FUN_001bac6c(Self *self, bool flag)
{
    int a = FUN_001aa91c()->f328;
    int b = FUN_001aa91c()->f32c;
    VecVec *v390 = &FUN_001aa91c()->f390;
    VecVec *v330 = &FUN_001aa91c()->f330;
    char *g5 = FUN_001aa938();
    int ra, rb, row;
    for (row = 0, ra = 1, rb = 82; row < 2; row++, ra += 3, rb += 3) {
        for (int col = 0; col < 3; col++) {
            Rec12 *rec = &self->recs[col + ra];
            Holder *h = &self->items[col + rb];
            if ((unsigned)row < v390->size && (unsigned)col < v390->At(row)->size) {
                int e = v390->At(row)->data[col];
                rec->w->s1(0);
                h->Set(0);
                int v = FUN_0020d484(e);
                Obj *o = rec->w;
                o->f_f8 = v;
                o->f_138 = 1;
                FUN_00113a50(o);
                if (v330->At(row)->data[col] != 0)
                    FUN_001055a4(h->w, FUN_00225e04(g5 + 0x18));
                else
                    FUN_001055a4(h->w, h->f10);
            } else {
                rec->w->s1(1);
                h->Set(1);
            }
        }
    }
    if (flag) {
        self->w914->s1(0);
        FUN_00111aa4(self->w914, a + b * 3, 0);
    }
    Holder *p = &self->items[80];
    Holder *q = &self->items[81];
    if (flag) {
        p->Set(0);
        q->Set(0);
    } else {
        p->Set(1);
        q->Set(1);
    }
}
