/* HSTMATCH module=EBOOT.BIN start=0x002156a0 end=0x00215734 symbol=FUN_002156a0 lang=c++ */
/* Hand-written reconstruction from the disassembly (twin of src/sharing_main/opponent_sign_test_0022452c.cpp with the addresses substituted; matching idiom: the result `int r = 0;` is declared before the float local, which gives retail's a0/v1 address temporaries); exact match verified; names and types await human review. */
/* Reads the float at +0x494 of the other player (players[side ^ 1] of the game object) and returns
   1 when it is zero, 2 when its sign agrees with the sign of the int at +0x58 of DAT_00338b44,
   otherwise 0 (C++: the two comparison results are bools, masked with andi 0xff). */
struct Player { char pad[0x494]; float f494; };
struct Game { char pad[0x70]; Player *players[2]; };
struct Cfg { char pad[0x58]; int n; };
struct Self { char pad[0x148]; unsigned int side; };

extern "C" {
extern Game *DAT_003386b0;
extern Cfg *DAT_00338b44;

int FUN_002156a0(Self *self)
{
  int r = 0;
  float f = DAT_003386b0->players[self->side ^ 1]->f494;
  if (f == 0.0f) {
    r = 1;
  } else if ((f > 0.0f) == ((float)DAT_00338b44->n > 0.0f)) {
    r = 2;
  }
  return r;
}
}
