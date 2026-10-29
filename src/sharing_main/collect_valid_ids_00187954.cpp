/* HSTMATCH module=hstp_trans_main.prx start=0x00187954 end=0x00187ab0 symbol=FUN_00187954 lang=c++ */
/* Clone of src/eboot/collect_valid_ids_0017b260.cpp (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag v0) corrected by hand: the byte-offset counter is declared before the loop index (s3/s2 order), stores go through `out[off >> 2]` (srl+sll folds to retail`s `and -4`), and range tests are `a >= 0 && a < 0x100`; readability pass; exact match verified; names and types await human review. */
#define COMPONENT_LIMIT 0x100 /* valid component values are 0..255 */

extern "C" {
extern char DAT_00387ccc;
extern int FUN_00065fa4(void *);
extern int FUN_00066038(void *, int, int);
extern void FUN_000661a8(void *, int, int);
extern void FUN_00066260(void *, int, int, int, void *);
}

/* Reads the CSV rows after the header and appends every value in 0..255 of the three columns to out. */
extern "C" void FUN_00187954(int *out, void *csv, int arg)
{
    FUN_00066260(csv, arg, 0, 0, &DAT_00387ccc);
    int rows = FUN_00065fa4(csv);
    int off = 0;
    int i = 1;
    if (1 < rows) {
        do {
            FUN_000661a8(csv, i, 0);
            int r = FUN_00066038(csv, i, 1);
            int g = FUN_00066038(csv, i, 2);
            int b = FUN_00066038(csv, i, 3);
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
