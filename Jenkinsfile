node('docker') {
    checkout scm
    stage('Build') {
        docker.image('gcc').inside {
            sh 'apt update'
            sh 'apt install cmake --yes'
            sh 'cmake CMakeLists.txt'
            sh 'make'
        }
    }
}