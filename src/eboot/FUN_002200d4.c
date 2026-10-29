/* HSTMATCH module=EBOOT.BIN start=0x002200d4 end=0x002201d4 symbol=FUN_002200d4 lang=c99 data=0x002f0b54 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002f0b54-0x002f0b7c) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
extern void FUN_00102e38(void *self);
extern void FUN_00104118(void *self, const char *name, int flag);
extern void FUN_00103540(void *self, float value);
extern void FUN_001037c8(void *self, int mode);
extern void *FUN_001039d8(void *self, void *src, int flag);
extern void *FUN_001026b8(void *model, const char *name);
extern void FUN_00220338(void *self);
extern char DAT_003096e4[];
extern char DAT_002f0b14[];
/* Table row: index of the source object to search, the name to look up, and where the result word is stored. */
struct Entry_002200d4 { int idx; const char *name; int result; };
extern struct Entry_002200d4 DAT_002f0b28[3];
#define ENTRY_COUNT 3 /* rows in the lookup table */

/* Constructor of a layout pane: loads its layout file, resolves the named parts through the table and
   leaves the timer idle. */
void *FUN_002200d4(void *self)
{
    int *words = (int *)self; /* the object viewed as an array of words */
    FUN_00102e38(self);
    *(void **)self = &DAT_003096e4;
    words[0x1c] = 0;
    FUN_00104118(self, "data/menu/lobby/lobby_add/addlayout.lay", 0);
    FUN_00103540(self, 1110.0f);
    FUN_001037c8(self, 18);
    {
    void **src = (void **)&DAT_002f0b14;
    int j;
    for (j = 0; j < 1; j++) {}
    words[0x18] = (int)FUN_001039d8(self, *src, 0);
    }
#pragma opt_strength_reduction off
    int i = 0;
    struct Entry_002200d4 *entry = DAT_002f0b28;
    int off = 0;
    do {
        int *part = (int *)FUN_001026b8((void *)words[0x18 + entry->idx], entry->name);
        *(int *)((int)self + off + 100) = (int)part;
        entry->result = part[9];
        i++;
        off += 4;
        entry++;
    } while (i < ENTRY_COUNT);
    words[0x17] = -1; /* timer: idle */
    *((char *)self + 0x74) = 0;
    FUN_00220338(self);
    return self;
}
