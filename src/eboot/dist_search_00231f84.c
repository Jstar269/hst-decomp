/* HSTMATCH module=EBOOT.BIN start=0x00231f84 end=0x00232084 symbol=FUN_00231f84 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/challenge_menu.h"

extern float FUN_0000ce3c(float base, float exponent);
extern float sqrtf(float value);

#define FAR_DISTANCE 99999.0f /* start value of the best squared distance */
#define POINT_MIN_COUNT 2     /* a point is usable from this count on */

/* Find the usable point nearest to the selected one's position; returns its index and the distance. */
void FUN_00231f84(ChallengeMenu *self, int *out_idx, float *out_dist)
{
    int best_idx = 0;
    float best = FAR_DISTANCE;
    int i = 0;
    for (; i < POINT_COUNT; i++) {
        int ok = 0;
        if (self->count[i] >= POINT_MIN_COUNT)
            ok = 1;
        if (!ok)
            continue;
        float sx = FUN_0000ce3c(self->pos_x - self->x[i], 2.0f);
        float sy = FUN_0000ce3c(self->pos_y - self->y[i], 2.0f);
        float d = sx + sy;
        if (d < best) {
            best = d;
            best_idx = i;
        }
    }
    *out_idx = best_idx;
    *out_dist = sqrtf(best);
}
