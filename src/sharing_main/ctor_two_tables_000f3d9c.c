/* HSTMATCH module=hstp_trans_main.prx start=0x000f3d9c end=0x000f3ec0 symbol=FUN_000f3d9c lang=c99 data=0x0037dc44 */
/* Clone of src/eboot/ctor_two_tables_000ee6d4.c (hstclone.py tag c21sn4s): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x0037dc44-0x0037dc6f) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Hand-written reconstruction from the disassembly (structure taken from the sibling ctor_two_tables_000f13e8.cpp); exact match verified; names and types await human review. */
extern void FUN_0010873c(void *self);
extern void FUN_00109a44(void *self, char *name, int flag);
extern void FUN_00108e6c(void *self, float value);
extern void FUN_001090f4(void *self, int v);
extern void *FUN_00109304(void *self, void *src, int flag);
extern void *FUN_00108124(void *model, int name);
extern void FUN_00105570(void *p, int v);
extern void FUN_000f3f28(void *self);
extern char DAT_003b0c20[];
extern float DAT_0037da74;
extern char *DAT_0037db14[];
struct Entry_000f3d9c { int idx; int name; int result; };
extern struct Entry_000f3d9c DAT_0037dbb4[];

char *FUN_000f3d9c(char *self)
{
    FUN_0010873c(self);
    *(void **)self = &DAT_003b0c20;
    FUN_00109a44(self, "data/menu/inpane/inp_replay/inp_replay.lay", 0);
    FUN_00108e6c(self, DAT_0037da74);
    FUN_001090f4(self, -251);
    int i = 0;
    char **src = DAT_0037db14;
    int off = 0;
    do {
        *(void **)(self + off + 0x5c) = FUN_00109304(self, *src, 0);
        i++;
        src++;
        off += 4;
    } while (i < 5);
    int j = 0;
    struct Entry_000f3d9c *e = DAT_0037dbb4;
    off = 0;
    do {
        char *h = (char *)FUN_00108124(*(void **)(self + e->idx * 4 + 0x5c), e->name);
        *(void **)(self + off + 0x70) = h;
        e->result = *(int *)(h + 0x24);
        FUN_00105570(*(void **)(self + off + 0x70), -250);
        j++;
        e++;
        off += 4;
    } while (j < 12);
    *(int *)(self + 0xa0) = *(int *)(*(char **)(self + 0x98) + 0x20);
    FUN_000f3f28(self);
    return self;
}
