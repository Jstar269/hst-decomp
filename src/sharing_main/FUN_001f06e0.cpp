/* HSTMATCH module=hstp_trans_main.prx start=0x001f06e0 end=0x001f077c symbol=FUN_001f06e0 lang=c++ */
/* Clone of src/eboot/FUN_001e248c.cpp (hstclone.py tag c155507): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Hand-written from the disassembly; exact match verified. Names and types await human review. */
/* Matching idiom: the seventh call's second argument is the VALUE of the pointer field at +0x2468
   (the earlier calls take its address), which is what makes the last argument setup `lw a1,9320(s0)` +
   `addiu a0,s0,9344` in the jal delay slot. */
struct Obj {
    char pad0[0x2464];
    void *f2464;                    /* 0x2464 */
    void *f2468;                    /* 0x2468 */
    void *f246c;                    /* 0x246c */
    char pad1[0x2480 - 0x2470];
    char f2480[0x100];              /* 0x2480 */              /* 0x2480 */
};

extern "C" {
    extern char DAT_00393f04;
    extern char DAT_00393b84;
    extern char DAT_002d8bd8;
    extern void FUN_00109a44(void *, void *, int);
    extern void FUN_00108e6c(void *, float);
    extern void FUN_001090f4(void *, int);
    extern void FUN_00225e94(void *, void *, void *, int);
    extern void FUN_00225f18(void *, void *, void *, int);
    extern void FUN_00108f54(void *, int);
    extern void FUN_002267ac(void *, void *);
}

extern "C" void FUN_001f06e0(Obj *p)
{
    FUN_00109a44(p->f2464, &DAT_00393f04, 0);
    FUN_00108e6c(p->f2464, 2900.0f);
    FUN_001090f4(p->f2464, -256);
    FUN_00225e94(&p->f2468, p->f2464, &DAT_00393b84, 1);
    FUN_00225f18(&p->f246c, &p->f2468, &DAT_002d8bd8, 1);
    FUN_00108f54(p->f2464, 1);
    FUN_002267ac(&p->f2480, p->f2468);
}
