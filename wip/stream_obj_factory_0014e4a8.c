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
    void *p;
    void *q;
    unsigned h;

    switch (param_2) {
    case 1:
        v.i = FUN_0014f028(param_3);
        p = (void *)FUN_00000bcc(0xc);
        if (p == 0)
            return 0;
        *(int **)p = (int *)DAT_00308460;
        ((int *)p)[1] = param_2;
        *(int **)p = (int *)DAT_003083f0;
        *(float *)((char *)p + 8) = v.f;
        return p;
    case 2:
        fv.f = FUN_0014f014(param_3);
        p = (void *)FUN_00000bcc(0xc);
        if (p == 0)
            return 0;
        *(int **)p = (int *)DAT_00308460;
        ((int *)p)[1] = param_2;
        *(int **)p = (int *)DAT_003083f0;
        *(float *)((char *)p + 8) = fv.f;
        return p;
    case 3:
        p = (void *)FUN_00000bcc(0xc);
        if (p == 0)
            return 0;
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
            ((int *)q)[2] = (h & 0xffff) >> 12;
            ((int *)q)[3] = h & 0xfff;
        }
        ((void **)p)[2] = q;
        return p;
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
        if (p == 0)
            return 0;
        *(int **)p = (int *)DAT_00308460;
        ((int *)p)[1] = param_2;
        *(int **)p = (int *)DAT_003082b8;
        return p;
    default:
        return 0;
    }
}
// near miss: 109/106 words. Every arm's instruction sequence matches retail once the s-register
// shift is accounted for (case 1's union pun through sp+28, case 2's float through sp+24, case 3's
// nested alloc with the ext/andi split of the halfword, the 4..15 arm shared with case 0), and the
// jump table at 0x2c1a50 needs rodata= in the header or hstmatch reports UNPLACED_SECTION.
// Remaining deltas, all one causing the other:
//  * retail materialises the default's `move v0,zero` INSIDE the `beqz at` delay slot, which takes
//    v0 for the whole head, so the table base goes to a0 (`lui a0,0x2c; addiu a0`) and the index
//    to v1 (`sll v1,s0,2; addu v1,v1,a0; lw v1; jr v1`). Ours leaves v0 free, so the base is v1
//    and the index v0, and the delay slot gets `move s2,a2` while `move v0,zero` is emitted at the
//    default's target instead (+2 words).
//  * the case-1 null test: retail `beqzl v0,EPILOGUE+4` with `lw ra` in the delay; ours `bnezl
//    v0,body` plus a separate `b epilogue; move v0,zero` pair.
// Ruled out: `return 0` vs `return p` vs `if (!p)`; body nested under `if (p != 0) {...}` with a
// trailing `return p` (that form fixes the case-3 early return but keeps the same head delta);
// default written first; `default: break;` (105 words but the 4..15 arm then returns 0).
// Facts pinned: the four vtable pairs are BASE-then-DERIVED stores (0x308460 then 0x3083f0 for
// cases 1/2, 0x308460 then 0x308444 for case 3's outer, 0x30840c then 0x308428 for its inner,
// 0x308460 then 0x3082b8 for 4..15); case 1's value is an INT read (sw v0) bit-cast to the float
// field, case 2's is a real float read (swc1 $f0) -- so case 1 needs a union, not a float local;
// `(h & 0xffff) >> 12` rings `andi` + `ext` and `h & 0xfff` a second `andi` off the SAME temp.
// near miss from lane fm8 (unreviewed)
