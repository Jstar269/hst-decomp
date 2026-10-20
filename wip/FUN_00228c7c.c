/* HSTMATCH module=EBOOT.BIN start=0x00228c7c end=0x0022909c symbol=FUN_00228c7c lang=c99 */
/*
 * WIP Status: 262/264 words (99.2% length match).
 *
 * Architecture & Discoveries:
 * - This function is an event handler for a 3D game object (`Obj *self, int event`).
 * - Event dispatch sequence in retail:
 *     if (event == 24) goto LAB_24;
 *     if (event == 14) goto LAB_14;
 *     if (event == 22) goto LAB_22;
 *     if (event == 8)  goto LAB_8;
 *     if (event == 19) return 0;
 *     if (event == 4)  return 0;
 *     return 0;
 *   In retail, cases 19 and 4 branch to the epilogue at 0x22908c and 0x229088.
 * - Inlined transform updates:
 *   Two blocks are inlined across the cases:
 *   1) UPDATE_TRANSFORM: copies target_pos to pos, clears field_430, copies
 *      identity matrix (DAT_002bc410..DAT_002bc44c) float by float, calls
 *      FUN_0004d2d4 (rotation by angle_deg * DEG_TO_RAD), copies pos to matrix row 3,
 *      and calls FUN_00055044 on subobjects.
 *   2) RESET_TRANSFORM: sets pos.y = 10.0f, copies pos to matrix row 3, and calls
 *      FUN_00055044 on subobjects.
 * - Remaining difference:
 *   A 2-word difference in how the tail cases (19, 4, default) are folded into the epilogue.
 */

typedef struct Vec4 {
    float x, y, z, w;
} Vec4;

typedef struct Mat4 {
    Vec4 r0, r1, r2, r3;
} Mat4;

typedef struct Obj {
    char pad0[0x3c];
    int field_3c;           /* 0x3c */
    Vec4 pos;               /* 0x40 */
    Vec4 target_pos;        /* 0x50 */
    Mat4 matrix;            /* 0x60 */
    char pad_a0[0x10];      /* 0xa0 */
    char field_b0[0x364];   /* 0xb0 */
    void *field_414;        /* 0x414 */
    char pad_418[0xc];      /* 0x418 */
    int angle_deg;          /* 0x424 */
    int pad_428;            /* 0x428 */
    int field_42c;          /* 0x42c */
    int field_430;          /* 0x430 */
    unsigned char field_434;/* 0x434 */
    unsigned char field_435;/* 0x435 */
    unsigned char field_436;/* 0x436 */
    unsigned char field_437;/* 0x437 */
    char pad_438[0x21];     /* 0x438 */
    unsigned char field_459;/* 0x459 */
} Obj;

typedef struct GlobalSub {
    char pad[0x58];
    int field_58;
} GlobalSub;

typedef struct GlobalRoot {
    char pad[0x9c];
    GlobalSub *sub;
} GlobalRoot;

extern GlobalRoot *DAT_003386b0;
extern float DAT_002bc410;
extern float DAT_002bc414;
extern float DAT_002bc418;
extern float DAT_002bc41c;
extern float DAT_002bc420;
extern float DAT_002bc424;
extern float DAT_002bc428;
extern float DAT_002bc42c;
extern float DAT_002bc430;
extern float DAT_002bc434;
extern float DAT_002bc438;
extern float DAT_002bc43c;
extern float DAT_002bc440;
extern float DAT_002bc444;
extern float DAT_002bc448;
extern float DAT_002bc44c;

extern void FUN_0004d2d4(Mat4 *out, const Mat4 *in, float angle);
extern void FUN_00055044(void *obj, const Mat4 *m);

#define UPDATE_TRANSFORM(self) do { \
    if ((self)->field_3c != 1) { \
        (self)->field_3c = 1; \
        (self)->field_434 = 1; \
    } \
    (self)->pos.x = (self)->target_pos.x; \
    (self)->pos.y = (self)->target_pos.y; \
    (self)->pos.z = (self)->target_pos.z; \
    (self)->pos.w = (self)->target_pos.w; \
    (self)->field_430 = 0; \
    (self)->matrix.r0.x = DAT_002bc410; \
    (self)->matrix.r0.y = DAT_002bc414; \
    (self)->matrix.r0.z = DAT_002bc418; \
    (self)->matrix.r0.w = DAT_002bc41c; \
    (self)->matrix.r1.x = DAT_002bc420; \
    (self)->matrix.r1.y = DAT_002bc424; \
    (self)->matrix.r1.z = DAT_002bc428; \
    (self)->matrix.r1.w = DAT_002bc42c; \
    (self)->matrix.r2.x = DAT_002bc430; \
    (self)->matrix.r2.y = DAT_002bc434; \
    (self)->matrix.r2.z = DAT_002bc438; \
    (self)->matrix.r2.w = DAT_002bc43c; \
    (self)->matrix.r3.x = DAT_002bc440; \
    (self)->matrix.r3.y = DAT_002bc444; \
    (self)->matrix.r3.z = DAT_002bc448; \
    (self)->matrix.r3.w = DAT_002bc44c; \
    FUN_0004d2d4(&(self)->matrix, &(self)->matrix, (float)(self)->angle_deg * 0.017453292f); \
    (self)->matrix.r3.x = (self)->pos.x; \
    (self)->matrix.r3.y = (self)->pos.y; \
    (self)->matrix.r3.z = (self)->pos.z; \
    (self)->matrix.r3.w = (self)->pos.w; \
    FUN_00055044((self)->field_b0, &(self)->matrix); \
    FUN_00055044((self)->field_414, &(self)->matrix); \
} while (0)

#define RESET_TRANSFORM(self) do { \
    (self)->pos.y = 10.0f; \
    (self)->matrix.r3.x = (self)->pos.x; \
    (self)->matrix.r3.y = (self)->pos.y; \
    (self)->matrix.r3.z = (self)->pos.z; \
    (self)->matrix.r3.w = (self)->pos.w; \
    FUN_00055044((self)->field_b0, &(self)->matrix); \
    FUN_00055044((self)->field_414, &(self)->matrix); \
    (self)->field_435 = 0; \
} while (0)

int FUN_00228c7c(Obj *self, int event)
{
    if (event == 24) goto LAB_24;
    if (event == 14) goto LAB_14;
    if (event == 22) goto LAB_22;
    if (event == 8)  goto LAB_8;
    if (event == 19) return 0;
    if (event == 4)  return 0;
    return 0;

LAB_8:
    self->field_459 = 0;
    if (self->field_42c >= 0) {
        RESET_TRANSFORM(self);
        self->field_437 = 1;
    }
    return 0;

LAB_22:
LAB_14:
    if (!self->field_437 && self->field_42c >= 0) {
        if (self->field_42c > DAT_003386b0->sub->field_58) {
            UPDATE_TRANSFORM(self);
            self->field_435 = 1;
        } else if (!self->field_437) {
            RESET_TRANSFORM(self);
        }
    }
    return 0;

LAB_24:
    UPDATE_TRANSFORM(self);
    self->field_435 = 1;
    self->field_437 = 0;
    self->field_42c = -1;
    return 0;
}
// near miss from lane s10171846g1r1-0 (unreviewed)
