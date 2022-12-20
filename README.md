# wxWidgets training project

## Important note before start:

Project includes "preInstalledLibs" and "submodules" branches. wxWidgets code is the same for both branches. The difference is in the way of wxWidgets library connection. "main" branch is equal with "submodules" branch.
Setting up and working with the "submodules" branch is easier. Doing steps 1, 7 and 8 will be enough. If you have an empty "3rdParty" folder after "git clone" you'll have to run "git submodule update --init --recursive".

## Steps of workplace preparation (Microsoft Visual Studio):

1. Download and install CMake (https://cmake.org/download/)
2. Go to https://www.wxwidgets.org/downloads/ and download "Source Code" in any format which you prefer. (I used "Windows 7z")
3. Unpack/install this file to some directory. (further in the text: <wxDirPath>)
4. Go to <wxDirPath>/build/msw and open apropriate Visual Studio solution. (I used wx_vc17.sln)
5. Go to "Batch build" (Build -> Batch build) and check the library components you need or check all if you have enough disk space. (approximately ~16 GB and ~23 minutes on Intel i7-36xx, SSD)
6. Create a new variable with name "WXWIN" and value "<wxDirPath>" (Windows: Press WinKey+R -> type sysdm.cpl -> Advanced tab -> Environment Variables... -> New button (User section for current user only, system section for all users))
7. Clone GitHub repository with key --recurse-submodules (https://github.com/KliKonNik/wxWidgetsTests.git) 
8. Open local GitHub repository (from point 7) with Microsoft Visual Studio.

Done.
