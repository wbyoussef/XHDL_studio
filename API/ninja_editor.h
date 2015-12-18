#ifndef NINJA_EDITOR_H
#define NINJA_EDITOR_H
/* 
TODO  :

COPY FUNCTIONS :
	* Copy arch


	* add architecture
	* rename architecture 
	* delete architecture
	* duplicate architecture

	* add a port_map    => Done 
	* add a port_map.connexion
	* rename a port_map.source 
	* rename a port_map.destination
	* change a port_map.label

DONE :
	* load arch from XML file
	* load arch from XML stream
	* copy/paste enum
	* ON PROGRESS : clone architecture 




*/
class XhdlIp;
class XhdlArch;
class XhdlEnumType;

bool rename_arch (XhdlIp* ip, const char* old_arch_name, const char* new_arch_name);
XhdlArch* arch_load_from_xml (const char* filename);
XhdlArch* arch_load_from_string (const char* doc_stream);
const char* get_arch_name (XhdlArch* arch);
bool clone_enum (XhdlEnumType* src, XhdlEnumType* Dest);
bool clone_arch (XhdlArch* src, XhdlArch* Dest);






bool add_arch (XhdlIp* ip, const char* arch_name);
bool add_port_map (XhdlIp* ip, const char* arch_name, const char* map_name, const char* component_name);
bool add_port_map_connexion (XhdlIp* ip, const char* arch_name, const char* map_name, const char* from_name,const char* to_name);
bool import_port_map (XhdlIp* ip,const char* arch_name,const char* map_name, const char* filename);


#endif
