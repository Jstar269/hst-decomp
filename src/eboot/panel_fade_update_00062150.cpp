/* HSTMATCH module=EBOOT.BIN start=0x00062150 end=0x000622d4 symbol=FUN_00062150 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag g2) corrected by hand: 32-record fade loop with per-slot scale, compare chain as a switch; readability pass; exact match verified; names and types await human review. */
extern "C" unsigned char DAT_00331878;
extern "C" float DAT_00331880[];
extern "C" int DAT_002d105c;
extern "C" int DAT_002d1060;
extern "C" int DAT_002d1064;
extern "C" int DAT_002d1068;

extern "C" void FUN_00070330(float rate);
extern "C" void FUN_000790d0(int id, int x, int y);

#define PANEL_LAST 31 /* index of the last of the 32 records */

/* One record: moves from (x0, y0) to (x1, y1) over span steps; timer counts the remaining steps. */
struct Panel
{
    float x0;       /* 0x00 */
    float y0;       /* 0x04 */
    float x1;       /* 0x08 */
    float y1;       /* 0x0c */
    float span;     /* 0x10 */
    float timer;    /* 0x14 */
};

/* Per-frame update while the global flag is set: sets a rate from fps, then advances every running record by
   one step and passes its interpolated position (times a per-record scale) to FUN_000790d0. */
extern "C" void FUN_00062150(float fps)
{
    if (DAT_00331878 != 0) {
        FUN_00070330((60.0f / fps) / 59.94f);
        int i;
        Panel *panel;
        for (i = 0, panel = (Panel *)DAT_00331880; i <= PANEL_LAST; i++, panel++) {
            if (panel->timer > 0.0f) {
                panel->timer = panel->timer - 1.0f;
                float progress = 1.0f - panel->timer / panel->span;
                float unit_scale = 128.0f;
                switch (i) {
                case 3: unit_scale = (float)DAT_002d105c; break;
                case 2: unit_scale = (float)DAT_002d1060; break;
                case 4: unit_scale = (float)DAT_002d1064; break;
                case 9: unit_scale = (float)DAT_002d1068; break;
                }
                FUN_000790d0(i, (int)(unit_scale * (panel->x0 + progress * (panel->x1 - panel->x0))),
                             (int)(unit_scale * (panel->y0 + progress * (panel->y1 - panel->y0))));
                if (panel->timer <= 0.0f) {
                    panel->x0 = panel->x1;
                    panel->y0 = panel->y1;
                    panel->timer = 0.0f;
                }
            }
        }
    }
}
