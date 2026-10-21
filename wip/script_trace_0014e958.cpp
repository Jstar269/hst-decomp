/* HSTMATCH module=EBOOT.BIN start=0x0014e958 end=0x0014ea74 symbol=FUN_0014e958 lang=c++ */
/* Hand-written reconstruction from the disassembly; NEAR MISS (byte-identical apart from the 4 jal targets of the static stub, see trailing comments); names and types await human review. */
struct Thing { char pad[8]; int kind; };
struct Node { char pad[0x18]; int depth; Thing *thing; };
struct Obj {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual int m5();
};
struct Out { int v; };

extern unsigned char DAT_003402f0;
extern char DAT_002dc240[];
extern char DAT_002dc24c[];
extern char DAT_002dc358[];
static void Dbg(const char *, ...) {}
extern "C" {
void FUN_0014f3cc(Out *, int *, Thing **);
int FUN_0014e11c(Obj *, Node *, float);
void FUN_0014f43c(Out *, int *, Thing ***, int *);

int FUN_0014e958(Obj *self, Node *node, float f)
{
    int two;
    Out o1;
    Thing *thing;
    Out o2;
    Thing **pt;
    thing = node->thing;
    int kind = thing->kind;
    FUN_0014f3cc(&o1, &node->depth, &thing);
    if (kind == 1) {
        return FUN_0014e11c(self, node, f);
    }
    if (DAT_003402f0 != 0) {
        if (DAT_003402f0 != 0) {
            Dbg(DAT_002dc240);
            for (int i = 0; i < node->depth + 1; i++) {
                Dbg(DAT_002dc24c);
            }
        }
        Dbg(DAT_002dc358, self->m5());
    }
    two = 2;
    pt = &node->thing;
    FUN_0014f43c(&o2, &node->depth, &pt, &two);
    return 0;
}
}

// sn1: body is word-for-word retail (register colouring, frame slots 60/56/52/48/44, branch shapes) EXCEPT that the four calls to the print stub
// 0x0014c610 go to the file-local `Dbg`, and hstmatch reports MISPLACED (stub is the first .text function). Retail keeps the loop counter in v1
// (`addiu v1,v1,1` after `jal 0x14c610`) and kind/self/node in s2/s1/s0: that is MWCC's register knowledge of an empty STATIC variadic stub defined
// earlier in the same file (MWCC-NOTES 2026-10-15 0x195bb0, 2026-10-17 0x205b54). With an extern prototype the counter takes an s-register and
// self/node/kind colour s2/s1/s0 (27 words off). A run source needs every function between the stub (0x14c610) and here (0x2348 bytes, most not matched yet).
// The locals must be declared in this order for the slots to match: `int two; Out o1; Thing *thing; Out o2; Thing **pt;`.
// near miss from lane sn1 (unreviewed)
