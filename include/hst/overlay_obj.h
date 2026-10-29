/* Overlay object: two owned parts, a link and a few state words. */
#ifndef HST_OVERLAY_OBJ_H
#define HST_OVERLAY_OBJ_H

struct OverlayPartA;
struct OverlayPartB;

typedef struct OverlayObj {
    struct OverlayPartA *part_a; /* 0x00 */
    struct OverlayPartB *part_b; /* 0x04 */
    int *link;                   /* 0x08 */
    int unk0c;                   /* 0x0c */
    int unk10;                   /* 0x10 */
    int unk14;                   /* 0x14 */
    char pad18[4];
    unsigned char unk1c;         /* 0x1c */
    unsigned char unk1d;         /* 0x1d */
    unsigned char unk1e;         /* 0x1e */
} OverlayObj;

#endif
