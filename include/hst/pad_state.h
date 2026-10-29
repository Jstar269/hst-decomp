/* Pad state block: four bytes of 2-bit signed button states, then the two stick axes. */
#ifndef HST_PAD_STATE_H
#define HST_PAD_STATE_H

/* One byte holding four signed 2-bit button states. */
typedef struct PadBits {
    signed char st0 : 2;
    signed char st1 : 2;
    signed char st2 : 2;
    signed char st3 : 2;
} PadBits;

typedef struct PadState {
    char pad00[0x88];
    PadBits byte88; /* 0x88 */
    PadBits byte89; /* 0x89 */
    PadBits byte8a; /* 0x8a */
    PadBits byte8b; /* 0x8b */
    char pad8c[4];
    float stickX;   /* 0x90 */
    float stickY;   /* 0x94 */
} PadState;

#endif
