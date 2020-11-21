pipeline {
    agent {
        node {
            label 'lars-thinkpad'
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
            }
        }
        stage('Build') {
            steps {
                sh 'rm -rf build && mkdir build && cd build && cmake .. && cmake --build . && cpack .'
            }
        }
        stage('Archive') {
            steps {
                sh 'rm -rf installer && mkdir installer && mv build/lzx-tools-installer.exe installer/lzx-tools-installer.exe'
                sh 'mv build/_CPack_Packages/win64/IFW/lzx-tools-installer/repository installer/repository'
                archiveArtifacts artifacts: 'installer/*'
                //archiveArtifacts artifacts: 'installer/lzx-tools-installer.exe'
            }
        }
    }
}