pipeline {
    agent { docker 'gcc' }
    stages {
        stage('build') {
            steps {
                sh 'sudo apt update'
                sh 'sudo apt install cmake --yes'
                sh 'cmake CMakeLists.txt'
                sh 'make'
            }
        }
    }
}