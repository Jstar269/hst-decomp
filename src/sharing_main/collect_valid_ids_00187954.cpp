/* HSTMATCH module=hstp_trans_main.prx start=0x00187954 end=0x00187ab0 symbol=FUN_00187954 lang=c++ */
/* Clone of src/eboot/collect_valid_ids_0017b260.cpp (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag v0) corrected by hand: the byte-offset counter is declared before the loop index (s3/s2 order), stores go through `out[off >> 2]` (srl+sll folds to retail`s `and -4`), and range tests are `a >= 0 && a < 0x100`; exact match verified; names and types await human review. */
extern "C" {
extern char DAT_00387ccc;
extern int FUN_00065fa4(void *);
extern int FUN_00066038(void *, int, int);
extern void FUN_000661a8(void *, int, int);
extern void FUN_00066260(void *, int, int, int, void *);
}

extern "C" void FUN_00187954(int *out, void *s, int x)
{
    FUN_00066260(s, x, 0, 0, &DAT_00387ccc);
    int n = FUN_00065fa4(s);
    int off = 0;
    int i = 1;
    if (1 < n) {
        do {
            FUN_000661a8(s, i, 0);
            int a = FUN_00066038(s, i, 1);
            int b = FUN_00066038(s, i, 2);
            int c = FUN_00066038(s, i, 3);
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
