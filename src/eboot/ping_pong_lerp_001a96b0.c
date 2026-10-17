/* HSTMATCH module=EBOOT.BIN start=0x001a96b0 end=0x001a9848 symbol=FUN_001a96b0 lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */

typedef struct Vec4 {
    float x;
    float y;
    float z;
    float w;
} Vec4;

typedef struct Obj {
    char pad[16];
    Vec4 v16;
    Vec4 p32;
    Vec4 p48;
} Obj;

extern void *DAT_003313c4;
extern int DAT_00341788;
extern char DAT_002e1e70[];

extern void *FUN_001ff670(void);
extern int FUN_00065740(void *, const char *, int);
extern void FUN_0005c998(void *, int, const Vec4 *);

void FUN_001a96b0(Obj *o)
{
    Vec4 *dst = (Vec4 *)((char *)DAT_003313c4 + 464);
    dst->x = o->v16.x;
    dst->y = o->v16.y;
    dst->z = o->v16.z;
    dst->w = o->v16.w;

    void *obj = FUN_001ff670();
    if (FUN_00065740(obj, DAT_002e1e70, 1) == 0) {
        return;
    }

    int count = DAT_00341788 + 1;
    DAT_00341788 = count;
    if (count >= 60) {
        count = 0;
        DAT_00341788 = 0;
    }

    Vec4 result;
    int rem = count % 30;

    if (count >= 30) {
        float t = (float)rem;
        result.x = o->p48.x + t * (o->p32.x - o->p48.x) / 30.0f;
        result.y = o->p48.y + t * (o->p32.y - o->p48.y) / 30.0f;
        result.z = o->p48.z + t * (o->p32.z - o->p48.z) / 30.0f;
        result.w = 1.0f;
    } else {
        float t = (float)rem;
        result.x = o->p32.x + t * (o->p48.x - o->p32.x) / 30.0f;
        result.y = o->p32.y + t * (o->p48.y - o->p32.y) / 30.0f;
        result.z = o->p32.z + t * (o->p48.z - o->p32.z) / 30.0f;
        result.w = 1.0f;
    }

    FUN_0005c998(DAT_003313c4, 0, &result);
}
