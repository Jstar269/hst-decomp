/* HSTMATCH module=hstp_trans_main.prx start=0x000f5be4 end=0x000f5d0c symbol=FUN_000f5be4 lang=c99 */
/* Clone of src/eboot/ctor_two_tables_000f051c.c (hstclone.py tag c21sn2s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern void FUN_0010873c(void *self);
extern void FUN_00109a44(void *self, char *name, int flag);
extern void FUN_00108e6c(void *self, float value);
extern void FUN_001090f4(void *self, int value);
extern void *FUN_00109304(void *self, void *src, int flag);
extern void *FUN_00108124(void *model, char *name);
extern void FUN_000f6000(void *self);
extern char DAT_003b0b80[];
extern char DAT_0037e200[];
extern float DAT_0037da74;
extern char *DAT_0037e1b4[];
struct Entry_000f5be4 { int idx; char *name; int result; };
extern struct Entry_000f5be4 DAT_0037e1d0[];

char *FUN_000f5be4(char *self)
{
    FUN_0010873c(self);
    *(void **)self = &DAT_003b0b80;
    FUN_00109a44(self, DAT_0037e200, 0);
    FUN_00108e6c(self, DAT_0037da74);
    FUN_001090f4(self, -251);
    int i = 0;
    char **src = DAT_0037e1b4;
    int off = 0;
    do {
        *(void **)(self + off + 0x58) = FUN_00109304(self, *src, 0);
        i++;
        src++;
        off += 4;
    } while (i < 2);
    int j = 0;
    struct Entry_000f5be4 *e = DAT_0037e1d0;
    off = 0;
    do {
        int *h = (int *)FUN_00108124(*(void **)(self + e->idx * 4 + 0x58), e->name);
        *(void **)(self + off + 0x60) = h;
        e->result = h[9];
        *(float *)(self + off + 0x70) = (float)*(short *)(*(int *)(self + off + 0x60) + 6);
        j++;
        off += 4;
        e++;
    } while (j < 4);
    FUN_000f6000(self);
    *(int *)(self + 0x80) = 0x3f800000;
    return self;
}
