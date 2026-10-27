/* HSTMATCH module=hstp_trans_main.prx start=0x0022452c end=0x002245c0 symbol=FUN_0022452c lang=c++ */
/* Hand-written reconstruction from the disassembly (matching idiom: the result `int r = 0;` is declared before the float local; declared after it, MWCC colours the address temporaries v1/v0 instead of retail's a0/v1, 7 words); exact match verified; names and types await human review. */
/* Reads the float at +0x494 of the other player (players[side ^ 1] of the game object) and returns
   1 when it is zero, 2 when its sign agrees with the sign of the int at +0x58 of DAT_003e1e84,
   otherwise 0 (C++: the two comparison results are bools, masked with andi 0xff). */
struct Player { char pad[0x494]; float f494; };
struct Game { char pad[0x70]; Player *players[2]; };
struct Cfg { char pad[0x58]; int n; };
struct Self { char pad[0x148]; unsigned int side; };

extern "C" {
extern Game *DAT_003e19f0;
extern Cfg *DAT_003e1e84;

int FUN_0022452c(Self *self)
{
  int r = 0;
  float f = DAT_003e19f0->players[self->side ^ 1]->f494;
  if (f == 0.0f) {
    r = 1;
  } else if ((f > 0.0f) == ((float)DAT_003e1e84->n > 0.0f)) {
    r = 2;
  }
  return r;
}
}
