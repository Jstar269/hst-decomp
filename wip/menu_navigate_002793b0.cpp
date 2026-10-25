/* HSTMATCH module=EBOOT.BIN start=0x002793b0 end=0x00279578 symbol=FUN_002793b0 lang=c++ */

struct Sub {
    char pad[0xdc];
    int cursor;
};

struct Obj {
    char pad[0x104];
    int mode;
    char pad2[0xc];
    int m_cursor[5];
    char pad3[0x474 - 0x114 - 5 * 4];
    Sub *sub;

    int GetCursor(int m);
    void SetCursor(int m, int c);
};

extern "C" {
    void FUN_0010b8cc(Sub *, int, int);
    int FUN_001b1c44(void *, int);
    void FUN_0026f7f4(const char *, ...);
    extern char DAT_0034179c;
    extern const char DAT_002fe5e8;
    extern const char DAT_002fe600;
}

inline int Obj::GetCursor(int m) {
    switch (m) {
    case 1:
    case 2:
    case 3:
    case 4:
        return m_cursor[m];
    default:
        FUN_0026f7f4(&DAT_002fe5e8, m);
        return 4;
    }
}

inline void Obj::SetCursor(int m, int c) {
    m_cursor[m] = c;
    FUN_0026f7f4(&DAT_002fe600, m, c);
}

extern "C" void FUN_002793b0(Obj *self, int param_2) {
    int cur = self->sub->cursor;
    bool valid = (cur >= 0 && cur < 4);
    if (valid) {
        FUN_0010b8cc(self->sub, param_2, 0);
        if (cur != self->sub->cursor) {
            FUN_001b1c44(&DAT_0034179c, 1);
        }
        return;
    }

    int old_cur = self->GetCursor(self->mode);
    int mode = self->mode;
    switch (mode) {
    case 1:
    case 2:
    case 3:
    case 4:
        FUN_0010b8cc(self->sub, param_2, 0);
        self->SetCursor(mode, self->sub->cursor);
        break;
    }

    if (old_cur != self->GetCursor(self->mode)) {
        FUN_001b1c44(&DAT_0034179c, 1);
    }
}
// near miss from lane ag4 (unreviewed)
