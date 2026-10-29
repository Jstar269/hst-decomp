/* HSTMATCH module=EBOOT.BIN start=0x001b25bc end=0x001b28f0 symbol=FUN_001b25bc lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; matching idiom: `from = from ? from : &G->ref_pos` (a ternary keeps the null test's else-first layout and duplicated first load), Vec4 temporaries declared in frame order and copied field by field, distance test written `d2 >= r*r` (c.nge.s), inline Clamp(const float &v, const float &lo, const float &hi) { return v < lo ? lo : (v > hi ? hi : v); } with the global read directly in the arguments; readability pass; names and types await human review. */
struct Vec4 {
    float x, y, z, w;
} __attribute__((aligned(16)));
/* Slot table view: only the byte at 0x7dd is read here. */
struct TableView {
    char pad[0x7dd];
    unsigned char unk7dd;
};
struct Ref {
    TableView *table;
};
/* Global with the reference vectors used for the angle. */
struct Glob {
    char pad[0x1d0];
    Vec4 ref_pos;   /* 0x1d0 default for the origin argument */
    Vec4 ref_dir;   /* 0x1e0 direction the angle is measured from */
    Vec4 ref_axis;  /* 0x1f0 axis the angle is measured around */
};
#define RADIUS_STEPS 3 /* number of radius thresholds in the scale table */
extern Glob *DAT_003313c4;
extern float DAT_002e9924[];
extern float DAT_002e9930[];
extern float DAT_002e993c;
extern "C" {
void FUN_00022498(Vec4 *, Vec4 *, float);
void FUN_00022434(Vec4 *, Vec4 *, Vec4 *);
void FUN_00048f08(Vec4 *, Vec4 *);
float FUN_000224d8(Vec4 *, Vec4 *);
void FUN_00022518(Vec4 *, Vec4 *);
float FUN_0000c5bc(float);
void FUN_000224f8(Vec4 *, Vec4 *, Vec4 *);
}

static inline float Clamp(const float &v, const float &lo, const float &hi) { return v < lo ? lo : (v > hi ? hi : v); }
/* Signed angle, in turns, between the direction from `from` to `target` (flattened onto the plane
   around ref_axis) and ref_dir; with fold != 0 the angle is folded to +-0.25 and clamped. */
extern "C" float FUN_001b25bc(Ref *ref, Vec4 *target, int fold, Vec4 *from)
{
    Vec4 *axis = &DAT_003313c4->ref_axis;
    Vec4 *base = &DAT_003313c4->ref_dir;
    Vec4 origin;
    Vec4 dir;
    Vec4 along;
    Vec4 side;
    Vec4 delta_copy;
    Vec4 flat_copy;
    Vec4 delta;
    Vec4 proj;
    Vec4 cross;
    Vec4 flat;
    Vec4 perp;
    from = from ? from : &DAT_003313c4->ref_pos;
    origin.x = from->x;
    origin.y = from->y;
    origin.z = from->z;
    origin.w = from->w;
    if (ref->table->unk7dd != 0) {
        unsigned i = 0;
        float *radius = DAT_002e9924;
        do {
            if (origin.x * origin.x + origin.z * origin.z >= radius[0] * radius[0]) {
                FUN_00022498(&origin, &origin, DAT_002e9930[i]);
                break;
            }
            i++;
            radius++;
        } while (i < RADIUS_STEPS);
        origin.w = 1.0f;
    }
    FUN_00022434(&delta, target, &origin);
    delta_copy.x = delta.x;
    delta_copy.y = delta.y;
    delta_copy.z = delta.z;
    delta_copy.w = delta.w;
    FUN_00048f08(&dir, &delta_copy);
    float d = FUN_000224d8(&dir, axis);
    FUN_00022498(&proj, axis, d);
    along.x = proj.x;
    along.y = proj.y;
    along.z = proj.z;
    along.w = proj.w;
    FUN_00022434(&perp, &dir, &along);
    flat_copy.x = perp.x;
    flat_copy.y = perp.y;
    flat_copy.z = perp.z;
    flat_copy.w = perp.w;
    FUN_00022518(&flat, &flat_copy);
    dir.x = flat.x;
    dir.y = flat.y;
    dir.z = flat.z;
    flat.w = 0.0f;
    dir.w = 0.0f;
    float angle = FUN_0000c5bc(FUN_000224d8(&dir, base));
    FUN_000224f8(&cross, axis, base);
    side.x = cross.x;
    side.y = cross.y;
    side.z = cross.z;
    side.w = cross.w;
    if (FUN_000224d8(&dir, &side) < 0.0f) {
        angle = -angle;
    }
    angle = angle / 6.2831855f; /* radians to turns */
    if (fold != 0) {
        if (0.25f <= angle && angle < 0.75f) {
            angle = 0.5f - angle;
        } else if (-0.75f <= angle && angle < -0.25f) {
            angle = -0.5f - angle;
        }
        angle = Clamp(angle * DAT_002e993c, -DAT_002e993c * 0.25f, DAT_002e993c * 0.25f);
    }
    return angle;
}
