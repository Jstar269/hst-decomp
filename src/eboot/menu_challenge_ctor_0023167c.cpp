/* HSTMATCH module=EBOOT.BIN start=0x0023167c end=0x00231a18 symbol=FUN_0023167c lang=c++ data=0x002f3dd0 */
/* Hand-written reconstruction from the disassembly; exact match verified; matching idiom: each loop is a block with its own counter, table pointer and byte offset declared in that order (saved regs counter > pointer > offset), stores through (unsigned int)self + off + DISP and the reload through (unsigned long)self + off + DISP (the two casts stop MWCC folding them into one pointer), FUN_00051398 declared (obj, float), the first widget slot re-read for the virtual call, FUN_0008d994 takes the tested global; names and types await human review. Data: its string literals (2 strings, 0x002f3dd0-0x002f3e22) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/challenge_menu.h"

#define LAYOUT_FRONT_ORDER 1100.0f /* draw order value of the layout and the character widgets */
#define VIDEO_ORDER 2300.0f
#define CHAR_WIDGET_SIZE 0x48
#define PART_STATE_A 17 /* state ids passed to FUN_000ffc3c */
#define PART_STATE_B 16

struct Widget {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5(int);
};
/* Lookup record: which pane and key to fetch a part with, and where the part's value is stored back. */
struct PartRec {
    int pane;
    int key;
    int out;
};
extern unsigned DAT_00309878;
extern char *DAT_002f36b8[];  /* names of the layout panes */
extern PartRec DAT_002f39f0[];
extern int DAT_003386c8;
extern "C" {
void FUN_00102e38(void *);
void FUN_00104118(void *, char *, int);
void FUN_00103540(float, void *);
void FUN_001037c8(void *, int);
void FUN_000143b0(char *, char *, int);
void *FUN_00000bcc(int);
void *FUN_00050fc0(void *);
void FUN_000511c4(void *, char *, int);
void FUN_00051398(void *, float);
Widget *FUN_001039d8(void *, char *, int);
void *FUN_001026b8(void *, int);
void FUN_000ffc3c(void *, int);
void *FUN_0008d994(int);
}
/* Constructor: load the layout, build the character widgets, fetch the panes and parts, clear the point tables. */
extern "C" ChallengeMenu *FUN_0023167c(ChallengeMenu *self)
{
    char name[256];
    FUN_00102e38(self);
    self->vtable = (unsigned)&DAT_00309878;
    self->unk1d4 = 0;
    FUN_00104118(self, "data/menu/challengedisp/challenge.lay", 0);
    FUN_00103540(LAYOUT_FRONT_ORDER, self);
    FUN_001037c8(self, PART_STATE_A);
    /* Character widgets: stored through byte offsets from the object (matching idiom, see note). */
    {
    int i = 0;
    int off = 0;
    do {
        FUN_000143b0(name, "data/menu/challengedisp/challenge_cha%02d", i);
        void *mem = FUN_00000bcc(CHAR_WIDGET_SIZE);
        void *obj = mem;
        if (mem != 0) {
            obj = FUN_00050fc0(mem);
        }
        *(void **)((unsigned int)self + off + 0x16c) = obj;
        FUN_000511c4(obj, name, 0);
        void *again = *(void **)((unsigned long)self + off + 0x16c);
        FUN_00051398(again, LAYOUT_FRONT_ORDER);
        i++;
        off += 4;
    } while (i < CHALLENGE_CHARS);
    }
    self->unk1d8 = 1;
    self->unk1d9 = 1;
    self->unk1da = 0;
    {
    int i = 0;
    char **names = DAT_002f36b8;
    int off = 0;
    do {
        Widget *pane = FUN_001039d8(self, *names, 0);
        *(Widget **)((unsigned int)self + off + 0x54) = pane;
        (*(Widget **)((unsigned int)self + off + 0x54))->m5(-2);
        i++;
        names++;
        off += 4;
    } while (i < CHALLENGE_PANES);
    }
    {
    int i = 0;
    PartRec *rec = DAT_002f39f0;
    int off = 0;
    do {
        void *part = FUN_001026b8(self->panes[rec->pane], rec->key);
        *(void **)((unsigned int)self + off + 100) = part;
        if (part != 0) {
            FUN_000ffc3c(part, PART_STATE_A);
            rec->out = *(int *)(*(char **)((unsigned long)self + off + 100) + 0x24);
        }
        i++;
        rec++;
        off += 4;
    } while (i < CHALLENGE_PARTS);
    }
    FUN_000ffc3c(self->parts[CHALLENGE_PARTS - 1], PART_STATE_B);
    FUN_000ffc3c(self->parts[23], PART_STATE_B);
    self->video = 0;
    if (DAT_003386c8 != 0) {
        void *video = FUN_0008d994(DAT_003386c8);
        self->video = video;
        FUN_00103540(VIDEO_ORDER, video);
    }
    self->mode = 0;
    self->selected = 0;
    self->unk1e4 = 0;
    self->pending = 0;
    self->pos_x = 0;
    self->pos_y = 0;
    self->unk1f4 = 0;
    self->unk1f8 = 0;
    self->unk1fc = 0;
    int k = 0;
    ChallengeMenu *p = self;
    do {
        p->count[0] = 0; p->unk228[0] = 0; p->unk250[0] = 0; p->unk278[0] = 0; p->x[0] = 0; p->y[0] = 0;
        p->count[1] = 0; p->unk228[1] = 0; p->unk250[1] = 0; p->unk278[1] = 0; p->x[1] = 0; p->y[1] = 0;
        p->count[2] = 0; p->unk228[2] = 0; p->unk250[2] = 0; p->unk278[2] = 0; p->x[2] = 0; p->y[2] = 0;
        p->count[3] = 0; p->unk228[3] = 0; p->unk250[3] = 0; p->unk278[3] = 0; p->x[3] = 0; p->y[3] = 0;
        p->count[4] = 0; p->unk228[4] = 0; p->unk250[4] = 0; p->unk278[4] = 0; p->x[4] = 0;
        k += 5;
        p->y[4] = 0;
        p = (ChallengeMenu *)((unsigned *)p + 5);
    } while (k < POINT_COUNT);
    k = 0;
    p = self;
    do {
        k += 5;
        p->x[0] = (float)(int)((PointPart *)p->parts[CHALLENGE_FIRST_POINT_PART])->left;
        p->y[0] = (float)(int)((PointPart *)p->parts[CHALLENGE_FIRST_POINT_PART])->top;
        p->x[1] = (float)(int)((PointPart *)p->parts[CHALLENGE_FIRST_POINT_PART + 1])->left;
        p->y[1] = (float)(int)((PointPart *)p->parts[CHALLENGE_FIRST_POINT_PART + 1])->top;
        p->x[2] = (float)(int)((PointPart *)p->parts[CHALLENGE_FIRST_POINT_PART + 2])->left;
        p->y[2] = (float)(int)((PointPart *)p->parts[CHALLENGE_FIRST_POINT_PART + 2])->top;
        p->x[3] = (float)(int)((PointPart *)p->parts[CHALLENGE_FIRST_POINT_PART + 3])->left;
        p->y[3] = (float)(int)((PointPart *)p->parts[CHALLENGE_FIRST_POINT_PART + 3])->top;
        p->x[4] = (float)(int)((PointPart *)p->parts[CHALLENGE_FIRST_POINT_PART + 4])->left;
        p->y[4] = (float)(int)((PointPart *)p->parts[CHALLENGE_FIRST_POINT_PART + 4])->top;
        p = (ChallengeMenu *)((unsigned *)p + 5);
    } while (k < POINT_COUNT);
    return self;
}
