pipeline {
    agent { docker 'gcc' }
    stages {
        stage('build') {
            steps {
                sh 'apt update'
                sh 'apt install cmake --yes'
                sh 'cmake CMakeLists.txt'
                sh 'make'
            }
        }
    }
}