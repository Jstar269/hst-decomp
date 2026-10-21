/* HSTMATCH module=EBOOT.BIN start=0x00220f00 end=0x00221014 symbol=FUN_00220f00 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern void FUN_00102e38(void *self);
extern void FUN_00104118(void *self, char *name, int flag);
extern void FUN_00103540(void *self, float value);
extern void *FUN_001039d8(void *self, void *src, int flag);
extern void *FUN_001026b8(void *model, char *name);
extern void FUN_00221260(void *self);
extern char DAT_003096a4[];
extern char DAT_002f0d14[];
extern float DAT_002eff88;
extern char *DAT_002f0c40[];
struct Entry_00220f00 { int idx; char *name; int result; };
extern struct Entry_00220f00 DAT_002f0ca0[];

char *FUN_00220f00(char *self)
{
    FUN_00102e38(self);
    *(void **)self = &DAT_003096a4;
    FUN_00104118(self, DAT_002f0d14, 0);
    FUN_00103540(self, DAT_002eff88);
    int i = 0;
    char **src = DAT_002f0c40;
    int off = 0;
    do {
        *(void **)(self + off + 0x64) = FUN_001039d8(self, *src, 0);
        i++;
        src++;
        off += 4;
    } while (i < 5);
    int j = 0;
    struct Entry_00220f00 *e = DAT_002f0ca0;
    off = 0;
    do {
        int *h = (int *)FUN_001026b8(*(void **)(self + e->idx * 4 + 0x64), e->name);
        *(void **)(self + off + 0x78) = h;
        e->result = h[9];
        j++;
        off += 4;
        e++;
    } while (j < 9);
    *(int *)(self + 0x60) = -1;
    *(int *)(self + 0x54) = -999;
    *(char *)(self + 0x9c) = 0;
    FUN_00221260(self);
    return self;
}
