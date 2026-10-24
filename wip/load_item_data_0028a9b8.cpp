/* HSTMATCH module=EBOOT.BIN start=0x0028a9b8 end=0x0028ac5c symbol=FUN_0028a9b8 lang=c++ */
/* Hand-written reconstruction: C++ struct copy with 25-iteration unrolled string copy,
   FUN_0022cad0 check, 3-state f10 dispatch, vector erase with empty Tag temporary,
   and Item loop with inlined vector push_back. 173/169 words (4 words over). */

struct Header {
    int f0;
    int f4;
    int f8;
    int fc;
    int f10;
    int f14;
    int f18;
    float f1c;
    int f20;
    int f24;
    int f28;
    unsigned char f2c;
    signed char f2d;
    char name[50];
};

struct Vec4 {
    float x, y, z, w;
};

struct Vec3 {
    float x, y, z;
};

struct Item {
    Vec4 r0;
    Vec3 r1;
};

struct ItemSlice {
    Item *items;
    int count;
};

struct Sub70 {
    char pad[8];
    int f8;
};

struct Vector {
    Item *data;
    unsigned int size;
    unsigned int capacity;
};

struct Obj {
    char pad_00[0x54];
    signed char f54;    /* 0x54 */
    char pad_55[0x70 - 0x55];
    Sub70 *sub70;       /* 0x70 */
    char pad_74[0x80 - 0x74];
    Header hdr;         /* 0x80 */
    Vector vec;         /* 0xe0 */
};

struct Tag {};

extern "C" {
extern void *DAT_0034a114;
int FUN_0022cad0(int, int, int);
void FUN_0028ad5c(Obj *);
void FUN_0028c860(Vector *, unsigned int, Tag);
short FUN_0002fe80(int, void *);
void FUN_0028c81c(Vector *, const Item *, Tag);
}

extern "C" void FUN_0028a9b8(Obj *self, const Header *hdr, const ItemSlice *slice)
{
    self->hdr.f0 = hdr->f0;
    self->hdr.f4 = hdr->f4;
    self->hdr.f8 = hdr->f8;
    self->hdr.fc = hdr->fc;
    self->hdr.f10 = hdr->f10;
    self->hdr.f14 = hdr->f14;
    self->hdr.f18 = hdr->f18;
    self->hdr.f1c = hdr->f1c;
    self->hdr.f20 = hdr->f20;
    self->hdr.f24 = hdr->f24;
    self->hdr.f28 = hdr->f28;
    self->hdr.f2c = hdr->f2c;
    self->hdr.f2d = hdr->f2d;

    const char *src = hdr->name;
    char *dst = self->hdr.name;
    int i = 25;
    do {
        char c0 = src[0];
        char c1 = src[1];
        i--;
        dst[0] = c0;
        dst[1] = c1;
        src += 2;
        dst += 2;
    } while (i > 0);

    int r = FUN_0022cad0(*(int *)((char *)DAT_0034a114 + 0xcc),
                         *(int *)((char *)DAT_0034a114 + 0xd0),
                         self->hdr.f8);
    if (r != 0) {
        if (self->hdr.f10 == 2) {
            FUN_0028ad5c(self);
        } else if (self->hdr.f10 != 1) {
            if (self->hdr.f10 == 0) {
                self->f54 = 0;
            }
        }
    }

    FUN_0028c860(&self->vec, self->vec.size, Tag());

    Item *it = slice->items;
    int cond = ((it == slice->items + slice->count) ^ 1);
    if (cond) {
        do {
            if (*(short *)it == *(int *)((char *)DAT_0034a114 + 0xcc) + 1) {
                if (hdr->fc == ((short *)it)[1]) {
                    Item temp;
                    temp.r0 = it->r0;
                    temp.r1 = it->r1;
                    int sub_val = self->sub70->f8;
                    short code;
                    if (sub_val == 0) {
                        code = -1;
                    } else {
                        code = FUN_0002fe80(sub_val, &temp.r1);
                    }
                    ((short *)&temp)[4] = code;

                    if (self->vec.size < self->vec.capacity) {
                        Item *dest = self->vec.data ? &self->vec.data[self->vec.size] : 0;
                        if (dest != 0) {
                            dest->r0 = temp.r0;
                            dest->r1 = temp.r1;
                        }
                        self->vec.size++;
                    } else {
                        FUN_0028c81c(&self->vec, &temp, Tag());
                    }
                }
            }
            it++;
            cond = ((it == slice->items + slice->count) ^ 1);
        } while (cond);
    }
}
// near miss from lane ag2 (unreviewed)
