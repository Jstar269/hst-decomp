/* HSTMATCH module=hstp_trans_main.prx start=0x00230474 end=0x00230588 symbol=FUN_00230474 lang=c99 */
/* Clone of src/eboot/ctor_tables_00220f00.c (hstclone.py tag ds1011s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern void FUN_0010873c(void *self);
extern void FUN_00109a44(void *self, char *name, int flag);
extern void FUN_00108e6c(void *self, float value);
extern void *FUN_00109304(void *self, void *src, int flag);
extern void *FUN_00108124(void *model, char *name);
extern void FUN_002307d4(void *self);
extern char DAT_003b2970[];
extern char DAT_003990e0[];
extern float DAT_00398354;
extern char *DAT_0039900c[];
struct Entry_00230474 { int idx; char *name; int result; };
extern struct Entry_00230474 DAT_0039906c[];

char *FUN_00230474(char *self)
{
    FUN_0010873c(self);
    *(void **)self = &DAT_003b2970;
    FUN_00109a44(self, DAT_003990e0, 0);
    FUN_00108e6c(self, DAT_00398354);
    int i = 0;
    char **src = DAT_0039900c;
    int off = 0;
    do {
        *(void **)(self + off + 0x64) = FUN_00109304(self, *src, 0);
        i++;
        src++;
        off += 4;
    } while (i < 5);
    int j = 0;
    struct Entry_00230474 *e = DAT_0039906c;
    off = 0;
    do {
        int *h = (int *)FUN_00108124(*(void **)(self + e->idx * 4 + 0x64), e->name);
        *(void **)(self + off + 0x78) = h;
        e->result = h[9];
        j++;
        off += 4;
        e++;
    } while (j < 9);
    *(int *)(self + 0x60) = -1;
    *(int *)(self + 0x54) = -999;
    *(char *)(self + 0x9c) = 0;
    FUN_002307d4(self);
    return self;
}
