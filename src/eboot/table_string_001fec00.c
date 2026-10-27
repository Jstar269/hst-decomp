/* HSTMATCH module=EBOOT.BIN start=0x001fec00 end=0x001fecb4 symbol=FUN_001fec00 lang=c99 */
/* Clone of src/sharing_main/table_string_0020d3d0.c (hstclone.py tag a0db26EBhs): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* String for n rounded down to a multiple of ten from the table of resource 0x12 (FUN_0018c9f4): one of three
   distinct empty strings when the resource is not loaded (f4 == 0), its header value at +8 is below 26, or the
   index is out of range. Retail has three separate "" objects in reverse use order (MWCC pools identical
   literals), so they are referenced through their address symbols. */
typedef struct Tab {
    char pad[0x12c];
    char **items;
    int count;
} Tab;

typedef struct Ver {
    char pad[8];
    int v;
} Ver;

typedef struct Res {
    int f0;
    int f4;
    Ver *f8;
    Tab *fc;
} Res;

extern Res *FUN_0018c9f4(int id);
extern char DAT_002c0e18[];
extern char DAT_002c0e1c[];
extern char DAT_002c0e20[];

char *FUN_001fec00(int n)
{
    int idx = n / 10 * 10;
    Res *r = FUN_0018c9f4(0x12);
    if (r->f4 == 0) return DAT_002c0e20;
    if (r->f8->v < 26) return DAT_002c0e1c;
    if (idx < 0 || idx >= r->fc->count) return DAT_002c0e18;
    return r->fc->items[idx];
}
