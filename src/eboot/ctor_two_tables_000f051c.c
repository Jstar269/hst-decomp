/* HSTMATCH module=EBOOT.BIN start=0x000f051c end=0x000f0644 symbol=FUN_000f051c lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern void FUN_00102e38(void *self);
extern void FUN_00104118(void *self, char *name, int flag);
extern void FUN_00103540(void *self, float value);
extern void FUN_001037c8(void *self, int value);
extern void *FUN_001039d8(void *self, void *src, int flag);
extern void *FUN_001026b8(void *model, char *name);
extern void FUN_000f0938(void *self);
extern char DAT_003078b4[];
extern char DAT_002d7428[];
extern float DAT_002d6c9c;
extern char *DAT_002d73dc[];
struct Entry_000f051c { int idx; char *name; int result; };
extern struct Entry_000f051c DAT_002d73f8[];

char *FUN_000f051c(char *self)
{
    FUN_00102e38(self);
    *(void **)self = &DAT_003078b4;
    FUN_00104118(self, DAT_002d7428, 0);
    FUN_00103540(self, DAT_002d6c9c);
    FUN_001037c8(self, -251);
    int i = 0;
    char **src = DAT_002d73dc;
    int off = 0;
    do {
        *(void **)(self + off + 0x58) = FUN_001039d8(self, *src, 0);
        i++;
        src++;
        off += 4;
    } while (i < 2);
    int j = 0;
    struct Entry_000f051c *e = DAT_002d73f8;
    off = 0;
    do {
        int *h = (int *)FUN_001026b8(*(void **)(self + e->idx * 4 + 0x58), e->name);
        *(void **)(self + off + 0x60) = h;
        e->result = h[9];
        *(float *)(self + off + 0x70) = (float)*(short *)(*(int *)(self + off + 0x60) + 6);
        j++;
        off += 4;
        e++;
    } while (j < 4);
    FUN_000f0938(self);
    *(int *)(self + 0x80) = 0x3f800000;
    return self;
}
