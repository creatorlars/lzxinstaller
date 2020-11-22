pipeline {
    agent {
        node {
            label 'lzx-windows'
        }
    }
    
    environment {
        PROJECT_NAME = 'lzxinstaller'
        PROJECT_DESCRIPTION = 'LZX Tools Installer'
        PROJECT_VERSION = '0.1.0'
        PROJECT_AUTHOR = 'LZX Industries'
    }

    stages {
        stage('Import Artifacts') {
            steps {
                copyArtifacts(projectName: 'lzxcore-tbc2-base', target: 'components')   
                copyArtifacts(projectName: 'lzxplnx', target: 'components')   
                copyArtifacts(projectName: 'lzxdfu', target: 'components')   
            }
        }
        stage('Build') {
            steps {
                bat 'mkdir build && cd build && cmake .. && cmake --build . && cpack .'
            }
        }
        stage('Archive') {
            steps {
                bat 'mkdir installer'
                bat 'move build\\lzx-tools-installer.exe installer'
                bat 'move build\\_CPack_Packages\\win64\\IFW\\lzx-tools-installer\\repository installer'
                archiveArtifacts artifacts: 'installer/*'
                //archiveArtifacts artifacts: 'installer/lzx-tools-installer.exe'
            }
        }
    }
}