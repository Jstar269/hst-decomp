/* HSTMATCH module=EBOOT.BIN start=0x00231f84 end=0x00232084 symbol=FUN_00231f84 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern float FUN_0000ce3c(float value, float period);
extern float sqrtf(float value);

void FUN_00231f84(char *self, int *out_idx, float *out_dist)
{
    int best_idx = 0;
    float best = 99999.0f;
    int i = 0;
    char *p = self;
    for (; i < 10; i++, p += 4) {
        int ok = 0;
        if (*(int *)(p + 0x200) >= 2)
            ok = 1;
        if (!ok)
            continue;
        float sx = FUN_0000ce3c(*(float *)(self + 0x1ec) - *(float *)(p + 0x2a0), 2.0f);
        float sy = FUN_0000ce3c(*(float *)(self + 0x1f0) - *(float *)(p + 0x2c8), 2.0f);
        float d = sx + sy;
        if (d < best) {
            best = d;
            best_idx = i;
        }
    }
    *out_idx = best_idx;
    *out_dist = sqrtf(best);
}
