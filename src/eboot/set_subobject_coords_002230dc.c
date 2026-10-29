/* HSTMATCH module=EBOOT.BIN start=0x002230dc end=0x00223144 symbol=FUN_002230dc lang=c99 */
/* Ghidra pseudocode (hstgen.py tag p128a) corrected by hand: typed subobject struct and natural for-loop; readability pass; exact match verified; names and types await human review. */

/* Child layer: position pair stored at 0x60. */
struct Sub {
    char pad[0x60];
    float x;                /* 0x60 */
    float y;                /* 0x64 */
};

/* Object with up to two child layers and an offset position (copied into the first child). */
struct Obj {
    char pad[0x68];
    struct Sub *sub[2];     /* 0x68 */
    char pad2[0xb4 - 0x70];
    float x;                /* 0xb4 */
    float y;                /* 0xb8 */
};

extern void FUN_00103480(struct Obj *);

/* Sets the position from (x, y) shifted by a fixed offset and copies it to the first child layer. */
void FUN_002230dc(struct Obj *obj, float x, float y)
{
    int i;
    obj->x = x - 182.0f;
    obj->y = y - 50.0f;

    for (i = 0; i < 2; i++) {
        if (obj->sub[i] != 0 && i == 0) {
            obj->sub[i]->x = obj->x;
            obj->sub[i]->y = obj->y;
        }
    }
    FUN_00103480(obj);
}
