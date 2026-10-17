/* HSTMATCH module=hstp_trans_main.prx start=0x0005da74 end=0x0005daf4 symbol=FUN_0005da74 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

typedef struct {
    float a[4];
    float b[4];
} Item_0005da74;

typedef struct {
    char pad[0x18];
    int count;
    Item_0005da74 *items;
} Container_0005da74;

void FUN_0005da74(Container_0005da74 *self, int index, float *out1, float *out2)
{
    if (index < self->count) {
        if (out1 != 0) {
            Item_0005da74 *item = &self->items[index];
            out1[0] = item->a[0];
            out1[1] = item->a[1];
            out1[2] = item->a[2];
            out1[3] = item->a[3];
        }
        if (out2 != 0) {
            Item_0005da74 *item = &self->items[index];
            out2[0] = item->b[0];
            out2[1] = item->b[1];
            out2[2] = item->b[2];
            out2[3] = item->b[3];
        }
    }
}
