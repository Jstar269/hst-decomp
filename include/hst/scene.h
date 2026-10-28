/* Scene task object (owner of the game state machine and the per-match objects). */
#ifndef HST_SCENE_H
#define HST_SCENE_H

enum { SCENE_MAX_PLAYERS = 4 }; /* singles use 2, doubles 4 */

typedef struct Obj Obj;
typedef struct Ball Ball;
typedef struct Score Score;

typedef struct Scene {
    void *vtbl;                          /* 0x00 */
    char pad4[0x38];
    int state;                           /* 0x3c current state id */
    int next;                            /* 0x40 requested state id */
    int unk44;
    int unk48;
    unsigned char unk4c;
    char pad4d[3];
    int unk50;
    int unk54;
    unsigned char busy;                  /* 0x58 */
    unsigned char unk59;
    unsigned char unk5a;
    unsigned char unk5b;
    int side;                            /* 0x5c toggled when unk60 changes */
    int unk60;
    int unk64;                           /* last seen unk60 */
    unsigned char unk68;
    char pad69[3];
    int timer;                           /* 0x6c */
    Obj *players[SCENE_MAX_PLAYERS];     /* 0x70 */
    Obj *fuki;                           /* 0x80 */
    Obj *fukiAnim;                       /* 0x84 */
    Ball *ball;                          /* 0x88 */
    Obj *unk8c;
    Obj *effect;                         /* 0x90 */
    Obj *inpane;                         /* 0x94 */
    Obj *banner;                         /* 0x98 */
    Obj *unk9c;
    Score *score;                        /* 0xa0 */
    Obj *unka4;
    Obj *sound;                          /* 0xa8 */
} Scene;

#endif
