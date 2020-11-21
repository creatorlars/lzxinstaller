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
            }
        }
        stage('Build') {
            steps {
                sh 'rm -rf build && mkdir build && cd build && cmake .. && cmake --build . && cpack .'
            }
        }
        stage('Archive') {
            steps {
                //sh 'mkdir downloads && cp -R ${WORKSPACE}/build/_CPack_Packages/win64/IFW/lzx-tools-installer/repository ${WORKSPACE}/downloads'
                //sh 'rm -rf installer && mkdir installer && cp -R ${WORKSPACE}/build/lzx-tools-installer.exe ${WORKSPACE}/installer'
                //archiveArtifacts artifacts: 'downloads'
                archiveArtifacts artifacts: 'build/lzx-tools-installer.exe'
            }
        }
    }
}