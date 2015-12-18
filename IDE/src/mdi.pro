greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

unix:INCLUDEPATH += /usr/include/libxml2
win32:INCLUDEPATH += c:/libxml2/include/libxml2
INCLUDEPATH += ./../../API
unix:QMAKE_CXXFLAGS += -std=c++0x
unix:LIBS += -L/usr/lib \
    -lxml2
win32:LIBS += -Lc:/libxml2/bin \
    -lxml2 \
    -lregex2
HEADERS = mainwindow.h \
    mdichild.h \
    ../../API/XmlReader.h \
    ../../API/Xhdl_tcl_interface.h \
    ../../API/XhdlStatic.h \
    ../../API/xhdl_simple_instruction.h \
    ../../API/xhdl_signal_editor.h \
    ../../API/XhdlSignal.h \
    ../../API/XhdlSequential.h \
    ../../API/xhdlproj_man.h \
    ../../API/XhdlProcess.h \
    ../../API/XhdlPortMap.h \
    ../../API/XhdlPlain.h \
    ../../API/XhdlPackage.h \
    ../../API/XhdlIp.h \
    ../../API/xhdl_instruction.h \
    ../../API/xhdl_if_statement.h \
    ../../API/Xhdl_gen_xml_lib.h \
    ../../API/XhdlExpression.h \
    ../../API/XhdlEnumType.h \
    ../../API/XhdlEntity.h \
    ../../API/XhdlClasses.h \
    ../../API/XhdlChecker_Process.h \
    ../../API/XhdlChecker_Entity.h \
    ../../API/XhdlChecker_Arch.h \
    ../../API/XhdlChecker.h \
    ../../API/xhdl_case_element.h \
    ../../API/xhdl_case.h \
    ../../API/XhdlBody.h \
    ../../API/xhdlarch_edit_operations.h \
    ../../API/XhdlArch.h \
    ../../API/XhdlAffectation.h \
    ../../API/vhdl_xhdl_actions.h \
    ../../API/vhdl.yacc_tab.cpp.h \
    ../../API/ninja_editor.h \
    ../../API/ninja_defines.h \
    ../../API/ninja_checker.h \
    ip_view.h \
    qentityscene.h \
    qscenebasicelement.h \
    ui_mainwindow.h \
    entity_editor_dialog.h \
    ninja_apis.h \
    qscene_inout.h \
    qentityscene_label.h \
    qscene_port.h \
    qscene_body.h \
    xs_qtreewidgetitem.h \
    ../../API/xhdl_atom.h
SOURCES = mainwindow.cpp \
    mdichild.cpp \
    ../../API/XmlReader.cpp \
    ../../API/Xhdl_tcl_interface.cpp \
    ../../API/XhdlStatic.cpp \
    ../../API/xhdl_simple_instruction.cpp \
    ../../API/xhdl_signal_editor.cpp \
    ../../API/XhdlSignal.cpp \
    ../../API/XhdlSequential.cpp \
    ../../API/xhdlproj_man.cpp \
    ../../API/XhdlProcess.cpp \
    ../../API/XhdlPortMap.cpp \
    ../../API/XhdlPlain.cpp \
    ../../API/XhdlPackage.cpp \
    ../../API/XhdlIp.cpp \
    ../../API/xhdl_instruction.cpp \
    ../../API/xhdl_if_statement.cpp \
    ../../API/Xhdl_gen_xml_lib.cpp \
    ../../API/XhdlExpression.cpp \
    ../../API/XhdlEnumType.cpp \
    ../../API/XhdlEntity.cpp \
    ../../API/XhdlChecker_Process.cpp \
    ../../API/XhdlChecker_Entity.cpp \
    ../../API/XhdlChecker_Arch.cpp \
    ../../API/XhdlChecker.cpp \
    ../../API/xhdl_case_element.cpp \
    ../../API/xhdl_case.cpp \
    ../../API/XhdlBody.cpp \
    ../../API/xhdlarch_edit_operations.cpp \
    ../../API/XhdlArch.cpp \
    ../../API/XhdlAffectation.cpp \
    ../../API/vhdl_xhdl_actions.cpp \
    ../../API/vhdl.yacc_tab.cpp \
    ../../API/ninja_editor.cpp \
    ../../API/ninja_checker.cpp \
    ../../API/libyywrap.cpp \
    ../../API/lex.yy.cpp \
    main.cpp \
    ip_view.cpp \
    qentityscene.cpp \
    qscenebasicelement.cpp \
    entity_editor_dialog.cpp \
    ninja_apis.cpp \
    qscene_inout.cpp \
    qentityscene_label.cpp \
    qscene_port.cpp \
    qscene_body.cpp \
    xs_qtreewidgetitem.cpp \
    ../../API/xhdl_atom.cpp
RESOURCES = mdi.qrc

# install
target.path = $$[QT_INSTALL_EXAMPLES]/mainwindows/mdi
sources.files = $$SOURCES \
    $$HEADERS \
    $$RESOURCES \
    $$FORMS \
    mdi.pro \
    images
sources.path = $$[QT_INSTALL_EXAMPLES]/mainwindows/mdi
INSTALLS += target \
    sources
OTHER_FILES += ../../API/Makefile
FORMS += ip_view.ui \
    mainwindow.ui \
    entity_editor_dialog.ui
