/* HSTMATCH module=EBOOT.BIN start=0x001a96b0 end=0x001a9848 symbol=FUN_001a96b0 lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */

/* The step counter runs 0..PINGPONG_PERIOD-1; each half interpolates between the two points. */
#define PINGPONG_HALF 30
#define PINGPONG_HALF_F 30.0f
#define PINGPONG_PERIOD 60

typedef struct Vec4 {
    float x;
    float y;
    float z;
    float w;
} Vec4;

typedef struct Obj {
    char pad[16];
    Vec4 v10;  /* 0x10 copied to the global object's vector */
    Vec4 p20;  /* 0x20 first end point */
    Vec4 p30;  /* 0x30 second end point */
} Obj;

extern void *DAT_003313c4;
extern int DAT_00341788; /* step counter */
extern char DAT_002e1e70[];

extern void *FUN_001ff670(void);
extern int FUN_00065740(void *, const char *, int);
extern void FUN_0005c998(void *, int, const Vec4 *);

void FUN_001a96b0(Obj *o)
{
    /* Copy the vector into the global object, then step the interpolation. */
    Vec4 *dst = (Vec4 *)((char *)DAT_003313c4 + 464);
    dst->x = o->v10.x;
    dst->y = o->v10.y;
    dst->z = o->v10.z;
    dst->w = o->v10.w;

    void *obj = FUN_001ff670();
    if (FUN_00065740(obj, DAT_002e1e70, 1) == 0) {
        return;
    }

    int count = DAT_00341788 + 1;
    DAT_00341788 = count;
    if (count >= PINGPONG_PERIOD) {
        count = 0;
        DAT_00341788 = 0;
    }

    Vec4 result;
    int rem = count % PINGPONG_HALF;

    if (count >= PINGPONG_HALF) {
        float t = (float)rem;
        result.x = o->p30.x + t * (o->p20.x - o->p30.x) / PINGPONG_HALF_F;
        result.y = o->p30.y + t * (o->p20.y - o->p30.y) / PINGPONG_HALF_F;
        result.z = o->p30.z + t * (o->p20.z - o->p30.z) / PINGPONG_HALF_F;
        result.w = 1.0f;
    } else {
        float t = (float)rem;
        result.x = o->p20.x + t * (o->p30.x - o->p20.x) / PINGPONG_HALF_F;
        result.y = o->p20.y + t * (o->p30.y - o->p20.y) / PINGPONG_HALF_F;
        result.z = o->p20.z + t * (o->p30.z - o->p20.z) / PINGPONG_HALF_F;
        result.w = 1.0f;
    }

    FUN_0005c998(DAT_003313c4, 0, &result);
}
