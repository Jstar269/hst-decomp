/* HSTMATCH module=hstp_trans_main.prx start=0x002bd6ec end=0x002bd7ec symbol=FUN_002bd6ec lang=c99 */
/* Hand-written reconstruction (port of src/eboot/find_max_cell_002adec4.c, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. */

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

extern void *FUN_00089f84(int x);
extern int DAT_003e19f0;
extern char *DAT_003ea8e8;
extern struct Row DAT_003eaaf0[];

int FUN_002bd6ec(int *outRow, int *outCol)
{
    struct Cfg *cfg = FUN_00089f84(DAT_003e19f0);
    struct Row *row = &DAT_003eaaf0[cfg->idx];
    short skipRow = row->skipRow;
    short skipCol = row->skipCol;
    unsigned short *base = (unsigned short *)(DAT_003ea8e8 + 0x87128);
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
