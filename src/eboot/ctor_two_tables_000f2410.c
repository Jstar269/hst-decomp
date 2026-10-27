/* HSTMATCH module=EBOOT.BIN start=0x000f2410 end=0x000f2548 symbol=FUN_000f2410 lang=c99 data=0x002d79b4 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002d79b4-0x002d79e0) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
extern void FUN_00102e38(void *self);
extern void FUN_00104118(void *self, char *name, int flag);
extern void FUN_00103540(void *self, float value);
extern void FUN_001037c8(void *self, int value);
extern void *FUN_001039d8(void *self, void *src, int flag);
extern void *FUN_001026b8(void *model, char *name);
extern void FUN_000f2550(void *self);
extern char DAT_00307814[];
extern float DAT_002d6c9c;
extern char *DAT_002d78f4[];
struct Entry_000f2410 { int idx; char *name; int result; };
extern struct Entry_000f2410 DAT_002d7948[];

char *FUN_000f2410(char *self)
{
    FUN_00102e38(self);
    *(void **)self = &DAT_00307814;
    FUN_00104118(self, "data/menu/inpane/inp_ingame/inpane_sabu.lay", 0);
    FUN_00103540(self, DAT_002d6c9c);
    FUN_001037c8(self, -251);
    int i = 0;
    char **src = DAT_002d78f4;
    int off = 0;
    do {
        *(void **)(self + off + 0x54) = FUN_001039d8(self, *src, 0);
        i++;
        src++;
        off += 4;
    } while (i < 3);
    int j = 0;
    struct Entry_000f2410 *e = DAT_002d7948;
    off = 0;
    do {
        int *h = (int *)FUN_001026b8(*(void **)(self + e->idx * 4 + 0x54), e->name);
        *(void **)(self + off + 0x60) = h;
        e->result = h[9];
        j++;
        off += 4;
        e++;
    } while (j < 9);
    *(int *)(self + 0x88) = 0;
    *(int *)(self + 0x8c) = 0;
    *(int *)(self + 0x94) = 0;
    *(char *)(self + 0xa0) = 0;
    *(int *)(self + 0x98) = 0;
    *(char *)(self + 0xa1) = 0;
    *(int *)(self + 0x9c) = 0;
    *(char *)(self + 0xa2) = 0;
    *(int *)(self + 0x90) = 2;
    *(int *)(self + 0xa4) = 0;
    FUN_000f2550(self);
    return self;
}
