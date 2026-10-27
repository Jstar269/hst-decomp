/* HSTMATCH module=hstp_trans_main.prx start=0x002baca8 end=0x002bad68 symbol=FUN_002baca8 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* After FUN_00108aec, when enabled: in mode +0x3114 hand +0x311c (if set) and +0x3124 to FUN_0005ffd8, otherwise
   pass args[i] to virtual slot 2 of each item's object. The hidden byte is tested by the loop and again inside
   the inline Item::Update, which is retail's second (redundant) `bnez` with the argument load in its slot. */
struct VObj {
    virtual void v0();
    virtual void v1();
    virtual void Set(int);
};

struct Item {
    VObj *obj;
    char pad[0x15];
    unsigned char hidden;
    unsigned char active;

    void Update(int arg)
    {
        if (!hidden && active) obj->Set(arg);
    }
};

struct Self {
    char pad0[0x30c5];
    unsigned char on;
    char pad1[0x3104 - 0x30c6];
    Item *items[4];
    unsigned char mode;
    int count;
    void *p311c;
    int f3120;
    int f3124;
    int args[4];
};

extern "C" void FUN_00108aec(Self *);
extern "C" void FUN_0005ffd8(void *, int);

extern "C" void FUN_002baca8(Self *self)
{
    FUN_00108aec(self);
    if (self->on) {
        if (self->mode) {
            if (self->p311c) FUN_0005ffd8(self->p311c, self->f3124);
        } else {
            for (int i = 0; i < self->count; i++) {
                Item *p = self->items[i];
                if (!p->hidden) p->Update(self->args[i]);
            }
        }
    }
}
