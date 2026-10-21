/* HSTMATCH module=hstp_trans_main.prx start=0x002b65c4 end=0x002b69a8 symbol=FUN_002b65c4 lang=c++ */
/* Clone of src/eboot/menu_input_update_002a6e34.cpp (hstclone.py tag c21sn35s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Scrolling list menu input: four button polls (0x10, 0x40, 0x80, 0x20) move the cursor/scroll window of a 38-row page; mode 0 handles all four buttons (b1/b2 step by two rows), mode 1 only b3/b4. Matching idioms: a switch (case 0, case 1) on the mode; if/else-if chains over the buttons; cursor/scroll updates written as relative member updates (m->cursor = m->cursor + 2; ... m->cursor = m->cursor - 1) so the stored value is reused from a register; 'x >= limit' (not 'limit <= x') gives slt v1 instead of at; the final loop walks the parameter pointer for the item table and a copy for the name rows. */
struct Item {
  char pad[0xf8];
  char *name;
  char pad_fc[0x3c];
  int flag;
};
struct Row {
  unsigned char flag;
  char name[127];
};
struct Menu {
  char pad0[0x290];
  Item *items[38];
  char pad_328[0x38];
  Row rows[38];
  char pad_1660[4];
  int mode;
  int cursor;
  int scroll;
  int total;
  int sel;
  int btn0, btn1, btn2, btn3;
};

extern "C" {
extern char *DAT_003ea8e8;
bool FUN_0020c850(int *, int, int);
int FUN_002beb30(char *);
void FUN_002b6adc(Menu *);
void FUN_002b69a8(Menu *, int);
void FUN_00113a50();

void FUN_002b65c4(Menu *m)
{
  bool b1 = FUN_0020c850(&m->btn0, 0x10, 0x300);
  bool b2 = FUN_0020c850(&m->btn1, 0x40, 0x300);
  bool b3 = FUN_0020c850(&m->btn2, 0x80, 0x300);
  bool b4 = FUN_0020c850(&m->btn3, 0x20, 0x300);
  int scroll0 = m->scroll;
  int cursor0 = m->cursor;
  int limit = FUN_002beb30(DAT_003ea8e8 + 0x87128);
  if (m->rows[0].flag == 0) {
    return;
  }
  switch (m->mode) {
  case 0:
    if (b1) {
      if (m->cursor < 2) {
        if (m->scroll >= 2) {
          m->scroll = m->scroll - 2;
        }
      } else {
        m->cursor = m->cursor - 2;
      }
    } else if (b2) {
      if (m->cursor >= 10) {
        int v = m->scroll;
        if (v < m->total - 0xc) {
          m->scroll = v + 2;
          int n = m->cursor + m->scroll;
          if (limit == n) {
            m->cursor = m->cursor - 1;
          } else if (limit < n) {
            m->scroll = m->scroll - 2;
          }
        }
      } else {
        m->cursor = m->cursor + 2;
        int n = m->cursor + m->scroll;
        if (limit == n) {
          m->cursor = m->cursor - 1;
        } else if (limit < n) {
          m->cursor = m->cursor - 2;
        }
      }
    } else if (b3) {
      if (m->cursor < 1) {
        if (m->scroll >= 2) {
          m->scroll = m->scroll - 2;
          m->cursor = m->cursor + 1;
        }
      } else {
        m->cursor = m->cursor - 1;
      }
    } else if (b4) {
      if (m->cursor >= 0xb) {
        if (m->scroll < m->total - 0xc) {
          m->scroll = m->scroll + 2;
          m->cursor = m->cursor - 1;
          if (m->cursor + m->scroll >= limit) {
            m->scroll = m->scroll - 2;
            m->cursor = m->cursor + 1;
          }
        }
      } else {
        m->cursor = m->cursor + 1;
        if (m->cursor + m->scroll >= limit) {
          m->cursor = m->cursor - 1;
        }
      }
    }
    m->sel = m->cursor;
    if (m->scroll == scroll0) {
      return;
    }
    FUN_002b6adc(m);
    {
      int i = 0;
      char *p = (char *)m;
      do {
        Item *it = *(Item **)((char *)m + 0x290);
        it->name = p + 0x361;
        it->flag = 1;
        FUN_00113a50();
        i++;
        m = (Menu *)((char *)m + 4);
        p += 0x80;
      } while (i < 0x26);
    }
    break;
  case 1:
    if (b3) {
      if (m->cursor < 1) {
        if (m->scroll >= 2) {
          m->scroll = m->scroll - 2;
          m->cursor = m->cursor + 1;
        }
      } else {
        m->cursor = m->cursor - 1;
      }
    } else if (b4) {
      if (m->cursor >= 0xb) {
        if (m->scroll < m->total - 0xc) {
          m->scroll = m->scroll + 2;
          m->cursor = m->cursor - 1;
          if (m->cursor + m->scroll >= limit) {
            m->scroll = m->scroll - 2;
            m->cursor = m->cursor + 1;
          }
        }
      } else {
        m->cursor = m->cursor + 1;
        if (m->cursor + m->scroll >= limit) {
          m->cursor = m->cursor - 1;
        }
      }
    }
    m->sel = m->cursor;
    if (cursor0 != m->cursor) {
      FUN_002b69a8(m, m->mode);
    }
    break;
  }
}
}
