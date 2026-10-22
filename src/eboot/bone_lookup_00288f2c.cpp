/* HSTMATCH module=EBOOT.BIN start=0x00288f2c end=0x002890c0 symbol=FUN_00288f2c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Res { char pad[8]; int h; };
struct Owner { char pad[0x8c]; Res *f8c; };

struct Obj {
    virtual int m0(); virtual int m1(); virtual int m2(); virtual int m3();
    virtual int m4(); virtual int m5(); virtual int m6(); virtual int m7();
    virtual int m8(); virtual int m9(); virtual int m10(); virtual int m11();
    char pad4[0x54];
    Owner *f58;
    char pad5c[0x14];
    Owner *f70;
    Obj *AsMode23()
    {
        bool match = m11() == 2;
        if (!match) match = m11() == 3;
        if (match) {
            Obj *p = this;
            if (p) { p = (Obj *)((char *)p - 0xe0); }
            return p;
        }
        return 0;
    }
    Obj *AsMode4()
    {
        return m11() == 4 ? this : 0;
    }
};

extern "C" {
extern char DAT_002feb6c[];
extern char DAT_002feb7c[];
int FUN_0002fe80(int h, char *name);
}

extern "C" int FUN_00288f2c(Obj *self, Owner **out)
{
    int result = -1;
    Owner *owner = 0;
    bool match = self->m11() == 2;
    if (!match) match = self->m11() == 3;
    if (match) {
        owner = self->AsMode23()->f58;
        int h = owner->f8c->h;
        result = h ? FUN_0002fe80(h, DAT_002feb6c) : -1;
    } else if (self->m11() == 4) {
        owner = self->AsMode4()->f70;
        int h = owner->f8c->h;
        result = h ? FUN_0002fe80(h, DAT_002feb7c) : -1;
    }
    if (out) *out = owner;
    return result;
}
