/* HSTMATCH module=hstp_trans_main.prx start=0x00196cf4 end=0x00196dd8 symbol=FUN_00196cf4 lang=c++ */
/* Clone of src/eboot/ctor_test_record_0018a5a8.cpp (hstclone.py tag c064507): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern "C" char DAT_003b2408;
extern "C" void *DAT_00388174;
extern "C" char DAT_00388178;
extern "C" char DAT_0038817c;

extern "C" void FUN_0010873c(void *);
extern "C" void FUN_00196e34(void *);
extern "C" void FUN_00197158(void *, int);
extern "C" void FUN_000143b0(void *, void *);
extern "C" void FUN_0019709c(void *, void *);
extern "C" void FUN_001970ac(void *, void *, int);

extern "C" void *FUN_00196cf4(char *o) {
    int i, off;
    FUN_0010873c(o);
    *(void **)o = &DAT_003b2408;
    FUN_00196e34(o);
    FUN_00197158(o, 4);
    *(int *)(o + 0x58) = 0;
    *(int *)(o + 0x5c) = 0;
    *(int *)(o + 0x60) = 0;
    *(int *)(o + 0x64) = 0;
    *(int *)(o + 0x68) = 0;
    *(void **)(o + 0x98) = DAT_00388174;
    *(char *)(o + 0x6c) = 0;
    *(char *)(o + 0x6d) = 1;
    *(char *)(o + 0x6e) = 1;
    *(char *)(o + 0x6f) = 1;
    *(char *)(o + 0x70) = 0;
    *(char *)(o + 0x71) = 0;
    for (i = 0, off = 0; i < 3; i++, off += 0x400)
        FUN_000143b0(o + off + 0x9c, &DAT_00388178);
    FUN_0019709c(o, &DAT_0038817c);
    FUN_001970ac(o, DAT_00388174, 0);
    return o;
}

// matching idiom: separate induction variables in one for header, `for (i = 0, off = 0; i < 3; i++, off += 0x400)` (off = byte offset of the 0x400-byte member array element);
// the same loop with i/off updated in the body or with `i * 0x400` colours the saved registers differently.
