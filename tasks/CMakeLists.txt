# Generated from orogen/lib/orogen/templates/tasks/CMakeLists.txt

include(inclinometer_solar2TaskLib)
ADD_LIBRARY(${INCLINOMETER_SOLAR2_TASKLIB_NAME} SHARED 
    ${INCLINOMETER_SOLAR2_TASKLIB_SOURCES})
add_dependencies(${INCLINOMETER_SOLAR2_TASKLIB_NAME}
    regen-typekit)



TARGET_LINK_LIBRARIES(${INCLINOMETER_SOLAR2_TASKLIB_NAME}
    ${OrocosRTT_LIBRARIES}
    ${QT_LIBRARIES}
    ${INCLINOMETER_SOLAR2_TASKLIB_DEPENDENT_LIBRARIES})
SET_TARGET_PROPERTIES(${INCLINOMETER_SOLAR2_TASKLIB_NAME}
    PROPERTIES LINK_INTERFACE_LIBRARIES "${INCLINOMETER_SOLAR2_TASKLIB_INTERFACE_LIBRARIES}")
SET_TARGET_PROPERTIES(${INCLINOMETER_SOLAR2_TASKLIB_NAME}
    PROPERTIES INTERFACE_LINK_LIBRARIES "${INCLINOMETER_SOLAR2_TASKLIB_INTERFACE_LIBRARIES}")

INSTALL(TARGETS ${INCLINOMETER_SOLAR2_TASKLIB_NAME}
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib/orocos)

INSTALL(FILES ${INCLINOMETER_SOLAR2_TASKLIB_HEADERS}
    DESTINATION include/orocos/inclinometer_solar2)

