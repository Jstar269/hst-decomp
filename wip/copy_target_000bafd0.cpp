/* HSTMATCH module=EBOOT.BIN start=0x000bafd0 end=0x000bb034 symbol=FUN_000bafd0 lang=c++ */
/* Hand-written reconstruction from the disassembly; near miss (7 of 25 words differ). */
/* Copies the six target bytes (a MAC address) into a local buffer, hands the buffer to the
   adhoc-matching call FUN_002b7dc8 together with the manager pointer at +0x16c of the object and
   reports the result: a negative result is logged with FUN_000ba3ac(DAT_002d51e0, code) and the
   function returns false, anything else returns true.
   Matching idioms that DID work: the copy is the compiler-generated memberwise copy of a six-byte
   class (a user-declared constructor makes the copy memberwise, and MWCC copies it as a loop of
   three two-byte element copies: lb/lb/sb/sb with the counter decrement between the loads and the
   stores). The signed byte loads (lb, not lbu) mean the members are plain char.
   What still differs: only the two registers of the copy loop. Retail keeps the destination
   pointer in t1 and the element counter in t0, every spelling tried here keeps them in a3 and a2
   (the generated copy's own temp pool). Tried: the struct as unsigned char[6], char[6], three
   two-byte members, three short members, six char members, a copy constructor instead of the
   assignment, an explicit copy loop, a user-defined operator=, extra (unused) function
   parameters, and a four-parameter prototype for the callee - all produce the same a3/a2
   allocation. */
struct Target { unsigned char id[6]; Target() {} };

struct Obj {
  char pad[0x16c];
  void *f16c;
};

extern "C" {
extern char DAT_002d51e0[];
int FUN_002b7dc8(void *a, void *b);
void FUN_000ba3ac(char *msg, int code);
}

extern "C" bool FUN_000bafd0(Obj *self, unsigned char *param_2)
{
  Target t;
  t = *(Target *)param_2;
  int r = FUN_002b7dc8(self->f16c, &t);
  if (r < 0) {
    FUN_000ba3ac(DAT_002d51e0, r);
    return 0;
  }
  return 1;
}
// near miss from lane km2 (unreviewed)
