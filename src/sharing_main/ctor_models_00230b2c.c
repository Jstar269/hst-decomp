/* HSTMATCH module=hstp_trans_main.prx start=0x00230b2c end=0x00230c38 symbol=FUN_00230b2c lang=c99 */
/* Clone of src/eboot/ctor_models_002215b8.c (hstclone.py tag ds1011s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern void FUN_0010873c(void *self);
extern void FUN_00109a44(void *self, char *name, int flag);
extern void FUN_00108e6c(void *self, float value);
extern void *FUN_00109304(void *self, void *src, int flag);
extern void *FUN_00108124(void *model, char *name);
extern void FUN_00230d2c(void *self);
extern char DAT_003b2950[];
extern char DAT_00399168[];
extern float DAT_00398354;
extern char *DAT_00399128[];
struct Entry_00230b2c { int idx; char *name; int result; };
extern struct Entry_00230b2c DAT_0039913c[];

char *FUN_00230b2c(char *self)
{
    FUN_0010873c(self);
    *(void **)self = &DAT_003b2950;
    FUN_00109a44(self, DAT_00399168, 0);
    FUN_00108e6c(self, DAT_00398354);
    int i = 0;
    char **src = DAT_00399128;
    int off = 0;
    do {
        *(void **)(self + off + 0x60) = FUN_00109304(self, *src, 0);
        i++;
        src++;
        off += 4;
    } while (i < 2);
    int j = 0;
    struct Entry_00230b2c *e = DAT_0039913c;
    off = 0;
    do {
        int *h = (int *)FUN_00108124(*(void **)(self + e->idx * 4 + 0x60), e->name);
        *(void **)(self + off + 0x68) = h;
        e->result = h[9];
        j++;
        off += 4;
        e++;
    } while (j < 3);
    *(int *)(self + 0x5c) = -1;
    *(char *)(self + 0x74) = 0;
    FUN_00230d2c(self);
    return self;
}
