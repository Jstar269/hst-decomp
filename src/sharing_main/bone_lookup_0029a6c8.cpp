/* HSTMATCH module=hstp_trans_main.prx start=0x0029a6c8 end=0x0029a85c symbol=FUN_0029a6c8 lang=c++ data=0x003a7a94 */
/* Clone of src/eboot/bone_lookup_00288f2c.cpp (hstclone.py tag c23fbop): addresses substituted; exact match verified; names and types await human review. Data: its string literals (2 strings, 0x003a7a94-0x003a7aab) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
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
int FUN_0002fea8(int h, char *name);
}

extern "C" int FUN_0029a6c8(Obj *self, Owner **out)
{
    int result = -1;
    Owner *owner = 0;
    bool match = self->m11() == 2;
    if (!match) match = self->m11() == 3;
    if (match) {
        owner = self->AsMode23()->f58;
        int h = owner->f8c->h;
        result = h ? FUN_0002fea8(h, "Bip01HeadNub") : -1;
    } else if (self->m11() == 4) {
        owner = self->AsMode4()->f70;
        int h = owner->f8c->h;
        result = h ? FUN_0002fea8(h, "Pelvis") : -1;
    }
    if (out) *out = owner;
    return result;
}
