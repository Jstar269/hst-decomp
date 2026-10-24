/* HSTMATCH module=EBOOT.BIN start=0x0017b260 end=0x0017b3bc symbol=FUN_0017b260 lang=c++ */
/* LoadMenuColorCsv: generic name,R,G,B menu color files; see docs/DATA-TABLES.md */
/* Ghidra pseudocode (hstgen.py tag v0) corrected by hand: the byte-offset counter is declared before the loop index (s3/s2 order), stores go through `out[off >> 2]` (srl+sll folds to retail`s `and -4`), and range tests are `a >= 0 && a < 0x100`; exact match verified; names and types await human review. */
extern "C" {
extern char DAT_002e0694;
extern int FUN_000650e0(void *);
extern int FUN_00065104(void *, int, int);
extern void FUN_0006517c(void *, int, int);
extern void FUN_000651b8(void *, int, int, int, void *);
}

extern "C" void FUN_0017b260(int *out, void *s, int x)
{
    FUN_000651b8(s, x, 0, 0, &DAT_002e0694);
    int n = FUN_000650e0(s);
    int off = 0;
    int i = 1;
    if (1 < n) {
        do {
            FUN_0006517c(s, i, 0);
            int a = FUN_00065104(s, i, 1);
            int b = FUN_00065104(s, i, 2);
            int c = FUN_00065104(s, i, 3);
            if (a >= 0 && a < 0x100) {
                out[off >> 2] = a;
                off += 4;
            }
            if (b >= 0 && b < 0x100) {
                out[off >> 2] = b;
                off += 4;
            }
            if (c >= 0 && c < 0x100) {
                out[off >> 2] = c;
                off += 4;
            }
            i++;
        } while (i < n);
    }
}
