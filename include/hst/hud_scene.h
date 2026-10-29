/* HUD scene object: owned parts, a row of widgets, gauges and a table of eleven entries. */
#ifndef HST_HUD_SCENE_H
#define HST_HUD_SCENE_H

#define HUD_GAUGE_COUNT 11

struct HudPart;   /* owned child with a virtual destructor */
struct HudWidget; /* child with virtual methods */
struct HudTop;
struct HudPanel;

typedef struct HudGauge {
    char pad00[0x60];
    unsigned int unk60; /* 0x60 */
    unsigned int unk64; /* 0x64 */
    char pad68[0x78 - 0x68];
    float value;        /* 0x78 */
} HudGauge;

typedef struct HudBlock {
    unsigned char flag; /* 0x0 */
    char pad01[7];
    float unk8;         /* 0x8 */
} HudBlock;

typedef struct HudEntry {
    unsigned int unk0; /* 0x0 */
    unsigned int unk4; /* 0x4 */
    unsigned int unk8; /* 0x8 */
} HudEntry;

typedef struct HudScene {
    const void *vptr;             /* 0x00 */
    char pad04[0x3c - 4];
    struct HudPart *unk3c;        /* 0x3c */
    struct HudPart *unk40;        /* 0x40 */
    struct HudPart *unk44;        /* 0x44 */
    int countdown;                /* 0x48 */
    char pad4c[0x54 - 0x4c];
    struct HudTop *top;           /* 0x54 */
    struct HudWidget *unk58;      /* 0x58 */
    struct HudWidget *unk5c;      /* 0x5c */
    struct HudWidget *unk60;      /* 0x60 */
    struct HudWidget *unk64;      /* 0x64 */
    struct HudWidget *unk68;      /* 0x68 */
    struct HudWidget *unk6c;      /* 0x6c */
    struct HudWidget *unk70;      /* 0x70 */
    struct HudWidget *unk74;      /* 0x74 */
    struct HudWidget *unk78;      /* 0x78 */
    unsigned char *unk7c;         /* 0x7c */
    HudBlock *unk80;              /* 0x80 */
    struct HudWidget *unk84;      /* 0x84 */
    struct HudPanel *unk88;       /* 0x88 */
    void *unk8c;                  /* 0x8c */
    void *unk90;                  /* 0x90 */
    void *unk94;                  /* 0x94 */
    void *unk98;                  /* 0x98 */
    HudGauge *gauges[HUD_GAUGE_COUNT]; /* 0x9c */
    HudEntry entries[HUD_GAUGE_COUNT]; /* 0xc8 */
    char pad14c[0x155 - 0x14c];
    unsigned char unk155;         /* 0x155 */
} HudScene;

#endif
