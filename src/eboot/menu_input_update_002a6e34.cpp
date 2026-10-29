/* HSTMATCH module=EBOOT.BIN start=0x002a6e34 end=0x002a7218 symbol=FUN_002a6e34 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Scrolling list menu input: four button polls (up, down, left, right) move the cursor/scroll window of a 38-row page; mode 0 handles all four buttons (up/down step by two rows), mode 1 only left/right. Matching idioms: a switch (case 0, case 1) on the mode; if/else-if chains over the buttons; cursor/scroll updates written as relative member updates (m->cursor = m->cursor + 2; ... m->cursor = m->cursor - 1) so the stored value is reused from a register; 'x >= limit' (not 'limit <= x') gives slt v1 instead of at; the final loop walks the parameter pointer for the item table and a copy for the name rows. */
#include "hst/pad_buttons.h"

#define ROW_COUNT 38      /* rows in the page */
#define VISIBLE_ROWS 12   /* rows shown at once; the cursor moves inside this window */

/* Pad masks for the other two directions (left and right come from pad_buttons.h). */
enum { MENU_PAD_UP = 0x10, MENU_PAD_DOWN = 0x40 };

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
  Item *items[ROW_COUNT];
  char pad_328[0x38];
  Row rows[ROW_COUNT];
  char pad_1660[4];
  int mode;
  int cursor;
  int scroll;
  int total;
  int sel;
  int up_poll, down_poll, left_poll, right_poll;
};

extern "C" {
extern char *DAT_003415a8;
bool FUN_001fe080(int *, int, int);
int FUN_002af274(char *);
void FUN_002a734c(Menu *);
void FUN_002a7218(Menu *, int);
void FUN_0010d4a8();

void FUN_002a6e34(Menu *menu)
{
  bool up = FUN_001fe080(&menu->up_poll, MENU_PAD_UP, 0x300);
  bool down = FUN_001fe080(&menu->down_poll, MENU_PAD_DOWN, 0x300);
  bool left = FUN_001fe080(&menu->left_poll, PAD_LEFT, 0x300);
  bool right = FUN_001fe080(&menu->right_poll, PAD_RIGHT, 0x300);
  int scroll0 = menu->scroll;
  int cursor0 = menu->cursor;
  int limit = FUN_002af274(DAT_003415a8 + 0x87128);
  if (menu->rows[0].flag == 0) {
    return;
  }
  switch (menu->mode) {
  case 0:
    if (up) {
      if (menu->cursor < 2) {
        if (menu->scroll >= 2) {
          menu->scroll = menu->scroll - 2;
        }
      } else {
        menu->cursor = menu->cursor - 2;
      }
    } else if (down) {
      if (menu->cursor >= VISIBLE_ROWS - 2) {
        int v = menu->scroll;
        if (v < menu->total - VISIBLE_ROWS) {
          menu->scroll = v + 2;
          int n = menu->cursor + menu->scroll;
          if (limit == n) {
            menu->cursor = menu->cursor - 1;
          } else if (limit < n) {
            menu->scroll = menu->scroll - 2;
          }
        }
      } else {
        menu->cursor = menu->cursor + 2;
        int n = menu->cursor + menu->scroll;
        if (limit == n) {
          menu->cursor = menu->cursor - 1;
        } else if (limit < n) {
          menu->cursor = menu->cursor - 2;
        }
      }
    } else if (left) {
      if (menu->cursor < 1) {
        if (menu->scroll >= 2) {
          menu->scroll = menu->scroll - 2;
          menu->cursor = menu->cursor + 1;
        }
      } else {
        menu->cursor = menu->cursor - 1;
      }
    } else if (right) {
      if (menu->cursor >= VISIBLE_ROWS - 1) {
        if (menu->scroll < menu->total - VISIBLE_ROWS) {
          menu->scroll = menu->scroll + 2;
          menu->cursor = menu->cursor - 1;
          if (menu->cursor + menu->scroll >= limit) {
            menu->scroll = menu->scroll - 2;
            menu->cursor = menu->cursor + 1;
          }
        }
      } else {
        menu->cursor = menu->cursor + 1;
        if (menu->cursor + menu->scroll >= limit) {
          menu->cursor = menu->cursor - 1;
        }
      }
    }
    menu->sel = menu->cursor;
    if (menu->scroll == scroll0) {
      return;
    }
    FUN_002a734c(menu);
    {
      int i = 0;
      char *p = (char *)menu;
      do {
        Item *it = *(Item **)((char *)menu + 0x290);
        it->name = p + 0x361;
        it->flag = 1;
        FUN_0010d4a8();
        i++;
        menu = (Menu *)((char *)menu + 4);
        p += 0x80;
      } while (i < ROW_COUNT);
    }
    break;
  case 1:
    if (left) {
      if (menu->cursor < 1) {
        if (menu->scroll >= 2) {
          menu->scroll = menu->scroll - 2;
          menu->cursor = menu->cursor + 1;
        }
      } else {
        menu->cursor = menu->cursor - 1;
      }
    } else if (right) {
      if (menu->cursor >= VISIBLE_ROWS - 1) {
        if (menu->scroll < menu->total - VISIBLE_ROWS) {
          menu->scroll = menu->scroll + 2;
          menu->cursor = menu->cursor - 1;
          if (menu->cursor + menu->scroll >= limit) {
            menu->scroll = menu->scroll - 2;
            menu->cursor = menu->cursor + 1;
          }
        }
      } else {
        menu->cursor = menu->cursor + 1;
        if (menu->cursor + menu->scroll >= limit) {
          menu->cursor = menu->cursor - 1;
        }
      }
    }
    menu->sel = menu->cursor;
    if (cursor0 != menu->cursor) {
      FUN_002a7218(menu, menu->mode);
    }
    break;
  }
}
}
