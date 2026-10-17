/* HSTMATCH module=hstp_trans_main.prx start=0x0028bdc0 end=0x0028be40 symbol=FUN_0028bdc0 lang=c99 */
/* Clone of src/eboot/FUN_0027aadc_0027aadc.c (hstclone.py tag u5cr1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: typed the five-word tail as floats; exact match verified; names and types await human review. */
typedef unsigned char undefined;
typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long long ulonglong;
typedef long long longlong;
typedef unsigned char uchar;
typedef unsigned char bool;
typedef unsigned long long undefined8;
typedef int code();
#define true 1
#define false 0
#define ABS(x) ((x) < 0 ? -(x) : (x))
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;


typedef struct {
  unsigned char bytes[5];
  unsigned char padding[3];
  unsigned int words[5];
  float values[5];
} Record;

Record *FUN_0028bdc0(Record *param_1,Record *param_2)
{
  param_1->bytes[0] = param_2->bytes[0];
  param_1->bytes[1] = param_2->bytes[1];
  param_1->bytes[2] = param_2->bytes[2];
  param_1->bytes[3] = param_2->bytes[3];
  param_1->bytes[4] = param_2->bytes[4];
  param_1->words[0] = param_2->words[0];
  param_1->words[1] = param_2->words[1];
  param_1->words[2] = param_2->words[2];
  param_1->words[3] = param_2->words[3];
  param_1->words[4] = param_2->words[4];
  param_1->values[0] = param_2->values[0];
  param_1->values[1] = param_2->values[1];
  param_1->values[2] = param_2->values[2];
  param_1->values[3] = param_2->values[3];
  param_1->values[4] = param_2->values[4];
  return param_1;
}
