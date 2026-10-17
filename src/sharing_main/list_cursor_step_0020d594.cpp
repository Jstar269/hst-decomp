/* HSTMATCH module=hstp_trans_main.prx start=0x0020d594 end=0x0020d694 symbol=FUN_0020d594 lang=c++ */
/* Clone of src/eboot/list_cursor_step_001fedc4.cpp (hstclone.py tag s10170158a1r4s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern "C" int DAT_00397134;
extern "C" int DAT_00397138;
static inline int Clamp(int v, const int &lo, const int &hi) { return v < lo ? lo : (hi < v ? hi : v); }
extern "C" void FUN_0020d594(int *cursor, int *scroll, int count, int visible, int dir, int wrap)
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
            *scroll = Clamp(v, DAT_00397134, max_scroll);
        } else {
            *cursor = *cursor - 1;
        }
    } else if (wrap != 0) {
        *scroll = 0;
        *cursor = 0;
    } else if (*cursor >= visible - 1) {
        int v = *scroll + 1;
        *scroll = v;
        *scroll = Clamp(v, DAT_00397138, max_scroll);
    } else {
        *cursor = *cursor + 1;
    }
}
