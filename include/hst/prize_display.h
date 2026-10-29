/* Prize display screen object and the row records it clears. */
#ifndef HST_PRIZE_DISPLAY_H
#define HST_PRIZE_DISPLAY_H

enum { PRIZE_PANE_COUNT = 2, PRIZE_ROW_COUNT = 16 };

struct Widget;
struct Choice;

typedef struct PrizePane {
    char pad[0x60];
    float x; /* 0x60 */
    float y; /* 0x64 */
    char pad68[0x78 - 0x68];
    float scale; /* 0x78 */
} PrizePane;

/* One entry of a row table; entries are 0x30 bytes apart. */
typedef struct PrizeRow {
    char pad[0x20];
    unsigned char shown; /* 0x20 */
    char pad21[0x30 - 0x21];
} PrizeRow;

typedef struct PrizeDisplay {
    const void *vptr; /* 0x0 */
    char pad4[0x54 - 4];
    int unk54; /* 0x54 */
    char pad58[0x60 - 0x58];
    int state; /* 0x60 */
    int unk64; /* 0x64 */
    PrizePane *panes[PRIZE_PANE_COUNT]; /* 0x68 */
    char pad70[0x7c - 0x70];
    unsigned *color; /* 0x7c */
    char pad80[0x9c - 0x80];
    struct Widget *info_widget; /* 0x9c */
    void *board; /* 0xa0 */
    struct Choice *choice; /* 0xa4 */
    int selected; /* 0xa8 */
    int scroll; /* 0xac */
    unsigned char active; /* 0xb0 */
    unsigned char has_choice; /* 0xb1 */
    unsigned char alt_layout; /* 0xb2 */
    char padb3;
    float base_x; /* 0xb4 */
    float base_y; /* 0xb8 */
} PrizeDisplay;

#endif
