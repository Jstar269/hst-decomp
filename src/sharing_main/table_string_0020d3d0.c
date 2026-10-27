/* HSTMATCH module=hstp_trans_main.prx start=0x0020d3d0 end=0x0020d484 symbol=FUN_0020d3d0 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* String for n rounded down to a multiple of ten from the table of resource 0x12 (FUN_001991d4): one of three
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

extern Res *FUN_001991d4(int id);
extern char DAT_002d10cc[];
extern char DAT_002d10d0[];
extern char DAT_002d10d4[];

char *FUN_0020d3d0(int n)
{
    int idx = n / 10 * 10;
    Res *r = FUN_001991d4(0x12);
    if (r->f4 == 0) return DAT_002d10d4;
    if (r->f8->v < 26) return DAT_002d10d0;
    if (idx < 0 || idx >= r->fc->count) return DAT_002d10cc;
    return r->fc->items[idx];
}
