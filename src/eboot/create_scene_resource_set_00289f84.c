/* HSTMATCH module=EBOOT.BIN start=0x00289f84 end=0x0028a230 symbol=FUN_00289f84 lang=c99 data=0x002fec24 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. Data: its string literals (8 strings, 0x002fec24-0x002fed41) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Ghidra pseudocode corrected by hand: allocation failure labels, cleanup returns, and final string selection were matched to retail; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/scene_res.h"

#define PATH_SIZE 256
#define MODEL_OBJ_SIZE 0x30  /* size of a model object */
#define MOTION_OBJ_SIZE 0x10 /* size of a motion object */
#define SET_SIZE 0x10        /* size of the resource set */

extern void FUN_00000a00();
extern void *FUN_00000bcc();
extern void FUN_000143b0();
extern SceneModel *FUN_00053670();
extern int FUN_00053718();
extern void *FUN_00055df8();

/* Load the model, collision, break model and motion of item `item` at level `level` below `base_dir`; null when the model is missing. */
SceneResSet * FUN_00289f84(u32 unused,char *base_dir,u32 level,u32 item)
{
  SceneResSet *set;
  SceneModel *res;
  void *motion;
  u8 model_path [PATH_SIZE];
  u8 col_script_path [PATH_SIZE];
  u8 motion_path [PATH_SIZE];
  u8 texture_dir [PATH_SIZE];
  u8 attr_dir [PATH_SIZE];
  
  set = (SceneResSet *)FUN_00000bcc(SET_SIZE);
  if (set != (SceneResSet *)0x0) {
    set->model = 0;
    set->collision = 0;
    set->breakModel = 0;
    set->motion = 0;
  }
  FUN_000143b0(model_path,"%s/item/item%03d/L%02d_item%03d.i3r",base_dir,item,level,
               item);
  FUN_000143b0(texture_dir,"%s/item/sourceimages/",base_dir);
  res = (SceneModel *)FUN_00000bcc(MODEL_OBJ_SIZE);
  if (res == 0) goto first_allocation_failed;
  res = FUN_00053670(res,model_path,texture_dir,0,0,0,3);
  set->model = res;
  goto first_allocation_done;
first_allocation_failed:
  set->model = res;
first_allocation_done:
  ;
  if (res->data == 0) {
    if (res != 0) {
      FUN_00053718(res,1);
      set->model = 0;
    }
    if (set == (SceneResSet *)0x0) goto cleanup_done;
    FUN_00000a00(set);
    set = (SceneResSet *)0x0;
cleanup_done:
    return set;
  }
  else {
    FUN_000143b0(attr_dir,"%s/attr/",base_dir);
    FUN_000143b0(model_path,"%s/item/item%03d/L%02d_item%03d_col.i3r",base_dir,item,level,
                 item);
    FUN_000143b0(col_script_path,"%s/item/item%03d/L%02d_item%03d_col.i3c",base_dir,item,level,
                 item);
    res = (SceneModel *)FUN_00000bcc(MODEL_OBJ_SIZE);
    if (res == 0) goto allocation_one_failed;
    res = FUN_00053670(res,model_path,attr_dir,col_script_path,attr_dir,0,0);
    set->collision = res;
    goto allocation_one_done;
allocation_one_failed:
    set->collision = res;
allocation_one_done:
    ;
    if (res->data == 0) {
      if (res == 0) goto second_destroy_done;
      FUN_00053718(res,1);
      set->collision = 0;
    }
second_destroy_done:
    ;
    FUN_000143b0(model_path,"%s/item/item%03d/L%02d_item%03d_Break.i3r",base_dir,item,level,
                 item);
    res = (SceneModel *)FUN_00000bcc(MODEL_OBJ_SIZE);
    if (res == 0) goto allocation_two_failed;
    res = FUN_00053670(res,model_path,texture_dir,0,0,0,0);
    set->breakModel = res;
    goto allocation_two_done;
allocation_two_failed:
    set->breakModel = res;
allocation_two_done:
    ;
    if (res->data == 0) {
      if (res != 0) {
        FUN_00053718(res,1);
        set->breakModel = 0;
      }
    }
    res = set->breakModel;
    if (res != 0) {
      FUN_000143b0(motion_path,"%s/item/item%03d/L%02d_item%03d_Break.i3m",base_dir,item,level,
                   item);
    }
    else {
      FUN_000143b0(motion_path,"%s/item/item%03d/L%02d_item%03d_motion01.i3m",base_dir,item,level,
                   item);
    }
    motion = FUN_00000bcc(MOTION_OBJ_SIZE);
    if (motion == 0) goto allocation_three_failed;
    motion = FUN_00055df8(motion,motion_path,0);
    set->motion = motion;
    goto allocation_three_done;
allocation_three_failed:
    set->motion = motion;
allocation_three_done:
    ;
  }
  return set;
}
