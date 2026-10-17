/* HSTMATCH module=EBOOT.BIN start=0x00205374 end=0x00205428 symbol=FUN_00205374 lang=c++ */
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

extern "C" void FUN_0005743c(int, int, int, int);

extern "C" void FUN_00205374(Outer *self, int flag, int v) {
    int x = self->p->m64;
    if (x != 0) {
        for (int i = 0; i < 6; i++) {
            if (flag) {
                FUN_0005743c(x, i, self->arr[i], v);
            } else {
                FUN_0005743c(x, i, self->arr[i], 0);
            }
        }
    }
}
