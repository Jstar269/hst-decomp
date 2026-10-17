/* HSTMATCH module=EBOOT.BIN start=0x001fedc4 end=0x001feec4 symbol=FUN_001fedc4 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern "C" int DAT_002ef0ac;
extern "C" int DAT_002ef0b0;
static inline int Clamp(int v, const int &lo, const int &hi) { return v < lo ? lo : (hi < v ? hi : v); }
extern "C" void FUN_001fedc4(int *cursor, int *scroll, int count, int visible, int dir, int wrap)
{
    int max_scroll;
    if (count < visible) {
        max_scroll = 0;
    } else {
        max_scroll = count - visible;
    }
    if (dir < 0) {
        if (wrap != 0) {
            *scroll = max_scroll;
            *cursor = visible - 1;
        } else if (*cursor < 1) {
            int v = *scroll - 1;
            *scroll = v;
            *scroll = Clamp(v, DAT_002ef0ac, max_scroll);
        } else {
            *cursor = *cursor - 1;
        }
    } else if (wrap != 0) {
        *scroll = 0;
        *cursor = 0;
    } else if (*cursor >= visible - 1) {
        int v = *scroll + 1;
        *scroll = v;
        *scroll = Clamp(v, DAT_002ef0b0, max_scroll);
    } else {
        *cursor = *cursor + 1;
    }
}
