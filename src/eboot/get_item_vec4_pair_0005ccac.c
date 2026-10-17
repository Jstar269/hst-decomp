/* HSTMATCH module=EBOOT.BIN start=0x0005ccac end=0x0005cd2c symbol=FUN_0005ccac lang=c99 */
/* Clone of src/sharing_main/get_item_vec4_pair_0005da74.c (hstclone.py tag u1r2e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

typedef struct {
    float a[4];
    float b[4];
} Item_0005ccac;

typedef struct {
    char pad[0x18];
    int count;
    Item_0005ccac *items;
} Container_0005ccac;

void FUN_0005ccac(Container_0005ccac *self, int index, float *out1, float *out2)
{
    if (index < self->count) {
        if (out1 != 0) {
            Item_0005ccac *item = &self->items[index];
            out1[0] = item->a[0];
            out1[1] = item->a[1];
            out1[2] = item->a[2];
            out1[3] = item->a[3];
        }
        if (out2 != 0) {
            Item_0005ccac *item = &self->items[index];
            out2[0] = item->b[0];
            out2[1] = item->b[1];
            out2[2] = item->b[2];
            out2[3] = item->b[3];
        }
    }
}
