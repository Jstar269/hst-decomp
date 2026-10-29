/* HSTMATCH module=EBOOT.BIN start=0x0017b260 end=0x0017b3bc symbol=FUN_0017b260 lang=c++ */
/* LoadMenuColorCsv: generic name,R,G,B menu color files; see docs/DATA-TABLES.md */
/* Ghidra pseudocode (hstgen.py tag v0) corrected by hand: the byte-offset counter is declared before the loop index (s3/s2 order), stores go through `out[off >> 2]` (srl+sll folds to retail`s `and -4`), and range tests are `a >= 0 && a < 0x100`; readability pass; exact match verified; names and types await human review. */
#define COMPONENT_LIMIT 0x100 /* valid component values are 0..255 */

extern "C" {
extern char DAT_002e0694;
extern int FUN_000650e0(void *);
extern int FUN_00065104(void *, int, int);
extern void FUN_0006517c(void *, int, int);
extern void FUN_000651b8(void *, int, int, int, void *);
}

/* Reads the CSV rows after the header and appends every value in 0..255 of the three columns to out. */
extern "C" void FUN_0017b260(int *out, void *csv, int arg)
{
    FUN_000651b8(csv, arg, 0, 0, &DAT_002e0694);
    int rows = FUN_000650e0(csv);
    int off = 0;
    int i = 1;
    if (1 < rows) {
        do {
            FUN_0006517c(csv, i, 0);
            int r = FUN_00065104(csv, i, 1);
            int g = FUN_00065104(csv, i, 2);
            int b = FUN_00065104(csv, i, 3);
            if (r >= 0 && r < COMPONENT_LIMIT) {
                out[off >> 2] = r;
                off += 4;
            }
            if (g >= 0 && g < COMPONENT_LIMIT) {
                out[off >> 2] = g;
                off += 4;
            }
            if (b >= 0 && b < COMPONENT_LIMIT) {
                out[off >> 2] = b;
                off += 4;
            }
            i++;
        } while (i < rows);
    }
}
