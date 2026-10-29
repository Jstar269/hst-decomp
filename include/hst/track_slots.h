/* Owner of a fixed array of per-slot handles with one activity byte per slot. */
#ifndef HST_TRACK_SLOTS_H
#define HST_TRACK_SLOTS_H

#define TRACK_SLOT_COUNT 27     /* handles, and activity bytes */

typedef struct TrackSlots {
    char pad00[0x44];
    unsigned char unk44;                    /* 0x44 set when one of the "reset" slot kinds is initialised */
    char pad45[3];
    int *handles[TRACK_SLOT_COUNT];         /* 0x48 */
    unsigned char active[TRACK_SLOT_COUNT]; /* 0xb4 */
    char padcf[0xec - 0xcf];
    int unkec;                              /* 0xec */
} TrackSlots;

#endif
