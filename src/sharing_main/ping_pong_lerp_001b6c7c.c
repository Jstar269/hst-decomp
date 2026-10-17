/* HSTMATCH module=hstp_trans_main.prx start=0x001b6c7c end=0x001b6e14 symbol=FUN_001b6c7c lang=c99 */
/* Clone of src/eboot/ping_pong_lerp_001a96b0.c (hstclone.py tag u1r5s): addresses substituted; exact match verified; names and types await human review. */
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

extern void *DAT_003da704;
extern int DAT_003eaac4;
extern char DAT_00389740[];

extern void *FUN_0020de40(void);
extern int FUN_00066a84(void *, const char *, int);
extern void FUN_0005d724(void *, int, const Vec4 *);

void FUN_001b6c7c(Obj *o)
{
    Vec4 *dst = (Vec4 *)((char *)DAT_003da704 + 464);
    dst->x = o->v16.x;
    dst->y = o->v16.y;
    dst->z = o->v16.z;
    dst->w = o->v16.w;

    void *obj = FUN_0020de40();
    if (FUN_00066a84(obj, DAT_00389740, 1) == 0) {
        return;
    }

    int count = DAT_003eaac4 + 1;
    DAT_003eaac4 = count;
    if (count >= 60) {
        count = 0;
        DAT_003eaac4 = 0;
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

    FUN_0005d724(DAT_003da704, 0, &result);
}
