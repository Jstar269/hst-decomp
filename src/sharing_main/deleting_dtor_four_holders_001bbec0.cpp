/* HSTMATCH module=hstp_trans_main.prx start=0x001bbec0 end=0x001bc04c symbol=FUN_001bbec0 lang=c++ */
/* Clone of src/eboot/deleting_dtor_four_holders_001ae7e8.cpp (hstclone.py tag s10170158a2r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (recipe of deleting_dtor_slots_00199a0c.cpp); exact match verified; names and types await human review. */
/* Deleting destructor: four members each point to a Holder with a user destructor that deletes its virtual-dtor pointee; `delete self->mN` inlines it and gives the doubled null tests (outer `if`, delete's own test, and the holder's `if (obj != 0)` around `delete obj`). Names provisional. */
extern "C" {
extern char DAT_003b2580;
}
struct VC {
    virtual ~VC();
};
struct Holder {
    VC *obj;
    ~Holder()
    {
        if (obj != 0) {
            delete obj;
            obj = 0;
        }
    }
};
struct Obj {
    void *vptr;
    Holder *m1;
    Holder *m2;
    Holder *m3;
    Holder *m4;
};
extern "C" Obj *FUN_001bbec0(Obj *self, short flag)
{
    if (self != 0) {
        self->vptr = &DAT_003b2580;
        if (self->m1 != 0) {
            delete self->m1;
            self->m1 = 0;
        }
        if (self->m2 != 0) {
            delete self->m2;
            self->m2 = 0;
        }
        if (self->m3 != 0) {
            delete self->m3;
            self->m3 = 0;
        }
        if (self->m4 != 0) {
            delete self->m4;
            self->m4 = 0;
        }
        if (flag > 0)
            delete self;
    }
    return self;
}
