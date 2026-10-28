/* HSTMATCH module=EBOOT.BIN start=0x001fe8c0 end=0x001fe974 symbol=FUN_001fe8c0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: typed the mixed word, byte, and float record members and grouped the two-float tail; exact match verified; names and types await human review. */

typedef struct { float f[4]; } Float4;
typedef struct { float f[2]; } Float2;
typedef struct {
  unsigned int word;
  unsigned char bytes[4];
  union { Float4 vector; unsigned int u[4]; } vector;
  union { Float2 pair; float f[2]; unsigned int u[2]; } tail;
} Record;

void FUN_001fe8c0(Record *param_1)
{
  int iVar1 = 0;
  do {
    if (iVar1 == 9) {
      param_1->word = 0x7fffffff;
      param_1->bytes[0] = 0;
      param_1->bytes[1] = 0;
      param_1->bytes[2] = 0;
      param_1->bytes[3] = 0;
      param_1->vector.u[0] = 0x7fffffff;
      param_1->vector.u[1] = 0x7fffffff;
      param_1->vector.u[2] = 0x7fffffff;
      param_1->vector.u[3] = 0x7fffffff;
      param_1->tail.u[0] = 0x7fffffff;
      param_1->tail.u[1] = 0x7fffffff;
    }
    else {
      param_1->word = param_1[1].word;
      param_1->bytes[0] = param_1[1].bytes[0];
      param_1->bytes[1] = param_1[1].bytes[1];
      param_1->bytes[2] = param_1[1].bytes[2];
      param_1->bytes[3] = param_1[1].bytes[3];
      param_1->vector.vector = param_1[1].vector.vector;
      param_1->tail.pair = param_1[1].tail.pair;
    }
    iVar1 = iVar1 + 1;
    param_1 = param_1 + 1;
  } while (iVar1 < 10);
}
