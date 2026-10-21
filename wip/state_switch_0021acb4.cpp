/* HSTMATCH module=EBOOT.BIN start=0x0021acb4 end=0x0021ae88 symbol=FUN_0021acb4 lang=c++ rodata=0x002c9954 */
/* Hand-written reconstruction from the disassembly; NEAR MISS (112/117 words, 5 words short, see trailing comments); names and types await human review. */
class Owner {
public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
};

struct OwnerData {
    char pad0[0x54];
    unsigned char f54;
    char pad1[0xe8 - 0x55];
    int f0e8;
    int tab[1];
};

struct Flags {
    char pad[0x8b];
    signed char a : 2;
    signed char x : 2;
    signed char b : 2;
};

struct Self {
    OwnerData *owner;
    unsigned kind;
};

extern Flags *DAT_002cfc8c;
extern int DAT_0034179c;
extern int DAT_003415ac;

extern "C" {
void FUN_0021abe0(Self *, int);
int FUN_001155c0(int);
void FUN_00103628(int, int);
int FUN_001156d4(int);
void FUN_001b1c44(int *, int);

void FUN_0021acb4(Self *self)
{
    switch (self->kind) {
    case 1: case 2: case 3: case 4: case 5:
    case 8: case 9: case 10:
    case 14: case 15: case 16: case 17:
        FUN_0021abe0(self, 11);
        break;
    case 6: case 7: case 13: case 18:
        if (FUN_001155c0(DAT_003415ac) != 0) {
            FUN_00103628(DAT_003415ac, 1);
            if (FUN_001156d4(DAT_003415ac) == 0) {
                switch (self->kind) {
                case 13:
                    FUN_0021abe0(self, 14);
                    break;
                case 18:
                    FUN_0021abe0(self, 8);
                    break;
                case 6:
                    FUN_0021abe0(self, 9);
                    break;
                case 7:
                    FUN_0021abe0(self, 10);
                    break;
                }
            } else {
                FUN_0021abe0(self, 0);
            }
        }
        break;
    default: {
        OwnerData *o = self->owner;
        if (o->f54 != 0 && self->kind == 0) {
            FUN_0021abe0(self, o->tab[o->f0e8] + 1);
            self->owner->f54 = 0;
        }
        if (DAT_002cfc8c->a == 0 || DAT_002cfc8c->b == 0) {
            if (self->kind == 0) {
                FUN_001b1c44(&DAT_0034179c, 12);
                FUN_0021abe0(self, 11);
            }
        }
        ((Owner *)self->owner)->m2();
        break;
    }
    }
}
}

// sn1 NEAR (112/117 words; apart from address shifts the only difference is five words): retail's five likely-branch slots `beql a0,v1,Lcase; move a0,s0`
// (inner switch on kind 7,6,18,13 tests + the `bnezl v0` before the default `FUN_0021abe0(self, 0)`) are NOT retargeted: each case body still starts with its own
// `move a0,s0` (executed twice on the taken path), while ours skips it (branch to the `jal`) and so is five words shorter. Everything else is word-exact:
// outer jump table (rodata 0x2c9954: 1-5,8-10,14-17 -> FUN_0021abe0(self,11); 6,7,13,18 -> the group below; 0,11,12 and >18 -> default), the inner switch needs its
// cases in reverse test order (13,18,6,7) with bodies in source order, bitfields `a:2, x:2, b:2` at +0x8b, `((Owner*)self->owner)->m2()` = slot 2 (lw t9,16).
// Tried: if/else-if chain (bodies inline, wrong), #pragma peephole/scheduling off, optimization_level 3, inline_depth(0): none keeps the redundant target move.
// near miss from lane sn1 (unreviewed)
