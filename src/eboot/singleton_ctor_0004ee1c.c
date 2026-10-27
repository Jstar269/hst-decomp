/* HSTMATCH module=EBOOT.BIN start=0x0004ee1c end=0x0004ef98 symbol=FUN_0004ee1c lang=c99 data=0x002d0a74 */
/* Clone of src/sharing_main/singleton_ctor_0004f670.c (hstclone.py tag a0db26EBhs): addresses substituted; exact match verified; names and types await human review. Data: its string literals (2 strings, 0x002d0a74-0x002d0a8a) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Constructor of the singleton whose deleting dtor is src/sharing_main/deleting_dtor_0004f7ec.c: zero the
   3-word member at +0x1a0a8, stop with "already exist." when the instance flag is set, clear the tables, name
   the 576 entries ".%04d" (sprintf 0x143b0) and reset the state fields. Matching idioms: `int base = (int)self;`
   with explicit byte-offset counters (retail keeps i, i*6 and i*16 as separate induction variables and re-adds
   the base per access), and the `(unsigned int)base` cast on the second name address so it is recomputed after
   the call instead of being CSE'd into a saved register. */
typedef struct {
    int a;
    int b;
    int c;
} Sub;

typedef struct {
    char *name;
    char pad4[0x10 - 0x4];
} Entry;

typedef struct {
    char pad0[0x1fc];
    unsigned char f1fc;
    char pad1fd[0x200 - 0x1fd];
    int f200;
    Entry entries[576];
    char pad2604[0x18e04 - 0x2604];
    char names[576][6];
    char pad19b84[0x1a008 - 0x19b84];
    unsigned char f1a008;
    unsigned char f1a009;
    char pad1a00a[0x1a00c - 0x1a00a];
    int f1a00c;
    int f1a010;
    int f1a014;
    int f1a018;
    int f1a01c;
    char pad1a020[0x1a0a0 - 0x1a020];
    unsigned char f1a0a0;
    char pad1a0a1[0x1a0a4 - 0x1a0a1];
    int f1a0a4;
    Sub sub;
} Mgr;

extern unsigned char DAT_0032b230;
extern void FUN_0004ea98(const char *, ...);
extern void FUN_000114c0(void *, int, int);
extern int FUN_000143b0(char *, const char *, ...);
extern void FUN_00050bb8(Mgr *, char, char, char, char);

Mgr *FUN_0004ee1c(Mgr *self)
{
    int base = (int)self;
    int i;
    int nameOff;
    int entOff;
    Sub *s = &self->sub;

    s->a = 0;
    s->b = 0;
    s->c = 0;
    if (DAT_0032b230 != 0) {
        FUN_0004ea98("already exist.\n");
        for (;;) {
        }
    }
    DAT_0032b230 = 1;
    self->f200 = 0;
    FUN_000114c0(self->entries, 0, 0x19e04);
    for (i = 0, nameOff = 0, entOff = 0; i < 576; i++, nameOff += 6, entOff += 16) {
        /* names[i] (+0x18e04) gets ".%04d", entries[i].name (+0x204) points at it */
        FUN_000143b0((char *)(base + nameOff) + 0x18e04, ".%04d", i);
        *(char **)(base + entOff + 0x204) = (char *)((unsigned int)base + nameOff) + 0x18e04;
    }
    self->f1a008 = 1;
    self->f1a009 = 0;
    self->f1a00c = 0;
    self->f1a010 = 0;
    self->f1a014 = 0;
    self->f1a018 = 0;
    self->f1a01c = 0;
    self->f1a0a0 = 1;
    self->f1a0a4 = 0;
    self->f1fc = 1;
    FUN_00050bb8(self, 0, 0, 0, 0);
    return self;
}
