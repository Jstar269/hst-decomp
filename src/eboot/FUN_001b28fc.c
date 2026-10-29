/* HSTMATCH module=EBOOT.BIN start=0x001b28fc end=0x001b29a8 symbol=FUN_001b28fc lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: restored mixed float/integer argument prototype and call ordering; readability pass; exact match verified; names and types await human review. */

extern int FUN_00062c5c(int request, int flags);
extern int FUN_001b2240(void *self, int *handle_ref, void *ref_pos, float far_value, float near_value, float near_dist, float far_dist, void *out_volume, int fold, int pos);

/* Acquires a handle for `request`; when that succeeds runs the positional update on it. Returns the handle. */
int FUN_001b28fc(void *self, int request, void *ref_pos, float far_value, float near_value, float near_dist, float far_dist, void *out_volume)
{
    int handle;
    handle = FUN_00062c5c(request, 0);
    if (handle >= 0) {
        FUN_001b2240(self, &handle, ref_pos, far_value, near_value, near_dist, far_dist, out_volume, 0, 0);
    }
    return handle;
}
