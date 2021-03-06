#
# Sources.cmake
# This file contains a list of all sources which will be included in this module.
# *** NO GLOBBING ***
#

SET(MODULE_SRC
	# 
	collection/fixedarraystack.h
	collection/fixedqueue.h
	collection/linkedliststack.h
	collection/linkedqueue.h
	collection/resizablestack.h
	collection/resizablequeue.h
	sort/heap.h
	sort/sort.h
	union-find/quickfind.h
	union-find/quickunionpathcompression.h
	union-find/weightedquickunion.h
	
	# Sources
	union-find/quickfind.cpp
	union-find/quickunionpathcompression.cpp
	union-find/weightedquickunion.cpp

	)

#
# Platform dependent sources.
#
IF (${CMAKE_SYSTEM_NAME} MATCHES "Windows")
	SET(MODULE_PLATFORM_SRC
		
		)
ELSEIF(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
	SET(MODULE_PLATFORM_SRC
		)
ENDIF()

#
# Merge sources.
#
SET(MODULE_SOURCES ${MODULE_SRC} ${MODULE_PLATFORM_SRC} Sources.cmake)

#
# Define source groups.
#
SOURCE_GROUP(union-find "union-find/*")
SOURCE_GROUP(collection "collection/*")
