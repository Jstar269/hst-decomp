/* HSTMATCH module=EBOOT.BIN start=0x000e19d0 end=0x000e1d28 symbol=FUN_000e19d0 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

#define FADE_STEP 0.2f

extern "C" {
extern float DAT_002d6b64;
extern float DAT_002d6b68;

extern void FUN_00022434(void *out, const void *a, const void *b);
extern void FUN_00022518(void *out, const void *in);
extern float FUN_0001d940(const void *a, const void *b);
extern float FUN_000224d8(const void *a, const void *b);
extern float FUN_00022e44(float f);
}

struct Vec4 {
    float x, y, z, w;
    Vec4() {}
    Vec4(const Vec4 &o) : x(o.x), y(o.y), z(o.z), w(o.w) {}
};

struct TrailConfig {
    char pad[4];
    float min_dot;   /* 0x04 smallest accepted dot of the new segment with the previous direction */
    float min_len;   /* 0x08 smallest accepted segment length */
};

struct Trail {
    char pad[0x3c];
    TrailConfig *cfg;       /* 0x3c */
    char pad40[0x4c - 0x40];
    int max_count;          /* 0x4c ring capacity */
    char pad50[0x54 - 0x50];
    Vec4 *buf;              /* 0x54 ring of points */
    char pad58[0x60 - 0x58];
    unsigned char enabled;
    unsigned char holding;
    char pad62[0x64 - 0x62];
    int count;              /* 0x64 points in the ring */
    int start;              /* 0x68 oldest point */
    int head;               /* 0x6c next slot to write */
    char pad70[0x74 - 0x70];
    float fade;             /* 0x74 reduced each frame by FADE_STEP, clamped */
    char pad78[0x90 - 0x78];
    int holdTimer;          /* 0x90 frames left while holding */
    char pad94[0xa0 - 0x94];
    Vec4 cur_pos;           /* 0xa0 */
};

inline float clamp(const float &v, const float &lo, const float &hi) {
    return v < lo ? lo : (v > hi ? hi : v);
}

/* Per-frame update: appends the current position to the ring of points unless the new segment is too short or turns back too far, then updates the fade. */
extern "C" void FUN_000e19d0(Trail *trail)
{
    Vec4 newSeg;
    Vec4 prevDir;
    Vec4 prevSeg;
    Vec4 delta;
    Vec4 tmpNew;
    Vec4 tmpDir;
    Vec4 tmpDelta;
    Vec4 tmpPrev;

    if (trail->enabled == 0) return;

    if (trail->holding == 0) {
        if (trail->holdTimer < 1 && trail->fade > 0.0f) {
            trail->fade = trail->fade - FADE_STEP;
            trail->fade = clamp(trail->fade, DAT_002d6b64, DAT_002d6b68);
        }
    }

    int count = trail->count;
    bool accept = true;

    if (count > 1) {
        int idx = trail->head - 1;
        if (idx < 0) {
            idx = trail->max_count - 1;
        }
        idx--;
        if (idx < 0) {
            idx = trail->max_count - 1;
        }

        if (count > 2) {
            int idx2 = idx - 1;
            if (idx2 < 0) {
                idx2 = trail->max_count - 1;
            }

            FUN_00022434(&tmpNew, &trail->cur_pos, &trail->buf[idx]);
            newSeg = tmpNew;

            FUN_00022434(&tmpPrev, &trail->buf[idx], &trail->buf[idx2]);
            prevSeg = tmpPrev;

            FUN_00022518(&tmpDir, &prevSeg);
            prevDir = tmpDir;

            tmpDir.w = 0.0f;
            prevDir.w = 0.0f;

            float dot = FUN_0001d940(&newSeg, &prevDir);
            if (dot < trail->cfg->min_dot) {
                accept = false;
            }
        }

        if (accept) {
            FUN_00022434(&tmpDelta, &trail->cur_pos, &trail->buf[idx]);
            delta = tmpDelta;

            float len_sq = FUN_000224d8(&delta, &delta);
            float len = FUN_00022e44(len_sq);
            if (len < trail->cfg->min_len) {
                accept = false;
            }
        }
    }

    if (accept) {
        trail->buf[trail->head] = trail->cur_pos;
        int head = trail->head + 1;
        trail->head = head;
        if (head == trail->max_count) {
            trail->head = 0;
        }
        int max = trail->max_count;

        if (trail->count < max) {
            trail->count++;
        } else {
            if (++trail->start == max) {
                trail->start = 0;
            }
        }
    } else {
        int last = trail->head - 1;
        if (last < 0) {
            last = trail->max_count - 1;
        }
        trail->buf[last] = trail->cur_pos;
    }

    if (trail->enabled) {
        if (--trail->holdTimer <= 0) trail->holding = 0;
    } else {
        trail->fade = 0.0f;
    }
}
