/* HSTMATCH module=EBOOT.BIN start=0x001e248c end=0x001e2528 symbol=FUN_001e248c lang=c++ */
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
    extern char DAT_002ebfec;
    extern char DAT_002ebc78;
    extern char DAT_002c8798;
    extern void FUN_00104118(void *, void *, int);
    extern void FUN_00103540(void *, float);
    extern void FUN_001037c8(void *, int);
    extern void FUN_00216e90(void *, void *, void *, int);
    extern void FUN_00216f14(void *, void *, void *, int);
    extern void FUN_00103628(void *, int);
    extern void FUN_00217704(void *, void *);
}

extern "C" void FUN_001e248c(Obj *p)
{
    FUN_00104118(p->f2464, &DAT_002ebfec, 0);
    FUN_00103540(p->f2464, 2900.0f);
    FUN_001037c8(p->f2464, -256);
    FUN_00216e90(&p->f2468, p->f2464, &DAT_002ebc78, 1);
    FUN_00216f14(&p->f246c, &p->f2468, &DAT_002c8798, 1);
    FUN_00103628(p->f2464, 1);
    FUN_00217704(&p->f2480, p->f2468);
}
