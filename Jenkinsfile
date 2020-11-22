pipeline {
    agent none
    // agent {
    //     node {
    //         label 'lzx-windows'
    //     }
    // }
    
    environment {
        PROJECT_NAME = 'lzxinstaller'
        PROJECT_DESCRIPTION = 'LZX Tools Installer'
        PROJECT_VERSION = '0.1.0'
        PROJECT_AUTHOR = 'LZX Industries'
    }

    stages {
        stage('Build Linux') {
            agent {
                label 'master'
            }
            steps {
                copyArtifacts(projectName: 'lzxcore-tbc2-base', target: 'components')   
                copyArtifacts(projectName: 'lzxplnx', target: 'components')   
                copyArtifacts(projectName: 'lzxdfu', target: 'components')   
                sh 'mkdir build && cd build && cmake .. && cmake --build . && cpack .'
                sh 'mkdir installer'
                sh 'mv build/lzx-tools-installer.run installer/lzx-tools-installer.run'
                sh 'mv build/_CPack_Packages/Linux/IFW/lzx-tools-installer/repository installer/repository'
                archiveArtifacts artifacts: 'installer/**'
            }
        }
        stage('Build Windows') {
            agent {
                label 'lzx-windows'
            }
            steps {
                copyArtifacts(projectName: 'lzxcore-tbc2-base', target: 'components')   
                copyArtifacts(projectName: 'lzxplnx', target: 'components')   
                copyArtifacts(projectName: 'lzxdfu', target: 'components')   
                bat 'mkdir build && cd build && cmake .. && cmake --build . && cpack .'
                bat 'mkdir installer'
                bat 'move build\\lzx-tools-installer.exe installer'
                bat 'move build\\_CPack_Packages\\win64\\IFW\\lzx-tools-installer\\repository installer'
                archiveArtifacts artifacts: 'installer/**'
            }
        }
    }
}