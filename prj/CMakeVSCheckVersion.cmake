# CMake Visual Studio Version Checker
# This file is part of NAppGUI-SDK project
# See README.txt and LICENSE.txt

# Check for valid Visual Studio Version
#------------------------------------------------------------------------------
macro(checkVisualStudioVersion)
    # MSVC_VERSION
    # 1930 = 17.0 Visual Studio 2022 RTW (v143 toolset)
    # 1929 = 16.10/11 Visual Studio 2019 (v142 toolset)
    # 1928 = 16.8/9 Visual Studio 2019 (v142 toolset)
    # 1927 = 16.7 Visual Studio 2019 (v142 toolset)
    # 1926 = 16.6 Visual Studio 2019 (v142 toolset)
    # 1925 = 16.5 Visual Studio 2019 (v142 toolset)
    # 1924 = 16.4 Visual Studio 2019 (v142 toolset)
    # 1923 = 16.3 Visual Studio 2019 (v142 toolset)
    # 1922 = 16.2 Visual Studio 2019 (v142 toolset)
    # 1921 = 16.1 Visual Studio 2019 (v142 toolset)
    # 1920 = 16.0 Visual Studio 2019 (v142 toolset)
    # 1916 = 15.9 Visual Studio 2017 (v141 toolset)
    # 1915 = 15.8 Visual Studio 2017 (v141 toolset)
    # 1914 = 15.7 Visual Studio 2017 (v141 toolset)
    # 1913 = 15.6 Visual Studio 2017 (v141 toolset)
    # 1912 = 15.5 Visual Studio 2017 (v141 toolset)
    # 1911 = 15.3 Visual Studio 2017 (v141 toolset)
    # 1910 = 15.0 Visual Studio 2017 (v141 toolset)
    # 1900 = 14.0 Visual Studio 2015 (v140 toolset)
    # 1800 = 12.0 Visual Studio 2013 (v120 toolset)
    # 1700 = 11.0 Visual Studio 2012 (v110 toolset)
    # 1600 = 10.0 Visual Studio 2010 (v100 toolset)
    # 1500 = 9.0 Visual Studio 2008 (v90 toolset)
    # 1400 = 8.0 Visual Studio 2005 (v80 toolset)
    # 1310 = 7.1 Visual Studio .NET 2003
    # 1300 = 7.0 Visual Studio .NET 2002
    # 1200 = 6.0 Visual Studio 6.0

    #
    # CMake Visual Studio 2015 Problem in Windows 10
    # https://gitlab.kitware.com/cmake/cmake/issues/16713
    # For solving (cmake-gui)
    # 1) Delete CMake Cache
    # 2) Push [Add Entry] Name=CMAKE_SYSTEM_VERSION ; Type=STRING ; Value=8.1
    # 3) [Configure] (Visual Studio 14 2015) Generator
    # 4) [Generate]
    # 5) That's all!
    #
    # For solving in command line
    # cmake -G "Visual Studio 14" -DCMAKE_SYSTEM_VERSION=8.1
    #

	if(MSVC_VERSION EQUAL 1400)
		set(VS_TOOLSET_NUMBER 800)
		set(CMAKE_VS_PLATFORM_TOOLSET "v80")
	elseif(MSVC_VERSION EQUAL 1500)
		set(VS_TOOLSET_NUMBER 900)
		set(CMAKE_VS_PLATFORM_TOOLSET "v90")
	else()
		# Plaform Toolset Macro
		if (${CMAKE_VS_PLATFORM_TOOLSET} STREQUAL "v143")
			set(VS_TOOLSET_NUMBER 1430)
		elseif (${CMAKE_VS_PLATFORM_TOOLSET} STREQUAL "v142")
			set(VS_TOOLSET_NUMBER 1420)
		elseif (${CMAKE_VS_PLATFORM_TOOLSET} STREQUAL "v141")
			set(VS_TOOLSET_NUMBER 1410)
		elseif (${CMAKE_VS_PLATFORM_TOOLSET} STREQUAL "v141_xp")
			set(VS_TOOLSET_NUMBER 1004)
		elseif (${CMAKE_VS_PLATFORM_TOOLSET} STREQUAL "v140")
			set(VS_TOOLSET_NUMBER 1400)
		elseif (${CMAKE_VS_PLATFORM_TOOLSET} STREQUAL "v140_xp")
			set(VS_TOOLSET_NUMBER 1003)
		elseif (${CMAKE_VS_PLATFORM_TOOLSET} STREQUAL "v120")
			set(VS_TOOLSET_NUMBER 1200)
		elseif (${CMAKE_VS_PLATFORM_TOOLSET} STREQUAL "v120_xp")
			set(VS_TOOLSET_NUMBER 1002)
		elseif (${CMAKE_VS_PLATFORM_TOOLSET} STREQUAL "v110")
			set(VS_TOOLSET_NUMBER 1100)
		elseif (${CMAKE_VS_PLATFORM_TOOLSET} STREQUAL "v110_xp")
			set(VS_TOOLSET_NUMBER 1001)
		elseif (${CMAKE_VS_PLATFORM_TOOLSET} STREQUAL "v100")
			set(VS_TOOLSET_NUMBER 1000)
		elseif (${CMAKE_VS_PLATFORM_TOOLSET} STREQUAL "v90")
			set(VS_TOOLSET_NUMBER 900)
		elseif (${CMAKE_VS_PLATFORM_TOOLSET} STREQUAL "v80")
			set(VS_TOOLSET_NUMBER 800)
		else()
			message(FATAL_ERROR "Unsupported VS Platform Toolset (${CMAKE_VS_PLATFORM_TOOLSET})")
		endif()
	endif()

endmacro()

