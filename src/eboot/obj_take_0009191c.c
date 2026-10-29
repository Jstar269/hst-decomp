/* HSTMATCH module=EBOOT.BIN start=0x0009191c end=0x00091a9c symbol=FUN_0009191c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: plain-C struct with Vec4/Vec3/Vec2 members assigned whole (batched lwc1/swc1) and signed char at +0x74, float resets; readability pass; exact match verified; names and types await human review. */
typedef struct { float x, y, z, w; } Vec4;
typedef struct { float x, y, z; } Vec3;
typedef struct { float x, y; } Vec2;
/* The model-set object, with float members so the whole-member copies use float moves. */
typedef struct ModelSetView {
    int vtbl;
    Vec4 linkA;         /* 0x04 */
    Vec3 linkB;         /* 0x14 */
    int unk20;          /* 0x20 */
    int entries;        /* 0x24 */
    int level;          /* 0x28 */
    int pad2c;
    Vec4 vecA;          /* 0x30 */
    Vec4 vecB;          /* 0x40 */
    Vec4 modelsA;      /* 0x50 */
    Vec2 modelsB;      /* 0x60 */
    int unk68, unk6c, unk70;
    signed char unk74;
    unsigned char unk75;
    char pad76[0x80 - 0x76];
    char boneA[0x30];   /* 0x80 */
    char boneB[0x30];   /* 0xb0 */
} ModelSetView;

extern void FUN_00091a9c(void *, void *);
extern void FUN_00091af4(ModelSetView *);
extern void FUN_00091bc8(ModelSetView *);
extern void FUN_00091cbc(ModelSetView *);
extern void FUN_00092258(ModelSetView *);

/* Reset dst, move src's state into it, then rebuild dst's entry table and reset src. */
void FUN_0009191c(ModelSetView *dst, ModelSetView *src)
{
    FUN_00091bc8(dst);
    dst->linkA = src->linkA;
    dst->linkB = src->linkB;
    dst->unk20 = src->unk20;
    dst->entries = src->entries;
    dst->level = src->level;
    dst->vecA = src->vecA;
    dst->vecB = src->vecB;
    dst->modelsA = src->modelsA;
    dst->modelsB = src->modelsB;
    dst->unk68 = src->unk68;
    dst->unk6c = src->unk6c;
    dst->unk70 = src->unk70;
    dst->unk74 = src->unk74;
    dst->unk75 = src->unk75;
    FUN_00091a9c(dst->boneA, src->boneA);
    FUN_00091a9c(dst->boneB, src->boneB);
    dst->level = 0;
    dst->vecA.x = -1.0f;
    dst->vecA.y = -1.0f;
    dst->vecA.z = -1.0f;
    dst->vecA.w = -1.0f;
    dst->vecB.x = 0.0f;
    dst->vecB.y = 1.0f;
    dst->vecB.z = 0.0f;
    dst->vecB.w = 0.0f;
    FUN_00091cbc(dst);
    dst->unk74 = 0;
    FUN_00092258(dst);
    FUN_00091af4(src);
    FUN_00091cbc(src);
}
