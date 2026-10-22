/* HSTMATCH module=hstp_trans_main.prx start=0x001eb4b0 end=0x001eb594 symbol=FUN_001eb4b0 lang=c++ */
/* Clone of src/eboot/ctor_main_result_001dd28c.cpp (hstclone.py tag fm1): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* matching idiom: the global read of DAT_00393960 uses an empty loop as the join that makes MWCC keep
   the address unfolded (retail: lui v0,hi ; addiu v0,v0,lo ; lw a1,0(v0)). */

typedef struct { int idx; int name; int out; } Rec;

extern "C" Rec DAT_00393974[];
extern "C" void *DAT_00393960;
extern "C" char DAT_0039398c;
extern "C" char DAT_003b270c;

extern "C" void FUN_0010873c();
extern "C" void FUN_00109a44(void *, void *, int);
extern "C" void FUN_00108e6c(void *, float);
extern "C" void *FUN_00109304(void *, void *, int);
extern "C" void *FUN_00108124(void *, void *);

extern "C" void *FUN_001eb4b0(char *o) {
    int i;
    Rec *r;
    int off;
    FUN_0010873c();
    *(void **)o = &DAT_003b270c;
    FUN_00109a44(o, &DAT_0039398c, 0);
    FUN_00108e6c(o, 5000.0f);
    void **gp = &DAT_00393960;
    for (int i = 0; i < 0; i++) { }
    *(void **)(o + 0x58) = FUN_00109304(o, *gp, 0);
    i = 0;
    r = DAT_00393974;
    off = 0;
    do {
        void *q = FUN_00108124(*(void **)(o + 0x58 + r->idx * 4), (void *)r->name);
        *(void **)(o + 0x5c + off) = q;
        r->out = *(int *)((char *)q + 0x24);
        i = i + 1;
        off = off + 4;
        r++;
    } while (i < 2);
    *(int *)(o + 0x54) = 5;
    return o;
}
