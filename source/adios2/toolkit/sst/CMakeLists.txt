add_library(sst
  dp/dp.c
  dp/dummy_dp.c
  cp/cp.c
  cp/cp_common.c
)

target_compile_features(sst PRIVATE c_std_99)
target_include_directories(sst PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(sst PRIVATE EVPath::EVPath)
target_link_libraries(sst PUBLIC MPI::MPI_C)

install(TARGETS sst EXPORT adios2Exports
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
