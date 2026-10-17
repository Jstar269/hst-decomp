/* HSTMATCH module=hstp_trans_main.prx start=0x0005d6e0 end=0x0005d724 symbol=FUN_0005d6e0 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

typedef struct {
    float x;
    float y;
    float z;
    float w;
    char pad[0x10];
} Item_0005d6e0;

typedef struct {
    char pad[0x18];
    int count;
    Item_0005d6e0 *items;
} Container_0005d6e0;

void FUN_0005d6e0(Container_0005d6e0 *self, int index, const float *src)
{
    if (index < self->count) {
        Item_0005d6e0 *dst = &self->items[index];
        dst->x = src[0];
        dst->y = src[1];
        dst->z = src[2];
        dst->w = src[3];
    }
}
