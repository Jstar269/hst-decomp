/* HSTMATCH module=EBOOT.BIN start=0x0019d02c end=0x0019d1a4 symbol=FUN_0019d02c lang=c++ */
/* Draft written 2026-10-25 from the disassembly notes this wip carried (lane dsm1, tooling repair):
   the file had no code, so the item had never reached the comparison. Plain transcription, not the
   C++ class model the notes call for; expect the residue to be the inlined member destructors. */
extern "C" {
typedef unsigned char undefined;

extern char DAT_00309230;
extern char DAT_0030926c;
extern char DAT_0034179c;
extern void * DAT_0034a81c;
extern void * DAT_0034a818;

extern int FUN_002911c0(void *);
extern void FUN_002911cc(void *);
extern void FUN_00291340();
extern void FUN_001b3e2c(void *);
extern void FUN_001b338c(void *, int);
extern void FUN_001b2c70(void *);
extern void FUN_000006e8(void *, void (*)(void));
extern void FUN_000510c0();
extern void FUN_00102ea4(void *, int);
extern void FUN_000462a0(void *, int);
extern void FUN_00004138(void *, int);
extern void __dl__FPv(void *);

struct VObj {
    virtual void Dtor(int);
};

char * FUN_0019d02c(char * param_1, int param_2)
{
    char *self;

    self = param_1;
    if (self == 0) {
        return self;
    }
    *(void **)self = &DAT_00309230;
    if (DAT_0034a81c != 0 && FUN_002911c0(DAT_0034a818) != 0) {
        FUN_002911cc(DAT_0034a818);
    }
    if (DAT_0034a81c != 0) {
        if (DAT_0034a81c != 0) {
            ((VObj *)DAT_0034a81c)->Dtor(1);
        }
        DAT_0034a81c = 0;
    }
    FUN_00291340();
    FUN_001b3e2c(&DAT_0034179c);
    FUN_001b338c(&DAT_0034179c, 0xd);
    FUN_001b2c70(&DAT_0034179c);
    if (*(void **)(self + 0x8c) != 0) {
        ((VObj *)*(void **)(self + 0x8c))->Dtor(1);
        *(void **)(self + 0x8c) = 0;
    }
    if (*(void **)(self + 0x54) != 0) {
        FUN_000006e8(*(void **)(self + 0x54), FUN_000510c0);
        *(void **)(self + 0x54) = 0;
    }
    *(void **)(self + 0xa0) = &DAT_0030926c;
    FUN_00102ea4(self + 0xa0, 0);
    FUN_000462a0(self + 0x74, -1);
    FUN_00004138(self + 0x68, 0);
    FUN_00102ea4(self, 0);
    if ((short)param_2 > 0) {
        __dl__FPv(self);
    }
    return self;
}
}  /* extern "C" */
// improved by lane dsm1 (unreviewed): no comparable result -> 76 differing words
