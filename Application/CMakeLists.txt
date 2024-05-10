target_include_directories(CommonCode INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_sources(CommonCode INTERFACE
    Application.h
    main.cpp
)