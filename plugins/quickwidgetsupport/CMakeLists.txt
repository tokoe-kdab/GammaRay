# probe plugin
set(gammaray_quickwidgetsupport_srcs
  quickwidgetsupport.cpp
)
gammaray_add_plugin(gammaray_quickwidgetsupport gammaray_quickwidgetsupport.desktop ${gammaray_quickwidgetsupport_srcs})
target_link_libraries(gammaray_quickwidgetsupport gammaray_core Qt5::QuickWidgets)
