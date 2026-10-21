/* HSTMATCH module=hstp_trans_main.prx start=0x0022c5a0 end=0x0022c6d0 symbol=FUN_0022c5a0 lang=c99 */
/* Clone of src/eboot/ctor_parts_lobby_0021d02c.c (hstclone.py tag c21sn35s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Same shape as src/eboot/ctor_models_002215b8.c (used as the template): base ctor, vtable-ish pointer, layout load, 3 widget lookups and 9 model lookups with byte-offset induction variables. */
extern void FUN_0010873c(void *self);
extern void FUN_00109a44(void *self, char *name, int flag);
extern void FUN_00108e6c(float value, void *self);
extern void *FUN_00109304(void *self, void *src, int flag);
extern void *FUN_00108124(void *model, char *name);
extern void FUN_0022c8b4(void *self, int flag);
extern void FUN_0022c934(void *self);
extern char DAT_003b2a30[];
extern char DAT_003989c4[];
extern float DAT_00398354;
extern char *DAT_00398920[];
struct Entry_0022c5a0 { int idx; char *name; int result; };
extern struct Entry_0022c5a0 DAT_00398948[];

char *FUN_0022c5a0(char *self)
{
    FUN_0010873c(self);
    *(void **)self = &DAT_003b2a30;
    FUN_00109a44(self, DAT_003989c4, 0);
    FUN_00108e6c(10.0f + DAT_00398354, self);
    int i = 0;
    char **src = DAT_00398920;
    int off = 0;
    do {
        *(void **)(self + off + 0x70) = FUN_00109304(self, *src, 0);
        i++;
        src++;
        off += 4;
    } while (i < 3);
    int j = 0;
    struct Entry_0022c5a0 *e = DAT_00398948;
    off = 0;
    do {
        int *h = (int *)FUN_00108124(*(void **)(self + e->idx * 4 + 0x70), e->name);
        *(void **)(self + off + 0x7c) = h;
        e->result = h[9];
        j++;
        off += 4;
        e++;
    } while (j < 9);
    *(int *)(self + 0x5c) = 0;
    *(int *)(self + 0x60) = 0;
    *(int *)(self + 0x64) = -1;
    *(char *)(self + 0xa0) = 0;
    *(int *)(self + 0x6c) = -1;
    FUN_0022c8b4(self, 0);
    FUN_0022c934(self);
    return self;
}
