/* HSTMATCH module=EBOOT.BIN start=0x00288f2c end=0x002890c0 symbol=FUN_00288f2c lang=c++ */
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
            if (this) return (Obj *)((char *)this - 0xe0);
            return this;
        }
        return 0;
    }
    Obj *AsMode4()
    {
        if (m11() != 4) return 0;
        return this;
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
        if (h == 0)
            result = -1;
        else
            result = FUN_0002fe80(h, DAT_002feb6c);
    } else if (self->m11() == 4) {
        owner = self->AsMode4()->f70;
        int h = owner->f8c->h;
        if (h == 0)
            result = -1;
        else
            result = FUN_0002fe80(h, DAT_002feb7c);
    }
    if (out) *out = owner;
    return result;
}
// PARKED (lane sn2, ~25 compiles): 95 of 101 words, 61 differ. Structure verified: bone/attachment lookup that reads owner = (mode 2/3: adjusted
// this-0xe0)->f58 or (mode 4: this)->f70, then owner->f8c->h, then FUN_0002fe80(h, "Bip01HeadNub"/"Pelvis") or -1, and stores owner through `out`.
// The two pointer adjusts are inlined copies of FUN_00288a84 / FUN_00288af0 (retail still calls them out of line elsewhere, e.g. 0x288470).
// Open point: retail's inlined adjust keeps an unreachable else block and a `b JOIN; nop` (mode 2/3: `beqzl s3,J+4; lw; addiu s3,s3,-224; b J; nop;
// move s3,zero; J: lw s0,88(s3)`; mode 4: `bnel v0,v1,E+4; move s3,zero; b J+4; lw s0,112(s3); E: move s3,zero; J: lw s0,112(s3)`), i.e. the adjust code is NOT
// optimised/scheduled like a normal inline expansion (as if inlined from an earlier-compiled function body). Member functions (this version) reproduce the
// retained else block for mode 2/3 (with `b` + addiu in its slot); free inline functions, early returns, if/else assignments, ternaries all drop the else block.
// near miss from lane sn2 (unreviewed)
