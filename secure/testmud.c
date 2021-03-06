// MorgenGrauen MUDlib
#pragma strong_types,save_types,rtt_checks
#pragma no_clone,no_inherit,no_shadow
#pragma pedantic, range_check

#include <files.h>
#include <config.h>

// Variablen fuer das Savefile von Jof, was dieses Objekt schreibt.
string name = "jof";
string password = "";
int level = 100;
string shell = "/std/shells/magier";

public varargs int remove(int s)
{
  destruct(this_object());
  return 1;
}

protected void create()
{
# if !defined(__TESTMUD__) && MUDHOST==__HOST_NAME__
  remove();
  return;
# endif
  seteuid(getuid(this_object()));
  if(file_size("/players/jof") == FSIZE_NOFILE)
  {
    mkdir("/players/jof");
  }
  if(file_size("/players/jof/workroom") == FSIZE_NOFILE)
  {
    copy_file("/std/def_workroom.c","/players/jof/workroom.c");
  }
  if(file_size("/secure/save/j/jof.o") == FSIZE_NOFILE)
  {
    save_object("/secure/save/j/jof");
  }
  remove();
}
