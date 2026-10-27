/* HSTMATCH module=EBOOT.BIN start=0x0021d02c end=0x0021d15c symbol=FUN_0021d02c lang=c99 data=0x002f05f8 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002f05f8-0x002f0615) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Same shape as src/eboot/ctor_models_002215b8.c (used as the template): base ctor, vtable-ish pointer, layout load, 3 widget lookups and 9 model lookups with byte-offset induction variables. */
extern void FUN_00102e38(void *self);
extern void FUN_00104118(void *self, char *name, int flag);
extern void FUN_00103540(float value, void *self);
extern void *FUN_001039d8(void *self, void *src, int flag);
extern void *FUN_001026b8(void *model, char *name);
extern void FUN_0021d340(void *self, int flag);
extern void FUN_0021d3c0(void *self);
extern char DAT_00309764[];
extern float DAT_002eff88;
extern char *DAT_002f0554[];
struct Entry_0021d02c { int idx; char *name; int result; };
extern struct Entry_0021d02c DAT_002f057c[];

char *FUN_0021d02c(char *self)
{
    FUN_00102e38(self);
    *(void **)self = &DAT_00309764;
    FUN_00104118(self, "data/menu/parts/partslay.lay", 0);
    FUN_00103540(10.0f + DAT_002eff88, self);
    int i = 0;
    char **src = DAT_002f0554;
    int off = 0;
    do {
        *(void **)(self + off + 0x70) = FUN_001039d8(self, *src, 0);
        i++;
        src++;
        off += 4;
    } while (i < 3);
    int j = 0;
    struct Entry_0021d02c *e = DAT_002f057c;
    off = 0;
    do {
        int *h = (int *)FUN_001026b8(*(void **)(self + e->idx * 4 + 0x70), e->name);
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
    FUN_0021d340(self, 0);
    FUN_0021d3c0(self);
    return self;
}
