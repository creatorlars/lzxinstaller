pipeline {
    agent none
    stages {
        stage('Build Linux') {
            agent {
                label 'master'
            }
            steps {
                copyArtifacts(projectName: 'lzxcore-tbc2-base', target: 'firmware')   
                copyArtifacts(projectName: 'lzxplnx', target: 'firmware')   
                copyArtifacts(projectName: 'dfu-utils-cross', target: 'dfu-util')  
                sh 'rm -rf build'
                sh 'mkdir build && cd build && cmake .. && cmake --build . --config Rel/ease && cmake --build . --target bundle --config Release'
                //sh 'mkdir installer'
                //sh 'cp build/_CPack_Packages/** installer's
                //sh 'mv build/_CPack_Packages/Linux/IFW/LZX-0.1.1-win64/repository installer/Linux/repository'
                //archiveArtifacts artifacts: 'installer/**'
                archiveArtifacts artifacts: '${WORKSPACE}/build/_CPack_Packages/**'
            }
        }
        stage('Build Windows') {
            agent {
                label 'lzx-windows'
            }
            steps {
                copyArtifacts(projectName: 'lzxcore-tbc2-base', target: 'firmware')   
                copyArtifacts(projectName: 'lzxplnx', target: 'firmware')   
                copyArtifacts(projectName: 'dfu-utils-cross', target: 'dfu-util') 
                //bat 'cinst --no-progress -y 7zip'
                //bat 'pip install aqtinstall'
                bat 'mkdir build && cd build && mkdir bin'
                bat 'cd build && cmake .. && cmake --build . --config Release --target bundle'
                //bat 'mkdir installer'
                
                //bat 'move build\\_CPack_Packages\\** installer'
                //bat 'move build\\_CPack_Packages\\win64\\IFW\\LZX-0.1.1-win64\\repository installer\\win64'
                archiveArtifacts artifacts: '${WORKSPACE}\\build\\_CPack_Packages\\**'
            }
        }
    }
}


// jobs:
// - job: Ubuntu_1604
//   pool:
//     vmImage: 'ubuntu-16.04'
//   variables:
//     linuxdeployqtVersion: 6
//   steps:
//     - task: UsePythonVersion@0
//       inputs:
//         versionSpec: '3.6'
//         architecture: 'x64'
//     - script: |
//         sudo apt-get -q update
//         sudo apt-get install -y -q cmake ninja-build make g++ rpm p7zip-full
//         sudo apt-get install -y -q qtbase5-dev qt5-style-plugins
//         wget -q -O linuxdeployqt https://github.com/probonopd/linuxdeployqt/releases/download/6/linuxdeployqt-6-x86_64.AppImage
//         sudo install linuxdeployqt /usr/local/bin/
//       displayName: install dependencies
//     - task: CMake@1
//       displayName: configure
//       inputs:
//         workingDirectory: '$(Build.BinariesDirectory)/build'
//         cmakeArgs: $(Build.SourcesDirectory)
//     - task: CMake@1
//       displayName: build
//       inputs:
//         workingDirectory: '$(Build.BinariesDirectory)/build'
//         cmakeArgs: --build $(Build.BinariesDirectory)/build --target bundle
//     - script: ls -l $(Build.BinariesDirectory)/build

// - job: macOS
//   pool:
//     vmImage: 'macOS-10.13'
//   steps:
//     - task: UsePythonVersion@0
//       inputs:
//         versionSpec: '3.x'
//     - script: |
//         brew install p7zip
//         pip install aqtinstall
//         (cd /usr/local/opt; aqtinst 5.12.1 mac desktop clang_64)
//       displayName: install qt
//     - task: CMake@1
//       displayName: configure
//       inputs:
//         workingDirectory: '$(Build.BinariesDirectory)/build'
//         cmakeArgs: -DCMAKE_VERBOSE_MAKEFILE:BOOL=ON -DQt5_DIR=/usr/local/opt/Qt5.12.1/5.12.1/clang_64/lib/cmake/Qt5/ $(Build.SourcesDirectory)
//     - task: CMake@1
//       displayName: build
//       inputs:
//         workingDirectory: '$(Build.BinariesDirectory)/build'
//         cmakeArgs: --build $(Build.BinariesDirectory)/build
//     - task: CMake@1
//       displayName: build
//       inputs:
//         workingDirectory: '$(Build.BinariesDirectory)/build'
//         cmakeArgs: --build $(Build.BinariesDirectory)/build --target bundle
//     - script: ls -l $(Build.BinariesDirectory)/build

// - job: Windows64
//   pool:
//     vmImage: 'vs2017-win2016'
//   steps:
//     - task: UsePythonVersion@0
//       inputs:
//         versionSpec: '3.6'
//         architecture: 'x64'
//     - script: |
//         cinst --no-progress -y 7zip
//         pip install aqtinstall
//         cd $(Build.BinariesDirectory)
//         c
//       displayName: install qt
//     - task: CMake@1
//       displayName: configure
//       inputs:
//         workingDirectory: $(Build.BinariesDirectory)
//         cmakeArgs: -G "Visual Studio 15 2017 Win64" -DQt5_DIR=$(Build.BinariesDirectory)\Qt5.12.1\5.12.1\msvc2017_64\lib\cmake\Qt5 $(Build.SourcesDirectory)
//     - task: CMake@1
//       displayName: build
//       inputs:
//         workingDirectory: $(Build.BinariesDirectory)
//         cmakeArgs: --build . --config Release
//     - task: CMake@1
//       displayName: build package
//       inputs:
//         workingDirectory: $(Build.BinariesDirectory)
//         cmakeArgs: --build . --target bundle --config Release
//     - script: |
//         cat $(Build.BinariesDirectory)/_CPack_Packages/win64/NSIS/NSISOutput.log
//         ls -l $(Build.BinariesDirectory)

