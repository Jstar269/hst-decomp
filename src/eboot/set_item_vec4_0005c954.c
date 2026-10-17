/* HSTMATCH module=EBOOT.BIN start=0x0005c954 end=0x0005c998 symbol=FUN_0005c954 lang=c99 */
/* Clone of src/sharing_main/set_item_vec4_0005d6e0.c (hstclone.py tag u1r2e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

typedef struct {
    float x;
    float y;
    float z;
    float w;
    char pad[0x10];
} Item_0005c954;

typedef struct {
    char pad[0x18];
    int count;
    Item_0005c954 *items;
} Container_0005c954;

void FUN_0005c954(Container_0005c954 *self, int index, const float *src)
{
    if (index < self->count) {
        Item_0005c954 *dst = &self->items[index];
        dst->x = src[0];
        dst->y = src[1];
        dst->z = src[2];
        dst->w = src[3];
    }
}
