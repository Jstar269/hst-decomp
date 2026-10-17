/* HSTMATCH module=hstp_trans_main.prx start=0x00189ea0 end=0x00189f74 symbol=FUN_00189ea0 lang=c++ */
/* Clone of src/eboot/slot_trigger_0017d7ac.cpp (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct VC { virtual void s0(); virtual void s1(); };
struct Slot { char pad0[0x10]; VC sub; };
struct Mgr { char pad0[8]; Slot **list; };
extern "C" {
int FUN_0020d154(void *, int, int);
void FUN_00095080(void *, int, unsigned char *, int);
float FUN_0018a1ac(Mgr *, int);
void FUN_000953a8(float, void *);
}
extern "C" void FUN_00189ea0(Mgr *self, int idx, unsigned char c1, unsigned char c2, int extra)
{
    if (FUN_0020d154((char *)self + 0x2e4, idx, 0) == 0) {
        unsigned char arr[2] = { c1, c2 };
        Slot *s = self->list[idx];
        FUN_00095080(&s->sub, 1, arr, extra);
        FUN_000953a8(FUN_0018a1ac(self, idx), &s->sub);
        s->sub.s1();
    }
}
