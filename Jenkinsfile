pipeline {
    agent { docker 'ubuntu' }
    stages {
        stage('build') {
            steps {
                sh 'apt update'
                sh 'apt install gcc g++ make cmake --yes'
                sh 'cmake CMakeLists.txt'
                sh 'make'
            }
        }
    }
}