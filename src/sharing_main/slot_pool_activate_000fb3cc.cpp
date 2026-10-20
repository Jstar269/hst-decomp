/* HSTMATCH module=hstp_trans_main.prx start=0x000fb3cc end=0x000fb4c0 symbol=FUN_000fb3cc lang=c++ */
/* Clone of src/eboot/slot_pool_activate_000f5cd8.cpp (hstclone.py tag c055807): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
extern "C" {
struct Vec4 {
    float x, y, z, w;
} __attribute__((aligned(16)));

typedef struct {
    unsigned char active;
    unsigned char pad0[3];
    int type;
    int a;
    int b;
    int limit;
    int start;
    Vec4 v;
    int id;
} Slot;

typedef struct {
    unsigned char pad0[0xa0];
    Slot slots[16];
} Pool;

void FUN_000fb3cc(Pool *self, int type, int a, int b, Vec4 v, int id)
{
    unsigned int i;

    for (i = 0; i < 16; i++) {
        if (self->slots[i].active == 0) {
            self->slots[i].active = 1;
            self->slots[i].type = type;
            if (type == 0)
                self->slots[i].type = 0;
            self->slots[i].a = a;
            self->slots[i].b = b;
            if (type == 4 || type == 16) {
                self->slots[i].limit = 3000;
            } else if (type == 17) {
                self->slots[i].limit = 1;
            } else {
                self->slots[i].limit = 3000;
            }
            self->slots[i].start = self->slots[i].limit;
            self->slots[i].v = v;
            self->slots[i].id = id;
            return;
        }
    }
}
}
