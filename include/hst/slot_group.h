/* Layout of the four-slot actor group object and the UI host it reports to. */
#ifndef HST_SLOT_GROUP_H
#define HST_SLOT_GROUP_H

#define SLOT_GROUP_COUNT 4

typedef struct GroupSlot {
    char pad[0x58];
    void *attached; /* 0x58 */
} GroupSlot;

typedef struct GroupChild {
    char pad[0x94];
    int kind; /* 0x94 */
    char pad98[0x110 - 0x98];
    float unk110; /* 0x110 */
} GroupChild;

typedef struct SlotGroup {
    char pad0[0x3a0];
    GroupSlot *slot[SLOT_GROUP_COUNT]; /* 0x3a0 */
    char pad3b0[0x3cc - 0x3b0];
    int selected; /* 0x3cc */
    char pad3d0[0x514 - 0x3d0];
    unsigned char active; /* 0x514 */
    char pad515[0x521 - 0x515];
    unsigned char flag; /* 0x521 */
    char pad522[0x524 - 0x522];
    unsigned int mode; /* 0x524 */
    char pad528[0x584 - 0x528];
    GroupChild *child; /* 0x584 */
    char pad588[0x5b4 - 0x588];
    int handle; /* 0x5b4 */
} SlotGroup;

typedef struct HostSub {
    char pad[0x3c];
    char widget[1]; /* 0x3c */
} HostSub;

typedef struct UiHost {
    char pad[0xa8];
    HostSub *sub; /* 0xa8 */
} UiHost;

#endif
