/* HSTMATCH module=EBOOT.BIN start=0x000ee6d4 end=0x000ee7f8 symbol=FUN_000ee6d4 lang=c99 data=0x002d6e6c */
/* Hand-written reconstruction from the disassembly (structure taken from the sibling ctor_two_tables_000f13e8.cpp); exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002d6e6c-0x002d6e97) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
extern void FUN_00102e38(void *self);
extern void FUN_00104118(void *self, char *name, int flag);
extern void FUN_00103540(void *self, float value);
extern void FUN_001037c8(void *self, int v);
extern void *FUN_001039d8(void *self, void *src, int flag);
extern void *FUN_001026b8(void *model, int name);
extern void FUN_000ffc3c(void *p, int v);
extern void FUN_000ee860(void *self);
extern char DAT_00307954[];
extern float DAT_002d6c9c;
extern char *DAT_002d6d3c[];
struct Entry_000ee6d4 { int idx; int name; int result; };
extern struct Entry_000ee6d4 DAT_002d6ddc[];

char *FUN_000ee6d4(char *self)
{
    FUN_00102e38(self);
    *(void **)self = &DAT_00307954;
    FUN_00104118(self, "data/menu/inpane/inp_replay/inp_replay.lay", 0);
    FUN_00103540(self, DAT_002d6c9c);
    FUN_001037c8(self, -251);
    int i = 0;
    char **src = DAT_002d6d3c;
    int off = 0;
    do {
        *(void **)(self + off + 0x5c) = FUN_001039d8(self, *src, 0);
        i++;
        src++;
        off += 4;
    } while (i < 5);
    int j = 0;
    struct Entry_000ee6d4 *e = DAT_002d6ddc;
    off = 0;
    do {
        char *h = (char *)FUN_001026b8(*(void **)(self + e->idx * 4 + 0x5c), e->name);
        *(void **)(self + off + 0x70) = h;
        e->result = *(int *)(h + 0x24);
        FUN_000ffc3c(*(void **)(self + off + 0x70), -250);
        j++;
        e++;
        off += 4;
    } while (j < 12);
    *(int *)(self + 0xa0) = *(int *)(*(char **)(self + 0x98) + 0x20);
    FUN_000ee860(self);
    return self;
}
