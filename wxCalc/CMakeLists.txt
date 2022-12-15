set (TARGET wxCalc)
set (OUTPUT_NAME wxCalc)

set (SOURCE_FILES
        Calc_wxw.cpp
        Calc_wxw.hpp
)

add_executable (${TARGET} WIN64 ${SOURCE_FILES})

target_link_libraries(${TARGET} wx::core wx::base)

install(TARGETS ${TARGET}
        CONFIGURATIONS Debug
        RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/bin/wxCalc/Debug
)

install(TARGETS ${TARGET}
        CONFIGURATIONS Release
        RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/bin/wxCalc/Release
)
