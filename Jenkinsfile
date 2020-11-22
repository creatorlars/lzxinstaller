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
                sh 'mkdir installer/Linux'
                sh 'mv build/lzx.run installer/Linux/lzx.run'
                sh 'mv build/_CPack_Packages/Linux/IFW/lzx/repository installer/Linux/repository'
                archiveArtifacts artifacts: 'installer/Linux/**'
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
                bat 'mkdir installer/win64'
                bat 'move build\\lzx.exe installer\\win64'
                bat 'move build\\_CPack_Packages\\win64\\IFW\\lzx\\repository installer/win64'
                archiveArtifacts artifacts: 'installer/win64/**'
            }
        }
    }
}