/* HSTMATCH module=hstp_trans_main.prx start=0x001c2130 end=0x001c21a8 symbol=FUN_001c2130 lang=c++ */
/* Clone of src/eboot/slot_release_001b3e2c.cpp (hstclone.py tag c47): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Release the current slot: valid when idx < 474 and slot[idx] != 0, then (if a >= 0) FUN_00063810(slot[idx], a) and a = -1, and idx = 474 (none). The second read of idx is through an inline getter so MWCC reloads it; the flag is copied through a second bool with an else arm (c = b), which is what gives retail's a0/v1 register split. */
extern "C" void FUN_00063810(void *, int);
struct Obj {
    void *slot[474];
    int pad[17];
    int a;
    int idx;
    int Idx() const { return idx; }
};
struct Holder { Obj *obj; };
extern "C" void FUN_001c2130(Holder *h)
{
    Obj *o = h->obj;
    bool b = o->idx < 474;
    bool c = b;
    if (b)
        c = o->slot[o->idx] != 0;
    else
        c = b;
    if (c) {
        if (o->a >= 0) {
            FUN_00063810(o->slot[o->Idx()], o->a);
            o->a = -1;
        }
        o->idx = 474;
    }
}
