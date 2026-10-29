/* HSTMATCH module=EBOOT.BIN start=0x00220f00 end=0x00221014 symbol=FUN_00220f00 lang=c99 data=0x002f0d14 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002f0d14-0x002f0d3d) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
extern void FUN_00102e38(void *self);
extern void FUN_00104118(void *self, char *name, int flag);
extern void FUN_00103540(void *self, float value);
extern void *FUN_001039d8(void *self, void *src, int flag);
extern void *FUN_001026b8(void *model, char *name);
extern void FUN_00221260(void *self);
extern char DAT_003096a4[];
extern float DAT_002eff88;
extern char *DAT_002f0c40[];
#define PANE_COUNT 5  /* sub-panes created from the first table */
#define ENTRY_COUNT 9 /* named parts looked up in the second table */

/* Table row: index of the sub-pane to search, the part name, and where the part's result word is stored. */
struct Entry_00220f00 { int idx; char *name; int result; };
extern struct Entry_00220f00 DAT_002f0ca0[];

/* Constructor of a layout pane: loads its layout file, creates the sub-panes, resolves the named parts
   through the table and clears its selection. */
char *FUN_00220f00(char *self)
{
    FUN_00102e38(self);
    *(void **)self = &DAT_003096a4;
    FUN_00104118(self, "data/menu/lobby/lobbyinpane/golayout.lay", 0);
    FUN_00103540(self, DAT_002eff88);
    int i = 0;
    char **name = DAT_002f0c40;
    int off = 0;
    do {
        *(void **)(self + off + 0x64) = FUN_001039d8(self, *name, 0);
        i++;
        name++;
        off += 4;
    } while (i < PANE_COUNT);
    int j = 0;
    struct Entry_00220f00 *entry = DAT_002f0ca0;
    off = 0;
    do {
        int *part = (int *)FUN_001026b8(*(void **)(self + entry->idx * 4 + 0x64), entry->name);
        *(void **)(self + off + 0x78) = part;
        entry->result = part[9];
        j++;
        off += 4;
        entry++;
    } while (j < ENTRY_COUNT);
    *(int *)(self + 0x60) = -1;
    *(int *)(self + 0x54) = -999;
    *(char *)(self + 0x9c) = 0;
    FUN_00221260(self);
    return self;
}
