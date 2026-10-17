/* HSTMATCH module=hstp_trans_main.prx start=0x000d8c34 end=0x000d8d50 symbol=FUN_000d8c34 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Sub { char b[1]; };
struct Slot {
    char pad0[0x50];
    Sub sub;
    char pad1[0x7f];
    float fd0;
    char pad2[0x80];
    float f154;
    char pad3[0x58];
};
struct Ref {
    char pad0[0x41c];
    int f41c;
    char pad1[0x19c];
    int f5bc;
};
struct Root { char pad[0x70]; Ref *refs[4]; };

extern Root *DAT_003e19f0;
extern float DAT_003ea654;
extern "C" void FUN_00059c1c(float, Sub *, int);
extern "C" void FUN_0005ff00(float, Sub *);
extern "C" void FUN_00059b34(float, Sub *, int);
extern "C" void FUN_00055be8(Sub *, void *);
extern "C" void FUN_00059e58(Sub *);
extern "C" void FUN_0005fec8(Sub *);
extern "C" void *FUN_0009575c(int);

extern "C" void FUN_000d8c34(Slot *e)
{
    int i = 0;
    int off = 0;
    Slot *p = e;
    Ref *pl;
    do {
        pl = *(Ref **)((char *)DAT_003e19f0 + off + 0x70);
        if (pl != 0) {
            float r = (float)pl->f41c / DAT_003ea654;
            if (r == 0.0f) {
                FUN_00059c1c(0.0f, &p->sub, -1);
                FUN_0005ff00(0.0f, &p->sub);
                FUN_00059b34(0.0f, &p->sub, -1);
            } else if (r == 1.0f) {
                FUN_00059b34(33.0f, &p->sub, -1);
            }
            FUN_00055be8(&p->sub, FUN_0009575c(pl->f5bc));
            FUN_00059e58(&p->sub);
            FUN_0005fec8(&p->sub);
            p->fd0 = p->f154;
        }
        i++;
        off += 4;
        p++;
    } while (i < 4);
}
