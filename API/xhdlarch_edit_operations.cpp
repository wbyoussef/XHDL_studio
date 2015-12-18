#include "xhdlarch_edit_operations.h"
#include "Xhdl_tcl_interface.h"
#include "XhdlBody.h"
#include "Xhdl_gen_xml_lib.h"

#include "XmlReader.h"


/// Doc : previewed operations

bool xhdl_edit_new_process (XhdlIp* ip, const char* arch_name, const char* process_name)
{
  XhdlArch* arch = get_arch (ip,arch_name);
  
  if (arch == NULL)
    return false;
  //
  XhdlProcess *new_process = new XhdlProcess (arch->body);
  new_process->label = process_name; 
  arch->body->list_process.push_back(new_process);
  return true;
}


///		=> delete
bool xhdl_edit_delete_process (XhdlIp* ip, const char* arch_name, const char* process_name)
{
  XhdlArch* arch = get_arch (ip,arch_name);
  
  if (arch == NULL)
    
    return false;
  string process_label = string ( process_name);
  vector <XhdlProcess*>::iterator process_iter;
  for ( process_iter = (arch->body->list_process).begin (); process_iter != (arch->body->list_process).end (); process_iter ++)
    {
      if ( process_label == (*process_iter)->label )
	{
	  (arch->body->list_process).erase (process_iter);
	  
	  return true; 
	}
    }
  return true; 
}


///		=> Copy

XhdlProcess* xhdl_edit_copy_process (XhdlIp* ip, const char* arch_name, const char* process_orig_name)
  
{
  XhdlArch* arch = get_arch (ip,arch_name);
  if (arch == NULL)
    return NULL;
  
  // Get a pointer to original process
  XhdlProcess* orig_process = get_process (ip, arch_name, process_orig_name);
  // get ; process's xml
  string orig_process_xml = process_get_xml (orig_process);
  // build a process from xml 
  XhdlProcess *new_process = new XhdlProcess (arch->body);
  XmlReader *reader = new XmlReader ();
  reader->open_stream (const_cast <char *> ( orig_process_xml.c_str()));
  reader->moveToParent();
  new_process->fillObject (reader);
  return new_process;
}

bool xhdl_edit_duplicate_process (XhdlIp* ip, const char* arch_name, const char* process_orig_name, const char* process_dest_name)
  
{
  XhdlArch* arch = get_arch (ip,arch_name);
  if (arch == NULL)
    return false;
  
  XhdlProcess* new_process = xhdl_edit_copy_process  (ip, arch_name, process_orig_name);
  new_process->label = string (process_dest_name);
  (arch->body->list_process).push_back (new_process);
  return true;
}



///		=> Paste 
///		=> Cut
///		=> Rename 
///		=> Clone 
///		=> add input
bool xhdl_process_add_input (XhdlIp* ip, const char* arch_name, const char* process_name, const char* signal_name)
{
  
  return true;
}

///		=> rename input 
///		=> rename output





///		=> delete
bool xhdl_edit_delete_portmap (XhdlIp* ip, const char* arch_name, const char* portmap_name)
{
  XhdlArch* arch = get_arch (ip,arch_name);
  if (arch == NULL)
    return false;
  
  string portmap_label = string ( portmap_name);
  vector <XhdlPortMap*>::iterator portmap_iter;
  for ( portmap_iter = (arch->body->list_maps).begin (); portmap_iter != (arch->body->list_maps).end (); portmap_iter ++)
    {
      if ( portmap_label == (*portmap_iter)->label )
	{
	  (arch->body->list_maps).erase (portmap_iter);
	  return true;
	}
    }
  return true; 
}


///		=> Copy

XhdlPortMap* xhdl_edit_copy_portmap (XhdlIp* ip, const char* arch_name, const char* portmap_orig_name)
{
  XhdlArch* arch = get_arch (ip,arch_name);
  if (arch == NULL)
    return NULL;
  
  // Get a pointer to original portmap
  XhdlPortMap* orig_portmap = get_map (ip, arch_name, portmap_orig_name);
  // get ; portmap's xml
  string orig_portmap_xml = map_get_xml(orig_portmap);
  // build a portmap from xml 
  XhdlPortMap *new_portmap = new XhdlPortMap (arch->body);
  XmlReader *reader = new XmlReader ();
  reader->open_stream (const_cast <char *> ( orig_portmap_xml.c_str()));
  reader->moveToParent();
  new_portmap->fillObject (reader);
  return new_portmap;
}

bool xhdl_edit_duplicate_portmap (XhdlIp* ip, const char* arch_name, const char* portmap_orig_name, const char* portmap_dest_name)
{
  XhdlArch* arch = get_arch (ip,arch_name);
  if (arch == NULL)
    return false;
  
  XhdlPortMap* new_portmap = xhdl_edit_copy_portmap  (ip, arch_name, portmap_orig_name);
  new_portmap->label = string (portmap_dest_name);
  (arch->body->list_maps).push_back (new_portmap);
  return true;
}



///		=> Copy
///		=> Paste 
///		=> Cut
///		=> Rename 
///		=> Clone 
///		=> rename input 
///		=> rename output





///		=> delete
bool xhdl_edit_delete_stat (XhdlIp* ip, const char* arch_name, const char* stat_name)
  
{
  XhdlArch* arch = get_arch (ip,arch_name);
  if (arch == NULL)
    return false;
  
  string stat_label = string ( stat_name);
  vector <XhdlStatic*>::iterator stat_iter;
  for ( stat_iter = (arch->body->list_stat).begin (); stat_iter != (arch->body->list_stat).end (); stat_iter ++)
    {
      if ( stat_label == (*stat_iter)->aff->output )
	{
	  (arch->body->list_stat).erase (stat_iter);
	  
	  return true;
	}
    }
  return true; 
}


///		=> Copy

XhdlStatic* xhdl_edit_copy_stat (XhdlIp* ip, const char* arch_name, const char* stat_orig_name)
{
  XhdlArch* arch = get_arch (ip,arch_name);
  if (arch == NULL)
    return NULL;
  
  // Get a pointer to original stat
  XhdlStatic* orig_stat = get_stat (ip, arch_name, stat_orig_name);
  // get ; static assignement's xml
  string orig_stat_xml = stat_get_xml(orig_stat);
  // build a static assignement from xml 
  XhdlStatic *new_stat = new XhdlStatic (arch->body);
  XmlReader *reader = new XmlReader ();
  reader->open_stream (const_cast <char *> ( orig_stat_xml.c_str()));
  reader->moveToParent();
  new_stat->fillObject (reader);
  return new_stat;
}


bool xhdl_edit_duplicate_stat (XhdlIp* ip, const char* arch_name, const char* stat_orig_name, const char* stat_dest_name)
{
  XhdlArch* arch = get_arch (ip,arch_name);
  if (arch == NULL)
    return false;
  
  XhdlStatic* new_stat = xhdl_edit_copy_stat  (ip, arch_name, stat_orig_name);
  new_stat->aff->output = string (stat_dest_name);
  (arch->body->list_stat).push_back (new_stat);
  return true;
}




///		=> Copy
///		=> Paste 
///		=> Cut
///		=> Rename 
///		=> Clone 
///		=> rename input 
///		=> rename output


