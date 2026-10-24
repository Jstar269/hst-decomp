/* HSTMATCH module=EBOOT.BIN start=0x000c7cd0 end=0x000c7ed0 symbol=FUN_000c7cd0 lang=c++ */
struct False {};
extern "C" void FUN_000143b0(char *, const char *);
extern "C" void *FUN_00000bcc(int);
extern "C" void FUN_000cecb4(void *, char *);
extern "C" void FUN_00058ddc(void *, int, int);
extern "C" int FUN_00050ff4(void *, int, int);
extern "C" void FUN_0006ea5c(void *, void *, signed char);
extern "C" int DAT_003075b8;
extern "C" int DAT_003386b0;
extern "C" const char DAT_002d6264[];
extern "C" const char DAT_002d6290[];
extern "C" float DAT_002d624c[];

extern "C" void FUN_000c7cd0(int param_1, False, False)
{
    char buf[1024];
    float keys[6];
    int handle;
    int *slot;
    int i;
    unsigned j;
    int *p;
    void *obj;

    i = 0;
    p = (int *)param_1;
    do {
        p[0x59] = 0;
        p[0x5a] = 0;
        p[0x5b] = 0;
        p[0x5c] = 0;
        i = i + 5;
        p[0x5d] = 0;
        p = (int *)((int)p + 0x14);
    } while (i < 10);
    *(int *)(param_1 + 0x154) = 0;
    *(int *)(param_1 + 0x158) = 0;
    *(int *)(param_1 + 0x15c) = 0;
    *(int *)(param_1 + 0x160) = 0;
    i = 0;
    slot = (int *)param_1;
    do {
        switch (i) {
        case 5:
        case 4:
            FUN_000143b0(buf, DAT_002d6264);
            break;
        default:
            FUN_000143b0(buf, DAT_002d6290);
            break;
        }
        if ((int)slot[0x63] == 0) {
            obj = FUN_00000bcc(0x1c0);
            if (obj != 0) {
                FUN_000cecb4(obj, buf);
                *(int **)obj = (int *)&DAT_003075b8;
                FUN_00058ddc(obj, 1, 0xffffffff);
                *(char *)((int)obj + 0xc0) = 1;
            }
            slot[0x63] = (int)obj;
        }
        i = i + 1;
        slot = slot + 1;
    } while (i < 10);
    keys[0] = DAT_002d624c[0];
    keys[1] = DAT_002d624c[1];
    keys[2] = DAT_002d624c[2];
    keys[3] = DAT_002d624c[3];
    keys[4] = DAT_002d624c[4];
    keys[5] = DAT_002d624c[5];
    j = 0;
    do {
        handle = (int)FUN_00000bcc(0x48);
        if (handle != 0)
            handle = FUN_00050ff4((void *)handle, *(int *)&keys[j], 0);
        if ((unsigned int)*(int *)(param_1 + 0x1b8) < (unsigned int)*(int *)(param_1 + 0x1bc)) {
            i = *(int *)(param_1 + 0x1b8) + 1;
            *(int *)(param_1 + 0x1b8) = i;
            *(int *)(*(int *)(param_1 + 0x1b4) + i * 4 - 4) = handle;
        } else {
            FUN_0006ea5c((void *)(param_1 + 0x1b4), &handle, 0);
        }
        j = j + 1;
    } while (j < 6);
    *(float *)(param_1 + 0x2f0) = *(float *)(*(int *)(DAT_003386b0 + 0x88) + 0x110);
}
// near miss: 128/128 words, 63 differing. Frame and word count now match retail exactly.
// Fixed since the first attempt: (1) retail's 16-byte-larger frame comes from a SECOND trailing
// empty tag parameter (`(int param_1, False, False)`), not from a local; (2) the `i==4||i==5`
// test must be a SWITCH (`case 5: case 4:` - labels written in reverse so the `beq` chain tests 4
// before 5, 2 words) - as an `if (a||b)` MWCC folds it into `addiu v0,s0,-4; sltiu at,v0,2`;
// (3) the loop-3 alloc must be `handle = alloc(); if (handle != 0) handle = ctor(handle,..);`
// (retail stores the local twice, `beqzl a0` with `sw a0,52(sp)` in the slot); (4) loop 3's bound
// is UNSIGNED (`sltiu v1,s1,6`), so `unsigned j`.
// Remaining delta: loop 2's counter/pointer pair. Retail has i=s1 and slot=s0, ours the reverse
// (every differing word is downstream of that). Ruled out for it: declaration order both ways,
// assignment order, `for(i=0,slot=..;i<10;i++,slot++)`, increment order (i++ then slot++ and the
// reverse), and walking the index off param_1. In retail the SAME s1/s0 pair is reused by loop 3
// (j/&keys), which ours also does - only loop 2's pair is inverted.
// Separately, `FUN_0006ea5c(.., &handle, 0)`: retail materialises the char 0 as `move v0,zero;
// seb a2,v0` in the beqzl slot (`beqzl at`), MWCC folds the literal to `move a2,zero` (`beqz at`)
// = 1 word. Tried: `char z = 0;` local, `(char)0`, struct-with-char-member temporary, and
// `(char)(unsigned char)handle` (that one does emit seb but from `lb a2,52(sp)`).
// near miss from lane fm8 (unreviewed)
