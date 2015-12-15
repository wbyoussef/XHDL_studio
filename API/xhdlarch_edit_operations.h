
#ifndef XHDLARCH_EDIT_OPERATIONS_H
#define XHDLARCH_EDIT_OPERATIONS_H

#include "Xhdl_tcl_interface.h"
#include "XhdlBody.h"

/// Doc : previewed operations


	/// Processes
///		=> New
	bool xhdl_edit_new_process (XhdlIp* ip, const char* arch_name, const char* process_name);
///		=> delete
	bool xhdl_edit_delete_process (XhdlIp* ip, const char* arch_name, const char* process_name);
///		=> Copy
	XhdlProcess* xhdl_edit_copy_process (XhdlIp* ip, const char* arch_name, const char* process_orig_name);

///		=> Duplicate
bool xhdl_edit_duplicate_process (XhdlIp* ip, const char* arch_name, const char* process_orig_name, const char* process_dest_name);
///		=> Paste 
///		=> Cut
///		=> Rename 
///		=> Clone 
///		=> add input 
bool xhdl_process_add_input (XhdlIp* ip, const char* arch_name, const char* process_name, const char* signal_name);
///		=> rename input 
///		=> rename output


	/// Port maps
///		=> New
///		=> delete
	bool xhdl_edit_delete_portmap (XhdlIp* ip, const char* arch_name, const char* portmap_name);
///		=> Copy
	XhdlPortMap* xhdl_edit_copy_portmap (XhdlIp* ip, const char* arch_name, const char* portmap_orig_name);
///		=> Duplicate
	bool xhdl_edit_duplicate_portmap(XhdlIp* ip, const char* arch_name, const char* portmap_orig_name, const char* portmap_dest_name);
///		=> Copy
///		=> Paste 
///		=> Cut
///		=> Rename 
///		=> Clone 
///		=> rename input 
///		=> rename output

	/// static assignements 
///		=> New
///		=> delete
	bool xhdl_edit_delete_stat (XhdlIp* ip, const char* arch_name, const char* stat_name);
	XhdlStatic* xhdl_edit_copy_stat (XhdlIp* ip, const char* arch_name, const char* stat_orig_name);
	bool xhdl_edit_duplicate_stat (XhdlIp* ip, const char* arch_name, const char* stat_orig_name, const char* stat_dest_name);
///		=> Copy
///		=> Paste 
///		=> Cut
///		=> Rename 
///		=> Clone 
///		=> rename input 
///		=> rename output

	/// Signal connexion mechanism : 
	/// everything is composed of nets, if two inputs/outputs are connected to the same net, they are 
	/// connected

#endif 