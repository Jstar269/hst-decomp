/* HSTMATCH module=EBOOT.BIN start=0x000bd378 end=0x000bd480 symbol=FUN_000bd378 lang=c++ data=0x002d5458 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string literals (2 strings, 0x002d5458-0x002d5495) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
extern "C" {
extern void FUN_000ba3ac(...);
}
struct VC_0 { virtual ~VC_0(); };
struct Rec {
    int vt;
    int a;
    int b;
    int c;
    unsigned char d;
};
extern "C" void *FUN_00000bcc(unsigned);
extern char DAT_003073e4;
struct Obj {
    char pad0[0x198];
    int cur;
    char pad1[0x40];
    VC_0 *slots[8];
};

extern "C" int FUN_000bd378(Obj *self, int param_2, int param_3)
{
    if (self->cur < 0) {
        FUN_000ba3ac("CreateCHMasterObj() failed.\n");
        return 0;
    }
    VC_0 *p = self->slots[self->cur];
    if (p) {
        delete p;
        self->slots[self->cur] = 0;
    }
    int *r = (int *)FUN_00000bcc(0x14);
    if (r) {
        r[0] = (int)&DAT_003073e4;
        r[2] = 0;
        r[1] = 0;
        r[3] = 0;
        *(unsigned char *)(r + 4) = 0;
    }
    self->slots[self->cur] = (VC_0 *)r;
    ((int *)self->slots[self->cur])[3] = param_3;
    ((int *)self->slots[self->cur])[1] = param_2;
    FUN_000ba3ac("CreateCHMasterObj() success\n");
    return 1;
}
