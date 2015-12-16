
# {{{ load application
load ./ninja_verif.dll
load ./ninja_base.dll Xhdl
load ./gen_xml.dll
load ./ninja_editor.dll
load ninja_checker.dll
# }}}
set BIN_DIR [pwd]
 source ./wrappers.tcl
source ../tcl/ninja_editor_wrapp.tcl
source ../tcl/ninja_verif_wrapp.tcl
source ../tcl/xhdlarch_edit_operations.tcl
source ../tcl/ninja_checker.tcl