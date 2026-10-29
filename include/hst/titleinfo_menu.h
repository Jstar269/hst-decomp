/* Leading fields of the title-info menu object that the small helpers touch. */
#ifndef HST_TITLEINFO_MENU_H
#define HST_TITLEINFO_MENU_H

struct TitleInfoNotify;

typedef struct TitleInfoHead {
    char pad00[0x54];
    unsigned char unk54; /* 0x54 */
    unsigned char unk55; /* 0x55 */
    char pad56[0x640 - 0x56];
    void *game; /* 0x640 */
    char pad644[0x650 - 0x644];
    struct TitleInfoNotify *notify; /* 0x650 */
} TitleInfoHead;

#endif
