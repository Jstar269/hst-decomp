/* HSTMATCH module=EBOOT.BIN start=0x0018a6e8 end=0x0018a950 symbol=FUN_0018a6e8 lang=c99 */

typedef struct Item Item;
typedef struct Node Node;
typedef struct Self Self;

struct Vec4 {
    float x, y, z, w;
};

struct Item {
    char pad[0x64];
    float f64;          // 100 = 0x64
    char pad68[0x108 - 0x68];
    float f108;         // 264 = 0x108
    float f10c;         // 268 = 0x10c
    char pad110[0x118 - 0x110];
    unsigned color;     // 280 = 0x118
    char pad11c[4];
    struct Vec4 colorVec;      // 288 = 0x120
    char pad130[0x13c - 0x130];
    float f13c;         // 316 = 0x13c
    float f140;         // 320 = 0x140
    char pad144[0x14c - 0x144];
    unsigned char f14c; // 332 = 0x14c
};

struct Node {
    char pad[0x20];
    Item *item;
};

struct Self {
    char pad[0x74];
    void *f74;          // 0x74 (116)
    Item *items[3];     // 0x78 (120), 0x7c (124), 0x80 (128)
    char pad84[4];      // 0x84
    float scores[3];    // 0x88 (136), 0x8c (140), 0x90 (144)
};

extern float DAT_002e0ae8;
extern float DAT_002e0b08;
extern float DAT_002e0b0c;
extern float DAT_002e0b10;
extern float DAT_00341528;
extern int DAT_003417a4;
extern char DAT_002e0b13[];
extern char DAT_002e0b44[];
extern char DAT_002e0b50[];
extern char DAT_002e0b5c[];
extern char DAT_002e0b68[];

void FUN_00104118(void *self, const char *path, int flag);
void FUN_00103540(void *self, float f);
void *FUN_001039d8(void *self, const char *name, int flag);
Node *FUN_001026b8(void *parent, const char *name);
void FUN_000143b0(char *buf, const char *fmt, ...);
void FUN_00022498(float scale, struct Vec4 *out, const struct Vec4 *in);
void FUN_0010d4a8(Item *item);
void FUN_0018a6e8(Self *self);

void FUN_0018a6e8(Self *self)
{
    char buf[64];
    struct Vec4 in;
    struct Vec4 in2;
    struct Vec4 out;
    struct Vec4 out2;
    Item *item;
    register Self *cursor;
    int i;
    FUN_00104118(self, DAT_002e0b13 + 1, 1);
    FUN_00103540(self, DAT_002e0ae8);

    void *h = FUN_001039d8(self, DAT_002e0b44, 0);
    self->f74 = FUN_001026b8(h, DAT_002e0b50);

    h = FUN_001039d8(self, DAT_002e0b44, 0);
    Node *node = FUN_001026b8(h, DAT_002e0b5c);
    item = node->item;

    item->color = 0x80808080;
    in.x = 128.0f;
    in.y = 128.0f;
    in.z = 128.0f;
    in.w = 128.0f;
    FUN_00022498(0.008f, &out, &in);

    item->colorVec = out;
    self->items[0] = item;
    self->scores[0] = item->f64;

    cursor = self;
    i = 0;
    do {
        FUN_000143b0(buf, DAT_002e0b68, i);
        h = FUN_001039d8(self, DAT_002e0b44, 0);
        node = FUN_001026b8(h, buf);
        item = node->item;

        item->color = 0x80151515;
        in2.x = 21.0f;
        in2.y = 21.0f;
        in2.z = 21.0f;
        in2.w = 128.0f;
        FUN_00022498(0.008f, &out2, &in2);

        item->colorVec = out2;
        cursor->items[1] = item;
        cursor->scores[1] = item->f64;
        cursor = (Self *)((char *)cursor + 4);
        i++;
    } while (i < 2);

    int j = 0;
    do {
        Item *it = self->items[0];
        it->f13c = DAT_002e0b08;
        it->f140 = DAT_00341528;
        it->f108 = DAT_002e0b0c;
        it->f10c = DAT_002e0b10;
        FUN_0010d4a8(it);

        it = self->items[0];
        if (DAT_003417a4 < 9) {
            it->f14c = 1;
            if (it->f14c == 0) {
                FUN_0010d4a8(it);
            }
        } else {
            it->f14c = 0;
            if (it->f14c == 0) {
                FUN_0010d4a8(it);
            }
        }
        j++;
        self = (Self *)((char *)self + 4);
    } while (j < 3);
}
// near miss from lane ag3 (unreviewed)
