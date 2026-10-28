/* HSTMATCH module=hstp_trans_main.prx start=0x000bd438 end=0x000bd468 symbol=FUN_000bd438 lang=c99 */
/* Clone of src/eboot/FUN_000ba0f4.c (hstclone.py tag c170007): addresses substituted; exact match verified; names and types await human review. */
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
extern Obj *DAT_003e19f0;
void FUN_000bd438(Vec4 *out)
{
    Node *n = DAT_003e19f0->node;

    out->x = n->v.x;
    out->y = n->v.y;
    out->z = n->v.z;
    out->w = n->v.w;
}
