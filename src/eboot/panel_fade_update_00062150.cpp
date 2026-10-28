/* HSTMATCH module=EBOOT.BIN start=0x00062150 end=0x000622d4 symbol=FUN_00062150 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag g2) corrected by hand: 32-record fade loop with per-slot scale, compare chain as a switch; exact match verified; names and types await human review. */
extern "C" unsigned char DAT_00331878;
extern "C" float DAT_00331880[];
extern "C" int DAT_002d105c;
extern "C" int DAT_002d1060;
extern "C" int DAT_002d1064;
extern "C" int DAT_002d1068;

extern "C" void FUN_00070330(float rate);
extern "C" void FUN_000790d0(int id, int x, int y);

struct Panel
{
    float x0;
    float y0;
    float x1;
    float y1;
    float span;
    float timer;
};

extern "C" void FUN_00062150(float fps)
{
    if (DAT_00331878 != 0) {
        FUN_00070330((60.0f / fps) / 59.94f);
        int i;
        Panel *p;
        for (i = 0, p = (Panel *)DAT_00331880; i <= 31; i++, p++) {
            if (p->timer > 0.0f) {
                p->timer = p->timer - 1.0f;
                float s = 1.0f - p->timer / p->span;
                float k = 128.0f;
                switch (i) {
                case 3: k = (float)DAT_002d105c; break;
                case 2: k = (float)DAT_002d1060; break;
                case 4: k = (float)DAT_002d1064; break;
                case 9: k = (float)DAT_002d1068; break;
                }
                FUN_000790d0(i, (int)(k * (p->x0 + s * (p->x1 - p->x0))),
                             (int)(k * (p->y0 + s * (p->y1 - p->y0))));
                if (p->timer <= 0.0f) {
                    p->x0 = p->x1;
                    p->y0 = p->y1;
                    p->timer = 0.0f;
                }
            }
        }
    }
}
