/* HSTMATCH module=hstp_trans_main.prx start=0x00213bdc end=0x00213c90 symbol=FUN_00213bdc lang=c++ */
/* Clone of src/eboot/apply_six_entries_00205374.cpp (hstclone.py tag s10170158a1r2s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag s256a/v4) corrected by hand: typed Outer/Inner structs, for loop with the flag branch kept in the loop as retail does, matching idiom: #pragma opt_strength_reduction off (retail recomputes i*4 and reloads arr every pass); exact match verified; names and types await human review. */
#pragma opt_strength_reduction off

struct Inner {
    char pad[0x64];
    int m64;
};

struct Outer {
    Inner *p;
    int pad4[2];
    int *arr;
};

extern "C" void FUN_00058090(int, int, int, int);

extern "C" void FUN_00213bdc(Outer *self, int flag, int v) {
    int x = self->p->m64;
    if (x != 0) {
        for (int i = 0; i < 6; i++) {
            if (flag) {
                FUN_00058090(x, i, self->arr[i], v);
            } else {
                FUN_00058090(x, i, self->arr[i], 0);
            }
        }
    }
}
