/* HSTMATCH module=EBOOT.BIN start=0x000b2fc0 end=0x000b3390 symbol=FUN_000b2fc0 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Rec {
    char pad[0x62];
    signed char kind : 4;
};

struct Entry {
    char pad[0x50];
    unsigned char flags[24];
};

struct Table {
    Entry *data;
    int a, b;
};

struct Info {
    short id;
    char pad[0x120 - 2];
};

struct Self {
    char pad[0x148];
    int slot;
    char pad14c[0x154 - 0x14c];
    short *chara;
};

extern void *DAT_00338b08;
extern Table *DAT_0034a7e8;
extern Info DAT_0034180e[];

extern "C" Rec *FUN_000d8c24(void *, int, int);

extern "C" unsigned char FUN_000b2fc0(Self *self, int key)
{
    unsigned char r = 0;
    int idx = -1;
    switch (key) {
    case 158:
    case 159:
        idx = 0;
        break;
    case 160:
    case 161:
        idx = 1;
        break;
    case 162:
    case 163:
        idx = 2;
        break;
    case 164:
    case 165:
        idx = 3;
        break;
    case 174:
    case 175:
        idx = 4;
        break;
    case 176:
    case 177:
        idx = 5;
        break;
    case 178:
    case 179:
        idx = 6;
        break;
    case 180:
    case 181:
        idx = 7;
        break;
    case 182:
    case 183:
        idx = 8;
        break;
    case 184:
    case 185:
        idx = 9;
        break;
    case 198:
    case 199:
        idx = 10;
        break;
    case 201:
    case 202:
        idx = 11;
        break;
    case 204:
    case 205:
        idx = 12;
        break;
    case 207:
    case 208:
        idx = 13;
        break;
    case 210:
    case 211:
        idx = 14;
        break;
    case 213:
    case 214:
        idx = 15;
        break;
    case 216:
        idx = 16;
        break;
    case 218:
        idx = 17;
        break;
    case 220:
        idx = 18;
        break;
    case 222:
        idx = 19;
        break;
    case 166:
    case 167:
        idx = 20;
        break;
    case 168:
    case 169:
        idx = 21;
        break;
    case 170:
    case 171:
        idx = 22;
        break;
    case 172:
    case 173:
        idx = 23;
        break;
    }
    if (idx >= 0) {
        int ch = *self->chara;
        int kind = FUN_000d8c24(DAT_00338b08, 0, ch)->kind;
        Table *t = &DAT_0034a7e8[kind != 0];
        ch = kind == 0 ? ch : DAT_0034180e[self->slot].id;
        Entry *e = &t->data[ch];
        r = e->flags[idx];
    }
    return r;
}
