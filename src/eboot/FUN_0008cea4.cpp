/* HSTMATCH module=EBOOT.BIN start=0x0008cea4 end=0x0008d07c symbol=FUN_0008cea4 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/room_block.h"

/* One of three 0x120-byte sub-records. */
struct SeqChunk {
    char unk0[0xcc];
    unsigned char unkcc;                /* 0xcc cleared after construction */
    char padcd[0x108 - 0xcd];
    char unk108[0x10];                  /* 0x108 passed by address */
    char unk118[8];                     /* 0x118 passed by address */
};

/* Sequence info record, set up by "tADH_SeqInfo::Init()". */
struct SeqInfo {
    int ids[5];                         /* 0x00 -1 when unset */
    unsigned char unk14;                /* 0x14 */
    char pad15[3];
    char unk18[0x40 - 0x18];            /* 0x18 passed by address */
    SeqChunk chunk[3];                  /* 0x40 */
    char pad3a0[0x3a8 - 0x3a0];
    unsigned char unk3a8;               /* 0x3a8 */
    char pad3a9[3];
    int unk3ac;
    int unk3b0;
    int unk3b4;
    int unk3b8;
    int unk3bc;
    int unk3c0;
    int unk3c4;
    unsigned char unk3c8;               /* 0x3c8 */
    unsigned char unk3c9;
    unsigned char unk3ca;
    unsigned char unk3cb;
    char pad3cc[0x3d1 - 0x3cc];
    unsigned char unk3d1;               /* 0x3d1 */
    unsigned char unk3d2;
    char pad3d3[0x3d8 - 0x3d3];
    unsigned char unk3d8;               /* 0x3d8 */
    char pad3d9[0x3dc - 0x3d9];
    unsigned char unk3dc;               /* 0x3dc */
    unsigned char unk3dd;
    unsigned char unk3de;
    char pad3df;
    RoomBlock room;                     /* 0x3e0 */
    int unk44c;                         /* 0x44c */
    int unk450;                         /* 0x450 */
};

extern "C" {
extern int *DAT_003415a8;
extern char s_tADH_SeqInfo__Init___002beaa8[];
extern void FUN_0008d388(SeqChunk *p, int a, int b, int c, int d, int e, int f);
extern void FUN_0008d2ec(SeqChunk *p);
extern void FUN_0008d298(void *p);
extern void FUN_0008d264(void *p);
extern void FUN_0008d22c(void *p);
extern void FUN_0008d1ec(void *p);
extern void FUN_0008d148(void *p);
extern void FUN_0008d114(void *p);
extern void FUN_0008d0e4(void *p, void *src);
extern void FUN_0008d0cc(void *p, void *src);
extern void FUN_000114c0(void *p, int a, int b);
extern void FUN_0008cae8(char *msg);
}

/* Initialises the sequence info record to its defaults. */
extern "C" void *FUN_0008cea4(SeqInfo *info)
{
    unsigned int i;
    int *id;
    SeqChunk *chunk;

    chunk = &info->chunk[0];
    FUN_0008d388(chunk, 0, 0, 0, 0, 0, 0);
    FUN_0008d2ec(chunk);
    chunk = &info->chunk[1];
    FUN_0008d388(chunk, 0, 0, 0, 0, 0, 0);
    FUN_0008d2ec(chunk);
    chunk = &info->chunk[2];
    FUN_0008d388(chunk, 0, 0, 0, 0, 0, 0);
    FUN_0008d2ec(chunk);
    FUN_0008d298(&info->unk3c8);
    FUN_0008d264(&info->unk3dc);
    FUN_0008d22c(&info->unk3dd);
    FUN_0008d1ec(&info->room);
    FUN_0008d148(&info->unk3a8);
    i = 0;
    id = info->ids;
    do {
        i++;
        *id++ = -1;
    } while (i < 4);
    info->ids[4] = -1;
    info->unk14 = 0;
    FUN_0008d114(info->unk18);
    FUN_0008d2ec(&info->chunk[0]);
    info->chunk[0].unkcc = 0;
    FUN_0008d2ec(&info->chunk[1]);
    FUN_0008d2ec(&info->chunk[2]);
    info->chunk[1].unkcc = 0;
    info->chunk[2].unkcc = 0;
    FUN_0008d0e4(info->chunk[0].unk108, (char *)DAT_003415a8 + 4);
    FUN_0008d0cc(info->chunk[0].unk118, (char *)DAT_003415a8 + 0x18);
    info->unk3a8 = 0;
    info->unk3ac = 0;
    info->unk3b0 = 0;
    info->unk3b4 = 0;
    info->unk3c0 = 0;
    info->unk3c4 = 0;
    info->unk3b8 = 0;
    info->unk3bc = 0;
    info->unk3c8 = 0;
    info->unk3c9 = 1;
    info->unk3ca = 2;
    info->unk3cb = 0;
    info->unk3d1 = 0;
    info->unk3d2 = 0;
    info->unk3d8 = 0;
    info->unk3dc = 0;
    info->unk3dd = 0;
    info->unk3de = 0;
    FUN_000114c0(&info->room, 0, sizeof(RoomBlock));
    info->room.unk68 = -1;
    info->room.unk6a = -1;
    info->room.unk24 = -1;
    info->unk44c = 0;
    info->unk450 = 0;
    FUN_0008cae8(s_tADH_SeqInfo__Init___002beaa8);
    return info;
}
