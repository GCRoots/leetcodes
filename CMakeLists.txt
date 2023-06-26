cmake_minimum_required(VERSION 3.19)
project(leetcodes)

set(CMAKE_CXX_STANDARD 14)

set(DEMOS
        01_easy
        02_medium
        03_hard
        )


foreach(_dir IN ITEMS ${DEMOS})
    file(GLOB _files "${_dir}/*.cpp")
    message(STATUS "Pattern `${_dir}':")

    foreach(_file IN ITEMS ${_files})

        get_filename_component(_file_name
                ${_file} NAME
                )
        set(_project_name "${_file_name}")
        message(STATUS "  ${_dir}/${_file_name} is going to be built")

        add_executable(${_project_name} "${_dir}/${_file_name}")
    endforeach()

endforeach()
