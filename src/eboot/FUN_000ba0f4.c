/* HSTMATCH module=EBOOT.BIN start=0x000ba0f4 end=0x000ba124 symbol=FUN_000ba0f4 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct Vec4 {
    float x, y, z, w;
} Vec4;
typedef struct Node {
    char pad0[16];
    Vec4 v;                      /* 16 */
} Node;
typedef struct Obj {
    char pad0[136];
    Node *node;                  /* 136 */
} Obj;
extern Obj *DAT_003386b0;
void FUN_000ba0f4(Vec4 *out)
{
    Node *n = DAT_003386b0->node;

    out->x = n->v.x;
    out->y = n->v.y;
    out->z = n->v.z;
    out->w = n->v.w;
}
