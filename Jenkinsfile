pipeline {
    agent { docker 'gcc' }
    stages {
        stage('build') {
            steps {
                sh 'cmake CMakeLists.txt'
                sh 'make'
            }
        }
    }
}