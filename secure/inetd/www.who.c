#pragma strict_types, save_types, rtt_checks, pedantic
#pragma no_clone, no_shadow, no_inherit

#include <www.h>

private string MakeLink(mixed entry)
{
  string nm;
  int idx;

  entry[1] = regreplace(entry[1], "<", "\\&lt;", 1);
  entry[1] = regreplace(entry[1], ">", "\\&gt;", 1);
  nm = getuid(entry[0]);
  if(nm == " R O O T ") return "<TT>"+entry[1][0..2]+"</TT>"+entry[1][3..];
  idx = strstr(lower_case(entry[1]), nm);
  return "<TT>"+entry[1][0..2]+"</TT>"+entry[1][3..idx-1]
       + "<A HREF=\""+MUDWWW+"?"+REQ+"="+R_FINGER+"&"+USER+"="+nm+"\"><B>"
       + entry[1][idx..idx = idx+sizeof(nm)]
       + "</B></A>"
       + entry[1][idx+1..];
}

public string Request(mapping cmds)
{
  string *who, *list; int i, s;
  if (!sizeof(cmds)) return ERROR("Anfrage ung&uuml;ltig!");
  who = allocate(s = sizeof(list = WHO));
  for(i = s; i--; i > 0) 
    who[i] = MakeLink(list[s - i - 1]);
  // who = map(WHO, #'MakeLink/*'*/);
  return "<H2>Wer ist gerade in "MUDNAME"?</H2><HR>"
       + "<OL><LI>"+implode(who, "\n<LI>")+"</OL>";
}
