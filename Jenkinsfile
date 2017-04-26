pipeline {
    agent { docker 'gcc'}
    stages {
        stage('Build') {
            steps {
                apt update
                apt install cmake --yes
                cmake CMakeLists.txt
                make
            }
        }
    }
}