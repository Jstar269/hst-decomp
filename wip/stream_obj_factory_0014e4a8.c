/* HSTMATCH module=EBOOT.BIN start=0x0014e4a8 end=0x0014e650 symbol=FUN_0014e4a8 lang=c99 rodata=0x002c1a50 */
extern char DAT_00308460[];
extern char DAT_003083f0[];
extern char DAT_00308444[];
extern char DAT_0030840c[];
extern char DAT_00308428[];
extern char DAT_003082b8[];
extern int FUN_00000bcc(unsigned);
extern int FUN_0014f028(int);
extern float FUN_0014f014(int);
extern int FUN_0014f050(int);

void *FUN_0014e4a8(int param_1, int param_2, int param_3)
{
    union {
        int i;
        float f;
    } v;
    union {
        int i;
        float f;
    } fv;
    void *r;
    void *p;
    void *q;
    unsigned short h;

    r = 0;
    switch (param_2) {
    case 1:
        v.i = FUN_0014f028(param_3);
        p = (void *)FUN_00000bcc(0xc);
        if (p != 0) {
            *(int **)p = (int *)DAT_00308460;
            ((int *)p)[1] = param_2;
            *(int **)p = (int *)DAT_003083f0;
            *(float *)((char *)p + 8) = v.f;
            return p;
        }
        return p;
    case 2:
        fv.f = FUN_0014f014(param_3);
        p = (void *)FUN_00000bcc(0xc);
        if (p != 0) {
            *(int **)p = (int *)DAT_00308460;
            ((int *)p)[1] = param_2;
            *(int **)p = (int *)DAT_003083f0;
            *(float *)((char *)p + 8) = fv.f;
        }
        r = p;
        break;
    case 3:
        p = (void *)FUN_00000bcc(0xc);
        if (p != 0) {
            *(int **)p = (int *)DAT_00308460;
            ((int *)p)[1] = param_2;
            *(int **)p = (int *)DAT_00308444;
            FUN_0014f050(param_3);
            q = (void *)FUN_00000bcc(0x10);
            if (q != 0) {
                *(int **)q = (int *)DAT_0030840c;
                *((char *)q + 4) = 0;
                *(int **)q = (int *)DAT_00308428;
                h = FUN_0014f050(param_3);
                ((int *)q)[2] = (h >> 12) & 0xf;
                ((int *)q)[3] = h & 0xfff;
            }
            ((void **)p)[2] = q;
        }
        r = p;
        break;
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
        p = (void *)FUN_00000bcc(8);
        if (p != 0) {
            *(int **)p = (int *)DAT_00308460;
            ((int *)p)[1] = param_2;
            *(int **)p = (int *)DAT_003082b8;
        }
        r = p;
    }
    return r;
}
// sn7 lane near miss, 106/106 words (was 109/106), est. 5-6 words left; first difference at +0x80 (end of case 1).
// Progress over the fm8 version: default is `r = 0` before the switch with `break` + `return r` (gives retail's
// `move v0,zero` in the beqz delay slot and the shared epilogue), case 2/4..15 return through r, case 3's pointer
// goes through r too; the switch index base is then a0/v1 as retail. Case 1 needs `if (p != 0) {...; return p;} return p;`
// (that is the only spelling that yields retail's `beqzl v0,epilogue+4` with `lw ra` in the slot and p in v0).
// `unsigned short h` + `(h >> 12) & 0xf` gives retail's `andi; ext v0,v1,12,4; andi v0,v1,0xfff` pair.
// Remaining deltas: (1) case 1's final `b epilogue` has the swc1 in its delay slot (retail: swc1 before the b, nop after);
// every spelling that ends case 1 with `break` loses the beqzl top (or moves p to s1). (2) case 3: retail tests the alloc with
// `beqz v0,epi; nop` and copies p to s1 only mid-body (`move s1,v0` between the 3rd vtable address and its store), ours copies
// at once and returns via `beqzl s1; move v0,s1`. Tried: r assigned inside the if, return p in the arm, a static inline Init3(self,..).
// Case 2's float needs the union (address-taken slot sp+24, not f20).
// improved by lane sn7 (unreviewed): 82 -> 39 differing words
