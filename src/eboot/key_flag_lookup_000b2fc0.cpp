/* HSTMATCH module=EBOOT.BIN start=0x000b2fc0 end=0x000b3390 symbol=FUN_000b2fc0 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/chara_player.h"

/* Character record; the low nibble at 0x62 selects the table. */
struct Rec {
    char pad[0x62];
    signed char kind : 4;
};

struct Entry {
    char pad[0x50];
    unsigned char flags[24];
};

/* Table of per-character entries. */
struct Table {
    Entry *data;
    int a, b;
};

/* Per-slot info row (0x120 bytes); only the id is used. */
struct Info {
    short id;
    char pad[0x120 - 2];
};

extern void *DAT_00338b08;
extern Table *DAT_0034a7e8;
extern Info DAT_0034180e[];

extern "C" Rec *FUN_000d8c24(void *, int, int);

/* Map a key code to a flag number (pairs of codes share one flag) and return that flag of the player's character entry; 0 for other keys. */
extern "C" unsigned char FUN_000b2fc0(CharaPlayer *self, int key)
{
    unsigned char result = 0;
    int flag = -1;
    switch (key) {
    case 158:
    case 159:
        flag = 0;
        break;
    case 160:
    case 161:
        flag = 1;
        break;
    case 162:
    case 163:
        flag = 2;
        break;
    case 164:
    case 165:
        flag = 3;
        break;
    case 174:
    case 175:
        flag = 4;
        break;
    case 176:
    case 177:
        flag = 5;
        break;
    case 178:
    case 179:
        flag = 6;
        break;
    case 180:
    case 181:
        flag = 7;
        break;
    case 182:
    case 183:
        flag = 8;
        break;
    case 184:
    case 185:
        flag = 9;
        break;
    case 198:
    case 199:
        flag = 10;
        break;
    case 201:
    case 202:
        flag = 11;
        break;
    case 204:
    case 205:
        flag = 12;
        break;
    case 207:
    case 208:
        flag = 13;
        break;
    case 210:
    case 211:
        flag = 14;
        break;
    case 213:
    case 214:
        flag = 15;
        break;
    case 216:
        flag = 16;
        break;
    case 218:
        flag = 17;
        break;
    case 220:
        flag = 18;
        break;
    case 222:
        flag = 19;
        break;
    case 166:
    case 167:
        flag = 20;
        break;
    case 168:
    case 169:
        flag = 21;
        break;
    case 170:
    case 171:
        flag = 22;
        break;
    case 172:
    case 173:
        flag = 23;
        break;
    }
    if (flag >= 0) {
        int chara_id = *self->chara;
        int kind = FUN_000d8c24(DAT_00338b08, 0, chara_id)->kind;
        Table *table = &DAT_0034a7e8[kind != 0];
        chara_id = kind == 0 ? chara_id : DAT_0034180e[self->slot].id;
        Entry *entry = &table->data[chara_id];
        result = entry->flags[flag];
    }
    return result;
}
