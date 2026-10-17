/* HSTMATCH module=EBOOT.BIN start=0x0017d7ac end=0x0017d880 symbol=FUN_0017d7ac lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct VC { virtual void s0(); virtual void s1(); };
struct Slot { char pad0[0x10]; VC sub; };
struct Mgr { char pad0[8]; Slot **list; };
extern "C" {
int FUN_001fe984(void *, int, int);
void FUN_000931ec(void *, int, unsigned char *, int);
float FUN_0017dab8(Mgr *, int);
void FUN_00093484(float, void *);
}
extern "C" void FUN_0017d7ac(Mgr *self, int idx, unsigned char c1, unsigned char c2, int extra)
{
    if (FUN_001fe984((char *)self + 0x2e4, idx, 0) == 0) {
        unsigned char arr[2] = { c1, c2 };
        Slot *s = self->list[idx];
        FUN_000931ec(&s->sub, 1, arr, extra);
        FUN_00093484(FUN_0017dab8(self, idx), &s->sub);
        s->sub.s1();
    }
}
