/* HSTMATCH module=hstp_trans_main.prx start=0x0022f648 end=0x0022f748 symbol=FUN_0022f648 lang=c99 data=0x00398f20 */
/* Clone of src/eboot/FUN_002200d4.c (hstclone.py tag c25unfold): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x00398f20-0x00398f48) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern void FUN_0010873c(void *self);
extern void FUN_00109a44(void *self, const char *name, int flag);
extern void FUN_00108e6c(void *self, float value);
extern void FUN_001090f4(void *self, int mode);
extern void *FUN_00109304(void *self, void *src, int flag);
extern void *FUN_00108124(void *model, const char *name);
extern void FUN_0022f8ac(void *self);
extern char DAT_003b29b0[];
extern char DAT_00398ee0[];
struct Entry_0022f648 { int idx; const char *name; int result; };
extern struct Entry_0022f648 DAT_00398ef4[3];
struct Obj_0022f648 { int pad[9]; int f24; };
void *FUN_0022f648(void *self)
{
    int *p = (int *)self;
    FUN_0010873c(self);
    *(void **)self = &DAT_003b29b0;
    p[0x1c] = 0;
    FUN_00109a44(self, "data/menu/lobby/lobby_add/addlayout.lay", 0);
    FUN_00108e6c(self, 1110.0f);
    FUN_001090f4(self, 18);
    {
    void **pq = (void **)&DAT_00398ee0;
    int j;
    for (j = 0; j < 1; j++) {}
    p[0x18] = (int)FUN_00109304(self, *pq, 0);
    }
#pragma opt_strength_reduction off
    int i = 0;
    struct Entry_0022f648 *e = DAT_00398ef4;
    int off = 0;
    do {
        int *h = (int *)FUN_00108124((void *)p[0x18 + e->idx], e->name);
        *(int *)((int)self + off + 100) = (int)h;
        e->result = h[9];
        i++;
        off += 4;
        e++;
    } while (i < 3);
    p[0x17] = -1;
    *((char *)self + 0x74) = 0;
    FUN_0022f8ac(self);
    return self;
}
// NEAR MISS: 63/64 words - one word short, everything else word-for-word exact.
// Only difference: retail materialises the global at 0x398ee0 with `lui; addiu v0,0x2f,0xb14; lw a1,0(v0)`,
// ours folds it to `lui v0,0x2f; lw a1,0xb14(v0)`. Ruled out: char[]/void*/volatile void*, local void**,
// int-cast address forms (all fold). Loop needed #pragma opt_strength_reduction off.
// LATER (ds11-00): best is now 64/64 words, 3 differing words, with `extern char **DAT_00398ee0;
// ... *DAT_00398ee0` -- mwcc then emits `lw v0,0xb14(v0); lw a1,0(v0)` (a real double dereference)
// where retail emits `addiu v0,v0,0xb14; lw a1,0(v0)`. Every address-taking spelling folds back to
// `lui; lw a1,0xb14(v0)` (63 words): char[]/void*[]/char*[]/char*const[] array forms, `char *const`
// and `volatile char *` globals, `char **slot = &DAT` local, unsigned-cast address, `*(char**)&DAT`,
// a struct with the pointer as its first member (4-byte and 16-byte), and a C++ reference local.
// So retail's addiu form is NOT reachable from any source spelling tried; open question.
