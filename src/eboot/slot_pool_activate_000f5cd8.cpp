/* HSTMATCH module=EBOOT.BIN start=0x000f5cd8 end=0x000f5dcc symbol=FUN_000f5cd8 lang=c++ */
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

void FUN_000f5cd8(Pool *self, int type, int a, int b, Vec4 v, int id)
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
