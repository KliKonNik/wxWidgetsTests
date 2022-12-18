set (TARGET wxCalc)
set (OUTPUT_NAME wxCalc)
set (CMAKE_INCLUDE_CURRENT_DIR ON)
set (FOLDER "wxCalc")

set (SOURCE_FILES
        wxCalcMain.hpp
        wxCalcMain.cpp
        MainWindow.hpp
        MainWindow.cpp
)

set (SOURCE_UI_WIDGETS
        Widgets/PanelButtons.hpp
        Widgets/PanelButtons.cpp
        Widgets/PanelDisplay.hpp
        Widgets/PanelDisplay.cpp
)

set (SOURCE_PUBLIC_VARIABLES
        PublicVars/InternalProjectVariables.hpp
        PublicVars/InternalProjectVariables.cpp
        PublicVars/Colors.hpp
        PublicVars/Colors.cpp
)

add_executable(${TARGET} WIN32 ${SOURCE_FILES} ${SOURCE_UI_WIDGETS} ${SOURCE_PUBLIC_VARIABLES})

set_target_properties(${TARGET} PROPERTIES FOLDER ${FOLDER})

target_link_libraries(${TARGET} ${wxWidgets_LIBRARIES})

install(TARGETS ${TARGET}
        CONFIGURATIONS Debug
        RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/bin/wxCalc/Debug
)

install(TARGETS ${TARGET}
        CONFIGURATIONS Release
        RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/bin/wxCalc/Release
)
