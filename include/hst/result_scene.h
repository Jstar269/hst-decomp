/* Result scene object (vtable with a deleting destructor): optional part objects, 0x8c-byte animators and pulse counters. */
#ifndef HST_RESULT_SCENE_H
#define HST_RESULT_SCENE_H

#include "hst/types.h"
#include "hst/animator.h"

/* Part object driven through its vtable; the class body lives in the C++ sources. */
struct ResultPart;
/* Colour word object; the pulse counters drive its value. */
struct ResultColor;

/* One 0x14-byte slot; the colour object is the first word. */
typedef struct ResultSlot {
    struct ResultColor *color;  /* 0x00 */
    char pad04[0x10];
} ResultSlot;

/* Number of entries of the integer table cleared by the constructor. */
#define RESULT_GRID_COUNT 21

typedef struct ResultScene {
    const void *vtable;               /* 0x00 */
    char pad04[0x38];
    struct ResultPart *part3c;  /* 0x3c */
    struct ResultPart *part40;  /* 0x40 */
    int mode;  /* 0x44 the per-frame update only handles mode 0 */
    Animator anim48;  /* 0x48 */
    struct ResultPart *partd4;  /* 0xd4 */
    char padd8[0x90];
    Animator anim168;  /* 0x168 */
    struct ResultPart *part1f4;  /* 0x1f4 */
    char pad1f8[0x78];
    void *unk270;  /* 0x270 */
    char pad274[0x138];
    Animator anim3ac;  /* 0x3ac */
    char pad438[0x4];
    Animator anim43c;  /* 0x43c */
    Animator anim4c8;  /* 0x4c8 */
    Animator anim554;  /* 0x554 */
    Animator anim5e0;  /* 0x5e0 */
    Animator anim66c;  /* 0x66c */
    Animator anim6f8;  /* 0x6f8 */
    Animator anim784;  /* 0x784 */
    struct ResultPart *part810;  /* 0x810 */
    char pad814[0x88];
    Animator anim89c;  /* 0x89c */
    Animator anim928;  /* 0x928 */
    struct ResultPart *part9b4;  /* 0x9b4 */
    char pad9b8[0xda4];
    struct ResultPart *part175c;  /* 0x175c */
    char pad1760[0xdc];
    Animator anim183c;  /* 0x183c */
    Animator anim18c8;  /* 0x18c8 */
    struct ResultPart *part1954;  /* 0x1954 */
    struct ResultPart *part1958;  /* 0x1958 */
    struct ResultPart *part195c;  /* 0x195c */
    char pad1960[0x17c];
    int grid[RESULT_GRID_COUNT];  /* 0x1adc */
    char pad1b30[0x4];
    Animator anim1b34;  /* 0x1b34 */
    Animator anim1bc0;  /* 0x1bc0 */
    Animator anim1c4c;  /* 0x1c4c */
    Animator anim1cd8;  /* 0x1cd8 */
    struct ResultPart *part1d64;  /* 0x1d64 */
    struct ResultPart *part1d68;  /* 0x1d68 */
    char pad1d6c[0x1bc];
    Animator anim1f28;  /* 0x1f28 */
    Animator anim1fb4;  /* 0x1fb4 */
    Animator anim2040;  /* 0x2040 */
    Animator anim20cc;  /* 0x20cc */
    Animator anim2158;  /* 0x2158 */
    struct ResultPart *part21e4;  /* 0x21e4 */
    char pad21e8[0x4];
    ResultSlot slotsA[1];  /* 0x21ec indexed by slotIndex */
    char pad2200[0xc4];
    Animator anim22c4;  /* 0x22c4 */
    int slotIndex;  /* 0x2350 */
    int pulseC;  /* 0x2354 pulse counter */
    char pad2358[0x4];
    struct ResultPart *part235c;  /* 0x235c */
    char pad2360[0x4];
    ResultSlot slotsB[1];  /* 0x2364 indexed by slotIndex */
    char pad2378[0xec];
    struct ResultPart *part2464;  /* 0x2464 */
    char pad2468[0x18];
    Animator anim2480;  /* 0x2480 */
    struct ResultPart *part250c;  /* 0x250c */
    char pad2510[0x18];
    int countdown;  /* 0x2528 calls the finish handler when it runs out */
    Animator anim252c;  /* 0x252c */
    struct ResultPart *part25b8;  /* 0x25b8 */
    char pad25bc[0x28];
    struct ResultColor *color25e4;  /* 0x25e4 */
    char pad25e8[0x10];
    struct ResultColor *color25f8;  /* 0x25f8 */
    char pad25fc[0x1a0];
    Animator anim279c;  /* 0x279c */
    Animator anim2828;  /* 0x2828 */
    int pulseA;  /* 0x28b4 pulse counter */
    int pulseB;  /* 0x28b8 pulse counter */
} ResultScene;

#endif
