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
                copyArtifacts(projectName: 'lzxplnx', target: 'artifacts/lzxplnx')        
                copyArtifacts(projectName: 'lzxplnx', target: 'artifacts/lzxcore-tbc2-base')   
                copyArtifacts(projectName: 'lzxplnx', target: 'artifacts/lzxdfu')   
            }
        }
        stage('Build') {
            steps {
                sh 'rm -rf build && mkdir build && cd build && cmake .. && cmake --build . && cpack .'
            }
        }
        stage('Export Artifacts') {
            steps {
                archiveArtifacts artifacts: 'build/repo'
                archiveArtifacts artifacts: 'build/*.exe'
                archiveArtifacts artifacts: 'build/*.dmg'
                archiveArtifacts artifacts: 'build/*.run'
            }
        }
    }
}