/* HSTMATCH module=hstp_trans_main.prx start=0x000f7ad8 end=0x000f7c10 symbol=FUN_000f7ad8 lang=c99 */
/* Clone of src/eboot/ctor_two_tables_000f2410.c (hstclone.py tag c21sn2s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern void FUN_0010873c(void *self);
extern void FUN_00109a44(void *self, char *name, int flag);
extern void FUN_00108e6c(void *self, float value);
extern void FUN_001090f4(void *self, int value);
extern void *FUN_00109304(void *self, void *src, int flag);
extern void *FUN_00108124(void *model, char *name);
extern void FUN_000f7c18(void *self);
extern char DAT_003b0ae0[];
extern char DAT_0037e78c[];
extern float DAT_0037da74;
extern char *DAT_0037e6cc[];
struct Entry_000f7ad8 { int idx; char *name; int result; };
extern struct Entry_000f7ad8 DAT_0037e720[];

char *FUN_000f7ad8(char *self)
{
    FUN_0010873c(self);
    *(void **)self = &DAT_003b0ae0;
    FUN_00109a44(self, DAT_0037e78c, 0);
    FUN_00108e6c(self, DAT_0037da74);
    FUN_001090f4(self, -251);
    int i = 0;
    char **src = DAT_0037e6cc;
    int off = 0;
    do {
        *(void **)(self + off + 0x54) = FUN_00109304(self, *src, 0);
        i++;
        src++;
        off += 4;
    } while (i < 3);
    int j = 0;
    struct Entry_000f7ad8 *e = DAT_0037e720;
    off = 0;
    do {
        int *h = (int *)FUN_00108124(*(void **)(self + e->idx * 4 + 0x54), e->name);
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
    FUN_000f7c18(self);
    return self;
}
