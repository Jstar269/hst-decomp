/* HSTMATCH module=EBOOT.BIN start=0x002adec4 end=0x002adfc4 symbol=FUN_002adec4 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

struct Row {
    char pad0[0x18];
    short skipRow;
    char pad1[0x22 - 0x1a];
    short skipCol;
    char pad2[288 - 0x24];
};

struct Cfg {
    char pad0[0x148];
    int idx;
};

extern void *FUN_0008882c(int x);
extern int DAT_003386b0;
extern char *DAT_003415a8;
extern struct Row DAT_003417b8[];

int FUN_002adec4(int *outRow, int *outCol)
{
    struct Cfg *cfg = FUN_0008882c(DAT_003386b0);
    struct Row *row = &DAT_003417b8[cfg->idx];
    short skipRow = row->skipRow;
    short skipCol = row->skipCol;
    unsigned short *base = (unsigned short *)(DAT_003415a8 + 0x87128);
    unsigned short *p;
    int bestRow = 0;
    int bestCol = 0;
    unsigned short best = 0;
    unsigned short v;
    int i;
    int j;

    for (i = 0; i < 15; i++) {
        p = base + i * 640;
        for (j = 0; j < 640; j++) {
            v = p[54 + j];
            if (i == skipRow && j == skipCol) {
                v = (v < 0xffff) ? v + 1 : v;
            }
            if (best < v) {
                best = v;
                bestRow = i;
                bestCol = j;
            }
        }
    }
    *outRow = bestRow;
    *outCol = bestCol;
    return best;
}
