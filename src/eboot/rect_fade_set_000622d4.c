/* HSTMATCH module=EBOOT.BIN start=0x000622d4 end=0x000623e8 symbol=FUN_000622d4 lang=c99 */
/* Hand-written reconstruction from the disassembly (DeepSeek V4.1 Flash (Freebuff), lane dsn2); names and types
   await human review. Exact match verified 2026-10-28 (pass 18); the decisive detail is that FUN_000790d0 takes
   all four arguments, which keeps a0-a3 live and forces the index*24 temp into t0. Frame 16 (ra 12, s2 8, s1 4, s0 0). a0 = element index into a 24-byte rect table at
   DAT_00331880, a1/a2 = width/height in pixels, a3 = fade ticks (<= 0 means "snap"). Rect fields:
   f0/f4 = current left/top, f8/fc = target left/top, f10 = fade length, f14 = remaining fade. */
typedef unsigned int u32;

typedef struct Rect {
    float f0;                    /* 0: current x */
    float f4;                    /* 4: current y */
    float f8;                    /* 8: target x */
    float fc;                    /* 12: target y */
    float f10;                   /* 16: fade length */
    float f14;                   /* 20: fade remaining */
} Rect;

extern Rect DAT_00331880[];

void FUN_000790d0(int idx, int w, int h, int fade);

void FUN_000622d4(int idx, int w, int h, int fade)
{
    Rect *r = DAT_00331880 + idx;

    if (fade <= 0) {
        FUN_000790d0(idx, w, h, fade);
        r->f8 = (float)w;
        r->f0 = (float)w;
        r->fc = (float)h;
        r->f4 = (float)h;
        r->f14 = 0.0f;
    } else {
        if (r->f14 > 0.0f) {
            float k = 1.0f - r->f14 / r->f10;
            float cur = r->f0;

            r->f0 = cur + k * (r->f8 - cur);
            cur = r->f4;
            r->f4 = cur + k * (r->fc - cur);
        }
        r->f8 = (float)w / 128.0f;
        r->fc = (float)h / 128.0f;
        r->f14 = (float)fade;
        r->f10 = (float)fade;
    }
}
// MEASURED STATE: 69/69 words, 6 differ, first write-first pass. a0 indexes a 24-byte rect table at DAT_00331880;
// a1/a2 are width/height, a3 the fade length. fade <= 0 snaps via FUN_000790d0 and stores the raw sizes, fade > 0
// lerps the current corner toward the target with k = 1 - remaining/length, then stores w/128, h/128 and the tick
// count in both f10 and f14. The last 6: one temp register (retail `sll t0,v1,3`, ours `sll a0`) and the two
// lwc1 pairs of the lerp loaded in the other order (retail loads the current corner first).

// PHASE-3 SWEEP (2026-10-28, pass 17): 6 -> 2 differ with the copy-through-temp lever on both lerp axes:
// `float cur = r->f0; r->f0 = cur + k * (r->f8 - cur);` (and the same with r->f4/r->fc) makes MWCC load the
// current corner before the target, matching retail's lwc1 order. That was worth 4 words.
// LEFT (2): `sll a0,v1,0x3` / `addu s2,v1,a0` vs retail's `sll t0,...` / `addu s2,v1,t0` - a scratch-register
// choice only. `DAT_00331880 + idx` and `&DAT_00331880[idx]` compile identically, so retail's t0 means a0 was
// still live there for a reason the body does not show. Wall: measured, 2 words, allocation.
