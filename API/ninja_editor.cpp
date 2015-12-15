
#include "ninja_editor.h"
#include "XhdlArch.h"
#include "XhdlIp.h"
#include "XhdlBody.h"
#include "XhdlEntity.h"
#include "XhdlEnumType.h"
#include "XmlReader.h"
#include "Xhdl_tcl_interface.h"

bool import_port_map (XhdlIp* ip,const char* arch_name,const char* map_name, const char* filename)
{
  // check if arh exists
  if ( !does_arch_exist (ip, arch_name))
    return false;
  // check if filename exists 
  // load external IP
  XhdlIp *tmp_ip = new XhdlIp ();
  tmp_ip->openXmlDoc(filename);
  tmp_ip->setIp();
  // add  a blank map
  add_port_map (ip,arch_name,map_name,(tmp_ip->entity->name).c_str());
  
  // fill map
  vector<XhdlSignal*>::const_iterator iter;
  for (iter=(ip->entity->list_bus).begin(); iter != (ip->entity->list_bus).end(); iter++)
    {
      add_port_map_connexion (
			      ip,arch_name,map_name,(*iter)->name.c_str(),(string (map_name) + string ("_") + (*iter)->name).c_str());
    }
  return true;
}

bool add_port_map_connexion (XhdlIp* ip, const char* arch_name, const char* map_name, const char* from_name,const char* to_name)
{
  if (does_map_exist (ip, arch_name, map_name))
    {
      XhdlPortMap *map ;
      map = get_map (ip,arch_name,map_name) ;
      if (map != NULL)
	{
	  XhdlPortMap::connection connect;
	  connect.formal = from_name;
	  connect.actual = to_name;
	  map->list_connect.push_back (connect);
	  return true;
	}
      
    } else
      {
	return false;
      }
  return false;
  
}


bool add_port_map (XhdlIp* ip, const char* arch_name, const char* map_name, const char* component_name)
{
  XhdlArch *arch;
  if ( does_arch_exist (ip, arch_name))
    arch = get_arch (ip, arch_name);
  else
    return false;
  
  if (does_map_exist (ip, arch_name, map_name))
    return false;
  else
    {
      XhdlPortMap *map = new XhdlPortMap(arch->body);
      map->label = map_name;
      map->component_name = component_name;
      map->list_connect.clear();
      arch->body->list_maps.push_back (map);
      return true;
    };
}


bool rename_arch (XhdlIp* ip, const char* old_arch_name, const char* new_arch_name)
{
  vector<XhdlArch*>::const_iterator iter;
  for (iter=(ip->list_arch).begin(); iter != (ip->list_arch).end(); iter++)
    {
      if (((&(*(*iter)))->name) == old_arch_name)
	{
	  (&(*(*iter)))->name   = new_arch_name;
	  return  true;
	} 
    }
  return false;
}    



XhdlArch* arch_load_from_xml (const char* filename)
{
  XhdlArch * return_arch = new XhdlArch(NULL);
  // open Xml File 
  XmlReader* xmlrd = new XmlReader ;
  xmlrd->openDoc(filename) ;
  return_arch->fillObject(xmlrd);
  return return_arch ;
}


XhdlArch* arch_load_from_string (char* doc_stream)
{
  XhdlArch * return_arch = new XhdlArch(NULL);
  // open Xml File 
  XmlReader* xmlrd = new XmlReader ;
  xmlrd->open_stream(doc_stream) ;
  return_arch->fillObject(xmlrd);
  return return_arch ;
}

const char* get_arch_name (XhdlArch* arch)
{	
  return arch->name.c_str();
}




bool clone_enum (XhdlEnumType* src, XhdlEnumType* Dest)
{
  Dest->name = src->name;
  vector <string>::const_iterator iter ;
  for ( iter = src->enumlist.begin () ; iter != src->enumlist.end () ; iter ++ )
    {
      Dest->enumlist.push_back (*iter);
    }
  
  
  return true;
}


bool clone_arch (XhdlArch* src, XhdlArch* Dest)
{
  //name
  Dest->name = src->name;  
  // type
  Dest->name = src->name;
  // list_bus
  // list_enum_type
  vector <XhdlEnumType*>::const_iterator iter ;
  for ( iter = src->list_enumtype.begin () ; iter != src->list_enumtype.end () ; iter ++ )
    { //TODO 
      
    }
  
  
  // parent
  Dest->parent = src->parent; 
  // xml_signals 
  
  return true;
}



/// adds architecture to current IP 
bool add_arch (XhdlIp* ip, const char* arch_name)
{
  
  if (does_arch_exist (ip, arch_name))
    {
      return false;
    } else 
      {
	XhdlArch* arch  = new XhdlArch (ip);
	arch->name = arch_name;
	ip->list_arch.push_back (arch); 
	return true;	
      }
  
}


// Ninja gui edit operations 
// portmap rename connxion
// 
