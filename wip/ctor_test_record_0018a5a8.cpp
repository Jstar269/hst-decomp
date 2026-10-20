/* HSTMATCH module=EBOOT.BIN start=0x0018a5a8 end=0x0018a68c symbol=FUN_0018a5a8 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern "C" char DAT_0030913c;
extern "C" void *DAT_002e0af4;
extern "C" char DAT_002e0af8;
extern "C" char DAT_002e0afc;

extern "C" void FUN_00102e38(void *);
extern "C" void FUN_0018a6e8(void *);
extern "C" void FUN_0018aa0c(void *, int);
extern "C" void FUN_000143b0(void *, void *);
extern "C" void FUN_0018a950(void *, void *);
extern "C" void FUN_0018a960(void *, void *, int);

extern "C" void *FUN_0018a5a8(char *o) {
    int off;
    int i;
    FUN_00102e38(o);
    *(void **)o = &DAT_0030913c;
    FUN_0018a6e8(o);
    FUN_0018aa0c(o, 4);
    *(int *)(o + 0x58) = 0;
    *(int *)(o + 0x5c) = 0;
    *(int *)(o + 0x60) = 0;
    *(int *)(o + 0x64) = 0;
    *(int *)(o + 0x68) = 0;
    i = 0;
    off = 0;
    *(void **)(o + 0x98) = DAT_002e0af4;
    *(char *)(o + 0x6c) = 0;
    *(char *)(o + 0x6d) = 1;
    *(char *)(o + 0x6e) = 1;
    *(char *)(o + 0x6f) = 1;
    *(char *)(o + 0x70) = 0;
    *(char *)(o + 0x71) = 0;
    do {
        FUN_000143b0(o + off + 0x9c, &DAT_002e0af8);
        i = i + 1;
        off = off + 0x400;
    } while (i < 3);
    FUN_0018a950(o, &DAT_002e0afc);
    FUN_0018a960(o, DAT_002e0af4, 0);
    return o;
}

// NEAR MISS: 22 of 57 words differ, and every one of them is the same register swap: retail keeps
// `this` in s1 and the 0x400 loop accumulator (`off`) in s2, this source gets this=s2 / off=s1
// (i stays s0 in both). Pure saved-register colouring of one param and one local; a $s1/$s2
// permutation fixes the file. Tried: declaration orders (i/off, off/i), initialisers at declaration,
// `off` folded into the loop as `i * 0x400` (loses s2 entirely), no-argument base-ctor prototype.
// near miss from lane ds7 (unreviewed)
