/* HSTMATCH module=EBOOT.BIN start=0x000d4f44 end=0x000d5060 symbol=FUN_000d4f44 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Model;
struct Player { char pad0[0x41c]; int m41c; char pad420[0x5bc - 0x420]; Model *model; };
struct Game { char pad0[0x70]; Player *players[4]; };
struct Entry { char pad0[0x50]; char eff[0x80]; float md0; char pad_d4[0x154 - 0xd4]; float m154; char pad158[0x1b0 - 0x158]; };
extern "C" {
extern Game *DAT_003386b0;
extern float DAT_00341314;
void FUN_000550c8(void *, void *);
void FUN_00058e50(void *, int, float);
void FUN_00058f38(void *, float, int);
void FUN_00059174(void *);
void FUN_0005f0d8(void *);
void FUN_0005f110(void *, float);
void *FUN_00093838(Model *);
}
extern "C" void FUN_000d4f44(Entry *e)
{
    int i = 0;
    int off = 0;
    Entry *p = e;
    do {
        Player *pl = *(Player **)((char *)DAT_003386b0 + off + 0x70);
        if (pl) {
            float f = (float)pl->m41c / DAT_00341314;
            if (f == 0.0f) {
                FUN_00058f38(p->eff, 0.0f, -1);
                FUN_0005f110(p->eff, 0.0f);
                FUN_00058e50(p->eff, -1, 0.0f);
            } else if (f == 1.0f) {
                FUN_00058e50(p->eff, -1, 33.0f);
            }
            FUN_000550c8(p->eff, FUN_00093838(pl->model));
            FUN_00059174(p->eff);
            FUN_0005f0d8(p->eff);
            p->md0 = p->m154;
        }
        i++; off += 4; p++;
    } while (i < 4);
}
